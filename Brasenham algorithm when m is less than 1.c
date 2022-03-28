#include<windows.h>
#include<GL/glut.h>
#include<math.h>
void display()
{
 glClear(GL_COLOR_BUFFER_BIT); ///Clear the color buffer of background
///axis
 glBegin(GL_LINES);
 glColor3f(1.0f,1.0f,1.0f); ///white color
 ///glVertex2f(0.0f,0.0f); /// center
 glVertex2f(-1.0f,0.0f); ///x-axis
 glVertex2f(1.0f,0.0f);
 glVertex2f(0.0f,1.0f);///y-axis
 glVertex2f(0.0f,-1.0f);
 glEnd();
///draw a point
 glPointSize(4.0f);
 GLfloat xstart = 0.2f, xend= 0.7f, ystart=0.1f, yend= 0.3f, x, y,dx, dy, p;

x = xstart;
y = ystart;
dx = xend - xstart;
dy = yend - ystart;
p = 2 *dy - dx;

    while(x<xend)
    {
        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        glFlush();
        x=x+0.001;

        if(p<0)
        {
        p=p+2*dy;
        }
        else
        {
         p=p+2*dy - 2* dx;}
         y=y+0.001;
        }
}



int main(int argc, char** argv)
{
 glutInit(&argc, argv); ///Initialize GLUT
 glutInitWindowSize(640,640); /// Set the initial window size with given width and height
 glutInitWindowPosition(80,50); ///Position of the window's initial top-left corner
 glutCreateWindow("Lab 1"); ///Create a window which name will be the given one
 glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH); ///shows color,allows for single buffer
//window and allows for depth buffer
 glutDisplayFunc(display); ///Call the named function to display
 glutMainLoop(); ///Enter the event-processing loop
 return 0;
}

