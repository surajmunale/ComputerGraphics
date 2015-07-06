//http://sjsu-mrt.googlecode.com/svn-history/r8/trunk/src/ply.c

#include "plyModel.h"
#include <stdio.h>
#include<string.h>
#include <math.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

//static float** norm;
//static float** tex;

plyModel::plyModel(string filename,int v,int f,int nonplumodel):NUM_VERTICES(v),NUM_FACES(f)
{

    if( nonplumodel==0)
    {
        vert=new float*[v];
        for (long long int i = 0; i < v; ++i)
        {
          vert[i] = new float[3];
        }

        faces=new long long int*[f];

        for (long long int i = 0; i < f; ++i)
        {
          faces[i] = new long long int[3];
           for(int j=0;j<3;j++)
           {
               faces[i][j]=0;
           }
        }

        norm=new float*[v];
        for (long long int i = 0; i < v; ++i)
        {
          norm[i] = new float[3];
        }

        tex=new float*[v];
        for (long long int i = 0; i < v; ++i)
        {
          tex[i] = new float[3];
        }
        this->filename=filename;
        display_init(filename);
    }
    else
    {
        this->nonplymodel=nonplumodel;

    }

}

int plyModel::loadFile(string filename)
{
    char myArray[filename.size()+1];//as 1 char space for null is also required
    strcpy(myArray, filename.c_str());
    FILE *file = fopen(myArray, "r");
    if (file == NULL)
    {
        perror("ply_load_mesh()");

        return 0;
    }
    this->file=file;
    skip_header();
    load_vertices();
    load_faces();
    fclose(file);
    return 1;
}

void plyModel::load_faces()
{
    long long int i,p1[3],p2[3],p3[3];

       for (i = 0; i < NUM_FACES; i++)
       {
           int v = fscanf(file, "3 %d %d %d\n",&faces[i][0], &faces[i][1], &faces[i][2]);

           if (v == EOF)
               perror("bunny");
       }
}

void plyModel::load_vertices()
{
    long long int i;
    char buffer[80];

    for (i = 0; i < NUM_VERTICES; i++) {
        char *p = fgets(buffer, 80, file);

        if (p == NULL)
            puts("load_vertices(): fgets error");

        sscanf(buffer, "%f %f %f", &vert[i][0], &vert[i][1], &vert[i][2]);
    }

}

void plyModel::skip_header()
{
    char buffer[80];
    do {
        char *p = fgets(buffer, 80, file);
        if (p == NULL)
            puts("skip_header(): fgets error");
    } while (strcmp(buffer, "end_header\n") != 0);
}
void plyModel:: normalize(float *v)
{
    float length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] /= length;
    v[1] /= length;
    v[2] /= length;
}
void plyModel::vector(long long int a, long long int b, float *v)
{
    v[0] = vert[a][0] - vert[b][0];
    v[1] = vert[a][1] - vert[b][1];
    v[2] = vert[a][2] - vert[b][2];
}
void plyModel:: cross_product(float *a, float *b, float *result)
{
    result[0] = a[1] * b[2] - b[1] * a[2];
    result[1] = a[2] * b[0] - b[2] * a[0];
    result[2] = a[0] * b[1] - b[0] * a[1];
}
void plyModel:: normal(long long  int i, long long  int j, long long  int k, float *n)
{
    float first[3], second[3];
    vector(j, i, first);
    vector(k, i, second);
    cross_product(first, second, n);
    normalize(n);
}

void plyModel::vector_add(float n0,float n1,float n2, unsigned index)
{
    norm[index][0] += n0;
    norm[index][1] += n1;
    norm[index][2] += n2;
}
GLuint plyModel:: loadBMP_custom(const char * imagepath)
{
    // Data read from the header of the BMP file
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int imageSize;   // = width*height*3
    // Actual RGB data
    unsigned char * data;
    unsigned int width, height;

    // Open the file
    FILE * file = fopen(imagepath,"rb");
    if (!file)
    {
        printf("Image could not be opened\n"); return 0;
    }

    if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
       printf("Not a correct BMP file\n");
       return 0;
    }
    if ( header[0]!='B' || header[1]!='M' ){
       printf("Not a correct BMP file\n");
       return 0;
    }

    // Read ints from the byte array
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    // Some BMP files are misformatted, guess missing information
    if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos==0)      dataPos=54; // The BMP header is done that way

    // Create a buffer
    data = new unsigned char [imageSize];

    // Read the actual data from the file into the buffer
    int result=fread(data,1,imageSize,file);

    if(result!=imageSize)
    {
        printf("Read error \n");
    }
    //printf("%s",data);

    //Everything is in memory now, the file can be closed
    fclose(file);

    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);


    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    free(data);
        return textureID;
}

void plyModel::display_draw()
{

    if(nonplymodel==0)
    {
        int i, j;

        if(this->filename.compare("bunny.ply")==0)
            glTranslatef(0.03,-0.09,-0.01);

        glBegin(GL_TRIANGLES);
        for (i = 0; i < NUM_FACES; i++)
            for (j = 0; j < 3; j++) {
                int vindex = faces[i][j];
                glNormal3fv(norm[vindex]);
                glTexCoord3fv(tex[vindex]);
                glVertex3fv(vert[vindex]);
            }
        glEnd();
    }
    else
    {
        switch (nonplymodel)
        {
        case 1:
                glutSolidTeapot(0.6);
            break;

        default:
            break;
        }
    }
}

void plyModel::display_flat_draw()
{
    int i, j;

    if(this->filename.compare("bunny.ply")==0)
    glTranslatef(0.03,-0.09,-0.01);

    glBegin(GL_TRIANGLES);
    for (i = 0; i < NUM_FACES; i++)
    {
        int vindex = faces[i][0];
        glNormal3fv(norm[vindex]);
        glTexCoord3fv(tex[vindex]);
        for (j = 0; j < 3; j++)
        {
            glVertex3fv(vert[faces[i][j]]);
        }
    }

    glEnd();
}

int plyModel::display_init(string filename)
{
   long long int i, j;

    if(!loadFile(filename))
    {
        return 0;
    }

    for (i = 0; i < NUM_FACES; i++)
    {
        long long int *v = faces[i];
        float vn[3];
        normal(v[0], v[1], v[2], vn); /* normal of the triangle face */
        for (j = 0; j < 3; j++)
        {
            vector_add(vn[0],vn[1],vn[2], v[j]); /* add face normals to vertex normals */
        }
    }

    for (i = 0; i < NUM_VERTICES; i++)
    {
        normalize(norm[i]);
        for (j = 0; j < 3; j++)
            tex[i][j] = vert[i][j] * 10 + 1;
    }
    return 1;
}

