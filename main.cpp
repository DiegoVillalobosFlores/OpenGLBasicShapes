#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

using namespace std;

void renderCircle();

int main(int argc, char **argv) {
    cout<<"Initializing GLUT"<<endl;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(420,420);
    glutCreateWindow("LOL");

    glutDisplayFunc(renderCircle);

    glutMainLoop();
    return 0;
}

void renderCircle(){
    int i;
    int lineAmount = 360;

    GLfloat x = 0;
    GLfloat y = 0;

    GLfloat radius = 1;
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.141592;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);
    for(i = 0 ; i <= lineAmount ; i++){
        glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();

    glutSwapBuffers();
}