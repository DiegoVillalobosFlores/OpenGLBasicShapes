#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

using namespace std;

void display();
void renderHalfCircle();
void keyPress(unsigned char key, int x, int y);
void moveObject(unsigned char key);
void reshape(int width, int height);
void renderHouse();
void renderUmbrella();

GLfloat xmeg = 0;
GLfloat ymeg = 0;
GLfloat xpos = 0;
GLfloat ypos = 0;

int main(int argc, char **argv) {
    cout<<"Initializing GLUT"<<endl;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(520,520);
    glutCreateWindow("House");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);

    glutMainLoop();
    return 0;
}

void display(){
    renderHouse();
    renderHalfCircle();
}

void renderHalfCircle(){
    int i;
    int lineAmount = 100;

    GLfloat x = 0;
    GLfloat y = 0;

    GLfloat radius = 0.1;
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.141592;
    glBegin(GL_LINES);
    for(i = 0 ; i <= lineAmount ; i++){
        glVertex2f(
                xpos + (0.7) + (radius * cos(i * 3.141592 / lineAmount)),
                ypos - (0.3) + (radius * sin(i * 3.141592 / lineAmount))
                //ypos + (radius * sin(i * twicePi / lineAmount))
        );
        glColor3f(1,1,1);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(xpos + 0.6,ypos-0.3);
    glVertex2f(xpos + 0.8,ypos-0.3);
    glColor3f(1,1,1);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(xpos+0.7,ypos-0.3);
    glVertex2f(xpos+0.7,ypos-0.5);
    glColor3f(1,1,1);
    glEnd();

    glutSwapBuffers();
}

void reshape (int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
    glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
    glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
    //gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
    glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}

void keyPress(unsigned char key, int x, int y){
    moveObject(key);
}

void renderUmbrella(){

}

void renderHouse(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex3f((xpos)-(0.5),(ypos),0);
    glVertex3f(xpos,(ypos)+(0.5),0);
    glVertex3f((xpos)+(0.5),ypos,0);
    glColor3f(1,0.5,0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((xpos)-(0.5),ypos);
    glVertex2f((xpos)-0.5,ypos-0.5);
    glVertex2f(xpos+0.5,ypos-0.5);
    glVertex2f(xpos+0.5,ypos);
    glColor3f(ypos,xpos+0.5,0.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(xpos-0.1,ypos-0.5);
    glVertex2f(xpos-0.1,ypos-0.2);
    glVertex2f(xpos+0.1,ypos-0.2);
    glVertex2f(xpos+0.1,ypos-0.5);
    glColor3f(0.2,xpos,ypos+0.2);
    glEnd();

    //glutSwapBuffers();
}

void moveObject(unsigned char key){
    cout<<key<<endl;
    switch (key){
        case 'q':
            exit(0);
        case 'a':
            xpos = xpos - 0.01;
            break;
        case 's':
            ypos = ypos - 0.01;
            break;
        case 'w':
            ypos = ypos + 0.01;
            break;
        case 'd':
            xpos = xpos + 0.01;
            break;
        case ' ':
            xpos = 0;
            ypos = 0;
        default:
            break;
    }
    glutPostRedisplay();
}