#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846


GLfloat position_bird = 0.0f;
GLfloat speed_bird = 0.01f;

void soundTrain()
{

    PlaySound("train.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void soundCar()
{

    PlaySound("car.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void soundOff()
{

    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);


}

void update_bird(int value) {

    if(position_bird >1.0)
        position_bird = -1.0f;

    position_bird += speed_bird;

	glutPostRedisplay();


	glutTimerFunc(100, update_bird, 0);
}

GLfloat position_train = 0.0f;
GLfloat speed_train = 0.05f;

void update_train(int value) {

    if(position_train <-1.5)
        position_train = 2.0f;

    position_train -= speed_train;

	glutPostRedisplay();


	glutTimerFunc(100, update_train, 0);
}

void SpecialInput_train(int key, int x, int y)
{
switch(key)
{case GLUT_KEY_UP:
speed_train=.5;
soundTrain();
soundCar();
break;
case GLUT_KEY_DOWN:
speed_train=.0;
soundOff();
soundCar();
break;
case GLUT_KEY_LEFT:
speed_train=.1;
soundTrain();
soundCar();
break;
case GLUT_KEY_RIGHT:
speed_train=.1;
soundTrain();
soundCar();
break;}
glutPostRedisplay();}

GLfloat position_jip1 = 0.0f;
GLfloat speed_jip1 = 0.08f;

void update_jip1(int value) {

    if(position_jip1 <-1.0)
        position_jip1 = 2.0f;

    position_jip1 -= speed_jip1;

	glutPostRedisplay();


	glutTimerFunc(100, update_jip1, 0);
}

GLfloat position_bus1 = 0.0f;
GLfloat speed_bus1 = 0.06f;

void update_bus1(int value) {

    if(position_bus1 <-1.0)
        position_bus1 = 2.0f;

    position_bus1 -= speed_bus1;

	glutPostRedisplay();


	glutTimerFunc(100, update_bus1, 0);
}

GLfloat position_car1 = 0.0f;
GLfloat speed_car1 = 0.1f;

void update_car1(int value) {

    if(position_car1 <-1.0)
        position_car1 = 2.0f;

    position_car1 -= speed_car1;

	glutPostRedisplay();


	glutTimerFunc(100, update_car1, 0);
}

GLfloat position_car2 = 0.0f;
GLfloat speed_car2 = 0.1f;

void update_car2(int value) {

    if(position_car2 >2.0)
        position_car2 = -1.0f;

    position_car2 += speed_car2;

	glutPostRedisplay();


	glutTimerFunc(100, update_car2, 0);
}

GLfloat position_jip2 = 0.0f;
GLfloat speed_jip2 = 0.08f;

void update_jip2(int value) {

    if(position_jip2 >1.5)
        position_jip2 = -1.5f;

    position_jip2 += speed_jip2;

	glutPostRedisplay();


	glutTimerFunc(100, update_jip2, 0);
}

GLfloat position_car3 = 0.0f;
GLfloat speed_car3 = 0.07f;

void update_car3(int value) {

    if(position_car3 >2.0)
        position_car3 = -2.0f;

    position_car3 += speed_car3;

	glutPostRedisplay();


	glutTimerFunc(100, update_car3, 0);
}

GLfloat position_bus2 = 0.0f;
GLfloat speed_bus2 = 0.06f;

void update_bus2(int value) {

    if(position_bus2 >2.0)
        position_bus2 = -2.0f;

    position_bus2 += speed_bus2;

	glutPostRedisplay();


	glutTimerFunc(100, update_bus2, 0);
}

void handleKeypress_RightCar(unsigned char key, int x, int y) {
	switch (key) {
case 'p':
    speed_jip2 = 0.0f;
    speed_car2 = 0.0f;
    speed_bus2 = 0.0f;
    speed_car3 = 0.0f;
    soundOff();
    soundTrain();
    break;
case 'r':
    speed_jip2 = 0.1f;
    speed_car2 = 0.1f;
    speed_bus2 = 0.1f;
    speed_car3 = 0.1f;
    soundCar();
    soundTrain();
    break;
glutPostRedisplay();
	}
}

void handleMouse_LeftCar(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
        speed_car1 = 0.0f;
        speed_bus1 = 0.0f;
        speed_jip1 = 0.0f;
        soundOff();
        soundTrain();
			}
    if (button == GLUT_RIGHT_BUTTON){
	    speed_car1 = 0.1f;
	    speed_bus1 = 0.1f;
	    speed_jip1 = 0.1f;
	    soundCar();
	    soundTrain();
			}
	glutPostRedisplay();
	}

GLfloat i = 0.f, rainX = 1., rainY = 1.;

void update_rain (int value) {
    rainX -= 0.1f;
    rainY -= 0.1f;

    if (rainX < -0.1f) {
      rainX = 0.1f;
      rainY = 0.1f;
    }
    glutTimerFunc(100, update_rain, 0);
}

void Idle()
{
    glutPostRedisplay();
}

void drawLine (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat a, GLfloat b, GLfloat c , int w) {
    glLineWidth(w);
    glBegin(GL_LINES);
    glColor3f(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}


void demo_day();

void demo_back(int val) {

 glutDisplayFunc(demo_day);

}


void rain() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Background Color
    //sky
    glBegin(GL_QUADS);
    glColor3ub(135, 173, 159);

    glVertex2f(-1,1);
    glVertex2f(-1,-.5);
    glVertex2f(1,-.5);
    glVertex2f(1,1);

    glEnd();

//sun

int j;
GLfloat x; GLfloat y; GLfloat radius;
int triangleAmount;
GLfloat twicePi = 2.0f * PI;

// end

//cloud
//1st ring
glLoadIdentity();
      glTranslatef(-0.7,0.1,0);

	int j7;

	GLfloat x7=.3f; GLfloat y7= .8f; GLfloat radius7 =.050f;
	int triangleAmount7 = 20; //# of triangles used to draw circle
	glColor3ub(105, 112, 120);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(j7 = 0; j7 <= triangleAmount7;j7++) {
			glVertex2f(
		            x7 + (radius7 * cos(j7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(j7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();
//2nd ring
	int j8;

	GLfloat x8=.35f; GLfloat y8= .85f; GLfloat radius8 =.050f;
	int triangleAmount8 = 20; //# of triangles used to draw circle
	glColor3ub(105, 112, 120);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(j8 = 0; j8 <= triangleAmount8;j8++) {
			glVertex2f(
		            x8 + (radius8 * cos(j8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(j8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();
//3rd ring
	int j9;

	GLfloat x9=.40f; GLfloat y9= .8f; GLfloat radius9 =.050f;
	int triangleAmount9 = 20; //# of triangles used to draw circle
	glColor3ub(105, 112, 120);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(j9 = 0; j9 <= triangleAmount9;j9++) {
			glVertex2f(
		            x9 + (radius8 * cos(j9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(j9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();
//4th ring
	int j10;

	GLfloat x10=.35f; GLfloat y10= .80f; GLfloat radius10 =.050f;
	int triangleAmount10 = 20; //# of triangles used to draw circle
	glColor3ub(105, 112, 120);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(j10 = 0; j10 <= triangleAmount10;j10++) {
			glVertex2f(
		            x10 + (radius10 * cos(j10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(j10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();

glLoadIdentity();

glTranslatef(0.0f, .05f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
int i2;
GLfloat x2=-.8f; GLfloat y2=.8f; GLfloat radius2 =.05f;
int triangleAmount2 = 30;

GLfloat twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.85f; y2=.85f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.87f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.77f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.75f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.75f; y2=.88f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glLoadIdentity();

glTranslatef(1.5f, .05f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
 x2=-.8f;  y2=.8f;  radius2 =.05f;
 triangleAmount2 = 30;

 twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.85f; y2=.85f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.87f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.77f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.75f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.75f; y2=.88f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glLoadIdentity();

glTranslatef(1.f, .05f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.8f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.85f; y2=.85f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.87f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.77f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.75f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(105, 112, 120);
i2;
x2=-.75f; y2=.88f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glLoadIdentity();
//end cloud

//starting buildings structure

glTranslatef(0.0f,0.1f, 0.0f);
//2nd left side building
    glBegin(GL_QUADS);
    glColor3ub(0, 78, 102);
    glVertex2f(-0.92f,0.3f);
    glVertex2f(-0.92f,0.5f);
    glVertex2f(-0.95f,0.5f);
    glVertex2f(-0.95f,0.3f);
    glEnd();




    glBegin(GL_POLYGON);
    glColor3ub(0, 153, 204);
    glVertex2f(-0.55f,-0.5f);
    glVertex2f(-0.55f,0.5f);
    glVertex2f(-0.92f,0.5f);
    glVertex2f(-0.92f,0.3f);
    glVertex2f(-0.8f,0.3f);
    glVertex2f(-0.8f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(242, 242, 242);

    glVertex2f(-0.6f,0.5f);
    glVertex2f(-0.6f,-0.35f);

    glVertex2f(-0.65f,0.5f);
    glVertex2f(-0.65f,-0.35f);

    glVertex2f(-0.7f,0.5f);
    glVertex2f(-0.7f,-0.35f);

    glVertex2f(-0.75f,0.5f);
    glVertex2f(-0.75f,-0.35f);

    glVertex2f(-0.8f,0.5f);
    glVertex2f(-0.8f,0.3f);

        glVertex2f(-0.85f,0.5f);
    glVertex2f(-0.85f,0.3f);

    glEnd();


    //1st left side building

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(-0.8f,-0.5f);
    glVertex2f(-0.8f,0.3f);
    glVertex2f(-1.0f,0.3f);
    glVertex2f(-1.0f,-0.5f);
    glEnd();

   glPointSize(2);
   glBegin(GL_POINTS);
   glColor3ub(0,0,0);
   glVertex2f(-0.95f,0.26f);
   glVertex2f(-0.9f,0.26f);
   glVertex2f(-0.85f,0.26f);

   glVertex2f(-0.95f,0.2f);
   glVertex2f(-0.9f,0.2f);
   glVertex2f(-0.85f,0.2f);

   glVertex2f(-0.95f,0.14f);
   glVertex2f(-0.9f,0.14f);
   glVertex2f(-0.85f,0.14f);

   glVertex2f(-0.95f,0.08f);
   glVertex2f(-0.9f,0.08f);
   glVertex2f(-0.85f,0.08f);

   glVertex2f(-0.95f,0.02f);
   glVertex2f(-0.9f,0.02f);
   glVertex2f(-0.85f,0.02f);

   glVertex2f(-0.95f,-0.04f);
   glVertex2f(-0.9f,-0.04f);
   glVertex2f(-0.85f,-0.04f);

   glVertex2f(-0.95f,-0.1f);
   glVertex2f(-0.9f,-0.1f);
   glVertex2f(-0.85f,-0.1f);

   glVertex2f(-0.95f,-0.16f);
   glVertex2f(-0.9f,-0.16f);
   glVertex2f(-0.85f,-0.16f);

   glVertex2f(-0.95f,-0.22f);
   glVertex2f(-0.9f,-0.22);
   glVertex2f(-0.85f,-0.22f);

    glVertex2f(-0.95f,-0.28f);
   glVertex2f(-0.9f,-0.28);
   glVertex2f(-0.85f,-0.28f);

    glVertex2f(-0.95f,-0.34f);
   glVertex2f(-0.9f,-0.34);
   glVertex2f(-0.85f,-0.34f);

    glVertex2f(-0.95f,-0.4f);
   glVertex2f(-0.9f,-0.4);
   glVertex2f(-0.85f,-0.4f);


   glEnd();

//3rd building front light ash

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-0.35f,-0.5f);
    glVertex2f(-0.35f,0.2f);
    glVertex2f(-0.55f,0.2f);
    glVertex2f(-0.55f,-0.5f);
    glEnd();


//4th building 1st black building from left side

   glTranslatef(-1.01f,-0.35f, 0.0f);
   glScalef(-0.7,0.3,0);
   glBegin(GL_QUADS);
   glColor3ub(89, 89, 89);
   glVertex2f(-0.32f,-0.5f);
   glVertex2f(-0.32f,0.1f);
   glVertex2f(-0.8f,0.1f);
   glVertex2f(-0.8f,-0.5f);
   glEnd();

   glPointSize(3);
   glBegin(GL_POINTS);
   glColor3ub(230, 230, 230);
   glVertex2f(-0.72f,-0.1f);
   glVertex2f(-0.62f,-0.1f);
   glVertex2f(-0.52f,-0.1f);
   glVertex2f(-0.42f,-0.1f);

     glVertex2f(-0.72f,-0.29f);
   glVertex2f(-0.62f,-0.29f);
   glVertex2f(-0.52f,-0.29f);
   glVertex2f(-0.42f,-0.29f);

   glEnd();

//5th building 2nd black building

   glLoadIdentity();
   glTranslatef(0.0f,0.1f, 0.0f);
   glBegin(GL_POLYGON);
   glColor3ub(89, 89, 89);
   glVertex2f(0.0f,-0.5f);
   glVertex2f(0.0f,0.2f);
   glVertex2f(-0.1f,0.2f);
   glVertex2f(-0.2f,0.2f);
   glVertex2f(-0.4f,0.1f);
   glVertex2f(-0.4f,-0.5f);

   glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex2f(0.22f,-0.5f);
    glVertex2f(0.22f,0.45f);
    glVertex2f(0.01f,0.48f);
    glVertex2f(0.0f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.03f,0.47f);
    glVertex2f(0.03f,0.54f);

    glVertex2f(0.04f,0.47f);
    glVertex2f(0.04f,0.54f);

    glVertex2f(0.05f,0.47f);
    glVertex2f(0.05f,0.54f);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
    glPointSize(3);
   glBegin(GL_POINTS);
   glColor3ub(230, 230, 230);
   glVertex2f(-0.08f,0.17f);
   glVertex2f(-0.16f,0.17f);
   glVertex2f(-0.24f,0.17f);


    glVertex2f(-0.08f,0.1f);
   glVertex2f(-0.16f,0.1f);
   glVertex2f(-0.24f,0.1f);
   glVertex2f(-0.32f,0.1f);

   glVertex2f(-0.08f,0.03f);
   glVertex2f(-0.16f,0.03f);
   glVertex2f(-0.24f,0.03f);
   glVertex2f(-0.32f,0.03f);

   glVertex2f(-0.08f,-0.05f);
   glVertex2f(-0.16f,-0.05f);
   glVertex2f(-0.24f,-0.05f);
   glVertex2f(-0.32f,-0.05f);

   glVertex2f(-0.08f,-0.12f);
   glVertex2f(-0.16f,-0.12f);
   glVertex2f(-0.24f,-0.12f);
   glVertex2f(-0.32f,-0.12f);

   glVertex2f(-0.08f,-0.19f);
   glVertex2f(-0.16f,-0.19f);
   glVertex2f(-0.24f,-0.19f);
   glVertex2f(-0.32f,-0.19f);

   glVertex2f(-0.08f,-0.26f);
   glVertex2f(-0.16f,-0.26f);
   glVertex2f(-0.24f,-0.26f);
   glVertex2f(-0.32f,-0.26f);

   glVertex2f(-0.08f,-0.33f);
   glVertex2f(-0.16f,-0.33f);
   glVertex2f(-0.24f,-0.33f);
   glVertex2f(-0.32f,-0.33f);

   glVertex2f(-0.08f,-0.4f);
   glVertex2f(-0.16f,-0.4f);
   glVertex2f(-0.24f,-0.4f);
   glVertex2f(-0.32f,-0.4f);

   glEnd();





//BLUE BUILDING

   glBegin(GL_POLYGON);
   glColor3ub(77, 255, 255);
   glVertex2f(0.45f,-0.5f);
   glVertex2f(0.45f,0.5f);
   glVertex2f(0.25f,0.5f);
   glVertex2f(0.25,-0.3f);
   glVertex2f(0.2f,-0.3f);
   glVertex2f(0.2f,-0.5f);
   glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 230, 230);
    glVertex2f(0.45f,0.5f);
    glVertex2f(0.25f,0.5f);
    glVertex2f(0.25f,0.47f);
    glVertex2f(0.45f,0.47f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f,-0.3f);
    glVertex2f(0.45f,-0.3f);

    glVertex2f(0.25f,0.45f);
    glVertex2f(0.45f,0.45f);

    glVertex2f(0.25f,0.42f);
    glVertex2f(0.45f,0.42f);

    glVertex2f(0.25f,0.39f);
    glVertex2f(0.45f,0.39f);

    glVertex2f(0.25f,0.36f);
    glVertex2f(0.45f,0.36f);

    glVertex2f(0.25f,0.33f);
    glVertex2f(0.45f,0.33f);

    glVertex2f(0.25f,0.30f);
    glVertex2f(0.45f,0.30f);

    glVertex2f(0.25f,0.27f);
    glVertex2f(0.45f,0.27f);

    glVertex2f(0.25f,0.24f);
    glVertex2f(0.45f,0.24f);

    glVertex2f(0.25f,0.21f);
    glVertex2f(0.45f,0.21f);

    glVertex2f(0.25f,0.18f);
    glVertex2f(0.45f,0.18f);

    glVertex2f(0.25f,0.15f);
    glVertex2f(0.45f,0.15f);

    glVertex2f(0.25f,0.12f);
    glVertex2f(0.45f,0.12f);

    glVertex2f(0.25f,0.09f);
    glVertex2f(0.45f,0.09f);

    glVertex2f(0.25f,0.06f);
    glVertex2f(0.45f,0.06f);

    glVertex2f(0.25f,0.03f);
    glVertex2f(0.45f,0.03f);

    glVertex2f(0.25f,0.0f);
    glVertex2f(0.45f,0.0f);

    glVertex2f(0.25f,-0.03f);
    glVertex2f(0.45f,-0.03f);

    glVertex2f(0.25f,-0.06f);
    glVertex2f(0.45f,-0.06f);

    glVertex2f(0.25f,-0.09f);
    glVertex2f(0.45f,-0.09f);

    glVertex2f(0.25f,-0.12f);
    glVertex2f(0.45f,-0.12f);


    glVertex2f(0.25f,-0.30f);
    glVertex2f(0.45f,-0.30f);

    glVertex2f(0.25f,-0.27f);
    glVertex2f(0.45f,-0.27f);

    glVertex2f(0.25f,-0.24f);
    glVertex2f(0.45f,-0.24f);

    glVertex2f(0.25f,-0.21f);
    glVertex2f(0.45f,-0.21f);

    glVertex2f(0.25f,-0.18f);
    glVertex2f(0.45f,-0.18f);

    glVertex2f(0.25f,-0.15f);
    glVertex2f(0.45f,-0.15f);

    glEnd();


     glBegin(GL_QUADS);
     glVertex2f(0.25f,-0.5f);
     glVertex2f(0.25f,-0.4f);
     glVertex2f(0.28f,-0.4f);
     glVertex2f(0.28f,-0.5f);
     glEnd();





      glLoadIdentity();
      glTranslatef(0.0f,0.1f, 0.0f);
      glTranslatef(0.1,0,0);
     glBegin(GL_QUADS);
     glVertex2f(0.25f,-0.5f);
     glVertex2f(0.25f,-0.4f);
     glVertex2f(0.28f,-0.4f);
     glVertex2f(0.28f,-0.5f);
     glEnd();


     glLoadIdentity();
     glTranslatef(0.0f,0.1f, 0.0f);
     glBegin(GL_QUADS);
     glVertex2f(0.45f,-0.3f);
     glVertex2f(0.2f,-0.3f);
     glVertex2f(0.2f,-0.37f);
     glVertex2f(0.45f,-0.37f);
     glEnd();

//blue building end



    glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(0.67f,-0.5f);
    glVertex2f(0.67f,0.5f);
    glVertex2f(0.48f,0.3f);
    glVertex2f(0.48f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.74f,-0.5f);
    glVertex2f(0.71f,0.5f);
    glVertex2f(0.67f,-0.5f);
    glEnd();


       glTranslatef(0,-0.2,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();


    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
     glTranslatef(0,-0.4,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();


     glLoadIdentity();
     glTranslatef(0.0f,0.1f, 0.0f);
     glTranslatef(0,-0.6,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();

       glLoadIdentity();
       glTranslatef(0.0f,0.1f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();





    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
    glTranslatef(0.26,0,0);
    glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(0.67f,-0.5f);
    glVertex2f(0.67f,0.3f);
    glVertex2f(0.48f,0.5f);
    glVertex2f(0.48f,-0.5f);
    glEnd();

    glLoadIdentity();


    //Building start
glTranslatef(0.8f, -0.7f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(0, 85, 255);
    glVertex2f(-.98,0.3);
    glVertex2f(-0.8,0.3);
    glVertex2f(-0.8,0.9);
    glVertex2f(-.98,0.9);
    glColor3ub(0, 230, 230);
    glVertex2f(-0.8,0.32);
    glVertex2f(-0.7,0.32);
    glVertex2f(-0.7,0.87);
    glVertex2f(-0.8,0.87);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.35);
    glVertex2f(-0.9,0.35);
    glVertex2f(-0.9,0.45);
    glVertex2f(-.96,0.45);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.35);
    glVertex2f(-0.84,0.35);
    glVertex2f(-0.84,0.45);
    glVertex2f(-.87,0.45);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.53);
    glVertex2f(-0.9,0.53);
    glVertex2f(-0.9,0.63);
    glVertex2f(-.96,0.63);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.53);
    glVertex2f(-0.84,0.53);
    glVertex2f(-0.84,0.63);
    glVertex2f(-.87,0.63);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.73);
    glVertex2f(-0.9,0.73);
    glVertex2f(-0.9,0.83);
    glVertex2f(-.96,0.83);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.73);
    glVertex2f(-0.84,0.73);
    glVertex2f(-0.84,0.83);
    glVertex2f(-.87,0.83);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.37);
    glVertex2f(-0.73,0.37);
    glVertex2f(-0.73,0.47);
    glVertex2f(-.77,0.47);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.52);
    glVertex2f(-0.73,0.52);
    glVertex2f(-0.73,0.62);
    glVertex2f(-.77,0.62);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.67);
    glVertex2f(-0.73,0.67);
    glVertex2f(-0.73,0.77);
    glVertex2f(-.77,0.77);
glEnd();
glLoadIdentity();

//building end

glTranslatef(0.0f, -0.433f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(51, 51, 51);
glVertex2f(-1.0f,0.0f);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,0.05f);
glVertex2f(-1.0f,0.05f);
glEnd();

glLoadIdentity();

glTranslatef(0.0f, 0.023f, 0.0f);

    //rail line

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-1.0f,-0.5f);
glVertex2f(1.0f,0.-0.5f);
glEnd();

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-1.0f,-0.46f);
glVertex2f(1.0f,0.-0.46f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.01f,-0.46f);
glVertex2f(-0.02f,-0.46f);
glVertex2f(-0.03f,-0.5f);
glVertex2f(-0.02f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.03f,-0.46f);
glVertex2f(-0.04f,-0.46f);
glVertex2f(-0.05f,-0.5f);
glVertex2f(-0.04f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.05f,-0.46f);
glVertex2f(-0.06f,-0.46f);
glVertex2f(-0.07f,-0.5f);
glVertex2f(-0.06f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.07f,-0.46f);
glVertex2f(-0.08f,-0.46f);
glVertex2f(-0.09f,-0.5f);
glVertex2f(-0.08f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.09f,-0.46f);
glVertex2f(-0.1f,-0.46f);
glVertex2f(-0.11f,-0.5f);
glVertex2f(-0.1f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.11f,-0.46f);
glVertex2f(-0.12f,-0.46f);
glVertex2f(-0.13f,-0.5f);
glVertex2f(-0.12f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.13f,-0.46f);
glVertex2f(-0.14f,-0.46f);
glVertex2f(-0.15f,-0.5f);
glVertex2f(-0.14f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.15f,-0.46f);
glVertex2f(-0.16f,-0.46f);
glVertex2f(-0.17f,-0.5f);
glVertex2f(-0.16f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.17f,-0.46f);
glVertex2f(-0.18f,-0.46f);
glVertex2f(-0.19f,-0.5f);
glVertex2f(-0.18f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.19f,-0.46f);
glVertex2f(-0.20f,-0.46f);
glVertex2f(-0.21f,-0.5f);
glVertex2f(-0.20f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.21f,-0.46f);
glVertex2f(-0.22f,-0.46f);
glVertex2f(-0.23f,-0.5f);
glVertex2f(-0.22f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.23f,-0.46f);
glVertex2f(-0.24f,-0.46f);
glVertex2f(-0.25f,-0.5f);
glVertex2f(-0.24f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.25f,-0.46f);
glVertex2f(-0.26f,-0.46f);
glVertex2f(-0.27f,-0.5f);
glVertex2f(-0.26f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.27f,-0.46f);
glVertex2f(-0.28f,-0.46f);
glVertex2f(-0.29f,-0.5f);
glVertex2f(-0.28f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.29f,-0.46f);
glVertex2f(-0.3f,-0.46f);
glVertex2f(-0.31f,-0.5f);
glVertex2f(-0.3f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.31f,-0.46f);
glVertex2f(-0.32f,-0.46f);
glVertex2f(-0.33f,-0.5f);
glVertex2f(-0.32f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.33f,-0.46f);
glVertex2f(-0.34f,-0.46f);
glVertex2f(-0.35f,-0.5f);
glVertex2f(-0.34f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.35f,-0.46f);
glVertex2f(-0.36f,-0.46f);
glVertex2f(-0.37f,-0.5f);
glVertex2f(-0.36f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.37f,-0.46f);
glVertex2f(-0.38f,-0.46f);
glVertex2f(-0.39f,-0.5f);
glVertex2f(-0.38f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.39f,-0.46f);
glVertex2f(-0.4f,-0.46f);
glVertex2f(-0.41f,-0.5f);
glVertex2f(-0.4f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.41f,-0.46f);
glVertex2f(-0.42f,-0.46f);
glVertex2f(-0.43f,-0.5f);
glVertex2f(-0.42f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.43f,-0.46f);
glVertex2f(-0.44f,-0.46f);
glVertex2f(-0.45f,-0.5f);
glVertex2f(-0.44f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.45f,-0.46f);
glVertex2f(-0.46f,-0.46f);
glVertex2f(-0.47f,-0.5f);
glVertex2f(-0.46f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.47f,-0.46f);
glVertex2f(-0.48f,-0.46f);
glVertex2f(-0.49f,-0.5f);
glVertex2f(-0.48f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.49f,-0.46f);
glVertex2f(-0.5f,-0.46f);
glVertex2f(-0.51f,-0.5f);
glVertex2f(-0.5f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.51f,-0.46f);
glVertex2f(-0.52f,-0.46f);
glVertex2f(-0.53f,-0.5f);
glVertex2f(-0.52f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.53f,-0.46f);
glVertex2f(-0.54f,-0.46f);
glVertex2f(-0.55f,-0.5f);
glVertex2f(-0.54f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.55f,-0.46f);
glVertex2f(-0.56f,-0.46f);
glVertex2f(-0.57f,-0.5f);
glVertex2f(-0.56f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.57f,-0.46f);
glVertex2f(-0.58f,-0.46f);
glVertex2f(-0.59f,-0.5f);
glVertex2f(-0.58f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.59f,-0.46f);
glVertex2f(-0.6f,-0.46f);
glVertex2f(-0.61f,-0.5f);
glVertex2f(-0.6f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.61f,-0.46f);
glVertex2f(-0.62f,-0.46f);
glVertex2f(-0.63f,-0.5f);
glVertex2f(-0.62f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.63f,-0.46f);
glVertex2f(-0.64f,-0.46f);
glVertex2f(-0.65f,-0.5f);
glVertex2f(-0.64f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.65f,-0.46f);
glVertex2f(-0.66f,-0.46f);
glVertex2f(-0.67f,-0.5f);
glVertex2f(-0.66f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.67f,-0.46f);
glVertex2f(-0.68f,-0.46f);
glVertex2f(-0.69f,-0.5f);
glVertex2f(-0.68f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.69f,-0.46f);
glVertex2f(-0.7f,-0.46f);
glVertex2f(-0.71f,-0.5f);
glVertex2f(-0.7f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.71f,-0.46f);
glVertex2f(-0.72f,-0.46f);
glVertex2f(-0.73f,-0.5f);
glVertex2f(-0.72f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.73f,-0.46f);
glVertex2f(-0.74f,-0.46f);
glVertex2f(-0.75f,-0.5f);
glVertex2f(-0.74f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.75f,-0.46f);
glVertex2f(-0.76f,-0.46f);
glVertex2f(-0.77f,-0.5f);
glVertex2f(-0.76f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.77f,-0.46f);
glVertex2f(-0.78f,-0.46f);
glVertex2f(-0.79f,-0.5f);
glVertex2f(-0.78f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.79f,-0.46f);
glVertex2f(-0.8f,-0.46f);
glVertex2f(-0.81f,-0.5f);
glVertex2f(-0.8f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.81f,-0.46f);
glVertex2f(-0.82f,-0.46f);
glVertex2f(-0.83f,-0.5f);
glVertex2f(-0.82f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.83f,-0.46f);
glVertex2f(-0.84f,-0.46f);
glVertex2f(-0.85f,-0.5f);
glVertex2f(-0.84f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.85f,-0.46f);
glVertex2f(-0.86f,-0.46f);
glVertex2f(-0.87f,-0.5f);
glVertex2f(-0.86f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.87f,-0.46f);
glVertex2f(-0.88f,-0.46f);
glVertex2f(-0.89f,-0.5f);
glVertex2f(-0.88f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.89f,-0.46f);
glVertex2f(-0.9f,-0.46f);
glVertex2f(-0.91f,-0.5f);
glVertex2f(-0.9f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.91f,-0.46f);
glVertex2f(-0.92f,-0.46f);
glVertex2f(-0.93f,-0.5f);
glVertex2f(-0.92f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.93f,-0.46f);
glVertex2f(-0.94f,-0.46f);
glVertex2f(-0.95f,-0.5f);
glVertex2f(-0.94f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.95f,-0.46f);
glVertex2f(-0.96f,-0.46f);
glVertex2f(-0.97f,-0.5f);
glVertex2f(-0.96f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.97f,-0.46f);
glVertex2f(-0.98f,-0.46f);
glVertex2f(-0.99f,-0.5f);
glVertex2f(-0.98f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.01f,-0.46f);
glVertex2f(0.0f,-0.46f);
glVertex2f(-0.01f,-0.5f);
glVertex2f(0.0f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.03f,-0.46f);
glVertex2f(0.02f,-0.46f);
glVertex2f(0.01f,-0.5f);
glVertex2f(0.02f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.05f,-0.46f);
glVertex2f(0.04f,-0.46f);
glVertex2f(0.03f,-0.5f);
glVertex2f(0.04f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.07f,-0.46f);
glVertex2f(0.06f,-0.46f);
glVertex2f(0.05f,-0.5f);
glVertex2f(0.06f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.09f,-0.46f);
glVertex2f(0.08f,-0.46f);
glVertex2f(0.07f,-0.5f);
glVertex2f(0.08f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.11f,-0.46f);
glVertex2f(0.1f,-0.46f);
glVertex2f(0.09f,-0.5f);
glVertex2f(0.1f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.13f,-0.46f);
glVertex2f(0.12f,-0.46f);
glVertex2f(0.11f,-0.5f);
glVertex2f(0.12f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.15f,-0.46f);
glVertex2f(0.14f,-0.46f);
glVertex2f(0.13f,-0.5f);
glVertex2f(0.14f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.17f,-0.46f);
glVertex2f(0.16f,-0.46f);
glVertex2f(0.15f,-0.5f);
glVertex2f(0.16f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.19f,-0.46f);
glVertex2f(0.18f,-0.46f);
glVertex2f(0.17f,-0.5f);
glVertex2f(0.18f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.21f,-0.46f);
glVertex2f(0.2f,-0.46f);
glVertex2f(0.19f,-0.5f);
glVertex2f(0.2f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.23f,-0.46f);
glVertex2f(0.22f,-0.46f);
glVertex2f(0.21f,-0.5f);
glVertex2f(0.22f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.25f,-0.46f);
glVertex2f(0.24f,-0.46f);
glVertex2f(0.23f,-0.5f);
glVertex2f(0.24f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.27f,-0.46f);
glVertex2f(0.26f,-0.46f);
glVertex2f(0.25f,-0.5f);
glVertex2f(0.26f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.29f,-0.46f);
glVertex2f(0.28f,-0.46f);
glVertex2f(0.27f,-0.5f);
glVertex2f(0.28f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.31f,-0.46f);
glVertex2f(0.3f,-0.46f);
glVertex2f(0.29f,-0.5f);
glVertex2f(0.3f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.33f,-0.46f);
glVertex2f(0.32f,-0.46f);
glVertex2f(0.31f,-0.5f);
glVertex2f(0.32f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.35f,-0.46f);
glVertex2f(0.34f,-0.46f);
glVertex2f(0.33f,-0.5f);
glVertex2f(0.34f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.37f,-0.46f);
glVertex2f(0.36f,-0.46f);
glVertex2f(0.35f,-0.5f);
glVertex2f(0.36f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.39f,-0.46f);
glVertex2f(0.38f,-0.46f);
glVertex2f(0.37f,-0.5f);
glVertex2f(0.38f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.41f,-0.46f);
glVertex2f(0.4f,-0.46f);
glVertex2f(0.39f,-0.5f);
glVertex2f(0.4f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.43f,-0.46f);
glVertex2f(0.42f,-0.46f);
glVertex2f(0.41f,-0.5f);
glVertex2f(0.42f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.45f,-0.46f);
glVertex2f(0.44f,-0.46f);
glVertex2f(0.43f,-0.5f);
glVertex2f(0.44f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.47f,-0.46f);
glVertex2f(0.46f,-0.46f);
glVertex2f(0.45f,-0.5f);
glVertex2f(0.46f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.49f,-0.46f);
glVertex2f(0.48f,-0.46f);
glVertex2f(0.47f,-0.5f);
glVertex2f(0.48f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.51f,-0.46f);
glVertex2f(0.5f,-0.46f);
glVertex2f(0.49f,-0.5f);
glVertex2f(0.5f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.53f,-0.46f);
glVertex2f(0.52f,-0.46f);
glVertex2f(0.51f,-0.5f);
glVertex2f(0.52f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.55f,-0.46f);
glVertex2f(0.54f,-0.46f);
glVertex2f(0.53f,-0.5f);
glVertex2f(0.54f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.57f,-0.46f);
glVertex2f(0.56f,-0.46f);
glVertex2f(0.55f,-0.5f);
glVertex2f(0.56f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.59f,-0.46f);
glVertex2f(0.58f,-0.46f);
glVertex2f(0.57f,-0.5f);
glVertex2f(0.58f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.61f,-0.46f);
glVertex2f(0.6f,-0.46f);
glVertex2f(0.59f,-0.5f);
glVertex2f(0.6f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.63f,-0.46f);
glVertex2f(0.62f,-0.46f);
glVertex2f(0.61f,-0.5f);
glVertex2f(0.62f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.65f,-0.46f);
glVertex2f(0.64f,-0.46f);
glVertex2f(0.63f,-0.5f);
glVertex2f(0.64f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.67f,-0.46f);
glVertex2f(0.66f,-0.46f);
glVertex2f(0.65f,-0.5f);
glVertex2f(0.66f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.69f,-0.46f);
glVertex2f(0.68f,-0.46f);
glVertex2f(0.67f,-0.5f);
glVertex2f(0.68f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.71f,-0.46f);
glVertex2f(0.7f,-0.46f);
glVertex2f(0.69f,-0.5f);
glVertex2f(0.7f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.73f,-0.46f);
glVertex2f(0.72f,-0.46f);
glVertex2f(0.71f,-0.5f);
glVertex2f(0.72f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.75f,-0.46f);
glVertex2f(0.74f,-0.46f);
glVertex2f(0.73f,-0.5f);
glVertex2f(0.74f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.77f,-0.46f);
glVertex2f(0.76f,-0.46f);
glVertex2f(0.75f,-0.5f);
glVertex2f(0.76f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.79f,-0.46f);
glVertex2f(0.78f,-0.46f);
glVertex2f(0.77f,-0.5f);
glVertex2f(0.78f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.81f,-0.46f);
glVertex2f(0.8f,-0.46f);
glVertex2f(0.79f,-0.5f);
glVertex2f(0.8f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.83f,-0.46f);
glVertex2f(0.82f,-0.46f);
glVertex2f(0.81f,-0.5f);
glVertex2f(0.82f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.85f,-0.46f);
glVertex2f(0.84f,-0.46f);
glVertex2f(0.83f,-0.5f);
glVertex2f(0.84f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.87f,-0.46f);
glVertex2f(0.86f,-0.46f);
glVertex2f(0.85f,-0.5f);
glVertex2f(0.86f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.89f,-0.46f);
glVertex2f(0.88f,-0.46f);
glVertex2f(0.87f,-0.5f);
glVertex2f(0.88f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.91f,-0.46f);
glVertex2f(0.9f,-0.46f);
glVertex2f(0.89f,-0.5f);
glVertex2f(0.9f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.93f,-0.46f);
glVertex2f(0.92f,-0.46f);
glVertex2f(0.91f,-0.5f);
glVertex2f(0.92f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.95f,-0.46f);
glVertex2f(0.94f,-0.46f);
glVertex2f(0.93f,-0.5f);
glVertex2f(0.94f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.97f,-0.46f);
glVertex2f(0.96f,-0.46f);
glVertex2f(0.95f,-0.5f);
glVertex2f(0.96f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.99f,-0.46f);
glVertex2f(0.98f,-0.46f);
glVertex2f(0.97f,-0.5f);
glVertex2f(0.98f,-0.5f);
glEnd();

glLoadIdentity();

//train

glPushMatrix();
glTranslatef(position_train,0.0f, 0.0f);


glTranslatef(0.0f, 0.023f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.5f,-0.48f);
glVertex2f(-0.5f,-0.3f);
glVertex2f(-0.55f,-0.3f);
glVertex2f(-0.6f,-0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.11f,-0.48f);
glVertex2f(-0.11f,-0.2f);
glVertex2f(-0.5f,-0.2f);
glVertex2f(-0.5f,-0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glTranslatef(0.08f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.16f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.24f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.32f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int i;
x=-.42f; y=-.45f; radius =.05f;
triangleAmount = 200;
twicePi = 2.0f * PI;
glVertex2f(x, y);
for(i = 0; i <= triangleAmount;i++)
{
    glVertex2f
    (
        x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i7;
x7=-.42f; y7=-.45f; radius7 =.04f;
triangleAmount7 = 200;
twicePi7 = 2.0f * PI;
glVertex2f(x7, y7);
for(i7 = 0; i7 <= triangleAmount7;i7++)
{
    glVertex2f
    (
        x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)), y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
i;
x=-.2f; y=-.45f; radius =.05f;
triangleAmount = 200;
twicePi = 2.0f * PI;
glVertex2f(x, y);
for(i = 0; i <= triangleAmount;i++)
{
    glVertex2f
    (
        x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i8;
x8=-.2f; y8=-.45f; radius8 =.04f;
triangleAmount8 = 200;
twicePi8 = 2.0f * PI;
glVertex2f(x8, y8);
for(i8 = 0; i8 <= triangleAmount8;i8++)
{
    glVertex2f
    (
        x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)), y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
    );
}
glEnd();



glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.1f,-0.48f);
glVertex2f(0.28f,-0.48f);
glVertex2f(0.28f,-0.2f);
glVertex2f(-0.1f,-0.2f);
glEnd();

glTranslatef(0.41f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.49f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.57f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.65f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.725f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int i1;
GLfloat x1=-.02f; GLfloat y1=-.45f; GLfloat radius1 =.05f;
int triangleAmount1 = 200;
GLfloat twicePi1 = 2.0f * PI;
glVertex2f(x1, y1);
for(i1 = 0; i1 <= triangleAmount1;i1++)
{
    glVertex2f
    (
        x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)), y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i9;
x9=-.02f;  y9=-.45f;  radius9 =.04f;
 triangleAmount9 = 200;
 twicePi9 = 2.0f * PI;
glVertex2f(x9, y9);
for(i9 = 0; i9 <= triangleAmount9;i9++)
{
    glVertex2f
    (
        x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)), y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int k;
GLfloat u=.2f; GLfloat v=-.45f; GLfloat radius6 =.05f;
int triangleAmount6 = 200;
GLfloat twicePi6 = 2.0f * PI;
glVertex2f(u, v);
for(k = 0; k <= triangleAmount6;k++)
{
    glVertex2f
    (
        u + (radius6 * cos(k *  twicePi6 / triangleAmount6)), v + (radius6 * sin(k * twicePi6 / triangleAmount6))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i11;
GLfloat x11=.2f; GLfloat y11=-.45f; GLfloat radius11 =.04f;
int triangleAmount11 = 200;
GLfloat twicePi11 = 2.0f * PI;
glVertex2f(x11, y11);
for(i11 = 0; i11 <= triangleAmount11;i11++)
{
    glVertex2f
    (
        x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)), y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
    );
}
glEnd();

glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(0.29f,-0.48f);
glVertex2f(0.68f,-0.48f);
glVertex2f(0.68f,-0.2f);
glVertex2f(0.29f,-0.2f);
glEnd();

glTranslatef(0.80f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(0.88f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.96f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(1.04f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(1.12f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int r;
GLfloat s=.38f; GLfloat t=-.45f; GLfloat radius3 =.05f;
int triangleAmount3 = 200;
GLfloat twicePi3 = 2.0f * PI;
glVertex2f(s, t);
for(r = 0; r <= triangleAmount3;r++)
{
    glVertex2f
    (
        s + (radius3 * cos(r *  twicePi3 / triangleAmount3)), t + (radius3 * sin(r * twicePi3 / triangleAmount3))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i22;
GLfloat x22=.38f; GLfloat y22=-.45f; GLfloat radius22 =.04f;
int triangleAmount22 = 200;
GLfloat twicePi22 = 2.0f * PI;
glVertex2f(x22, y22);
for(i22 = 0; i22 <= triangleAmount;i22++)
{
    glVertex2f
    (
        x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)), y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int r1;
GLfloat s1=.6f; GLfloat t1=-.45f; GLfloat radius4 =.05f;
int triangleAmount4 = 200;
GLfloat twicePi4 = 2.0f * PI;
glVertex2f(s1, t1);
for(r1 = 0; r1 <= triangleAmount4;r1++)
{
    glVertex2f
    (
        s1 + (radius4 * cos(r1 *  twicePi4 / triangleAmount4)), t1 + (radius4 * sin(r1 * twicePi4 / triangleAmount4))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i33;
GLfloat x33=.6f; GLfloat y33=-.45f; GLfloat radius33 =.04f;
int triangleAmount33 = 200;
GLfloat twicePi33 = 2.0f * PI;
glVertex2f(x33, y33);
for(i33 = 0; i33 <= triangleAmount33;i33++)
{
    glVertex2f
    (
        x33 + (radius33 * cos(i33 *  twicePi33 / triangleAmount33)), y33 + (radius33* sin(i33 * twicePi33 / triangleAmount33))
    );
}
glEnd();


glPopMatrix();



    glLoadIdentity();





    //road
    glBegin(GL_QUADS);
    glColor3ub(51, 51, 51);

    glVertex2f(-1,-.5);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.5);

    glEnd();
//road's middle lines
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();

    //copying road's middle line
    //1
    glTranslatef(.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //2
    glTranslatef(.4,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //3
    glTranslatef(.6,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //4
    glTranslatef(.8,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //5
    glTranslatef(1,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //left side
    //6
    glTranslatef(-.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //7
    glTranslatef(-.4,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //8
    glTranslatef(-.6,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //9
    glTranslatef(-.8,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //10
    glTranslatef(-1,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //road upper side border
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(-1,-.48);
    glVertex2f(-1,-.5);
    glVertex2f(1,-.5);
    glVertex2f(1,-.48);
    glEnd();

    //Starting drawing light

    //road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light

//copy light 2
    glTranslatef(.45,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

    //copy light 3
     glTranslatef(.9,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

    //copy light 4
     glTranslatef(-.45,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

    //copy road light 5
     glTranslatef(-.9,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

//new car
glPushMatrix();
glTranslatef(position_car2,0.0f, 0.0f);

glTranslatef(0.9f, 0.05f, 0.0f);
glScalef(2.0,1.8,0);

 glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.8f,-0.33f);
    glVertex2f(-0.8f,-0.30f);
    glVertex2f(-0.9f,-0.30f);
    glVertex2f(-0.9f,-0.33f);
    glEnd();

   glColor3ub(13, 13, 13);
    glBegin(GL_QUADS);
    glVertex2f(-0.82f,-0.30f);
    glVertex2f(-0.83f,-0.28f);
    glVertex2f(-0.87f,-0.28f);
    glVertex2f(-0.88f,-0.30f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.824f,-0.298f);
    glVertex2f(-0.832f,-0.282f);
    glVertex2f(-0.848f,-0.282f);
    glVertex2f(-0.848f,-0.298f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.851f,-0.298f);
    glVertex2f(-0.851f,-0.282f);
    glVertex2f(-0.868f,-0.282f);
    glVertex2f(-0.876f,-0.298f);
    glEnd();

     i;
    j;
    x = -0.82f; y = -0.33f; radius = 0.01f; GLfloat a = -0.88f; GLfloat b = -0.33f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

    glColor3ub(13, 13, 13);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)),y + (radius * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    glColor3ub(13, 13, 13);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a, b);
    for(j = 0; j <= triangleAmount;j++)
        {
            glVertex2f(a + (radius * cos(j *  twicePi / triangleAmount)),b + (radius * sin(j * twicePi / triangleAmount)));
        }
    glEnd();

glPopMatrix();

glLoadIdentity();

//end new car
//blue car
glPushMatrix();
glTranslatef(position_jip2,0.0f, 0.0f);

glScalef(-.4,.4,0);
glTranslatef(-0.4f, -1.4f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(26, 83, 255);
glVertex2f(-.23,.3);
glVertex2f(-.38,.06);
glVertex2f(.12,.06);
glVertex2f(.12,.3);

glColor3ub(26, 83, 255);
glVertex2f(-.38,.06);
glVertex2f(-.38,-.06);
glVertex2f(.12,-.06);
glVertex2f(.12,.06);

glColor3ub(26, 83, 255);
glVertex2f(.12,-.06);
glVertex2f(.2,-.06);
glVertex2f(.19,.06);
glVertex2f(.12,.06);

glColor3ub(26, 83, 255);
glVertex2f(.12,.3);
glVertex2f(.12,.06);
glVertex2f(.19,.06);
glVertex2f(.16,.2);

glColor3ub(13, 13, 13);
glVertex2f(-.2,.28);
glVertex2f(-.32,.11);
glVertex2f(.15,.11);
glVertex2f(.1,.28);

glEnd();
 i;
	 x=.1f;  y=-.05f;  radius =.06f;
	 triangleAmount = 20;
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
glEnd();
 j;
	 x1=-.23f;  y1=-.05f;  radius1 =.06f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f(
		            x1 + (radius1 * cos(j*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(j* twicePi1 / triangleAmount1))
			);
		}
glEnd();
 k;
	 x=.1f;  y=-.05f;  radius =.03f;
	 triangleAmount2 = 20;
	 twicePi2 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(k = 0; k <= triangleAmount2;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi2 / triangleAmount2)),
			    y + (radius * sin(k * twicePi2 / triangleAmount2))
			);
		}
glEnd();
int l;
	 x=-.23f;  y=-.05f;  radius =.03f;
	 triangleAmount3 = 20;
	 twicePi3 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(l = 0; l <= triangleAmount3;l++) {
			glVertex2f(
		            x + (radius3 * cos(l*  twicePi3 / triangleAmount3)),
			    y + (radius3 * sin(l* twicePi3 / triangleAmount3))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();

//end blue car

//red car
glPushMatrix();
glTranslatef(position_car3,0.0f, 0.0f);

    glScalef(-.5,.4,0);
glTranslatef(-1.7f, -1.5f, 0.0f);

    glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,0);
glVertex2f(.3,0.0);
glVertex2f(.3,.1);
glVertex2f(-.2,.1);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 26, 51);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glVertex2f(-.05,.29);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.04,.25);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(-.05,.29);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(.3,.16);
glVertex2f(.2,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 40, 77);
glVertex2f(.15,.25);
glVertex2f(.2,.16);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glEnd();

glColor3ub(0, 0, 0);
 i;
	 x8=-.06f;  y8=0.0f;  radius8 =.06f;
	 triangleAmount8 = 20;
	 twicePi8 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(i = 0; i <= triangleAmount8;i++) {
			glVertex2f(
		            x8 + (radius8 * cos(i *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i * twicePi8 / triangleAmount8))
			);
		}
glEnd();
 i;
	 x=.18f;  y=0.0f;  radius =.06f;
	 triangleAmount = 20;
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi / triangleAmount)),
			    y + (radius * sin(i* twicePi / triangleAmount))
			);
		}
glEnd();
 r;
	 x11=-.06f;  y11=0.0f;  radius11 =.03f;
	 triangleAmount11 = 20;
	 twicePi11 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11);
		glColor3ub(255, 255,255);
		for(r = 0; r <= triangleAmount11;r++) {
			glVertex2f(
		            x11 + (radius11 * cos(r *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(r * twicePi11 / triangleAmount11))
			);
		}
glEnd();
 s;
	 x1=.18f;  y1=0.0f;  radius1 =0.03f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		glColor3ub(255, 255,255);
		for(s = 0; s <= triangleAmount1;s++) {
			glVertex2f(
		            x1 + (radius1 * cos(s*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(s* twicePi1 / triangleAmount1))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();
//end red car

//bus
glPushMatrix();
glTranslatef(position_bus2,0.0f, 0.0f);

glScalef(-.2,.3,0);
glTranslatef(.7f, -2.5f, 0.0f);

glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-.6,0.25);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.4);
    glVertex2f(-0.6,0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
    glVertex2f(-.6,0.4);
    glVertex2f(0.6,0.4);
    glVertex2f(0.6,0.7);
    glVertex2f(-.6,0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51, 153);
    glVertex2f(-.6,0.4);
    glVertex2f(-.5,0.4);
    glVertex2f(-.5,0.7);
    glVertex2f(-.6,0.7);


    glVertex2f(-.4,0.5);
    glVertex2f(-.3,0.5);
    glVertex2f(-.3,0.6);
    glVertex2f(-.4,0.6);

    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glVertex2f(-.2,0.5);
    glVertex2f(-.1,0.5);
    glVertex2f(-.1,0.6);
    glVertex2f(-.2,0.6);
    glEnd();

    glTranslatef(-.25,0,0);
    glBegin(GL_QUADS);
    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glEnd();
     glLoadIdentity();
     glTranslatef(position_bus2,0.0f, 0.0f);

     glScalef(-.2,.3,0);
glTranslatef(.7f, -2.5f, 0.0f);

	x=.3f; y=.25f; radius =.11f;
	glColor3f(0,0,0);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3f(0,0,0);
    j;

    x=-.3f;  y1=.25f;  radius =.11f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
			    x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius* sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

     x=.3f;  y=.25f;  radius =.06f;
	glColor3f(1,1,1);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius3 * cos(i *  twicePi3 / triangleAmount)),
			    y + (radius3* sin(i * twicePi3 / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1,1,1);
    i;

     x=-.3f;  y=.25f;  radius =.06f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius4 = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

	glLoadIdentity();

//traffic light
glTranslatef(0.0f, -0.38f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.91f,-0.4f);
glVertex2f(-0.9f,-0.4f);
glVertex2f(-0.9f,0.01f);
glVertex2f(-0.91f,0.01f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 102, 102);
glVertex2f(-0.93f,0.01f);
glVertex2f(-0.88f,0.01f);
glVertex2f(-0.88f,-0.15f);
glVertex2f(-0.93f,-0.15f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(-0.91f,0.001f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f(-0.91f,-0.12f);
glEnd();

glLoadIdentity();
glTranslatef(0.0f, -0.38f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.91f,-0.4f);
glVertex2f(0.9f,-0.4f);
glVertex2f(0.9f,0.01f);
glVertex2f(0.91f,0.01f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 102, 102);
glVertex2f(0.93f,0.01f);
glVertex2f(0.88f,0.01f);
glVertex2f(0.88f,-0.15f);
glVertex2f(0.93f,-0.15f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(0.9f,0.001f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f(0.9f,-0.12f);
glEnd();

glLoadIdentity();
//end traffic light

//bus
glPushMatrix();
glTranslatef(position_bus1,0.0f, 0.0f);

glScalef(.2,.3,0);
glTranslatef(1.0f, -3.0f, 0.0f);

glBegin(GL_QUADS);
    glColor3ub(0, 48, 48);
    glVertex2f(-.6,0.25);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.4);
    glVertex2f(-0.6,0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
    glVertex2f(-.6,0.4);
    glVertex2f(0.6,0.4);
    glVertex2f(0.6,0.7);
    glVertex2f(-.6,0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 48, 48);
    glVertex2f(-.6,0.4);
    glVertex2f(-.5,0.4);
    glVertex2f(-.5,0.7);
    glVertex2f(-.6,0.7);


    glVertex2f(-.4,0.5);
    glVertex2f(-.3,0.5);
    glVertex2f(-.3,0.6);
    glVertex2f(-.4,0.6);

    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glVertex2f(-.2,0.5);
    glVertex2f(-.1,0.5);
    glVertex2f(-.1,0.6);
    glVertex2f(-.2,0.6);
    glEnd();

    glTranslatef(-.25,0,0);
    glBegin(GL_QUADS);
    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glEnd();
     glLoadIdentity();
     glTranslatef(position_bus1,0.0f, 0.0f);

     glScalef(.2,.3,0);
glTranslatef(1.0f, -3.0f, 0.0f);

	x=.3f; y=.25f; radius =.11f;
	glColor3f(0,0,0);
	i;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3f(0,0,0);
    i;

    x=-.3f;  y1=.25f;  radius =.11f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     x=.3f;  y=.25f;  radius =.06f;
	glColor3f(1,1,1);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi3 / triangleAmount)),
			    y + (radius* sin(i * twicePi3 / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1,1,1);
    i;

     x=-.3f;  y=.25f;  radius =.06f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius4 = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();
	glLoadIdentity();

	//end bus

glPushMatrix();
glTranslatef(position_jip1,0.0f, 0.0f);

glScalef(.4,.4,0);
glTranslatef(-2.0f, -2.2f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(117, 102, 2);
glVertex2f(-.23,.3);
glVertex2f(-.38,.06);
glVertex2f(.12,.06);
glVertex2f(.12,.3);

glColor3ub(117, 102, 2);
glVertex2f(-.38,.06);
glVertex2f(-.38,-.06);
glVertex2f(.12,-.06);
glVertex2f(.12,.06);

glColor3ub(117, 102, 2);
glVertex2f(.12,-.06);
glVertex2f(.2,-.06);
glVertex2f(.19,.06);
glVertex2f(.12,.06);

glColor3ub(117, 102, 2);
glVertex2f(.12,.3);
glVertex2f(.12,.06);
glVertex2f(.19,.06);
glVertex2f(.16,.2);

glColor3ub(13, 13, 13);
glVertex2f(-.2,.28);
glVertex2f(-.32,.11);
glVertex2f(.15,.11);
glVertex2f(.1,.28);

glEnd();
    i;
	 x=.1f;  y=-.05f; radius =.06f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
glEnd();
    i;
	x=-.23f; y=-.05f; radius =.06f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi / triangleAmount)),
			    y + (radius * sin(i* twicePi / triangleAmount))
			);
		}
glEnd();
    k;
	x=.1f; y=-.05f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount))
			);
		}
glEnd();
    i;
	x=-.23f; y=-.05f; radius =.03f;
	triangleAmount3 = 20;
	twicePi3 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(i = 0; i <= triangleAmount3;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi3 / triangleAmount3)),
			    y + (radius * sin(i* twicePi3 / triangleAmount3))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();

    //red car
glPushMatrix();
glTranslatef(position_car1,0.0f, 0.0f);

    glScalef(.5,.4,0);
glTranslatef(-0.3f, -2.4f, 0.0f);

    glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,0);
glVertex2f(.3,0.0);
glVertex2f(.3,.1);
glVertex2f(-.2,.1);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 26, 51);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glVertex2f(-.05,.29);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.04,.25);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(-.05,.29);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(.3,.16);
glVertex2f(.2,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 40, 77);
glVertex2f(.15,.25);
glVertex2f(.2,.16);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glEnd();

glColor3ub(0, 0, 0);
int p;
	 x8=-.06f;  y8=0.0f;  radius8 =.06f;
	 triangleAmount8 = 20;
	 twicePi8 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(p = 0; p <= triangleAmount8;p++) {
			glVertex2f(
		            x8 + (radius8 * cos(p *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(p * twicePi8 / triangleAmount8))
			);
		}
glEnd();
int q;
	 x9=.18f;  y9=0.0f;  radius9 =.06f;
	 triangleAmount9 = 20;
	 twicePi9 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9);
		for(q = 0; q <= triangleAmount9;q++) {
			glVertex2f(
		            x9 + (radius9 * cos(q*  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(q* twicePi9 / triangleAmount9))
			);
		}
glEnd();
 r;
	 x11=-.06f;  y11=0.0f;  radius11 =.03f;
	 triangleAmount11 = 20;
	 twicePi11 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11);
		glColor3ub(255, 255,255);
		for(r = 0; r <= triangleAmount11;r++) {
			glVertex2f(
		            x11 + (radius11 * cos(r *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(r * twicePi11 / triangleAmount11))
			);
		}
glEnd();
 s;
	 x1=.18f;  y1=0.0f;  radius1 =0.03f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		glColor3ub(255, 255,255);
		for(s = 0; s <= triangleAmount1;s++) {
			glVertex2f(
		            x1 + (radius1 * cos(s*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(s* twicePi1 / triangleAmount1))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();
//end red car

glTranslatef(rainX, rainY, 0);
	for (double i = -1.0f; i < 1.0f; i += 0.15f) {
      for (double j = -1.0f; j < 1.0f; j += 0.15f) {
        drawLine(i, j, i - 0.1f, j - 0.1f, 1, 1, 1, 1);
      }
	}
	glLoadIdentity();
	i += 0.1f;

glFlush();

glutTimerFunc(1500,demo_back,0);
glFlush();
}



void demo_rain(int val) {

 glutDisplayFunc(rain);

}

void night() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Background Color
    //sky
    glBegin(GL_QUADS);
    glColor3ub(77, 110, 115);

    glVertex2f(-1,1);
    glVertex2f(-1,-.5);
    glVertex2f(1,-.5);
    glVertex2f(1,1);

    glEnd();

//moon
    glBegin(GL_TRIANGLE_FAN);
glColor3ub(255, 255, 128);
int j;
GLfloat x=.8f; GLfloat y=.8f; GLfloat radius =.1f;
int triangleAmount = 200;
GLfloat twicePi = 2.0f * PI;
glVertex2f(x, y);
for(j = 0; j <= triangleAmount;j++)
{
    glVertex2f
    (
        x + (radius * cos(j *  twicePi / triangleAmount)), y + (radius * sin(j * twicePi / triangleAmount))
    );
}
glEnd();

//moon end

//cloud
//1st ring
glLoadIdentity();
      glTranslatef(-0.7,0.1,0);

	int j7;

	GLfloat x7=.3f; GLfloat y7= .8f; GLfloat radius7 =.050f;
	int triangleAmount7 = 20; //# of triangles used to draw circle
	glColor3ub(149, 152, 156);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(j7 = 0; j7 <= triangleAmount7;j7++) {
			glVertex2f(
		            x7 + (radius7 * cos(j7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(j7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();
//2nd ring
	int j8;

	GLfloat x8=.35f; GLfloat y8= .85f; GLfloat radius8 =.050f;
	int triangleAmount8 = 20; //# of triangles used to draw circle
	glColor3ub(149, 152, 156);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(j8 = 0; j8 <= triangleAmount8;j8++) {
			glVertex2f(
		            x8 + (radius8 * cos(j8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(j8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();
//3rd ring
	int j9;

	GLfloat x9=.40f; GLfloat y9= .8f; GLfloat radius9 =.050f;
	int triangleAmount9 = 20; //# of triangles used to draw circle
	glColor3ub(149, 152, 156);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(j9 = 0; j9 <= triangleAmount9;j9++) {
			glVertex2f(
		            x9 + (radius8 * cos(j9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(j9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();
//4th ring
	int j10;

	GLfloat x10=.35f; GLfloat y10= .80f; GLfloat radius10 =.050f;
	int triangleAmount10 = 20; //# of triangles used to draw circle
	glColor3ub(149, 152, 156);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(j10 = 0; j10 <= triangleAmount10;j10++) {
			glVertex2f(
		            x10 + (radius10 * cos(j10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(j10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();

glLoadIdentity();

glTranslatef(0.0f, .05f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
int i2;
GLfloat x2=-.8f; GLfloat y2=.8f; GLfloat radius2 =.05f;
int triangleAmount2 = 30;

GLfloat twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.85f; y2=.85f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.87f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.77f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.75f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.75f; y2=.88f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glLoadIdentity();

glTranslatef(1.f, .05f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.8f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.85f; y2=.85f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.87f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.77f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.75f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(149, 152, 156);
i2;
x2=-.75f; y2=.88f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glLoadIdentity();
//end cloud
//stars
glPointSize(2.5);
glBegin(GL_POINTS);
glColor3f(255, 255, 255);
glVertex2f(0.0f,0.8f);
glColor3f(255, 255, 255);
glVertex2f(-0.1f,0.77f);
glColor3f(255, 255, 255);
glVertex2f(-0.2f,0.77f);
glColor3f(255, 255, 255);
glVertex2f(-0.2f,0.9f);
glColor3f(255, 255, 255);
glVertex2f(-0.3f,0.9f);
glColor3f(255, 255, 255);
glVertex2f(-0.4f,0.8f);
glColor3f(255, 255, 255);
glVertex2f(-0.5f,0.77f);
glColor3f(255, 255, 255);
glVertex2f(-0.55f,0.77f);
glVertex2f(-0.55f,0.8f);
glVertex2f(-0.6f,0.77f);
glVertex2f(-0.6f,0.8f);
glColor3f(255, 255, 255);
glVertex2f(0.3f,0.9f);
glColor3f(255, 255, 255);
glVertex2f(0.4f,0.8f);
glColor3f(255, 255, 255);
glVertex2f(0.5f,0.77f);
glColor3f(255, 255, 255);
glVertex2f(0.55f,0.77f);
glVertex2f(0.55f,0.8f);
glVertex2f(0.6f,0.77f);
glVertex2f(0.6f,0.8f);
glEnd();

//stars end
//starting buildings structure

glTranslatef(0.0f,0.1f, 0.0f);
//2nd left side building
    glBegin(GL_QUADS);
    glColor3ub(0, 60, 80);
    glVertex2f(-0.92f,0.3f);
    glVertex2f(-0.92f,0.5f);
    glVertex2f(-0.95f,0.5f);
    glVertex2f(-0.95f,0.3f);
    glEnd();




    glBegin(GL_POLYGON);
    glColor3ub(0, 153, 204);
    glVertex2f(-0.55f,-0.5f);
    glVertex2f(-0.55f,0.5f);
    glVertex2f(-0.92f,0.5f);
    glVertex2f(-0.92f,0.3f);
    glVertex2f(-0.8f,0.3f);
    glVertex2f(-0.8f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(242, 242, 242);

    glVertex2f(-0.6f,0.5f);
    glVertex2f(-0.6f,-0.35f);

    glVertex2f(-0.65f,0.5f);
    glVertex2f(-0.65f,-0.35f);

    glVertex2f(-0.7f,0.5f);
    glVertex2f(-0.7f,-0.35f);

    glVertex2f(-0.75f,0.5f);
    glVertex2f(-0.75f,-0.35f);

    glVertex2f(-0.8f,0.5f);
    glVertex2f(-0.8f,0.3f);

        glVertex2f(-0.85f,0.5f);
    glVertex2f(-0.85f,0.3f);

    glEnd();


    //1st left side building

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(-0.8f,-0.5f);
    glVertex2f(-0.8f,0.3f);
    glVertex2f(-1.0f,0.3f);
    glVertex2f(-1.0f,-0.5f);
    glEnd();

   glPointSize(2);
   glBegin(GL_POINTS);
   glColor3ub(0,0,0);
   glVertex2f(-0.95f,0.26f);
   glVertex2f(-0.9f,0.26f);
   glVertex2f(-0.85f,0.26f);

   glVertex2f(-0.95f,0.2f);
   glVertex2f(-0.9f,0.2f);
   glVertex2f(-0.85f,0.2f);

   glVertex2f(-0.95f,0.14f);
   glVertex2f(-0.9f,0.14f);
   glVertex2f(-0.85f,0.14f);

   glVertex2f(-0.95f,0.08f);
   glVertex2f(-0.9f,0.08f);
   glVertex2f(-0.85f,0.08f);

   glVertex2f(-0.95f,0.02f);
   glVertex2f(-0.9f,0.02f);
   glVertex2f(-0.85f,0.02f);

   glVertex2f(-0.95f,-0.04f);
   glVertex2f(-0.9f,-0.04f);
   glVertex2f(-0.85f,-0.04f);

   glVertex2f(-0.95f,-0.1f);
   glVertex2f(-0.9f,-0.1f);
   glVertex2f(-0.85f,-0.1f);

   glVertex2f(-0.95f,-0.16f);
   glVertex2f(-0.9f,-0.16f);
   glVertex2f(-0.85f,-0.16f);

   glVertex2f(-0.95f,-0.22f);
   glVertex2f(-0.9f,-0.22);
   glVertex2f(-0.85f,-0.22f);

    glVertex2f(-0.95f,-0.28f);
   glVertex2f(-0.9f,-0.28);
   glVertex2f(-0.85f,-0.28f);

    glVertex2f(-0.95f,-0.34f);
   glVertex2f(-0.9f,-0.34);
   glVertex2f(-0.85f,-0.34f);

    glVertex2f(-0.95f,-0.4f);
   glVertex2f(-0.9f,-0.4);
   glVertex2f(-0.85f,-0.4f);


   glEnd();

//3rd building front light ash

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-0.35f,-0.5f);
    glVertex2f(-0.35f,0.2f);
    glVertex2f(-0.55f,0.2f);
    glVertex2f(-0.55f,-0.5f);
    glEnd();


//4th building 1st black building from left side

   glTranslatef(-1.01f,-0.35f, 0.0f);
   glScalef(-0.7,0.3,0);
   glBegin(GL_QUADS);
   glColor3ub(89, 89, 89);
   glVertex2f(-0.32f,-0.5f);
   glVertex2f(-0.32f,0.1f);
   glVertex2f(-0.8f,0.1f);
   glVertex2f(-0.8f,-0.5f);
   glEnd();

   glPointSize(3);
   glBegin(GL_POINTS);
   glColor3ub(230, 230, 230);
   glVertex2f(-0.72f,-0.1f);
   glVertex2f(-0.62f,-0.1f);
   glVertex2f(-0.52f,-0.1f);
   glVertex2f(-0.42f,-0.1f);

     glVertex2f(-0.72f,-0.29f);
   glVertex2f(-0.62f,-0.29f);
   glVertex2f(-0.52f,-0.29f);
   glVertex2f(-0.42f,-0.29f);

   glEnd();

//5th building 2nd black building

   glLoadIdentity();
   glTranslatef(0.0f,0.1f, 0.0f);
   glBegin(GL_POLYGON);
   glColor3ub(89, 89, 89);
   glVertex2f(0.0f,-0.5f);
   glVertex2f(0.0f,0.2f);
   glVertex2f(-0.1f,0.2f);
   glVertex2f(-0.2f,0.2f);
   glVertex2f(-0.4f,0.1f);
   glVertex2f(-0.4f,-0.5f);

   glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex2f(0.22f,-0.5f);
    glVertex2f(0.22f,0.45f);
    glVertex2f(0.01f,0.48f);
    glVertex2f(0.0f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.03f,0.47f);
    glVertex2f(0.03f,0.54f);

    glVertex2f(0.04f,0.47f);
    glVertex2f(0.04f,0.54f);

    glVertex2f(0.05f,0.47f);
    glVertex2f(0.05f,0.54f);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
    glPointSize(3);
   glBegin(GL_POINTS);
   glColor3ub(230, 230, 230);
   glVertex2f(-0.08f,0.17f);
   glVertex2f(-0.16f,0.17f);
   glVertex2f(-0.24f,0.17f);


    glVertex2f(-0.08f,0.1f);
   glVertex2f(-0.16f,0.1f);
   glVertex2f(-0.24f,0.1f);
   glVertex2f(-0.32f,0.1f);

   glVertex2f(-0.08f,0.03f);
   glVertex2f(-0.16f,0.03f);
   glVertex2f(-0.24f,0.03f);
   glVertex2f(-0.32f,0.03f);

   glVertex2f(-0.08f,-0.05f);
   glVertex2f(-0.16f,-0.05f);
   glVertex2f(-0.24f,-0.05f);
   glVertex2f(-0.32f,-0.05f);

   glVertex2f(-0.08f,-0.12f);
   glVertex2f(-0.16f,-0.12f);
   glVertex2f(-0.24f,-0.12f);
   glVertex2f(-0.32f,-0.12f);

   glVertex2f(-0.08f,-0.19f);
   glVertex2f(-0.16f,-0.19f);
   glVertex2f(-0.24f,-0.19f);
   glVertex2f(-0.32f,-0.19f);

   glVertex2f(-0.08f,-0.26f);
   glVertex2f(-0.16f,-0.26f);
   glVertex2f(-0.24f,-0.26f);
   glVertex2f(-0.32f,-0.26f);

   glVertex2f(-0.08f,-0.33f);
   glVertex2f(-0.16f,-0.33f);
   glVertex2f(-0.24f,-0.33f);
   glVertex2f(-0.32f,-0.33f);

   glVertex2f(-0.08f,-0.4f);
   glVertex2f(-0.16f,-0.4f);
   glVertex2f(-0.24f,-0.4f);
   glVertex2f(-0.32f,-0.4f);

   glEnd();





//BLUE BUILDING

   glBegin(GL_POLYGON);
   glColor3ub(60, 155, 155);
   glVertex2f(0.45f,-0.5f);
   glVertex2f(0.45f,0.5f);
   glVertex2f(0.25f,0.5f);
   glVertex2f(0.25,-0.3f);
   glVertex2f(0.2f,-0.3f);
   glVertex2f(0.2f,-0.5f);
   glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 230, 230);
    glVertex2f(0.45f,0.5f);
    glVertex2f(0.25f,0.5f);
    glVertex2f(0.25f,0.47f);
    glVertex2f(0.45f,0.47f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f,-0.3f);
    glVertex2f(0.45f,-0.3f);

    glVertex2f(0.25f,0.45f);
    glVertex2f(0.45f,0.45f);

    glVertex2f(0.25f,0.42f);
    glVertex2f(0.45f,0.42f);

    glVertex2f(0.25f,0.39f);
    glVertex2f(0.45f,0.39f);

    glVertex2f(0.25f,0.36f);
    glVertex2f(0.45f,0.36f);

    glVertex2f(0.25f,0.33f);
    glVertex2f(0.45f,0.33f);

    glVertex2f(0.25f,0.30f);
    glVertex2f(0.45f,0.30f);

    glVertex2f(0.25f,0.27f);
    glVertex2f(0.45f,0.27f);

    glVertex2f(0.25f,0.24f);
    glVertex2f(0.45f,0.24f);

    glVertex2f(0.25f,0.21f);
    glVertex2f(0.45f,0.21f);

    glVertex2f(0.25f,0.18f);
    glVertex2f(0.45f,0.18f);

    glVertex2f(0.25f,0.15f);
    glVertex2f(0.45f,0.15f);

    glVertex2f(0.25f,0.12f);
    glVertex2f(0.45f,0.12f);

    glVertex2f(0.25f,0.09f);
    glVertex2f(0.45f,0.09f);

    glVertex2f(0.25f,0.06f);
    glVertex2f(0.45f,0.06f);

    glVertex2f(0.25f,0.03f);
    glVertex2f(0.45f,0.03f);

    glVertex2f(0.25f,0.0f);
    glVertex2f(0.45f,0.0f);

    glVertex2f(0.25f,-0.03f);
    glVertex2f(0.45f,-0.03f);

    glVertex2f(0.25f,-0.06f);
    glVertex2f(0.45f,-0.06f);

    glVertex2f(0.25f,-0.09f);
    glVertex2f(0.45f,-0.09f);

    glVertex2f(0.25f,-0.12f);
    glVertex2f(0.45f,-0.12f);


    glVertex2f(0.25f,-0.30f);
    glVertex2f(0.45f,-0.30f);

    glVertex2f(0.25f,-0.27f);
    glVertex2f(0.45f,-0.27f);

    glVertex2f(0.25f,-0.24f);
    glVertex2f(0.45f,-0.24f);

    glVertex2f(0.25f,-0.21f);
    glVertex2f(0.45f,-0.21f);

    glVertex2f(0.25f,-0.18f);
    glVertex2f(0.45f,-0.18f);

    glVertex2f(0.25f,-0.15f);
    glVertex2f(0.45f,-0.15f);

    glEnd();


     glBegin(GL_QUADS);
     glVertex2f(0.25f,-0.5f);
     glVertex2f(0.25f,-0.4f);
     glVertex2f(0.28f,-0.4f);
     glVertex2f(0.28f,-0.5f);
     glEnd();





      glLoadIdentity();
      glTranslatef(0.0f,0.1f, 0.0f);
      glTranslatef(0.1,0,0);
     glBegin(GL_QUADS);
     glVertex2f(0.25f,-0.5f);
     glVertex2f(0.25f,-0.4f);
     glVertex2f(0.28f,-0.4f);
     glVertex2f(0.28f,-0.5f);
     glEnd();


     glLoadIdentity();
     glTranslatef(0.0f,0.1f, 0.0f);
     glBegin(GL_QUADS);
     glVertex2f(0.45f,-0.3f);
     glVertex2f(0.2f,-0.3f);
     glVertex2f(0.2f,-0.37f);
     glVertex2f(0.45f,-0.37f);
     glEnd();

//blue building end



    glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(0.67f,-0.5f);
    glVertex2f(0.67f,0.5f);
    glVertex2f(0.48f,0.3f);
    glVertex2f(0.48f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.74f,-0.5f);
    glVertex2f(0.71f,0.5f);
    glVertex2f(0.67f,-0.5f);
    glEnd();


       glTranslatef(0,-0.2,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();


    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
     glTranslatef(0,-0.4,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();


     glLoadIdentity();
     glTranslatef(0.0f,0.1f, 0.0f);
     glTranslatef(0,-0.6,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();

       glLoadIdentity();
       glTranslatef(0.0f,0.1f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();





    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
    glTranslatef(0.26,0,0);
    glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(0.67f,-0.5f);
    glVertex2f(0.67f,0.3f);
    glVertex2f(0.48f,0.5f);
    glVertex2f(0.48f,-0.5f);
    glEnd();

    glLoadIdentity();


    //Building start
glTranslatef(0.8f, -0.7f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(0, 85, 255);
    glVertex2f(-.98,0.3);
    glVertex2f(-0.8,0.3);
    glVertex2f(-0.8,0.9);
    glVertex2f(-.98,0.9);
    glColor3ub(0, 230, 230);
    glVertex2f(-0.8,0.32);
    glVertex2f(-0.7,0.32);
    glVertex2f(-0.7,0.87);
    glVertex2f(-0.8,0.87);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.35);
    glVertex2f(-0.9,0.35);
    glVertex2f(-0.9,0.45);
    glVertex2f(-.96,0.45);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.35);
    glVertex2f(-0.84,0.35);
    glVertex2f(-0.84,0.45);
    glVertex2f(-.87,0.45);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.53);
    glVertex2f(-0.9,0.53);
    glVertex2f(-0.9,0.63);
    glVertex2f(-.96,0.63);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.53);
    glVertex2f(-0.84,0.53);
    glVertex2f(-0.84,0.63);
    glVertex2f(-.87,0.63);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.73);
    glVertex2f(-0.9,0.73);
    glVertex2f(-0.9,0.83);
    glVertex2f(-.96,0.83);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.73);
    glVertex2f(-0.84,0.73);
    glVertex2f(-0.84,0.83);
    glVertex2f(-.87,0.83);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.37);
    glVertex2f(-0.73,0.37);
    glVertex2f(-0.73,0.47);
    glVertex2f(-.77,0.47);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.52);
    glVertex2f(-0.73,0.52);
    glVertex2f(-0.73,0.62);
    glVertex2f(-.77,0.62);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.67);
    glVertex2f(-0.73,0.67);
    glVertex2f(-0.73,0.77);
    glVertex2f(-.77,0.77);
glEnd();
glLoadIdentity();

//building end

glTranslatef(0.0f, -0.433f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(51, 51, 51);
glVertex2f(-1.0f,0.0f);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,0.05f);
glVertex2f(-1.0f,0.05f);
glEnd();

glLoadIdentity();

glTranslatef(0.0f, 0.023f, 0.0f);

    //rail line

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-1.0f,-0.5f);
glVertex2f(1.0f,0.-0.5f);
glEnd();

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-1.0f,-0.46f);
glVertex2f(1.0f,0.-0.46f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.01f,-0.46f);
glVertex2f(-0.02f,-0.46f);
glVertex2f(-0.03f,-0.5f);
glVertex2f(-0.02f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.03f,-0.46f);
glVertex2f(-0.04f,-0.46f);
glVertex2f(-0.05f,-0.5f);
glVertex2f(-0.04f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.05f,-0.46f);
glVertex2f(-0.06f,-0.46f);
glVertex2f(-0.07f,-0.5f);
glVertex2f(-0.06f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.07f,-0.46f);
glVertex2f(-0.08f,-0.46f);
glVertex2f(-0.09f,-0.5f);
glVertex2f(-0.08f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.09f,-0.46f);
glVertex2f(-0.1f,-0.46f);
glVertex2f(-0.11f,-0.5f);
glVertex2f(-0.1f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.11f,-0.46f);
glVertex2f(-0.12f,-0.46f);
glVertex2f(-0.13f,-0.5f);
glVertex2f(-0.12f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.13f,-0.46f);
glVertex2f(-0.14f,-0.46f);
glVertex2f(-0.15f,-0.5f);
glVertex2f(-0.14f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.15f,-0.46f);
glVertex2f(-0.16f,-0.46f);
glVertex2f(-0.17f,-0.5f);
glVertex2f(-0.16f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.17f,-0.46f);
glVertex2f(-0.18f,-0.46f);
glVertex2f(-0.19f,-0.5f);
glVertex2f(-0.18f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.19f,-0.46f);
glVertex2f(-0.20f,-0.46f);
glVertex2f(-0.21f,-0.5f);
glVertex2f(-0.20f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.21f,-0.46f);
glVertex2f(-0.22f,-0.46f);
glVertex2f(-0.23f,-0.5f);
glVertex2f(-0.22f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.23f,-0.46f);
glVertex2f(-0.24f,-0.46f);
glVertex2f(-0.25f,-0.5f);
glVertex2f(-0.24f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.25f,-0.46f);
glVertex2f(-0.26f,-0.46f);
glVertex2f(-0.27f,-0.5f);
glVertex2f(-0.26f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.27f,-0.46f);
glVertex2f(-0.28f,-0.46f);
glVertex2f(-0.29f,-0.5f);
glVertex2f(-0.28f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.29f,-0.46f);
glVertex2f(-0.3f,-0.46f);
glVertex2f(-0.31f,-0.5f);
glVertex2f(-0.3f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.31f,-0.46f);
glVertex2f(-0.32f,-0.46f);
glVertex2f(-0.33f,-0.5f);
glVertex2f(-0.32f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.33f,-0.46f);
glVertex2f(-0.34f,-0.46f);
glVertex2f(-0.35f,-0.5f);
glVertex2f(-0.34f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.35f,-0.46f);
glVertex2f(-0.36f,-0.46f);
glVertex2f(-0.37f,-0.5f);
glVertex2f(-0.36f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.37f,-0.46f);
glVertex2f(-0.38f,-0.46f);
glVertex2f(-0.39f,-0.5f);
glVertex2f(-0.38f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.39f,-0.46f);
glVertex2f(-0.4f,-0.46f);
glVertex2f(-0.41f,-0.5f);
glVertex2f(-0.4f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.41f,-0.46f);
glVertex2f(-0.42f,-0.46f);
glVertex2f(-0.43f,-0.5f);
glVertex2f(-0.42f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.43f,-0.46f);
glVertex2f(-0.44f,-0.46f);
glVertex2f(-0.45f,-0.5f);
glVertex2f(-0.44f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.45f,-0.46f);
glVertex2f(-0.46f,-0.46f);
glVertex2f(-0.47f,-0.5f);
glVertex2f(-0.46f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.47f,-0.46f);
glVertex2f(-0.48f,-0.46f);
glVertex2f(-0.49f,-0.5f);
glVertex2f(-0.48f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.49f,-0.46f);
glVertex2f(-0.5f,-0.46f);
glVertex2f(-0.51f,-0.5f);
glVertex2f(-0.5f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.51f,-0.46f);
glVertex2f(-0.52f,-0.46f);
glVertex2f(-0.53f,-0.5f);
glVertex2f(-0.52f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.53f,-0.46f);
glVertex2f(-0.54f,-0.46f);
glVertex2f(-0.55f,-0.5f);
glVertex2f(-0.54f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.55f,-0.46f);
glVertex2f(-0.56f,-0.46f);
glVertex2f(-0.57f,-0.5f);
glVertex2f(-0.56f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.57f,-0.46f);
glVertex2f(-0.58f,-0.46f);
glVertex2f(-0.59f,-0.5f);
glVertex2f(-0.58f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.59f,-0.46f);
glVertex2f(-0.6f,-0.46f);
glVertex2f(-0.61f,-0.5f);
glVertex2f(-0.6f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.61f,-0.46f);
glVertex2f(-0.62f,-0.46f);
glVertex2f(-0.63f,-0.5f);
glVertex2f(-0.62f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.63f,-0.46f);
glVertex2f(-0.64f,-0.46f);
glVertex2f(-0.65f,-0.5f);
glVertex2f(-0.64f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.65f,-0.46f);
glVertex2f(-0.66f,-0.46f);
glVertex2f(-0.67f,-0.5f);
glVertex2f(-0.66f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.67f,-0.46f);
glVertex2f(-0.68f,-0.46f);
glVertex2f(-0.69f,-0.5f);
glVertex2f(-0.68f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.69f,-0.46f);
glVertex2f(-0.7f,-0.46f);
glVertex2f(-0.71f,-0.5f);
glVertex2f(-0.7f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.71f,-0.46f);
glVertex2f(-0.72f,-0.46f);
glVertex2f(-0.73f,-0.5f);
glVertex2f(-0.72f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.73f,-0.46f);
glVertex2f(-0.74f,-0.46f);
glVertex2f(-0.75f,-0.5f);
glVertex2f(-0.74f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.75f,-0.46f);
glVertex2f(-0.76f,-0.46f);
glVertex2f(-0.77f,-0.5f);
glVertex2f(-0.76f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.77f,-0.46f);
glVertex2f(-0.78f,-0.46f);
glVertex2f(-0.79f,-0.5f);
glVertex2f(-0.78f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.79f,-0.46f);
glVertex2f(-0.8f,-0.46f);
glVertex2f(-0.81f,-0.5f);
glVertex2f(-0.8f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.81f,-0.46f);
glVertex2f(-0.82f,-0.46f);
glVertex2f(-0.83f,-0.5f);
glVertex2f(-0.82f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.83f,-0.46f);
glVertex2f(-0.84f,-0.46f);
glVertex2f(-0.85f,-0.5f);
glVertex2f(-0.84f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.85f,-0.46f);
glVertex2f(-0.86f,-0.46f);
glVertex2f(-0.87f,-0.5f);
glVertex2f(-0.86f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.87f,-0.46f);
glVertex2f(-0.88f,-0.46f);
glVertex2f(-0.89f,-0.5f);
glVertex2f(-0.88f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.89f,-0.46f);
glVertex2f(-0.9f,-0.46f);
glVertex2f(-0.91f,-0.5f);
glVertex2f(-0.9f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.91f,-0.46f);
glVertex2f(-0.92f,-0.46f);
glVertex2f(-0.93f,-0.5f);
glVertex2f(-0.92f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.93f,-0.46f);
glVertex2f(-0.94f,-0.46f);
glVertex2f(-0.95f,-0.5f);
glVertex2f(-0.94f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.95f,-0.46f);
glVertex2f(-0.96f,-0.46f);
glVertex2f(-0.97f,-0.5f);
glVertex2f(-0.96f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.97f,-0.46f);
glVertex2f(-0.98f,-0.46f);
glVertex2f(-0.99f,-0.5f);
glVertex2f(-0.98f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.01f,-0.46f);
glVertex2f(0.0f,-0.46f);
glVertex2f(-0.01f,-0.5f);
glVertex2f(0.0f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.03f,-0.46f);
glVertex2f(0.02f,-0.46f);
glVertex2f(0.01f,-0.5f);
glVertex2f(0.02f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.05f,-0.46f);
glVertex2f(0.04f,-0.46f);
glVertex2f(0.03f,-0.5f);
glVertex2f(0.04f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.07f,-0.46f);
glVertex2f(0.06f,-0.46f);
glVertex2f(0.05f,-0.5f);
glVertex2f(0.06f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.09f,-0.46f);
glVertex2f(0.08f,-0.46f);
glVertex2f(0.07f,-0.5f);
glVertex2f(0.08f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.11f,-0.46f);
glVertex2f(0.1f,-0.46f);
glVertex2f(0.09f,-0.5f);
glVertex2f(0.1f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.13f,-0.46f);
glVertex2f(0.12f,-0.46f);
glVertex2f(0.11f,-0.5f);
glVertex2f(0.12f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.15f,-0.46f);
glVertex2f(0.14f,-0.46f);
glVertex2f(0.13f,-0.5f);
glVertex2f(0.14f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.17f,-0.46f);
glVertex2f(0.16f,-0.46f);
glVertex2f(0.15f,-0.5f);
glVertex2f(0.16f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.19f,-0.46f);
glVertex2f(0.18f,-0.46f);
glVertex2f(0.17f,-0.5f);
glVertex2f(0.18f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.21f,-0.46f);
glVertex2f(0.2f,-0.46f);
glVertex2f(0.19f,-0.5f);
glVertex2f(0.2f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.23f,-0.46f);
glVertex2f(0.22f,-0.46f);
glVertex2f(0.21f,-0.5f);
glVertex2f(0.22f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.25f,-0.46f);
glVertex2f(0.24f,-0.46f);
glVertex2f(0.23f,-0.5f);
glVertex2f(0.24f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.27f,-0.46f);
glVertex2f(0.26f,-0.46f);
glVertex2f(0.25f,-0.5f);
glVertex2f(0.26f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.29f,-0.46f);
glVertex2f(0.28f,-0.46f);
glVertex2f(0.27f,-0.5f);
glVertex2f(0.28f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.31f,-0.46f);
glVertex2f(0.3f,-0.46f);
glVertex2f(0.29f,-0.5f);
glVertex2f(0.3f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.33f,-0.46f);
glVertex2f(0.32f,-0.46f);
glVertex2f(0.31f,-0.5f);
glVertex2f(0.32f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.35f,-0.46f);
glVertex2f(0.34f,-0.46f);
glVertex2f(0.33f,-0.5f);
glVertex2f(0.34f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.37f,-0.46f);
glVertex2f(0.36f,-0.46f);
glVertex2f(0.35f,-0.5f);
glVertex2f(0.36f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.39f,-0.46f);
glVertex2f(0.38f,-0.46f);
glVertex2f(0.37f,-0.5f);
glVertex2f(0.38f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.41f,-0.46f);
glVertex2f(0.4f,-0.46f);
glVertex2f(0.39f,-0.5f);
glVertex2f(0.4f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.43f,-0.46f);
glVertex2f(0.42f,-0.46f);
glVertex2f(0.41f,-0.5f);
glVertex2f(0.42f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.45f,-0.46f);
glVertex2f(0.44f,-0.46f);
glVertex2f(0.43f,-0.5f);
glVertex2f(0.44f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.47f,-0.46f);
glVertex2f(0.46f,-0.46f);
glVertex2f(0.45f,-0.5f);
glVertex2f(0.46f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.49f,-0.46f);
glVertex2f(0.48f,-0.46f);
glVertex2f(0.47f,-0.5f);
glVertex2f(0.48f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.51f,-0.46f);
glVertex2f(0.5f,-0.46f);
glVertex2f(0.49f,-0.5f);
glVertex2f(0.5f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.53f,-0.46f);
glVertex2f(0.52f,-0.46f);
glVertex2f(0.51f,-0.5f);
glVertex2f(0.52f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.55f,-0.46f);
glVertex2f(0.54f,-0.46f);
glVertex2f(0.53f,-0.5f);
glVertex2f(0.54f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.57f,-0.46f);
glVertex2f(0.56f,-0.46f);
glVertex2f(0.55f,-0.5f);
glVertex2f(0.56f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.59f,-0.46f);
glVertex2f(0.58f,-0.46f);
glVertex2f(0.57f,-0.5f);
glVertex2f(0.58f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.61f,-0.46f);
glVertex2f(0.6f,-0.46f);
glVertex2f(0.59f,-0.5f);
glVertex2f(0.6f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.63f,-0.46f);
glVertex2f(0.62f,-0.46f);
glVertex2f(0.61f,-0.5f);
glVertex2f(0.62f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.65f,-0.46f);
glVertex2f(0.64f,-0.46f);
glVertex2f(0.63f,-0.5f);
glVertex2f(0.64f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.67f,-0.46f);
glVertex2f(0.66f,-0.46f);
glVertex2f(0.65f,-0.5f);
glVertex2f(0.66f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.69f,-0.46f);
glVertex2f(0.68f,-0.46f);
glVertex2f(0.67f,-0.5f);
glVertex2f(0.68f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.71f,-0.46f);
glVertex2f(0.7f,-0.46f);
glVertex2f(0.69f,-0.5f);
glVertex2f(0.7f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.73f,-0.46f);
glVertex2f(0.72f,-0.46f);
glVertex2f(0.71f,-0.5f);
glVertex2f(0.72f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.75f,-0.46f);
glVertex2f(0.74f,-0.46f);
glVertex2f(0.73f,-0.5f);
glVertex2f(0.74f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.77f,-0.46f);
glVertex2f(0.76f,-0.46f);
glVertex2f(0.75f,-0.5f);
glVertex2f(0.76f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.79f,-0.46f);
glVertex2f(0.78f,-0.46f);
glVertex2f(0.77f,-0.5f);
glVertex2f(0.78f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.81f,-0.46f);
glVertex2f(0.8f,-0.46f);
glVertex2f(0.79f,-0.5f);
glVertex2f(0.8f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.83f,-0.46f);
glVertex2f(0.82f,-0.46f);
glVertex2f(0.81f,-0.5f);
glVertex2f(0.82f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.85f,-0.46f);
glVertex2f(0.84f,-0.46f);
glVertex2f(0.83f,-0.5f);
glVertex2f(0.84f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.87f,-0.46f);
glVertex2f(0.86f,-0.46f);
glVertex2f(0.85f,-0.5f);
glVertex2f(0.86f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.89f,-0.46f);
glVertex2f(0.88f,-0.46f);
glVertex2f(0.87f,-0.5f);
glVertex2f(0.88f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.91f,-0.46f);
glVertex2f(0.9f,-0.46f);
glVertex2f(0.89f,-0.5f);
glVertex2f(0.9f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.93f,-0.46f);
glVertex2f(0.92f,-0.46f);
glVertex2f(0.91f,-0.5f);
glVertex2f(0.92f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.95f,-0.46f);
glVertex2f(0.94f,-0.46f);
glVertex2f(0.93f,-0.5f);
glVertex2f(0.94f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.97f,-0.46f);
glVertex2f(0.96f,-0.46f);
glVertex2f(0.95f,-0.5f);
glVertex2f(0.96f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.99f,-0.46f);
glVertex2f(0.98f,-0.46f);
glVertex2f(0.97f,-0.5f);
glVertex2f(0.98f,-0.5f);
glEnd();

glLoadIdentity();

//train

glPushMatrix();
glTranslatef(position_train,0.0f, 0.0f);


glTranslatef(0.0f, 0.023f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.5f,-0.48f);
glVertex2f(-0.5f,-0.3f);
glVertex2f(-0.55f,-0.3f);
glVertex2f(-0.6f,-0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.11f,-0.48f);
glVertex2f(-0.11f,-0.2f);
glVertex2f(-0.5f,-0.2f);
glVertex2f(-0.5f,-0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glTranslatef(0.08f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.16f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.24f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.32f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int i;
x=-.42f; y=-.45f; radius =.05f;
triangleAmount = 200;
twicePi = 2.0f * PI;
glVertex2f(x, y);
for(i = 0; i <= triangleAmount;i++)
{
    glVertex2f
    (
        x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i7;
x7=-.42f; y7=-.45f; radius7 =.04f;
triangleAmount7 = 200;
twicePi7 = 2.0f * PI;
glVertex2f(x7, y7);
for(i7 = 0; i7 <= triangleAmount7;i7++)
{
    glVertex2f
    (
        x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)), y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
i;
x=-.2f; y=-.45f; radius =.05f;
triangleAmount = 200;
twicePi = 2.0f * PI;
glVertex2f(x, y);
for(i = 0; i <= triangleAmount;i++)
{
    glVertex2f
    (
        x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i8;
x8=-.2f; y8=-.45f; radius8 =.04f;
triangleAmount8 = 200;
twicePi8 = 2.0f * PI;
glVertex2f(x8, y8);
for(i8 = 0; i8 <= triangleAmount8;i8++)
{
    glVertex2f
    (
        x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)), y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
    );
}
glEnd();



glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.1f,-0.48f);
glVertex2f(0.28f,-0.48f);
glVertex2f(0.28f,-0.2f);
glVertex2f(-0.1f,-0.2f);
glEnd();

glTranslatef(0.41f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.49f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.57f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.65f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.725f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int i1;
GLfloat x1=-.02f; GLfloat y1=-.45f; GLfloat radius1 =.05f;
int triangleAmount1 = 200;
GLfloat twicePi1 = 2.0f * PI;
glVertex2f(x1, y1);
for(i1 = 0; i1 <= triangleAmount1;i1++)
{
    glVertex2f
    (
        x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)), y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i9;
x9=-.02f;  y9=-.45f;  radius9 =.04f;
 triangleAmount9 = 200;
 twicePi9 = 2.0f * PI;
glVertex2f(x9, y9);
for(i9 = 0; i9 <= triangleAmount9;i9++)
{
    glVertex2f
    (
        x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)), y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int k;
GLfloat u=.2f; GLfloat v=-.45f; GLfloat radius6 =.05f;
int triangleAmount6 = 200;
GLfloat twicePi6 = 2.0f * PI;
glVertex2f(u, v);
for(k = 0; k <= triangleAmount6;k++)
{
    glVertex2f
    (
        u + (radius6 * cos(k *  twicePi6 / triangleAmount6)), v + (radius6 * sin(k * twicePi6 / triangleAmount6))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i11;
GLfloat x11=.2f; GLfloat y11=-.45f; GLfloat radius11 =.04f;
int triangleAmount11 = 200;
GLfloat twicePi11 = 2.0f * PI;
glVertex2f(x11, y11);
for(i11 = 0; i11 <= triangleAmount11;i11++)
{
    glVertex2f
    (
        x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)), y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
    );
}
glEnd();

glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(0.29f,-0.48f);
glVertex2f(0.68f,-0.48f);
glVertex2f(0.68f,-0.2f);
glVertex2f(0.29f,-0.2f);
glEnd();

glTranslatef(0.80f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(0.88f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.96f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(1.04f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(1.12f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int r;
GLfloat s=.38f; GLfloat t=-.45f; GLfloat radius3 =.05f;
int triangleAmount3 = 200;
GLfloat twicePi3 = 2.0f * PI;
glVertex2f(s, t);
for(r = 0; r <= triangleAmount3;r++)
{
    glVertex2f
    (
        s + (radius3 * cos(r *  twicePi3 / triangleAmount3)), t + (radius3 * sin(r * twicePi3 / triangleAmount3))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i22;
GLfloat x22=.38f; GLfloat y22=-.45f; GLfloat radius22 =.04f;
int triangleAmount22 = 200;
GLfloat twicePi22 = 2.0f * PI;
glVertex2f(x22, y22);
for(i22 = 0; i22 <= triangleAmount;i22++)
{
    glVertex2f
    (
        x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)), y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int r1;
GLfloat s1=.6f; GLfloat t1=-.45f; GLfloat radius4 =.05f;
int triangleAmount4 = 200;
GLfloat twicePi4 = 2.0f * PI;
glVertex2f(s1, t1);
for(r1 = 0; r1 <= triangleAmount4;r1++)
{
    glVertex2f
    (
        s1 + (radius4 * cos(r1 *  twicePi4 / triangleAmount4)), t1 + (radius4 * sin(r1 * twicePi4 / triangleAmount4))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i33;
GLfloat x33=.6f; GLfloat y33=-.45f; GLfloat radius33 =.04f;
int triangleAmount33 = 200;
GLfloat twicePi33 = 2.0f * PI;
glVertex2f(x33, y33);
for(i33 = 0; i33 <= triangleAmount33;i33++)
{
    glVertex2f
    (
        x33 + (radius33 * cos(i33 *  twicePi33 / triangleAmount33)), y33 + (radius33* sin(i33 * twicePi33 / triangleAmount33))
    );
}
glEnd();


glPopMatrix();



    glLoadIdentity();





    //road
    glBegin(GL_QUADS);
    glColor3ub(51, 51, 51);

    glVertex2f(-1,-.5);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.5);

    glEnd();
//road's middle lines
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();

    //copying road's middle line
    //1
    glTranslatef(.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //2
    glTranslatef(.4,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //3
    glTranslatef(.6,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //4
    glTranslatef(.8,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //5
    glTranslatef(1,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //left side
    //6
    glTranslatef(-.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //7
    glTranslatef(-.4,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //8
    glTranslatef(-.6,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //9
    glTranslatef(-.8,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //10
    glTranslatef(-1,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //road upper side border
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(-1,-.48);
    glVertex2f(-1,-.5);
    glVertex2f(1,-.5);
    glVertex2f(1,-.48);
    glEnd();

    //Starting drawing light

    //road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();


    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient[] = {4,4,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    //Left light
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(-.06,-.15);
    glVertex2f(-.09,-.15);
    glVertex2f(-.12,-.48);
    glVertex2f(-.03,-.48);
    glEnd();
    //Light Right
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.09,-.15);
    glVertex2f(.06,-.15);
    glVertex2f(.03,-.48);
    glVertex2f(.12,-.48);
    glEnd();
    glDisable(GL_LIGHTING);

//end 1st road light

//copy light 2
    glTranslatef(.45,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient1[] = {4,4,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.
    //Left light

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(-.06,-.15);
    glVertex2f(-.09,-.15);
    glVertex2f(-.12,-.48);
    glVertex2f(-.03,-.48);
    glEnd();
    //Light Right

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.09,-.15);
    glVertex2f(.06,-.15);
    glVertex2f(.03,-.48);
    glVertex2f(.12,-.48);
    glEnd();
    glDisable(GL_LIGHTING);

//end 2nd road light
    glLoadIdentity();

    //copy light 3
     glTranslatef(.9,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient2[] = {4,4,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);//A lighting model parameter.
    //Left light
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(-.06,-.15);
    glVertex2f(-.09,-.15);
    glVertex2f(-.12,-.48);
    glVertex2f(-.03,-.48);
    glEnd();
    //Light Right
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.09,-.15);
    glVertex2f(.06,-.15);
    glVertex2f(.03,-.48);
    glVertex2f(.12,-.48);
    glEnd();
    glDisable(GL_LIGHTING);

//end 3rd road light
    glLoadIdentity();

    //copy light 4
     glTranslatef(-.45,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient3[] = {4,4,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient3);//A lighting model parameter.
    //Left light
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(-.06,-.15);
    glVertex2f(-.09,-.15);
    glVertex2f(-.12,-.48);
    glVertex2f(-.03,-.48);
    glEnd();
    //Light Right
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.09,-.15);
    glVertex2f(.06,-.15);
    glVertex2f(.03,-.48);
    glVertex2f(.12,-.48);
    glEnd();
    glDisable(GL_LIGHTING);

//end 4th road light
    glLoadIdentity();

    //copy road light 5
     glTranslatef(-.9,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient4[] = {4,4,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient4);//A lighting model parameter.
    //Left light
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(-.06,-.15);
    glVertex2f(-.09,-.15);
    glVertex2f(-.12,-.48);
    glVertex2f(-.03,-.48);
    glEnd();
    //Light Right
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.09,-.15);
    glVertex2f(.06,-.15);
    glVertex2f(.03,-.48);
    glVertex2f(.12,-.48);
    glEnd();
    glDisable(GL_LIGHTING);
    //end 5th road light

//new car
glPushMatrix();
glTranslatef(position_car2,0.0f, 0.0f);

glTranslatef(0.9f, 0.05f, 0.0f);
glScalef(2.0,1.8,0);

 glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.8f,-0.33f);
    glVertex2f(-0.8f,-0.30f);
    glVertex2f(-0.9f,-0.30f);
    glVertex2f(-0.9f,-0.33f);
    glEnd();

   glColor3ub(13, 13, 13);
    glBegin(GL_QUADS);
    glVertex2f(-0.82f,-0.30f);
    glVertex2f(-0.83f,-0.28f);
    glVertex2f(-0.87f,-0.28f);
    glVertex2f(-0.88f,-0.30f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.824f,-0.298f);
    glVertex2f(-0.832f,-0.282f);
    glVertex2f(-0.848f,-0.282f);
    glVertex2f(-0.848f,-0.298f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.851f,-0.298f);
    glVertex2f(-0.851f,-0.282f);
    glVertex2f(-0.868f,-0.282f);
    glVertex2f(-0.876f,-0.298f);
    glEnd();

     i;
    j;
    x = -0.82f; y = -0.33f; radius = 0.01f; GLfloat a = -0.88f; GLfloat b = -0.33f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

    glColor3ub(13, 13, 13);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)),y + (radius * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    glColor3ub(13, 13, 13);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a, b);
    for(j = 0; j <= triangleAmount;j++)
        {
            glVertex2f(a + (radius * cos(j *  twicePi / triangleAmount)),b + (radius * sin(j * twicePi / triangleAmount)));
        }
    glEnd();

glPopMatrix();

glLoadIdentity();

//end new car
//blue car
glPushMatrix();
glTranslatef(position_jip2,0.0f, 0.0f);

glScalef(-.4,.4,0);
glTranslatef(-0.4f, -1.4f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(26, 83, 255);
glVertex2f(-.23,.3);
glVertex2f(-.38,.06);
glVertex2f(.12,.06);
glVertex2f(.12,.3);

glColor3ub(26, 83, 255);
glVertex2f(-.38,.06);
glVertex2f(-.38,-.06);
glVertex2f(.12,-.06);
glVertex2f(.12,.06);

glColor3ub(26, 83, 255);
glVertex2f(.12,-.06);
glVertex2f(.2,-.06);
glVertex2f(.19,.06);
glVertex2f(.12,.06);

glColor3ub(26, 83, 255);
glVertex2f(.12,.3);
glVertex2f(.12,.06);
glVertex2f(.19,.06);
glVertex2f(.16,.2);

glColor3ub(13, 13, 13);
glVertex2f(-.2,.28);
glVertex2f(-.32,.11);
glVertex2f(.15,.11);
glVertex2f(.1,.28);

glEnd();
 i;
	 x=.1f;  y=-.05f;  radius =.06f;
	 triangleAmount = 20;
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
glEnd();
 j;
	 x1=-.23f;  y1=-.05f;  radius1 =.06f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f(
		            x1 + (radius1 * cos(j*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(j* twicePi1 / triangleAmount1))
			);
		}
glEnd();
 k;
	 x=.1f;  y=-.05f;  radius =.03f;
	 triangleAmount2 = 20;
	 twicePi2 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(k = 0; k <= triangleAmount2;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi2 / triangleAmount2)),
			    y + (radius * sin(k * twicePi2 / triangleAmount2))
			);
		}
glEnd();
int l;
	 x=-.23f;  y=-.05f;  radius =.03f;
	 triangleAmount3 = 20;
	 twicePi3 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(l = 0; l <= triangleAmount3;l++) {
			glVertex2f(
		            x + (radius3 * cos(l*  twicePi3 / triangleAmount3)),
			    y + (radius3 * sin(l* twicePi3 / triangleAmount3))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();

//end blue car

//red car
glPushMatrix();
glTranslatef(position_car3,0.0f, 0.0f);

    glScalef(-.5,.4,0);
glTranslatef(-1.7f, -1.5f, 0.0f);

    glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,0);
glVertex2f(.3,0.0);
glVertex2f(.3,.1);
glVertex2f(-.2,.1);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 26, 51);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glVertex2f(-.05,.29);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.04,.25);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(-.05,.29);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(.3,.16);
glVertex2f(.2,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 40, 77);
glVertex2f(.15,.25);
glVertex2f(.2,.16);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glEnd();

glColor3ub(0, 0, 0);
 i;
	 x8=-.06f;  y8=0.0f;  radius8 =.06f;
	 triangleAmount8 = 20;
	 twicePi8 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(i = 0; i <= triangleAmount8;i++) {
			glVertex2f(
		            x8 + (radius8 * cos(i *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i * twicePi8 / triangleAmount8))
			);
		}
glEnd();
 i;
	 x=.18f;  y=0.0f;  radius =.06f;
	 triangleAmount = 20;
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi / triangleAmount)),
			    y + (radius * sin(i* twicePi / triangleAmount))
			);
		}
glEnd();
 r;
	 x11=-.06f;  y11=0.0f;  radius11 =.03f;
	 triangleAmount11 = 20;
	 twicePi11 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11);
		glColor3ub(255, 255,255);
		for(r = 0; r <= triangleAmount11;r++) {
			glVertex2f(
		            x11 + (radius11 * cos(r *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(r * twicePi11 / triangleAmount11))
			);
		}
glEnd();
 s;
	 x1=.18f;  y1=0.0f;  radius1 =0.03f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		glColor3ub(255, 255,255);
		for(s = 0; s <= triangleAmount1;s++) {
			glVertex2f(
		            x1 + (radius1 * cos(s*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(s* twicePi1 / triangleAmount1))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();
//end red car

//bus
glPushMatrix();
glTranslatef(position_bus2,0.0f, 0.0f);

glScalef(-.2,.3,0);
glTranslatef(.7f, -2.5f, 0.0f);

glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-.6,0.25);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.4);
    glVertex2f(-0.6,0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
    glVertex2f(-.6,0.4);
    glVertex2f(0.6,0.4);
    glVertex2f(0.6,0.7);
    glVertex2f(-.6,0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51, 153);
    glVertex2f(-.6,0.4);
    glVertex2f(-.5,0.4);
    glVertex2f(-.5,0.7);
    glVertex2f(-.6,0.7);


    glVertex2f(-.4,0.5);
    glVertex2f(-.3,0.5);
    glVertex2f(-.3,0.6);
    glVertex2f(-.4,0.6);

    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glVertex2f(-.2,0.5);
    glVertex2f(-.1,0.5);
    glVertex2f(-.1,0.6);
    glVertex2f(-.2,0.6);
    glEnd();

    glTranslatef(-.25,0,0);
    glBegin(GL_QUADS);
    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glEnd();
     glLoadIdentity();
     glTranslatef(position_bus2,0.0f, 0.0f);

     glScalef(-.2,.3,0);
glTranslatef(.7f, -2.5f, 0.0f);

	x=.3f; y=.25f; radius =.11f;
	glColor3f(0,0,0);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3f(0,0,0);
    j;

    x=-.3f;  y1=.25f;  radius =.11f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
			    x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius* sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

     x=.3f;  y=.25f;  radius =.06f;
	glColor3f(1,1,1);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius3 * cos(i *  twicePi3 / triangleAmount)),
			    y + (radius3* sin(i * twicePi3 / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1,1,1);
    i;

     x=-.3f;  y=.25f;  radius =.06f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius4 = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

	glLoadIdentity();

//traffic light
glTranslatef(0.0f, -0.38f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.91f,-0.4f);
glVertex2f(-0.9f,-0.4f);
glVertex2f(-0.9f,0.01f);
glVertex2f(-0.91f,0.01f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 102, 102);
glVertex2f(-0.93f,0.01f);
glVertex2f(-0.88f,0.01f);
glVertex2f(-0.88f,-0.15f);
glVertex2f(-0.93f,-0.15f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(-0.91f,0.001f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f(-0.91f,-0.12f);
glEnd();

glLoadIdentity();
glTranslatef(0.0f, -0.38f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.91f,-0.4f);
glVertex2f(0.9f,-0.4f);
glVertex2f(0.9f,0.01f);
glVertex2f(0.91f,0.01f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 102, 102);
glVertex2f(0.93f,0.01f);
glVertex2f(0.88f,0.01f);
glVertex2f(0.88f,-0.15f);
glVertex2f(0.93f,-0.15f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(0.9f,0.001f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f(0.9f,-0.12f);
glEnd();

glLoadIdentity();
//end traffic light

//bus
glPushMatrix();
glTranslatef(position_bus1,0.0f, 0.0f);

glScalef(.2,.3,0);
glTranslatef(1.0f, -3.0f, 0.0f);

glBegin(GL_QUADS);
    glColor3ub(0, 48, 48);
    glVertex2f(-.6,0.25);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.4);
    glVertex2f(-0.6,0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
    glVertex2f(-.6,0.4);
    glVertex2f(0.6,0.4);
    glVertex2f(0.6,0.7);
    glVertex2f(-.6,0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 48, 48);
    glVertex2f(-.6,0.4);
    glVertex2f(-.5,0.4);
    glVertex2f(-.5,0.7);
    glVertex2f(-.6,0.7);


    glVertex2f(-.4,0.5);
    glVertex2f(-.3,0.5);
    glVertex2f(-.3,0.6);
    glVertex2f(-.4,0.6);

    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glVertex2f(-.2,0.5);
    glVertex2f(-.1,0.5);
    glVertex2f(-.1,0.6);
    glVertex2f(-.2,0.6);
    glEnd();

    glTranslatef(-.25,0,0);
    glBegin(GL_QUADS);
    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glEnd();
     glLoadIdentity();
     glTranslatef(position_bus1,0.0f, 0.0f);

     glScalef(.2,.3,0);
glTranslatef(1.0f, -3.0f, 0.0f);

	x=.3f; y=.25f; radius =.11f;
	glColor3f(0,0,0);
	i;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3f(0,0,0);
    i;

    x=-.3f;  y1=.25f;  radius =.11f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     x=.3f;  y=.25f;  radius =.06f;
	glColor3f(1,1,1);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi3 / triangleAmount)),
			    y + (radius* sin(i * twicePi3 / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1,1,1);
    i;

     x=-.3f;  y=.25f;  radius =.06f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius4 = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();
	glLoadIdentity();

	//end bus

glPushMatrix();
glTranslatef(position_jip1,0.0f, 0.0f);

glScalef(.4,.4,0);
glTranslatef(-2.0f, -2.2f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(117, 102, 2);
glVertex2f(-.23,.3);
glVertex2f(-.38,.06);
glVertex2f(.12,.06);
glVertex2f(.12,.3);

glColor3ub(117, 102, 2);
glVertex2f(-.38,.06);
glVertex2f(-.38,-.06);
glVertex2f(.12,-.06);
glVertex2f(.12,.06);

glColor3ub(117, 102, 2);
glVertex2f(.12,-.06);
glVertex2f(.2,-.06);
glVertex2f(.19,.06);
glVertex2f(.12,.06);

glColor3ub(117, 102, 2);
glVertex2f(.12,.3);
glVertex2f(.12,.06);
glVertex2f(.19,.06);
glVertex2f(.16,.2);

glColor3ub(13, 13, 13);
glVertex2f(-.2,.28);
glVertex2f(-.32,.11);
glVertex2f(.15,.11);
glVertex2f(.1,.28);

glEnd();
    i;
	 x=.1f;  y=-.05f; radius =.06f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
glEnd();
    i;
	x=-.23f; y=-.05f; radius =.06f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi / triangleAmount)),
			    y + (radius * sin(i* twicePi / triangleAmount))
			);
		}
glEnd();
    k;
	x=.1f; y=-.05f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount))
			);
		}
glEnd();
    i;
	x=-.23f; y=-.05f; radius =.03f;
	triangleAmount3 = 20;
	twicePi3 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(i = 0; i <= triangleAmount3;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi3 / triangleAmount3)),
			    y + (radius * sin(i* twicePi3 / triangleAmount3))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();

    //red car
glPushMatrix();
glTranslatef(position_car1,0.0f, 0.0f);

    glScalef(.5,.4,0);
glTranslatef(-0.3f, -2.4f, 0.0f);

    glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,0);
glVertex2f(.3,0.0);
glVertex2f(.3,.1);
glVertex2f(-.2,.1);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 26, 51);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glVertex2f(-.05,.29);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.04,.25);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(-.05,.29);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(.3,.16);
glVertex2f(.2,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 40, 77);
glVertex2f(.15,.25);
glVertex2f(.2,.16);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glEnd();

glColor3ub(0, 0, 0);
int p;
	 x8=-.06f;  y8=0.0f;  radius8 =.06f;
	 triangleAmount8 = 20;
	 twicePi8 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(p = 0; p <= triangleAmount8;p++) {
			glVertex2f(
		            x8 + (radius8 * cos(p *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(p * twicePi8 / triangleAmount8))
			);
		}
glEnd();
int q;
	 x9=.18f;  y9=0.0f;  radius9 =.06f;
	 triangleAmount9 = 20;
	 twicePi9 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9);
		for(q = 0; q <= triangleAmount9;q++) {
			glVertex2f(
		            x9 + (radius9 * cos(q*  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(q* twicePi9 / triangleAmount9))
			);
		}
glEnd();
 r;
	 x11=-.06f;  y11=0.0f;  radius11 =.03f;
	 triangleAmount11 = 20;
	 twicePi11 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11);
		glColor3ub(255, 255,255);
		for(r = 0; r <= triangleAmount11;r++) {
			glVertex2f(
		            x11 + (radius11 * cos(r *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(r * twicePi11 / triangleAmount11))
			);
		}
glEnd();
 s;
	 x1=.18f;  y1=0.0f;  radius1 =0.03f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		glColor3ub(255, 255,255);
		for(s = 0; s <= triangleAmount1;s++) {
			glVertex2f(
		            x1 + (radius1 * cos(s*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(s* twicePi1 / triangleAmount1))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();
//end red car

glFlush();

glutTimerFunc(1500,demo_rain,0);
   glFlush();
}

void demo_night(int val) {

 glutDisplayFunc(night);

}


void day() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Background Color
    //sky
    glBegin(GL_QUADS);
    glColor3ub(77, 184, 200);

    glVertex2f(-1,1);
    glVertex2f(-1,-.5);
    glVertex2f(1,-.5);
    glVertex2f(1,1);

    glEnd();

//sun
    glBegin(GL_TRIANGLE_FAN);
glColor3ub(245, 117, 66);
int j;
GLfloat x=.8f; GLfloat y=.8f; GLfloat radius =.1f;
int triangleAmount = 200;
GLfloat twicePi = 2.0f * PI;
glVertex2f(x, y);
for(j = 0; j <= triangleAmount;j++)
{
    glVertex2f
    (
        x + (radius * cos(j *  twicePi / triangleAmount)), y + (radius * sin(j * twicePi / triangleAmount))
    );
}
glEnd();

// end

//cloud
//1st ring
glLoadIdentity();
      glTranslatef(-0.7,0.1,0);

	int j7;

	GLfloat x7=.3f; GLfloat y7= .8f; GLfloat radius7 =.050f;
	int triangleAmount7 = 20; //# of triangles used to draw circle
	glColor3ub(222, 224, 227);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(j7 = 0; j7 <= triangleAmount7;j7++) {
			glVertex2f(
		            x7 + (radius7 * cos(j7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(j7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();
//2nd ring
	int j8;

	GLfloat x8=.35f; GLfloat y8= .85f; GLfloat radius8 =.050f;
	int triangleAmount8 = 20; //# of triangles used to draw circle
	glColor3ub(222, 224, 227);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(j8 = 0; j8 <= triangleAmount8;j8++) {
			glVertex2f(
		            x8 + (radius8 * cos(j8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(j8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();
//3rd ring
	int j9;

	GLfloat x9=.40f; GLfloat y9= .8f; GLfloat radius9 =.050f;
	int triangleAmount9 = 20; //# of triangles used to draw circle
	glColor3ub(222, 224, 227);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(j9 = 0; j9 <= triangleAmount9;j9++) {
			glVertex2f(
		            x9 + (radius8 * cos(j9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(j9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();
//4th ring
	int j10;

	GLfloat x10=.35f; GLfloat y10= .80f; GLfloat radius10 =.050f;
	int triangleAmount10 = 20; //# of triangles used to draw circle
	glColor3ub(222, 224, 227);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(j10 = 0; j10 <= triangleAmount10;j10++) {
			glVertex2f(
		            x10 + (radius10 * cos(j10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(j10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();

glLoadIdentity();

glTranslatef(0.0f, .05f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
int i2;
GLfloat x2=-.8f; GLfloat y2=.8f; GLfloat radius2 =.05f;
int triangleAmount2 = 30;

GLfloat twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.85f; y2=.85f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.87f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.77f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.75f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.75f; y2=.88f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glLoadIdentity();

glTranslatef(1.f, .05f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.8f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.85f; y2=.85f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.87f; y2=.8f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.77f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.75f; y2=.82f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(222, 224, 227);
i2;
x2=-.75f; y2=.88f; radius2 =.05f;
triangleAmount2 = 30;

twicePi2 = 2.0f * PI;
glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2;i2++)
    {
        glVertex2f
        (
                x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
glEnd();

glLoadIdentity();
//end cloud
//birds
glPushMatrix();
glTranslatef(position_bird,0.0f, 0.0f);

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-0.6f,0.7f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.56f,0.7f);
glEnd();

glTranslatef(0.1f, 0.1f, 0.0f);

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-0.6f,0.7f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.56f,0.7f);
glEnd();

glLoadIdentity();
glTranslatef(position_bird,0.0f, 0.0f);

glTranslatef(0.11f, 0.05f, 0.0f);

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-0.6f,0.7f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.56f,0.7f);
glEnd();

glLoadIdentity();
glTranslatef(position_bird,0.0f, 0.0f);

glTranslatef(1.0f, 0.05f, 0.0f);

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-0.6f,0.7f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.56f,0.7f);
glEnd();

glLoadIdentity();
glTranslatef(position_bird,0.0f, 0.0f);

glTranslatef(1.1f, 0.05f, 0.0f);

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-0.6f,0.7f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.59f,0.68f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.58f,0.7f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.57f,0.68f);
glVertex2f(-0.56f,0.7f);
glEnd();

glPopMatrix();

glLoadIdentity();

//birds end

//starting buildings structure

glTranslatef(0.0f,0.1f, 0.0f);
//2nd left side building
    glBegin(GL_QUADS);
    glColor3ub(0, 78, 102);
    glVertex2f(-0.92f,0.3f);
    glVertex2f(-0.92f,0.5f);
    glVertex2f(-0.95f,0.5f);
    glVertex2f(-0.95f,0.3f);
    glEnd();




    glBegin(GL_POLYGON);
    glColor3ub(0, 153, 204);
    glVertex2f(-0.55f,-0.5f);
    glVertex2f(-0.55f,0.5f);
    glVertex2f(-0.92f,0.5f);
    glVertex2f(-0.92f,0.3f);
    glVertex2f(-0.8f,0.3f);
    glVertex2f(-0.8f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(242, 242, 242);

    glVertex2f(-0.6f,0.5f);
    glVertex2f(-0.6f,-0.35f);

    glVertex2f(-0.65f,0.5f);
    glVertex2f(-0.65f,-0.35f);

    glVertex2f(-0.7f,0.5f);
    glVertex2f(-0.7f,-0.35f);

    glVertex2f(-0.75f,0.5f);
    glVertex2f(-0.75f,-0.35f);

    glVertex2f(-0.8f,0.5f);
    glVertex2f(-0.8f,0.3f);

        glVertex2f(-0.85f,0.5f);
    glVertex2f(-0.85f,0.3f);

    glEnd();


    //1st left side building

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(-0.8f,-0.5f);
    glVertex2f(-0.8f,0.3f);
    glVertex2f(-1.0f,0.3f);
    glVertex2f(-1.0f,-0.5f);
    glEnd();

   glPointSize(2);
   glBegin(GL_POINTS);
   glColor3ub(0,0,0);
   glVertex2f(-0.95f,0.26f);
   glVertex2f(-0.9f,0.26f);
   glVertex2f(-0.85f,0.26f);

   glVertex2f(-0.95f,0.2f);
   glVertex2f(-0.9f,0.2f);
   glVertex2f(-0.85f,0.2f);

   glVertex2f(-0.95f,0.14f);
   glVertex2f(-0.9f,0.14f);
   glVertex2f(-0.85f,0.14f);

   glVertex2f(-0.95f,0.08f);
   glVertex2f(-0.9f,0.08f);
   glVertex2f(-0.85f,0.08f);

   glVertex2f(-0.95f,0.02f);
   glVertex2f(-0.9f,0.02f);
   glVertex2f(-0.85f,0.02f);

   glVertex2f(-0.95f,-0.04f);
   glVertex2f(-0.9f,-0.04f);
   glVertex2f(-0.85f,-0.04f);

   glVertex2f(-0.95f,-0.1f);
   glVertex2f(-0.9f,-0.1f);
   glVertex2f(-0.85f,-0.1f);

   glVertex2f(-0.95f,-0.16f);
   glVertex2f(-0.9f,-0.16f);
   glVertex2f(-0.85f,-0.16f);

   glVertex2f(-0.95f,-0.22f);
   glVertex2f(-0.9f,-0.22);
   glVertex2f(-0.85f,-0.22f);

    glVertex2f(-0.95f,-0.28f);
   glVertex2f(-0.9f,-0.28);
   glVertex2f(-0.85f,-0.28f);

    glVertex2f(-0.95f,-0.34f);
   glVertex2f(-0.9f,-0.34);
   glVertex2f(-0.85f,-0.34f);

    glVertex2f(-0.95f,-0.4f);
   glVertex2f(-0.9f,-0.4);
   glVertex2f(-0.85f,-0.4f);


   glEnd();

//3rd building front light ash

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-0.35f,-0.5f);
    glVertex2f(-0.35f,0.2f);
    glVertex2f(-0.55f,0.2f);
    glVertex2f(-0.55f,-0.5f);
    glEnd();


//4th building 1st black building from left side

   glTranslatef(-1.01f,-0.35f, 0.0f);
   glScalef(-0.7,0.3,0);
   glBegin(GL_QUADS);
   glColor3ub(89, 89, 89);
   glVertex2f(-0.32f,-0.5f);
   glVertex2f(-0.32f,0.1f);
   glVertex2f(-0.8f,0.1f);
   glVertex2f(-0.8f,-0.5f);
   glEnd();

   glPointSize(3);
   glBegin(GL_POINTS);
   glColor3ub(230, 230, 230);
   glVertex2f(-0.72f,-0.1f);
   glVertex2f(-0.62f,-0.1f);
   glVertex2f(-0.52f,-0.1f);
   glVertex2f(-0.42f,-0.1f);

     glVertex2f(-0.72f,-0.29f);
   glVertex2f(-0.62f,-0.29f);
   glVertex2f(-0.52f,-0.29f);
   glVertex2f(-0.42f,-0.29f);

   glEnd();

//5th building 2nd black building

   glLoadIdentity();
   glTranslatef(0.0f,0.1f, 0.0f);
   glBegin(GL_POLYGON);
   glColor3ub(89, 89, 89);
   glVertex2f(0.0f,-0.5f);
   glVertex2f(0.0f,0.2f);
   glVertex2f(-0.1f,0.2f);
   glVertex2f(-0.2f,0.2f);
   glVertex2f(-0.4f,0.1f);
   glVertex2f(-0.4f,-0.5f);

   glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex2f(0.22f,-0.5f);
    glVertex2f(0.22f,0.45f);
    glVertex2f(0.01f,0.48f);
    glVertex2f(0.0f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.03f,0.47f);
    glVertex2f(0.03f,0.54f);

    glVertex2f(0.04f,0.47f);
    glVertex2f(0.04f,0.54f);

    glVertex2f(0.05f,0.47f);
    glVertex2f(0.05f,0.54f);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
    glPointSize(3);
   glBegin(GL_POINTS);
   glColor3ub(230, 230, 230);
   glVertex2f(-0.08f,0.17f);
   glVertex2f(-0.16f,0.17f);
   glVertex2f(-0.24f,0.17f);


    glVertex2f(-0.08f,0.1f);
   glVertex2f(-0.16f,0.1f);
   glVertex2f(-0.24f,0.1f);
   glVertex2f(-0.32f,0.1f);

   glVertex2f(-0.08f,0.03f);
   glVertex2f(-0.16f,0.03f);
   glVertex2f(-0.24f,0.03f);
   glVertex2f(-0.32f,0.03f);

   glVertex2f(-0.08f,-0.05f);
   glVertex2f(-0.16f,-0.05f);
   glVertex2f(-0.24f,-0.05f);
   glVertex2f(-0.32f,-0.05f);

   glVertex2f(-0.08f,-0.12f);
   glVertex2f(-0.16f,-0.12f);
   glVertex2f(-0.24f,-0.12f);
   glVertex2f(-0.32f,-0.12f);

   glVertex2f(-0.08f,-0.19f);
   glVertex2f(-0.16f,-0.19f);
   glVertex2f(-0.24f,-0.19f);
   glVertex2f(-0.32f,-0.19f);

   glVertex2f(-0.08f,-0.26f);
   glVertex2f(-0.16f,-0.26f);
   glVertex2f(-0.24f,-0.26f);
   glVertex2f(-0.32f,-0.26f);

   glVertex2f(-0.08f,-0.33f);
   glVertex2f(-0.16f,-0.33f);
   glVertex2f(-0.24f,-0.33f);
   glVertex2f(-0.32f,-0.33f);

   glVertex2f(-0.08f,-0.4f);
   glVertex2f(-0.16f,-0.4f);
   glVertex2f(-0.24f,-0.4f);
   glVertex2f(-0.32f,-0.4f);

   glEnd();





//BLUE BUILDING

   glBegin(GL_POLYGON);
   glColor3ub(77, 255, 255);
   glVertex2f(0.45f,-0.5f);
   glVertex2f(0.45f,0.5f);
   glVertex2f(0.25f,0.5f);
   glVertex2f(0.25,-0.3f);
   glVertex2f(0.2f,-0.3f);
   glVertex2f(0.2f,-0.5f);
   glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 230, 230);
    glVertex2f(0.45f,0.5f);
    glVertex2f(0.25f,0.5f);
    glVertex2f(0.25f,0.47f);
    glVertex2f(0.45f,0.47f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f,-0.3f);
    glVertex2f(0.45f,-0.3f);

    glVertex2f(0.25f,0.45f);
    glVertex2f(0.45f,0.45f);

    glVertex2f(0.25f,0.42f);
    glVertex2f(0.45f,0.42f);

    glVertex2f(0.25f,0.39f);
    glVertex2f(0.45f,0.39f);

    glVertex2f(0.25f,0.36f);
    glVertex2f(0.45f,0.36f);

    glVertex2f(0.25f,0.33f);
    glVertex2f(0.45f,0.33f);

    glVertex2f(0.25f,0.30f);
    glVertex2f(0.45f,0.30f);

    glVertex2f(0.25f,0.27f);
    glVertex2f(0.45f,0.27f);

    glVertex2f(0.25f,0.24f);
    glVertex2f(0.45f,0.24f);

    glVertex2f(0.25f,0.21f);
    glVertex2f(0.45f,0.21f);

    glVertex2f(0.25f,0.18f);
    glVertex2f(0.45f,0.18f);

    glVertex2f(0.25f,0.15f);
    glVertex2f(0.45f,0.15f);

    glVertex2f(0.25f,0.12f);
    glVertex2f(0.45f,0.12f);

    glVertex2f(0.25f,0.09f);
    glVertex2f(0.45f,0.09f);

    glVertex2f(0.25f,0.06f);
    glVertex2f(0.45f,0.06f);

    glVertex2f(0.25f,0.03f);
    glVertex2f(0.45f,0.03f);

    glVertex2f(0.25f,0.0f);
    glVertex2f(0.45f,0.0f);

    glVertex2f(0.25f,-0.03f);
    glVertex2f(0.45f,-0.03f);

    glVertex2f(0.25f,-0.06f);
    glVertex2f(0.45f,-0.06f);

    glVertex2f(0.25f,-0.09f);
    glVertex2f(0.45f,-0.09f);

    glVertex2f(0.25f,-0.12f);
    glVertex2f(0.45f,-0.12f);


    glVertex2f(0.25f,-0.30f);
    glVertex2f(0.45f,-0.30f);

    glVertex2f(0.25f,-0.27f);
    glVertex2f(0.45f,-0.27f);

    glVertex2f(0.25f,-0.24f);
    glVertex2f(0.45f,-0.24f);

    glVertex2f(0.25f,-0.21f);
    glVertex2f(0.45f,-0.21f);

    glVertex2f(0.25f,-0.18f);
    glVertex2f(0.45f,-0.18f);

    glVertex2f(0.25f,-0.15f);
    glVertex2f(0.45f,-0.15f);

    glEnd();


     glBegin(GL_QUADS);
     glVertex2f(0.25f,-0.5f);
     glVertex2f(0.25f,-0.4f);
     glVertex2f(0.28f,-0.4f);
     glVertex2f(0.28f,-0.5f);
     glEnd();





      glLoadIdentity();
      glTranslatef(0.0f,0.1f, 0.0f);
      glTranslatef(0.1,0,0);
     glBegin(GL_QUADS);
     glVertex2f(0.25f,-0.5f);
     glVertex2f(0.25f,-0.4f);
     glVertex2f(0.28f,-0.4f);
     glVertex2f(0.28f,-0.5f);
     glEnd();


     glLoadIdentity();
     glTranslatef(0.0f,0.1f, 0.0f);
     glBegin(GL_QUADS);
     glVertex2f(0.45f,-0.3f);
     glVertex2f(0.2f,-0.3f);
     glVertex2f(0.2f,-0.37f);
     glVertex2f(0.45f,-0.37f);
     glEnd();

//blue building end



    glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(0.67f,-0.5f);
    glVertex2f(0.67f,0.5f);
    glVertex2f(0.48f,0.3f);
    glVertex2f(0.48f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.74f,-0.5f);
    glVertex2f(0.71f,0.5f);
    glVertex2f(0.67f,-0.5f);
    glEnd();


       glTranslatef(0,-0.2,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();


    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
     glTranslatef(0,-0.4,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();


     glLoadIdentity();
     glTranslatef(0.0f,0.1f, 0.0f);
     glTranslatef(0,-0.6,0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();

       glLoadIdentity();
       glTranslatef(0.0f,0.1f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.79f,0.3f);
     glVertex2f(0.67f,0.3f);
     glVertex2f(0.67f,0.27f);
     glVertex2f(0.79f,0.27f);
    glEnd();





    glLoadIdentity();
    glTranslatef(0.0f,0.1f, 0.0f);
    glTranslatef(0.26,0,0);
    glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(0.67f,-0.5f);
    glVertex2f(0.67f,0.3f);
    glVertex2f(0.48f,0.5f);
    glVertex2f(0.48f,-0.5f);
    glEnd();

    glLoadIdentity();


    //Building start
glTranslatef(0.8f, -0.7f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(0, 85, 255);
    glVertex2f(-.98,0.3);
    glVertex2f(-0.8,0.3);
    glVertex2f(-0.8,0.9);
    glVertex2f(-.98,0.9);
    glColor3ub(0, 230, 230);
    glVertex2f(-0.8,0.32);
    glVertex2f(-0.7,0.32);
    glVertex2f(-0.7,0.87);
    glVertex2f(-0.8,0.87);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.35);
    glVertex2f(-0.9,0.35);
    glVertex2f(-0.9,0.45);
    glVertex2f(-.96,0.45);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.35);
    glVertex2f(-0.84,0.35);
    glVertex2f(-0.84,0.45);
    glVertex2f(-.87,0.45);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.53);
    glVertex2f(-0.9,0.53);
    glVertex2f(-0.9,0.63);
    glVertex2f(-.96,0.63);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.53);
    glVertex2f(-0.84,0.53);
    glVertex2f(-0.84,0.63);
    glVertex2f(-.87,0.63);

    glColor3ub(0, 0, 0);
    glVertex2f(-.96,0.73);
    glVertex2f(-0.9,0.73);
    glVertex2f(-0.9,0.83);
    glVertex2f(-.96,0.83);

    glColor3ub(0, 0, 0);
    glVertex2f(-.87,0.73);
    glVertex2f(-0.84,0.73);
    glVertex2f(-0.84,0.83);
    glVertex2f(-.87,0.83);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.37);
    glVertex2f(-0.73,0.37);
    glVertex2f(-0.73,0.47);
    glVertex2f(-.77,0.47);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.52);
    glVertex2f(-0.73,0.52);
    glVertex2f(-0.73,0.62);
    glVertex2f(-.77,0.62);

    glColor3ub(102, 0, 0);
    glVertex2f(-.77,0.67);
    glVertex2f(-0.73,0.67);
    glVertex2f(-0.73,0.77);
    glVertex2f(-.77,0.77);
glEnd();
glLoadIdentity();

//building end

glTranslatef(0.0f, -0.433f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(51, 51, 51);
glVertex2f(-1.0f,0.0f);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,0.05f);
glVertex2f(-1.0f,0.05f);
glEnd();

glLoadIdentity();

glTranslatef(0.0f, 0.023f, 0.0f);

    //rail line

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-1.0f,-0.5f);
glVertex2f(1.0f,0.-0.5f);
glEnd();

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(-1.0f,-0.46f);
glVertex2f(1.0f,0.-0.46f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.01f,-0.46f);
glVertex2f(-0.02f,-0.46f);
glVertex2f(-0.03f,-0.5f);
glVertex2f(-0.02f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.03f,-0.46f);
glVertex2f(-0.04f,-0.46f);
glVertex2f(-0.05f,-0.5f);
glVertex2f(-0.04f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.05f,-0.46f);
glVertex2f(-0.06f,-0.46f);
glVertex2f(-0.07f,-0.5f);
glVertex2f(-0.06f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.07f,-0.46f);
glVertex2f(-0.08f,-0.46f);
glVertex2f(-0.09f,-0.5f);
glVertex2f(-0.08f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.09f,-0.46f);
glVertex2f(-0.1f,-0.46f);
glVertex2f(-0.11f,-0.5f);
glVertex2f(-0.1f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.11f,-0.46f);
glVertex2f(-0.12f,-0.46f);
glVertex2f(-0.13f,-0.5f);
glVertex2f(-0.12f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.13f,-0.46f);
glVertex2f(-0.14f,-0.46f);
glVertex2f(-0.15f,-0.5f);
glVertex2f(-0.14f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.15f,-0.46f);
glVertex2f(-0.16f,-0.46f);
glVertex2f(-0.17f,-0.5f);
glVertex2f(-0.16f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.17f,-0.46f);
glVertex2f(-0.18f,-0.46f);
glVertex2f(-0.19f,-0.5f);
glVertex2f(-0.18f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.19f,-0.46f);
glVertex2f(-0.20f,-0.46f);
glVertex2f(-0.21f,-0.5f);
glVertex2f(-0.20f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.21f,-0.46f);
glVertex2f(-0.22f,-0.46f);
glVertex2f(-0.23f,-0.5f);
glVertex2f(-0.22f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.23f,-0.46f);
glVertex2f(-0.24f,-0.46f);
glVertex2f(-0.25f,-0.5f);
glVertex2f(-0.24f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.25f,-0.46f);
glVertex2f(-0.26f,-0.46f);
glVertex2f(-0.27f,-0.5f);
glVertex2f(-0.26f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.27f,-0.46f);
glVertex2f(-0.28f,-0.46f);
glVertex2f(-0.29f,-0.5f);
glVertex2f(-0.28f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.29f,-0.46f);
glVertex2f(-0.3f,-0.46f);
glVertex2f(-0.31f,-0.5f);
glVertex2f(-0.3f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.31f,-0.46f);
glVertex2f(-0.32f,-0.46f);
glVertex2f(-0.33f,-0.5f);
glVertex2f(-0.32f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.33f,-0.46f);
glVertex2f(-0.34f,-0.46f);
glVertex2f(-0.35f,-0.5f);
glVertex2f(-0.34f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.35f,-0.46f);
glVertex2f(-0.36f,-0.46f);
glVertex2f(-0.37f,-0.5f);
glVertex2f(-0.36f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.37f,-0.46f);
glVertex2f(-0.38f,-0.46f);
glVertex2f(-0.39f,-0.5f);
glVertex2f(-0.38f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.39f,-0.46f);
glVertex2f(-0.4f,-0.46f);
glVertex2f(-0.41f,-0.5f);
glVertex2f(-0.4f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.41f,-0.46f);
glVertex2f(-0.42f,-0.46f);
glVertex2f(-0.43f,-0.5f);
glVertex2f(-0.42f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.43f,-0.46f);
glVertex2f(-0.44f,-0.46f);
glVertex2f(-0.45f,-0.5f);
glVertex2f(-0.44f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.45f,-0.46f);
glVertex2f(-0.46f,-0.46f);
glVertex2f(-0.47f,-0.5f);
glVertex2f(-0.46f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.47f,-0.46f);
glVertex2f(-0.48f,-0.46f);
glVertex2f(-0.49f,-0.5f);
glVertex2f(-0.48f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.49f,-0.46f);
glVertex2f(-0.5f,-0.46f);
glVertex2f(-0.51f,-0.5f);
glVertex2f(-0.5f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.51f,-0.46f);
glVertex2f(-0.52f,-0.46f);
glVertex2f(-0.53f,-0.5f);
glVertex2f(-0.52f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.53f,-0.46f);
glVertex2f(-0.54f,-0.46f);
glVertex2f(-0.55f,-0.5f);
glVertex2f(-0.54f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.55f,-0.46f);
glVertex2f(-0.56f,-0.46f);
glVertex2f(-0.57f,-0.5f);
glVertex2f(-0.56f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.57f,-0.46f);
glVertex2f(-0.58f,-0.46f);
glVertex2f(-0.59f,-0.5f);
glVertex2f(-0.58f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.59f,-0.46f);
glVertex2f(-0.6f,-0.46f);
glVertex2f(-0.61f,-0.5f);
glVertex2f(-0.6f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.61f,-0.46f);
glVertex2f(-0.62f,-0.46f);
glVertex2f(-0.63f,-0.5f);
glVertex2f(-0.62f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.63f,-0.46f);
glVertex2f(-0.64f,-0.46f);
glVertex2f(-0.65f,-0.5f);
glVertex2f(-0.64f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.65f,-0.46f);
glVertex2f(-0.66f,-0.46f);
glVertex2f(-0.67f,-0.5f);
glVertex2f(-0.66f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.67f,-0.46f);
glVertex2f(-0.68f,-0.46f);
glVertex2f(-0.69f,-0.5f);
glVertex2f(-0.68f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.69f,-0.46f);
glVertex2f(-0.7f,-0.46f);
glVertex2f(-0.71f,-0.5f);
glVertex2f(-0.7f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.71f,-0.46f);
glVertex2f(-0.72f,-0.46f);
glVertex2f(-0.73f,-0.5f);
glVertex2f(-0.72f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.73f,-0.46f);
glVertex2f(-0.74f,-0.46f);
glVertex2f(-0.75f,-0.5f);
glVertex2f(-0.74f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.75f,-0.46f);
glVertex2f(-0.76f,-0.46f);
glVertex2f(-0.77f,-0.5f);
glVertex2f(-0.76f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.77f,-0.46f);
glVertex2f(-0.78f,-0.46f);
glVertex2f(-0.79f,-0.5f);
glVertex2f(-0.78f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.79f,-0.46f);
glVertex2f(-0.8f,-0.46f);
glVertex2f(-0.81f,-0.5f);
glVertex2f(-0.8f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.81f,-0.46f);
glVertex2f(-0.82f,-0.46f);
glVertex2f(-0.83f,-0.5f);
glVertex2f(-0.82f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.83f,-0.46f);
glVertex2f(-0.84f,-0.46f);
glVertex2f(-0.85f,-0.5f);
glVertex2f(-0.84f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.85f,-0.46f);
glVertex2f(-0.86f,-0.46f);
glVertex2f(-0.87f,-0.5f);
glVertex2f(-0.86f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.87f,-0.46f);
glVertex2f(-0.88f,-0.46f);
glVertex2f(-0.89f,-0.5f);
glVertex2f(-0.88f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.89f,-0.46f);
glVertex2f(-0.9f,-0.46f);
glVertex2f(-0.91f,-0.5f);
glVertex2f(-0.9f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.91f,-0.46f);
glVertex2f(-0.92f,-0.46f);
glVertex2f(-0.93f,-0.5f);
glVertex2f(-0.92f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.93f,-0.46f);
glVertex2f(-0.94f,-0.46f);
glVertex2f(-0.95f,-0.5f);
glVertex2f(-0.94f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.95f,-0.46f);
glVertex2f(-0.96f,-0.46f);
glVertex2f(-0.97f,-0.5f);
glVertex2f(-0.96f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.97f,-0.46f);
glVertex2f(-0.98f,-0.46f);
glVertex2f(-0.99f,-0.5f);
glVertex2f(-0.98f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.01f,-0.46f);
glVertex2f(0.0f,-0.46f);
glVertex2f(-0.01f,-0.5f);
glVertex2f(0.0f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.03f,-0.46f);
glVertex2f(0.02f,-0.46f);
glVertex2f(0.01f,-0.5f);
glVertex2f(0.02f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.05f,-0.46f);
glVertex2f(0.04f,-0.46f);
glVertex2f(0.03f,-0.5f);
glVertex2f(0.04f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.07f,-0.46f);
glVertex2f(0.06f,-0.46f);
glVertex2f(0.05f,-0.5f);
glVertex2f(0.06f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.09f,-0.46f);
glVertex2f(0.08f,-0.46f);
glVertex2f(0.07f,-0.5f);
glVertex2f(0.08f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.11f,-0.46f);
glVertex2f(0.1f,-0.46f);
glVertex2f(0.09f,-0.5f);
glVertex2f(0.1f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.13f,-0.46f);
glVertex2f(0.12f,-0.46f);
glVertex2f(0.11f,-0.5f);
glVertex2f(0.12f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.15f,-0.46f);
glVertex2f(0.14f,-0.46f);
glVertex2f(0.13f,-0.5f);
glVertex2f(0.14f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.17f,-0.46f);
glVertex2f(0.16f,-0.46f);
glVertex2f(0.15f,-0.5f);
glVertex2f(0.16f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.19f,-0.46f);
glVertex2f(0.18f,-0.46f);
glVertex2f(0.17f,-0.5f);
glVertex2f(0.18f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.21f,-0.46f);
glVertex2f(0.2f,-0.46f);
glVertex2f(0.19f,-0.5f);
glVertex2f(0.2f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.23f,-0.46f);
glVertex2f(0.22f,-0.46f);
glVertex2f(0.21f,-0.5f);
glVertex2f(0.22f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.25f,-0.46f);
glVertex2f(0.24f,-0.46f);
glVertex2f(0.23f,-0.5f);
glVertex2f(0.24f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.27f,-0.46f);
glVertex2f(0.26f,-0.46f);
glVertex2f(0.25f,-0.5f);
glVertex2f(0.26f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.29f,-0.46f);
glVertex2f(0.28f,-0.46f);
glVertex2f(0.27f,-0.5f);
glVertex2f(0.28f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.31f,-0.46f);
glVertex2f(0.3f,-0.46f);
glVertex2f(0.29f,-0.5f);
glVertex2f(0.3f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.33f,-0.46f);
glVertex2f(0.32f,-0.46f);
glVertex2f(0.31f,-0.5f);
glVertex2f(0.32f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.35f,-0.46f);
glVertex2f(0.34f,-0.46f);
glVertex2f(0.33f,-0.5f);
glVertex2f(0.34f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.37f,-0.46f);
glVertex2f(0.36f,-0.46f);
glVertex2f(0.35f,-0.5f);
glVertex2f(0.36f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.39f,-0.46f);
glVertex2f(0.38f,-0.46f);
glVertex2f(0.37f,-0.5f);
glVertex2f(0.38f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.41f,-0.46f);
glVertex2f(0.4f,-0.46f);
glVertex2f(0.39f,-0.5f);
glVertex2f(0.4f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.43f,-0.46f);
glVertex2f(0.42f,-0.46f);
glVertex2f(0.41f,-0.5f);
glVertex2f(0.42f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.45f,-0.46f);
glVertex2f(0.44f,-0.46f);
glVertex2f(0.43f,-0.5f);
glVertex2f(0.44f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.47f,-0.46f);
glVertex2f(0.46f,-0.46f);
glVertex2f(0.45f,-0.5f);
glVertex2f(0.46f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.49f,-0.46f);
glVertex2f(0.48f,-0.46f);
glVertex2f(0.47f,-0.5f);
glVertex2f(0.48f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.51f,-0.46f);
glVertex2f(0.5f,-0.46f);
glVertex2f(0.49f,-0.5f);
glVertex2f(0.5f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.53f,-0.46f);
glVertex2f(0.52f,-0.46f);
glVertex2f(0.51f,-0.5f);
glVertex2f(0.52f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.55f,-0.46f);
glVertex2f(0.54f,-0.46f);
glVertex2f(0.53f,-0.5f);
glVertex2f(0.54f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.57f,-0.46f);
glVertex2f(0.56f,-0.46f);
glVertex2f(0.55f,-0.5f);
glVertex2f(0.56f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.59f,-0.46f);
glVertex2f(0.58f,-0.46f);
glVertex2f(0.57f,-0.5f);
glVertex2f(0.58f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.61f,-0.46f);
glVertex2f(0.6f,-0.46f);
glVertex2f(0.59f,-0.5f);
glVertex2f(0.6f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.63f,-0.46f);
glVertex2f(0.62f,-0.46f);
glVertex2f(0.61f,-0.5f);
glVertex2f(0.62f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.65f,-0.46f);
glVertex2f(0.64f,-0.46f);
glVertex2f(0.63f,-0.5f);
glVertex2f(0.64f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.67f,-0.46f);
glVertex2f(0.66f,-0.46f);
glVertex2f(0.65f,-0.5f);
glVertex2f(0.66f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.69f,-0.46f);
glVertex2f(0.68f,-0.46f);
glVertex2f(0.67f,-0.5f);
glVertex2f(0.68f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.71f,-0.46f);
glVertex2f(0.7f,-0.46f);
glVertex2f(0.69f,-0.5f);
glVertex2f(0.7f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.73f,-0.46f);
glVertex2f(0.72f,-0.46f);
glVertex2f(0.71f,-0.5f);
glVertex2f(0.72f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.75f,-0.46f);
glVertex2f(0.74f,-0.46f);
glVertex2f(0.73f,-0.5f);
glVertex2f(0.74f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.77f,-0.46f);
glVertex2f(0.76f,-0.46f);
glVertex2f(0.75f,-0.5f);
glVertex2f(0.76f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.79f,-0.46f);
glVertex2f(0.78f,-0.46f);
glVertex2f(0.77f,-0.5f);
glVertex2f(0.78f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.81f,-0.46f);
glVertex2f(0.8f,-0.46f);
glVertex2f(0.79f,-0.5f);
glVertex2f(0.8f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.83f,-0.46f);
glVertex2f(0.82f,-0.46f);
glVertex2f(0.81f,-0.5f);
glVertex2f(0.82f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.85f,-0.46f);
glVertex2f(0.84f,-0.46f);
glVertex2f(0.83f,-0.5f);
glVertex2f(0.84f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.87f,-0.46f);
glVertex2f(0.86f,-0.46f);
glVertex2f(0.85f,-0.5f);
glVertex2f(0.86f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.89f,-0.46f);
glVertex2f(0.88f,-0.46f);
glVertex2f(0.87f,-0.5f);
glVertex2f(0.88f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.91f,-0.46f);
glVertex2f(0.9f,-0.46f);
glVertex2f(0.89f,-0.5f);
glVertex2f(0.9f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.93f,-0.46f);
glVertex2f(0.92f,-0.46f);
glVertex2f(0.91f,-0.5f);
glVertex2f(0.92f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.95f,-0.46f);
glVertex2f(0.94f,-0.46f);
glVertex2f(0.93f,-0.5f);
glVertex2f(0.94f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.97f,-0.46f);
glVertex2f(0.96f,-0.46f);
glVertex2f(0.95f,-0.5f);
glVertex2f(0.96f,-0.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.99f,-0.46f);
glVertex2f(0.98f,-0.46f);
glVertex2f(0.97f,-0.5f);
glVertex2f(0.98f,-0.5f);
glEnd();

glLoadIdentity();

//train

glPushMatrix();
glTranslatef(position_train,0.0f, 0.0f);


glTranslatef(0.0f, 0.023f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.5f,-0.48f);
glVertex2f(-0.5f,-0.3f);
glVertex2f(-0.55f,-0.3f);
glVertex2f(-0.6f,-0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.11f,-0.48f);
glVertex2f(-0.11f,-0.2f);
glVertex2f(-0.5f,-0.2f);
glVertex2f(-0.5f,-0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glTranslatef(0.08f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.16f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.24f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.32f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

   glLoadIdentity();
   glTranslatef(position_train,0.0f, 0.0f);
   glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int i;
x=-.42f; y=-.45f; radius =.05f;
triangleAmount = 200;
twicePi = 2.0f * PI;
glVertex2f(x, y);
for(i = 0; i <= triangleAmount;i++)
{
    glVertex2f
    (
        x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i7;
x7=-.42f; y7=-.45f; radius7 =.04f;
triangleAmount7 = 200;
twicePi7 = 2.0f * PI;
glVertex2f(x7, y7);
for(i7 = 0; i7 <= triangleAmount7;i7++)
{
    glVertex2f
    (
        x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)), y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
i;
x=-.2f; y=-.45f; radius =.05f;
triangleAmount = 200;
twicePi = 2.0f * PI;
glVertex2f(x, y);
for(i = 0; i <= triangleAmount;i++)
{
    glVertex2f
    (
        x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i8;
x8=-.2f; y8=-.45f; radius8 =.04f;
triangleAmount8 = 200;
twicePi8 = 2.0f * PI;
glVertex2f(x8, y8);
for(i8 = 0; i8 <= triangleAmount8;i8++)
{
    glVertex2f
    (
        x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)), y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
    );
}
glEnd();



glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(-0.1f,-0.48f);
glVertex2f(0.28f,-0.48f);
glVertex2f(0.28f,-0.2f);
glVertex2f(-0.1f,-0.2f);
glEnd();

glTranslatef(0.41f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.49f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.57f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.65f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.725f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int i1;
GLfloat x1=-.02f; GLfloat y1=-.45f; GLfloat radius1 =.05f;
int triangleAmount1 = 200;
GLfloat twicePi1 = 2.0f * PI;
glVertex2f(x1, y1);
for(i1 = 0; i1 <= triangleAmount1;i1++)
{
    glVertex2f
    (
        x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)), y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i9;
x9=-.02f;  y9=-.45f;  radius9 =.04f;
 triangleAmount9 = 200;
 twicePi9 = 2.0f * PI;
glVertex2f(x9, y9);
for(i9 = 0; i9 <= triangleAmount9;i9++)
{
    glVertex2f
    (
        x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)), y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int k;
GLfloat u=.2f; GLfloat v=-.45f; GLfloat radius6 =.05f;
int triangleAmount6 = 200;
GLfloat twicePi6 = 2.0f * PI;
glVertex2f(u, v);
for(k = 0; k <= triangleAmount6;k++)
{
    glVertex2f
    (
        u + (radius6 * cos(k *  twicePi6 / triangleAmount6)), v + (radius6 * sin(k * twicePi6 / triangleAmount6))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i11;
GLfloat x11=.2f; GLfloat y11=-.45f; GLfloat radius11 =.04f;
int triangleAmount11 = 200;
GLfloat twicePi11 = 2.0f * PI;
glVertex2f(x11, y11);
for(i11 = 0; i11 <= triangleAmount11;i11++)
{
    glVertex2f
    (
        x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)), y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
    );
}
glEnd();

glBegin(GL_QUADS);
glColor3ub(41, 38, 54);
glVertex2f(0.29f,-0.48f);
glVertex2f(0.68f,-0.48f);
glVertex2f(0.68f,-0.2f);
glVertex2f(0.29f,-0.2f);
glEnd();

glTranslatef(0.80f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(0.88f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glTranslatef(0.96f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(1.04f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);
glTranslatef(1.12f, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(206, 213, 237);
glVertex2f(-0.5f,-0.28f);
glVertex2f(-0.5f,-0.32f);
glVertex2f(-0.45f,-0.32f);
glVertex2f(-0.45f,-0.28f);
glEnd();

glLoadIdentity();
glTranslatef(position_train,0.0f, 0.0f);
glTranslatef(0.0f, 0.023f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int r;
GLfloat s=.38f; GLfloat t=-.45f; GLfloat radius3 =.05f;
int triangleAmount3 = 200;
GLfloat twicePi3 = 2.0f * PI;
glVertex2f(s, t);
for(r = 0; r <= triangleAmount3;r++)
{
    glVertex2f
    (
        s + (radius3 * cos(r *  twicePi3 / triangleAmount3)), t + (radius3 * sin(r * twicePi3 / triangleAmount3))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i22;
GLfloat x22=.38f; GLfloat y22=-.45f; GLfloat radius22 =.04f;
int triangleAmount22 = 200;
GLfloat twicePi22 = 2.0f * PI;
glVertex2f(x22, y22);
for(i22 = 0; i22 <= triangleAmount;i22++)
{
    glVertex2f
    (
        x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)), y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(255,255,255);
int r1;
GLfloat s1=.6f; GLfloat t1=-.45f; GLfloat radius4 =.05f;
int triangleAmount4 = 200;
GLfloat twicePi4 = 2.0f * PI;
glVertex2f(s1, t1);
for(r1 = 0; r1 <= triangleAmount4;r1++)
{
    glVertex2f
    (
        s1 + (radius4 * cos(r1 *  twicePi4 / triangleAmount4)), t1 + (radius4 * sin(r1 * twicePi4 / triangleAmount4))
    );
}
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(0,0,0);
int i33;
GLfloat x33=.6f; GLfloat y33=-.45f; GLfloat radius33 =.04f;
int triangleAmount33 = 200;
GLfloat twicePi33 = 2.0f * PI;
glVertex2f(x33, y33);
for(i33 = 0; i33 <= triangleAmount33;i33++)
{
    glVertex2f
    (
        x33 + (radius33 * cos(i33 *  twicePi33 / triangleAmount33)), y33 + (radius33* sin(i33 * twicePi33 / triangleAmount33))
    );
}
glEnd();


glPopMatrix();



    glLoadIdentity();





    //road
    glBegin(GL_QUADS);
    glColor3ub(51, 51, 51);

    glVertex2f(-1,-.5);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.5);

    glEnd();
//road's middle lines
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();

    //copying road's middle line
    //1
    glTranslatef(.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //2
    glTranslatef(.4,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //3
    glTranslatef(.6,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //4
    glTranslatef(.8,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //5
    glTranslatef(1,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //left side
    //6
    glTranslatef(-.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //7
    glTranslatef(-.4,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //8
    glTranslatef(-.6,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //9
    glTranslatef(-.8,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //10
    glTranslatef(-1,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-.056,-.74);
    glVertex2f(-.05,-.76);
    glVertex2f(.05,-.76);
    glVertex2f(.044,-.74);
    glEnd();
    glLoadIdentity();

    //road upper side border
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(-1,-.48);
    glVertex2f(-1,-.5);
    glVertex2f(1,-.5);
    glVertex2f(1,-.48);
    glEnd();

    //Starting drawing light

    //road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light

//copy light 2
    glTranslatef(.45,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

    //copy light 3
     glTranslatef(.9,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

    //copy light 4
     glTranslatef(-.45,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

    //copy road light 5
     glTranslatef(-.9,0,0);
//road light foot
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 102);

    glVertex2f(-.015,-.48);
    glVertex2f(.015,-.48);
    glVertex2f(.015,-.46);
    glVertex2f(.01,-.45);
    glVertex2f(-.01,-.45);
    glVertex2f(-.015,-.46);
    glEnd();

    //road light stand
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);

    glVertex2f(.005,-.45);
    glVertex2f(.005,-.20);
    glVertex2f(-.005,-.20);
    glVertex2f(-.005,-.45);
    glEnd();

    //light lamp left part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.03,-.13);
    glVertex2f(-.08,-.13);
    glVertex2f(-.1,-.15);
    glVertex2f(-.03,-.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(-.005,-.20);
    glVertex2f(.0,-.20);
    glVertex2f(-.03,-.13);
    glVertex2f(-.03,-.15);
    glEnd();

    //lamp light right part
    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.1,-.15);
    glVertex2f(.08,-.13);
    glVertex2f(.03,-.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex2f(.03,-.15);
    glVertex2f(.03,-.13);
    glVertex2f(.0,-.20);
    glVertex2f(.005,-.20);
    glEnd();
//end 1st road light
    glLoadIdentity();

//new car
glPushMatrix();
glTranslatef(position_car2,0.0f, 0.0f);

glTranslatef(0.9f, 0.05f, 0.0f);
glScalef(2.0,1.8,0);

 glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.8f,-0.33f);
    glVertex2f(-0.8f,-0.30f);
    glVertex2f(-0.9f,-0.30f);
    glVertex2f(-0.9f,-0.33f);
    glEnd();

   glColor3ub(13, 13, 13);
    glBegin(GL_QUADS);
    glVertex2f(-0.82f,-0.30f);
    glVertex2f(-0.83f,-0.28f);
    glVertex2f(-0.87f,-0.28f);
    glVertex2f(-0.88f,-0.30f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.824f,-0.298f);
    glVertex2f(-0.832f,-0.282f);
    glVertex2f(-0.848f,-0.282f);
    glVertex2f(-0.848f,-0.298f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.851f,-0.298f);
    glVertex2f(-0.851f,-0.282f);
    glVertex2f(-0.868f,-0.282f);
    glVertex2f(-0.876f,-0.298f);
    glEnd();

     i;
    j;
    x = -0.82f; y = -0.33f; radius = 0.01f; GLfloat a = -0.88f; GLfloat b = -0.33f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

    glColor3ub(13, 13, 13);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)),y + (radius * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    glColor3ub(13, 13, 13);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a, b);
    for(j = 0; j <= triangleAmount;j++)
        {
            glVertex2f(a + (radius * cos(j *  twicePi / triangleAmount)),b + (radius * sin(j * twicePi / triangleAmount)));
        }
    glEnd();

glPopMatrix();

glLoadIdentity();

//end new car
//blue car
glPushMatrix();
glTranslatef(position_jip2,0.0f, 0.0f);

glScalef(-.4,.4,0);
glTranslatef(-0.4f, -1.4f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(26, 83, 255);
glVertex2f(-.23,.3);
glVertex2f(-.38,.06);
glVertex2f(.12,.06);
glVertex2f(.12,.3);

glColor3ub(26, 83, 255);
glVertex2f(-.38,.06);
glVertex2f(-.38,-.06);
glVertex2f(.12,-.06);
glVertex2f(.12,.06);

glColor3ub(26, 83, 255);
glVertex2f(.12,-.06);
glVertex2f(.2,-.06);
glVertex2f(.19,.06);
glVertex2f(.12,.06);

glColor3ub(26, 83, 255);
glVertex2f(.12,.3);
glVertex2f(.12,.06);
glVertex2f(.19,.06);
glVertex2f(.16,.2);

glColor3ub(13, 13, 13);
glVertex2f(-.2,.28);
glVertex2f(-.32,.11);
glVertex2f(.15,.11);
glVertex2f(.1,.28);

glEnd();
 i;
	 x=.1f;  y=-.05f;  radius =.06f;
	 triangleAmount = 20;
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
glEnd();
 j;
	 x1=-.23f;  y1=-.05f;  radius1 =.06f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f(
		            x1 + (radius1 * cos(j*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(j* twicePi1 / triangleAmount1))
			);
		}
glEnd();
 k;
	 x=.1f;  y=-.05f;  radius =.03f;
	 triangleAmount2 = 20;
	 twicePi2 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(k = 0; k <= triangleAmount2;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi2 / triangleAmount2)),
			    y + (radius * sin(k * twicePi2 / triangleAmount2))
			);
		}
glEnd();
int l;
	 x=-.23f;  y=-.05f;  radius =.03f;
	 triangleAmount3 = 20;
	 twicePi3 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(l = 0; l <= triangleAmount3;l++) {
			glVertex2f(
		            x + (radius3 * cos(l*  twicePi3 / triangleAmount3)),
			    y + (radius3 * sin(l* twicePi3 / triangleAmount3))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();

//end blue car

//red car
glPushMatrix();
glTranslatef(position_car3,0.0f, 0.0f);

    glScalef(-.5,.4,0);
glTranslatef(-1.7f, -1.5f, 0.0f);

    glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,0);
glVertex2f(.3,0.0);
glVertex2f(.3,.1);
glVertex2f(-.2,.1);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 26, 51);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glVertex2f(-.05,.29);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.04,.25);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(-.05,.29);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(.3,.16);
glVertex2f(.2,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 40, 77);
glVertex2f(.15,.25);
glVertex2f(.2,.16);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glEnd();

glColor3ub(0, 0, 0);
 i;
	 x8=-.06f;  y8=0.0f;  radius8 =.06f;
	 triangleAmount8 = 20;
	 twicePi8 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(i = 0; i <= triangleAmount8;i++) {
			glVertex2f(
		            x8 + (radius8 * cos(i *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i * twicePi8 / triangleAmount8))
			);
		}
glEnd();
 i;
	 x=.18f;  y=0.0f;  radius =.06f;
	 triangleAmount = 20;
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi / triangleAmount)),
			    y + (radius * sin(i* twicePi / triangleAmount))
			);
		}
glEnd();
 r;
	 x11=-.06f;  y11=0.0f;  radius11 =.03f;
	 triangleAmount11 = 20;
	 twicePi11 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11);
		glColor3ub(255, 255,255);
		for(r = 0; r <= triangleAmount11;r++) {
			glVertex2f(
		            x11 + (radius11 * cos(r *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(r * twicePi11 / triangleAmount11))
			);
		}
glEnd();
 s;
	 x1=.18f;  y1=0.0f;  radius1 =0.03f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		glColor3ub(255, 255,255);
		for(s = 0; s <= triangleAmount1;s++) {
			glVertex2f(
		            x1 + (radius1 * cos(s*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(s* twicePi1 / triangleAmount1))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();
//end red car

//bus
glPushMatrix();
glTranslatef(position_bus2,0.0f, 0.0f);

glScalef(-.2,.3,0);
glTranslatef(.7f, -2.5f, 0.0f);

glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-.6,0.25);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.4);
    glVertex2f(-0.6,0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
    glVertex2f(-.6,0.4);
    glVertex2f(0.6,0.4);
    glVertex2f(0.6,0.7);
    glVertex2f(-.6,0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51, 153);
    glVertex2f(-.6,0.4);
    glVertex2f(-.5,0.4);
    glVertex2f(-.5,0.7);
    glVertex2f(-.6,0.7);


    glVertex2f(-.4,0.5);
    glVertex2f(-.3,0.5);
    glVertex2f(-.3,0.6);
    glVertex2f(-.4,0.6);

    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glVertex2f(-.2,0.5);
    glVertex2f(-.1,0.5);
    glVertex2f(-.1,0.6);
    glVertex2f(-.2,0.6);
    glEnd();

    glTranslatef(-.25,0,0);
    glBegin(GL_QUADS);
    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glEnd();
     glLoadIdentity();
     glTranslatef(position_bus2,0.0f, 0.0f);

     glScalef(-.2,.3,0);
glTranslatef(.7f, -2.5f, 0.0f);

	x=.3f; y=.25f; radius =.11f;
	glColor3f(0,0,0);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3f(0,0,0);
    j;

    x=-.3f;  y1=.25f;  radius =.11f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
			    x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius* sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

     x=.3f;  y=.25f;  radius =.06f;
	glColor3f(1,1,1);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius3 * cos(i *  twicePi3 / triangleAmount)),
			    y + (radius3* sin(i * twicePi3 / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1,1,1);
    i;

     x=-.3f;  y=.25f;  radius =.06f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius4 = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

	glLoadIdentity();

//traffic light
glTranslatef(0.0f, -0.38f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(-0.91f,-0.4f);
glVertex2f(-0.9f,-0.4f);
glVertex2f(-0.9f,0.01f);
glVertex2f(-0.91f,0.01f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 102, 102);
glVertex2f(-0.93f,0.01f);
glVertex2f(-0.88f,0.01f);
glVertex2f(-0.88f,-0.15f);
glVertex2f(-0.93f,-0.15f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(-0.91f,0.001f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f(-0.91f,-0.12f);
glEnd();

glLoadIdentity();
glTranslatef(0.0f, -0.38f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f(0.91f,-0.4f);
glVertex2f(0.9f,-0.4f);
glVertex2f(0.9f,0.01f);
glVertex2f(0.91f,0.01f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 102, 102);
glVertex2f(0.93f,0.01f);
glVertex2f(0.88f,0.01f);
glVertex2f(0.88f,-0.15f);
glVertex2f(0.93f,-0.15f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(0.9f,0.001f);
glEnd();

glPointSize(8);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f(0.9f,-0.12f);
glEnd();

glLoadIdentity();
//end traffic light

//bus
glPushMatrix();
glTranslatef(position_bus1,0.0f, 0.0f);

glScalef(.2,.3,0);
glTranslatef(1.0f, -3.0f, 0.0f);

glBegin(GL_QUADS);
    glColor3ub(0, 48, 48);
    glVertex2f(-.6,0.25);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.4);
    glVertex2f(-0.6,0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
    glVertex2f(-.6,0.4);
    glVertex2f(0.6,0.4);
    glVertex2f(0.6,0.7);
    glVertex2f(-.6,0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 48, 48);
    glVertex2f(-.6,0.4);
    glVertex2f(-.5,0.4);
    glVertex2f(-.5,0.7);
    glVertex2f(-.6,0.7);


    glVertex2f(-.4,0.5);
    glVertex2f(-.3,0.5);
    glVertex2f(-.3,0.6);
    glVertex2f(-.4,0.6);

    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glVertex2f(-.2,0.5);
    glVertex2f(-.1,0.5);
    glVertex2f(-.1,0.6);
    glVertex2f(-.2,0.6);
    glEnd();

    glTranslatef(-.25,0,0);
    glBegin(GL_QUADS);
    glVertex2f(.4,0.5);
    glVertex2f(.3,0.5);
    glVertex2f(.3,0.6);
    glVertex2f(.4,0.6);

    glEnd();
     glLoadIdentity();
     glTranslatef(position_bus1,0.0f, 0.0f);

     glScalef(.2,.3,0);
glTranslatef(1.0f, -3.0f, 0.0f);

	x=.3f; y=.25f; radius =.11f;
	glColor3f(0,0,0);
	i;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3f(0,0,0);
    i;

    x=-.3f;  y1=.25f;  radius =.11f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     x=.3f;  y=.25f;  radius =.06f;
	glColor3f(1,1,1);
	i;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi3 / triangleAmount)),
			    y + (radius* sin(i * twicePi3 / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1,1,1);
    i;

     x=-.3f;  y=.25f;  radius =.06f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius4 = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();
	glLoadIdentity();

	//end bus

glPushMatrix();
glTranslatef(position_jip1,0.0f, 0.0f);

glScalef(.4,.4,0);
glTranslatef(-2.0f, -2.2f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(117, 102, 2);
glVertex2f(-.23,.3);
glVertex2f(-.38,.06);
glVertex2f(.12,.06);
glVertex2f(.12,.3);

glColor3ub(117, 102, 2);
glVertex2f(-.38,.06);
glVertex2f(-.38,-.06);
glVertex2f(.12,-.06);
glVertex2f(.12,.06);

glColor3ub(117, 102, 2);
glVertex2f(.12,-.06);
glVertex2f(.2,-.06);
glVertex2f(.19,.06);
glVertex2f(.12,.06);

glColor3ub(117, 102, 2);
glVertex2f(.12,.3);
glVertex2f(.12,.06);
glVertex2f(.19,.06);
glVertex2f(.16,.2);

glColor3ub(13, 13, 13);
glVertex2f(-.2,.28);
glVertex2f(-.32,.11);
glVertex2f(.15,.11);
glVertex2f(.1,.28);

glEnd();
    i;
	 x=.1f;  y=-.05f; radius =.06f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
glEnd();
    i;
	x=-.23f; y=-.05f; radius =.06f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi / triangleAmount)),
			    y + (radius * sin(i* twicePi / triangleAmount))
			);
		}
glEnd();
    k;
	x=.1f; y=-.05f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount))
			);
		}
glEnd();
    i;
	x=-.23f; y=-.05f; radius =.03f;
	triangleAmount3 = 20;
	twicePi3 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		glColor3ub(255, 255,255);
		for(i = 0; i <= triangleAmount3;i++) {
			glVertex2f(
		            x + (radius * cos(i*  twicePi3 / triangleAmount3)),
			    y + (radius * sin(i* twicePi3 / triangleAmount3))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();

    //red car
glPushMatrix();
glTranslatef(position_car1,0.0f, 0.0f);

    glScalef(.5,.4,0);
glTranslatef(-0.3f, -2.4f, 0.0f);

    glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,0);
glVertex2f(.3,0.0);
glVertex2f(.3,.1);
glVertex2f(-.2,.1);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.12,.1);
glVertex2f(.3,.1);
glVertex2f(.3,.16);
glVertex2f(-.07,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.2,.1);
glVertex2f(-.12,.1);
glVertex2f(-.07,.16);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 26, 51);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glVertex2f(-.05,.29);
glVertex2f(-.1,.2);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(-.04,.25);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(-.05,.29);
glEnd();

glBegin(GL_QUADS);
glColor3ub(204, 41, 0);
glVertex2f(.15,.25);
glVertex2f(.16,.29);
glVertex2f(.3,.16);
glVertex2f(.2,.16);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 40, 77);
glVertex2f(.15,.25);
glVertex2f(.2,.16);
glVertex2f(-.07,.16);
glVertex2f(-.04,.25);
glEnd();

glColor3ub(0, 0, 0);
int p;
	 x8=-.06f;  y8=0.0f;  radius8 =.06f;
	 triangleAmount8 = 20;
	 twicePi8 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(p = 0; p <= triangleAmount8;p++) {
			glVertex2f(
		            x8 + (radius8 * cos(p *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(p * twicePi8 / triangleAmount8))
			);
		}
glEnd();
int q;
	 x9=.18f;  y9=0.0f;  radius9 =.06f;
	 triangleAmount9 = 20;
	 twicePi9 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9);
		for(q = 0; q <= triangleAmount9;q++) {
			glVertex2f(
		            x9 + (radius9 * cos(q*  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(q* twicePi9 / triangleAmount9))
			);
		}
glEnd();
 r;
	 x11=-.06f;  y11=0.0f;  radius11 =.03f;
	 triangleAmount11 = 20;
	 twicePi11 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11);
		glColor3ub(255, 255,255);
		for(r = 0; r <= triangleAmount11;r++) {
			glVertex2f(
		            x11 + (radius11 * cos(r *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(r * twicePi11 / triangleAmount11))
			);
		}
glEnd();
 s;
	 x1=.18f;  y1=0.0f;  radius1 =0.03f;
	 triangleAmount1 = 20;
	 twicePi1 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		glColor3ub(255, 255,255);
		for(s = 0; s <= triangleAmount1;s++) {
			glVertex2f(
		            x1 + (radius1 * cos(s*  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(s* twicePi1 / triangleAmount1))
			);
		}
glEnd();

glPopMatrix();
glLoadIdentity();
//end red car

glFlush();

glutTimerFunc(1500,demo_night,0);
glFlush();
}

void demo_day()
{
       glutDisplayFunc(day);
}

void displayTraficGreen(){
glPointSize(8);
    glutDisplayFunc(demo_day);

    glBegin(GL_POINTS);
    glColor3f(0,1,0);
    glVertex2f(-0.91f,-0.12f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Test");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(day);
	//soundTrain();
	//soundCar();

	//glutKeyboardFunc(TraficLight);

	glutTimerFunc(100, update_bird, 0);
	glutTimerFunc(100, update_train, 0);
	glutTimerFunc(100, update_jip1, 0);
	glutTimerFunc(100, update_bus1, 0);
	glutTimerFunc(100, update_car1, 0);
	glutTimerFunc(100, update_car2, 0);
	glutTimerFunc(100, update_jip2, 0);
	glutTimerFunc(100, update_car3, 0);
    glutTimerFunc(100, update_bus2, 0);

    glutTimerFunc(100, update_rain, 0);

    glutSpecialFunc(SpecialInput_train);
    glutMouseFunc(handleMouse_LeftCar);
    glutKeyboardFunc(handleKeypress_RightCar);

    glutIdleFunc(Idle);

	glutMainLoop();
	return 0;
}
