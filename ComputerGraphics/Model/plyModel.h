//http://sjsu-mrt.googlecode.com/svn-history/r8/trunk/src/ply.c

#ifndef PLYMODEL_H
#define PLYMODEL_H
#include <string>
#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
using namespace std;

class plyModel
{

private:

    FILE *file;
    float** vert;
    long long int** faces;
    void skip_header();
    void load_vertices();
    void load_faces();
    void normalize(float *v);
    void vector(long long int a,long long int b, float *v);
    void cross_product(float *a, float *b, float *result);
    void normal(long long int i, long long int j, long long int k, float *n);
    void vector_add(float ,float,float, unsigned index);
    int display_init(string filename);
    GLuint loadBMP_custom(const char * imagepath);
public:
    plyModel(string filename, int vertices,int faces,int nonplymodel);
    string filename;
    int nonplymodel=0;
    const int NUM_VERTICES,NUM_FACES;
    static int yaw, pitch, roll;
    int loadFile(string filename);
    void display_draw();
    void display_flat_draw();
    int getPrespectiveid();
     float** norm;
     float** tex;


};

#endif // PLYMODEL_H
