#include "scene_graph.h"
#include <GL/glut.h>
#include <GL/glu.h>

Scene_Graph::Scene_Graph()
{

}
void Scene_Graph:: construct()
{

    //Set the Translation Matrix for the Base
surface->tranMatrix.setX(0);
surface->tranMatrix.setY(-2);
surface->tranMatrix.setZ(-3);

//Rotation
surface->rotationMatrix.setW(0.0);
surface->rotationMatrix.setX(0.0);
surface->rotationMatrix.setY(1.0);
surface->rotationMatrix.setZ(0.0);
//scale
surface->scaleMatrix.setX(1);
surface->scaleMatrix.setY(1);
surface->scaleMatrix.setZ(1);


//Set the Translation Matrix for the Base
b->tranMatrix.setX(0);
b->tranMatrix.setY(1.5);
b->tranMatrix.setZ(-3);

//Rotation
b->rotationMatrix.setW(0.0);
b->rotationMatrix.setX(0.0);
b->rotationMatrix.setY(1.0);
b->rotationMatrix.setZ(0.0);
//scale
b->scaleMatrix.setX(1);
b->scaleMatrix.setY(1);
b->scaleMatrix.setZ(1);


//Set the Translation Matrix for the Base1
b1->tranMatrix.setX(20);
b1->tranMatrix.setY(1.5);
b1->tranMatrix.setZ(-15);

//Rotation
b1->rotationMatrix.setW(0.0);
b1->rotationMatrix.setX(0.0);
b1->rotationMatrix.setY(1.0);
b1->rotationMatrix.setZ(0.0);
//scale
b1->scaleMatrix.setX(1);
b1->scaleMatrix.setY(1);
b1->scaleMatrix.setZ(1);

//Set the Translation Matrix for the Base2
b2->tranMatrix.setX(-20);
b2->tranMatrix.setY(1.5);
b2->tranMatrix.setZ(-15);
//Rotation
b2->rotationMatrix.setW(0.0);
b2->rotationMatrix.setX(0.0);
b2->rotationMatrix.setY(1.0);
b2->rotationMatrix.setZ(0.0);
//scale
b2->scaleMatrix.setX(1);
b2->scaleMatrix.setY(1);
b2->scaleMatrix.setZ(1);



//Set the Translation Matrix for the Base3
b3->tranMatrix.setX(60);
b3->tranMatrix.setY(1.5);
b3->tranMatrix.setZ(-25);
//Rotation
b3->rotationMatrix.setW(0.0);
b3->rotationMatrix.setX(0.0);
b3->rotationMatrix.setY(1.0);
b3->rotationMatrix.setZ(0.0);
//scale
b3->scaleMatrix.setX(1);
b3->scaleMatrix.setY(1);
b3->scaleMatrix.setZ(1);

//Set the Translation Matrix for the Base3
b4->tranMatrix.setX(-20);
b4->tranMatrix.setY(1.5);
b4->tranMatrix.setZ(-75);
//Rotation
b4->rotationMatrix.setW(0.0);
b4->rotationMatrix.setX(0.0);
b4->rotationMatrix.setY(1.0);
b4->rotationMatrix.setZ(0.0);
//scale
b4->scaleMatrix.setX(1);
b4->scaleMatrix.setY(1);
b4->scaleMatrix.setZ(1);

surface->childrens.push_back(b);
surface->childrens.push_back(b1);
surface->childrens.push_back(b2);
surface->childrens.push_back(b3);
surface->childrens.push_back(b4);
}

//Call root->left->right
void Scene_Graph:: display(Scene_Object *node)
{
   if(node==NULL)
   {
       return;
   }

   glPushMatrix();

   glTranslatef(node->tranMatrix.x(),node->tranMatrix.y(),node->tranMatrix.z());
   glRotatef(node->rotationMatrix.w(),node->rotationMatrix.x(),node->rotationMatrix.y(),node->rotationMatrix.z());
   glScalef(node->scaleMatrix.x(),node->scaleMatrix.y(),node->scaleMatrix.z());
   node->display();
   if(node->childrens.size()!=0)
   {
       for (std::list<Scene_Object *>::iterator it = node->childrens.begin(); it != node->childrens.end(); it++)
       {
          display(*it);
       }
   }
   glPopMatrix();
}

void Scene_Graph::clearDisplay(Scene_Object *node)
{
    if(node==NULL)
    {
        return;
    }
    node->isDisplayed=0;
    if(node->childrens.size()!=0)
    {
        for (std::list<Scene_Object *>::iterator it = node->childrens.begin(); it != node->childrens.end(); it++)
        {
           display(*it);
        }
    }
}

void Scene_Graph:: rotate()
{

}

void Scene_Graph:: translate()
{

}
