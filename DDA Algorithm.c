#include<windows.h>
#include <GL/glut.h>
#include<math.h>

float XS, XE, YS, YE,temp, i, m, b, y;

void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);

    XS = 1, YS = 38, XE = 39, YE = 1;

    if(XS>=XE)
    {
        temp = XS;
        XS = XE;
        XE = temp;
    }
    if(YS>=YE)
    {
        temp = YS;
        YS = YE;
        YE = temp;
    }
    m = (YE-YS)/(XE-XS);

    while(XS<=XE)
    {
        XS = XS + 1;
        YS = YS + m;
        y = round(YS);

        glColor3f (0.0f, 1.0f, 0.0f);

        glBegin(GL_POINTS);
        glVertex2i(XS,y);
    }
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("m = 1");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
