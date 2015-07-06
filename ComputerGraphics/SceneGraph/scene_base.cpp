#include "scene_base.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include<math.h>
#include <GL/freeglut.h>

//redius 4 represnt the base of merigoround
//redius 100 represnt the surface/ground below the base of merigoround.
Scene_Base::Scene_Base(float redius)
{
    this->redius=redius;
    if(redius==4)
    {
        //Set the transodrmation matrix for the cylinder
        //Main Pole
        c1->tranMatrix.setX(0);
        c1->tranMatrix.setY(6);
        c1->tranMatrix.setZ(0);
            //Rotation
        c1->rotationMatrix.setW(90.0);
        c1->rotationMatrix.setX(1.0);
        c1->rotationMatrix.setY(0.0);
        c1->rotationMatrix.setZ(0.0);
        //scale
        c1->scaleMatrix.setX(1);
        c1->scaleMatrix.setY(1);
        c1->scaleMatrix.setZ(1);

        //Pole1
        c2->tranMatrix.setX(2.5);
        c2->tranMatrix.setY(5);
        c2->tranMatrix.setZ(0);
            //Rotation
        c2->rotationMatrix.setW(90.0);
        c2->rotationMatrix.setX(1.0);
        c2->rotationMatrix.setY(0.0);
        c2->rotationMatrix.setZ(0.0);
        //scale
        c2->scaleMatrix.setX(1);
        c2->scaleMatrix.setY(1);
        c2->scaleMatrix.setZ(1);

        //Pole2
        c3->tranMatrix.setX(-2.5);
        c3->tranMatrix.setY(5);
        c3->tranMatrix.setZ(0);
           //Rotation
        c3->rotationMatrix.setW(90.0);
        c3->rotationMatrix.setX(1.0);
        c3->rotationMatrix.setY(0.0);
        c3->rotationMatrix.setZ(0.0);
        //scale
        c3->scaleMatrix.setX(1);
        c3->scaleMatrix.setY(1);
        c3->scaleMatrix.setZ(1);


        //Pole3
        c4->tranMatrix.setX(1.2);
        c4->tranMatrix.setY(5);
        c4->tranMatrix.setZ(2.6);
           //Rotation
        c4->rotationMatrix.setW(90.0);
        c4->rotationMatrix.setX(1.0);
        c4->rotationMatrix.setY(0.0);
        c4->rotationMatrix.setZ(0.0);
        //scale
        c4->scaleMatrix.setX(1);
        c4->scaleMatrix.setY(1);
        c4->scaleMatrix.setZ(1);


        //Pole4
        c5->tranMatrix.setX(-1.2);
        c5->tranMatrix.setY(5);
        c5->tranMatrix.setZ(2.6);
        //Rotation
        c5->rotationMatrix.setW(90.0);
        c5->rotationMatrix.setX(1.0);
        c5->rotationMatrix.setY(0.0);
        c5->rotationMatrix.setZ(0.0);
        //scale
        c5->scaleMatrix.setX(1);
        c5->scaleMatrix.setY(1);
        c5->scaleMatrix.setZ(1);

        //pole 5
        c6->tranMatrix.setX(0);
        c6->tranMatrix.setY(5);
        c6->tranMatrix.setZ(-2.6);
          //Rotation
        c6->rotationMatrix.setW(90.0);
        c6->rotationMatrix.setX(1.0);
        c6->rotationMatrix.setY(0.0);
        c6->rotationMatrix.setZ(0.0);
        //scale
        c6->scaleMatrix.setX(1);
        c6->scaleMatrix.setY(1);
        c6->scaleMatrix.setZ(1);

        //topcone
        topcone->tranMatrix.setX(0);
        topcone->tranMatrix.setY(0);
        topcone->tranMatrix.setZ(1.5);
         //Rotation
        topcone->rotationMatrix.setW(180.0);
        topcone->rotationMatrix.setX(1.0);
        topcone->rotationMatrix.setY(0.0);
        topcone->rotationMatrix.setZ(0.0);
        //scale
        topcone->scaleMatrix.setX(1);
        topcone->scaleMatrix.setY(1);
        topcone->scaleMatrix.setZ(1);


        //Cow1 attached to pole2
        cow1->tranMatrix.setX(0);
        cow1->tranMatrix.setY(0);
        cow1->tranMatrix.setZ(3.5);
          //Rotation
        cow1->rotationMatrix.setW(-90.0);
        cow1->rotationMatrix.setX(1.0);
        cow1->rotationMatrix.setY(0.0);
        cow1->rotationMatrix.setZ(0.0);
        //scale
        cow1->scaleMatrix.setX(1);
        cow1->scaleMatrix.setY(1);
        cow1->scaleMatrix.setZ(1);

        //horse1 attached to pole2
        horse1->tranMatrix.setX(0);
        horse1->tranMatrix.setY(0);
        horse1->tranMatrix.setZ(2.2);
          //Rotation
        horse1->rotationMatrix.setW(180.0);
        horse1->rotationMatrix.setX(1.0);
        horse1->rotationMatrix.setY(0.0);
        horse1->rotationMatrix.setZ(0.0);
        //scale
        horse1->scaleMatrix.setX(1);
        horse1->scaleMatrix.setY(1);
        horse1->scaleMatrix.setZ(1);


        //egret attached to pole3
        egret1->tranMatrix.setX(-1);
        egret1->tranMatrix.setY(0);
        egret1->tranMatrix.setZ(1.5);
        //Rotation
        egret1->rotationMatrix.setW(180.0);
        egret1->rotationMatrix.setX(1.0);
        egret1->rotationMatrix.setY(0.0);
        egret1->rotationMatrix.setZ(0.0);
        //scale
        egret1->scaleMatrix.setX(1);
        egret1->scaleMatrix.setY(1);
        egret1->scaleMatrix.setZ(1);


        //pickup car attached to pole4 and pole 5
        pickupcar->tranMatrix.setX(0);
        pickupcar->tranMatrix.setY(0);
        pickupcar->tranMatrix.setZ(3);
        //rotation
        pickupcar->rotationMatrix.setW(180.0);
        pickupcar->rotationMatrix.setX(1.0);
        pickupcar->rotationMatrix.setY(0.0);
        pickupcar->rotationMatrix.setZ(0.0);
        //scale
        pickupcar->scaleMatrix.setX(1);
        pickupcar->scaleMatrix.setY(1);
        pickupcar->scaleMatrix.setZ(1);


        //Cube attached to the pole6
        c->tranMatrix.setX(0);
        c->tranMatrix.setY(0);
        c->tranMatrix.setZ(3.0);
           //Rotation
        c->rotationMatrix.setW(0.0);
        c->rotationMatrix.setX(0.0);
        c->rotationMatrix.setY(0.0);
        c->rotationMatrix.setZ(0.0);
        //scale
        c->scaleMatrix.setX(1);
        c->scaleMatrix.setY(1);
        c->scaleMatrix.setZ(1);

        //apple attached to the cube
        apple->tranMatrix.setX(0);
        apple->tranMatrix.setY(0);
        apple->tranMatrix.setZ(-1.3);
           //Rotation
        apple->rotationMatrix.setW(180.0);
        apple->rotationMatrix.setX(1.0);
        apple->rotationMatrix.setY(0.0);
        apple->rotationMatrix.setZ(0.0);
        //scale
        apple->scaleMatrix.setX(1);
        apple->scaleMatrix.setY(1);
        apple->scaleMatrix.setZ(1);

        this->childrens.push_back(c1);
        this->childrens.push_back(c2);
        this->childrens.push_back(c3);
        this->childrens.push_back(c4);
        this->childrens.push_back(c5);
        this->childrens.push_back(c6);

        c1->childrens.push_back(topcone);

        c2->childrens.push_back(egret1);
        //c3->childrens.push_back(cow1);
        c3->childrens.push_back(horse1);
        c4->childrens.push_back(pickupcar);
        c6->childrens.push_back(c);
        c->childrens.push_back(apple);

    }
}

void Scene_Base::oscillate(int flag)
{
    if(flag)
    {
        c2->tranMatrix.setY(5.0);
        c3->tranMatrix.setY(5.0);
        c4->tranMatrix.setY(5.0);
        c5->tranMatrix.setY(5.0);
        c6->tranMatrix.setY(5.0);

    }
    else
    {
        c2->tranMatrix.setY(4.5);
        c3->tranMatrix.setY(4.5);
        c4->tranMatrix.setY(4.5);
        c5->tranMatrix.setY(4.5);
        c6->tranMatrix.setY(4.5);

    }
}

GLuint Scene_Base:: loadBMP_custom(const char * imagepath)
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

void Scene_Base:: translate(int x,int y,int z)
{
  glTranslatef(x,y,z);
}

void Scene_Base::rotate()
{
   glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
}

void Scene_Base::display()
{
//if(!isDisplayed)
//{
    if(redius==100)
    {

        glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);

        GLuint texture = loadBMP_custom("fur.bmp");
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
        glBindTexture(GL_TEXTURE_2D, texture);

        glBegin(GL_POLYGON);

                glTexCoord2f(0.0f, 0.0f);glVertex3d(500, 0,-500);
                glTexCoord2f(1.0f, 0.0f);glVertex3d(500, 0,-500);
                glTexCoord2f(1.0f, 1.0f);glVertex3d(-500, 0,-500);
                glTexCoord2f(0.0f, 1.0f);glVertex3d(-500,0,500);
                glTexCoord2f(1.0f, 0.0f);glVertex3d(0,0,500);
                glTexCoord2f(0.0f, 1.0f);glVertex3d(500,0,0);

        glEnd();

       glDisable(GL_TEXTURE_2D);

    }
    else
    {
        glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        GLuint texture = loadBMP_custom("base.bmp");
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
        glBindTexture(GL_TEXTURE_2D, texture);

            glBegin(GL_QUAD_STRIP);
                    double x1, y1, z;
                    y1=0.70;//height
                    int faces=2200; float r=4.0;
                    for (int i =0; i <= faces; i++)
                    {
                        double u = i/ (double) faces;
                        x1 = r*cos(2*M_PI*u);
                        z = r*sin(2*M_PI*u);
                          glTexCoord2f(0.0f, 0.0f);glVertex3f( 0, 0, z );
                          glTexCoord2f(1.0f, 0.0f);glVertex3f( 0, y1, z );
                          glTexCoord2f(1.0f, 1.0f);glVertex3f( x1, 0, z );
                          glTexCoord2f(0.0f, 1.0f);glVertex3f( x1, y1, z );
                     }
             glEnd();

             glDisable(GL_TEXTURE_2D);
    }
    isDisplayed=1;
//}
}

void Scene_Base::scale()
{


}
