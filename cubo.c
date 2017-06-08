/*
 * Kelvin Guilherme de Oliveira - 9293286
 * Leonardo Alves Gomes - 9293178 
 * Lucas Yudi Sugi - 9293251
 * Mauricio Caetano da Silva - 9040996 
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

//Here JUMP define how long the object can "jump" in one movement
#define JUMP 10

//Defines the initial window position
#define POSITION_WINDOW_X 5
#define POSITION_WINDOW_Y 5

//Objects aspect
GLfloat fAspect;

//Object position
GLfloat objectX = 240.0f;
GLfloat objectY = 240.0f;
GLfloat objectZ = 100.0f;

//angles that is used for move vision
GLfloat theta = -2.3;
GLfloat phi = 1.5;

//ray of vision
GLfloat ray = 10;

//vision position
GLfloat visX = 0;
GLfloat visY = 0;
GLfloat visZ = 0;

//move object
GLfloat moveX = 0;
GLfloat moveY = 0;
GLfloat moveZ = 0;

//move object
GLfloat translateX = 100;
GLfloat translateY = 100;
GLfloat translateZ = 0;

//angle used for zoom-in and zoom-out
GLfloat angulo_de_visao_vertical = 70.0f;

void drawObjetc(void){

	glPushMatrix();
	
	//obstacle Cube faces
	glBegin(GL_QUADS);
	//Front
	glColor3f(0.0f, 0.0f, 0.0f); //Black
	glVertex3f(40.0, 40.0, 40.0);
	glVertex3f(-40.0, 40.0, 40.0);
	glVertex3f(-40.0, -40.0, 40.0);
	glVertex3f(40.0, -40.0, 40.0);                                         					
	//Posterior
	glColor3f(0.0f, 0.0f, 0.0f); //Black
	glVertex3f(40.0, 40.0, -40.0);
	glVertex3f(40.0, -40.0, -40.0);
	glVertex3f(-40.0, -40.0, -40.0);
	glVertex3f(-40.0, 40.0, -40.0);
	//Left side
	glColor3f(0.0f, 0.0f, 0.0f); //Black
	glVertex3f(-40.0, 40.0, 40.0);
	glVertex3f(-40.0, 40.0, -40.0);
	glVertex3f(-40.0, -40.0, -40.0);
	glVertex3f(-40.0, -40.0, 40.0);
	//Right side
	glColor3f(0.0f, 0.0f, 0.0f); //Black
	glVertex3f(40.0, 40.0, 40.0); 
	glVertex3f(40.0, -40.0, 40.0); 
	glVertex3f(40.0, -40.0, -40.0);
	glVertex3f(40.0, 40.0, -40.0);
	//Superior  
	glColor3f(0.0f, 0.0f, 0.0f); //Black
	glVertex3f(-40.0, 40.0, -40.0);
	glVertex3f(-40.0, 40.0, 40.0); 
	glVertex3f(40.0, 40.0, 40.0);
	glVertex3f(40.0, 40.0, -40.0);
	//Inferior
	glColor3f(0.0f, 0.0f, 0.0f); //Black
	glVertex3f(-40.0, -40.0, -40.0); 
	glVertex3f(40.0, -40.0, -40.0);  
	glVertex3f(40.0, -40.0, 40.0); 
	glVertex3f(-40.0, -40.0, 40.0);
	glEnd();
	
	translateX += moveX;
	translateY += moveY;
	translateZ += moveZ;
	glTranslatef(objectX,objectY,objectZ);
	glRotatef(theta,0,0,1);
	glTranslatef(-objectX,-objectY,-objectZ);
	glTranslatef(translateX,translateY,translateZ);
	

	//Cube faces
	glBegin(GL_QUADS);
	//Front
	glColor3f(1.0f, 0.5f, 1.0f); //Pink		
	glVertex3f(40.0, 40.0, 40.0);
	glVertex3f(-40.0, 40.0, 40.0);
	glVertex3f(-40.0, -40.0, 40.0);
	glVertex3f(40.0, -40.0, 40.0);                                         					
	//Posterior
	glColor3f(0.0f, 0.0f, 0.0f); //Black
	glVertex3f(40.0, 40.0, -40.0);
	glVertex3f(40.0, -40.0, -40.0);
	glVertex3f(-40.0, -40.0, -40.0);
	glVertex3f(-40.0, 40.0, -40.0);
	//Left side
	glColor3f(0.0f, 1.0f, 0.0f); //Verde
	glVertex3f(-40.0, 40.0, 40.0);
	glVertex3f(-40.0, 40.0, -40.0);
	glVertex3f(-40.0, -40.0, -40.0);
	glVertex3f(-40.0, -40.0, 40.0);
	//Right side
	glColor3f(1.0f, 0.0f, 0.0f); //Vermelho
	glVertex3f(40.0, 40.0, 40.0); 
	glVertex3f(40.0, -40.0, 40.0); 
	glVertex3f(40.0, -40.0, -40.0);
	glVertex3f(40.0, 40.0, -40.0);
	//Superior  
	glColor3f(1.0f, 1.0f, 0.0f); //Amarelo
	glVertex3f(-40.0, 40.0, -40.0);
	glVertex3f(-40.0, 40.0, 40.0); 
	glVertex3f(40.0, 40.0, 40.0);
	glVertex3f(40.0, 40.0, -40.0);
	//Inferior
	glColor3f(0.0f, 0.0f, 1.0f); //Azul
	glVertex3f(-40.0, -40.0, -40.0); 
	glVertex3f(40.0, -40.0, -40.0);  
	glVertex3f(40.0, -40.0, 40.0); 
	glVertex3f(-40.0, -40.0, 40.0);
	glEnd();

	glPopMatrix();
}

//Draw scene
void draw(void){

	//Paint window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//object that is moved
	drawObjetc();

	glFlush();
	glutSwapBuffers();
}

//Define display parameters
void displayParameters(void){

	//Define projection coordinate system
	glMatrixMode(GL_PROJECTION);

	//reset matrix
	glLoadIdentity();

	//Defines the perspective projection
	gluPerspective(angulo_de_visao_vertical,fAspect,1.0f,1000.0f);

	//Define system coordinates 
	glMatrixMode(GL_MODELVIEW);

	//reset matrix
	glLoadIdentity();

	//position of object and position of vision
	gluLookAt(objectX, objectY, objectZ,    visX,visY,visZ,    0.0,0.0,1.0);
}

//Change window size after we have a resizing
void changeSizeWindow(GLsizei w, GLsizei h){
	//prevents division by zero
	if ( h == 0 ) h = 1;

	//new dimensions
	glViewport(0, 0, w, h);

	//resizing objects with aspect
	fAspect = (GLfloat)w/(GLfloat)h;

	displayParameters();
}

//Here we have the calculation of vision movement
void calcVision(){
	//Rotate with spherical coordinates	
	visX = objectX + (ray * cos(theta)*sin(phi));
	visY = objectY + (ray * sin(theta)*sin(phi));
	visZ = objectZ + (ray*cos(phi));
}


//Here we have the calculation of object position (UP and DOWN)
void calcObjectPositionUpDown(GLfloat up_or_down){
	GLfloat incX = visX-objectX;
	GLfloat incY = visY-objectY;
	GLfloat incZ = visZ-objectZ;

	GLfloat greaterInc = abs(incX);
	if(greaterInc < abs(incY)) greaterInc = abs(incY);
	if(greaterInc < abs(incZ)) greaterInc = abs(incZ);

	//Approach object in the viewing position(UP) / Distance object in the viewing position
	moveX = (incX/greaterInc)*up_or_down;
	moveY = (incY/greaterInc)*up_or_down;
	moveZ = (incZ/greaterInc)*up_or_down;

	objectX = objectX + moveX;
	objectY = objectY + moveY;
	objectZ = objectZ + moveZ;

	//recalculates vision
	calcVision();
}

//Here we have the calculation of object position (LEFT and RIGHT)
void calcObjectPositionLeftRight(GLfloat left_or_right){

	//Verifies whether the movement is vertical	
	if(objectY == visY){
		if(visX>objectX){
			moveY = -left_or_right;
			moveX = moveZ = 0;

			objectY = objectY - left_or_right;
		}
		else{
			moveY = left_or_right;
			moveX = moveZ = 0;

			objectY = objectY + left_or_right;	
		}	
	}
	//Verifies whether the movement is horizontal
	else if(objectX == visX){
		if(visY>objectY){
			moveX = left_or_right;
			moveY = moveZ = 0;

			objectX = objectX + left_or_right;	
		}
		else{
			moveX = -left_or_right;
			moveY = moveZ = 0;

			objectX = objectX - left_or_right;	
		}	
	}
	//Movement is performed on a slope
	else{
		//Check if we are in the first or second quadrant
		if(visY>objectY){
			//Let's calculate the line we will walk on
			GLfloat m = (visY-objectY)/(visX-objectX);
			m = -1/m;
			GLfloat h = objectY-(m*objectX);

			//angle is higher than 45?
			if(abs(m) > 1){
				//move object
				if(visX>objectX){
					objectY = objectY - left_or_right;	
					moveX = ((objectY-h)/m) - objectX;
					objectX += moveX;

					moveY = -left_or_right;
					moveZ = 0;
				}
				else{
					objectY = objectY + left_or_right;
					moveX = ((objectY-h)/m)-objectX;
					objectX += moveX;

					moveY = left_or_right;
					moveZ = 0;
				}
			}
			else{
				//move object
				objectX = objectX + left_or_right;
				moveY = ((m*objectX)+h)-objectY;
				objectY += moveY;	

				moveX = left_or_right;
				moveZ = 0;
			}

		}
		//We are in the third or fourth quadrant
		else{	
			//Let's calculate the line we will walk on
			GLfloat m = (visY-objectY)/(visX-objectX);
			m = -1/m;
			GLfloat h = objectY-(m*objectX);

			//angle is higher than 45?
			if(abs(m) > 1){
				//move object
				if(visX>objectX){
					objectY = objectY - left_or_right;	
					moveX = ((objectY-h)/m)-objectX;
					objectX += moveX;

					moveY = -left_or_right;
					moveZ = 0;
				}
				else{
					objectY = objectY + left_or_right;
					moveX = ((objectY-h)/m)-objectX;
					objectX += moveX;

					moveY = left_or_right;
					moveZ = 0;
				}	
			}
			else{
				//move object
				objectX = objectX - left_or_right;
				moveY = ((m*objectX)+h)-objectY;
				objectY += moveY;

				moveX = -left_or_right;
				moveZ = 0;
			}
		}	
	}
	//recalculates vision
	calcVision();
}

//Handle keyboard keys
void keyboard(unsigned char key, int x, int y){

	//exit	
	if (key == 27){
		exit(0);
	}

	//Move object
	if (key == 'w') {
		calcObjectPositionUpDown(JUMP);
		displayParameters();
		draw();
	}
	if (key == 's') {
		calcObjectPositionUpDown(-JUMP);
		displayParameters();
		draw();
	}
	if (key == 'a') {
		calcObjectPositionLeftRight(-JUMP);
		displayParameters();
		draw();
	}
	if (key == 'd') {
		calcObjectPositionLeftRight(JUMP);
		displayParameters();
		draw();
	}
}


//Function that's handle with special keys
void specialKey(int key, int x, int y){

	//Move vision
	if(key == GLUT_KEY_UP){
		phi +=-0.1;
		calcVision();
		displayParameters();
		draw();
	}
	else if(key == GLUT_KEY_DOWN){
		phi+=0.1;
		calcVision();
		displayParameters();
		draw();
	}
	else if(key == GLUT_KEY_RIGHT){
		theta = theta-0.1;
		if(theta>=360) theta = 0;
		calcVision();
		displayParameters();
		draw();
	}
	else if(key == GLUT_KEY_LEFT){
		theta = theta+0.1;
		if(theta>=360) theta = 0;
		calcVision();
		displayParameters();
		draw();
	}
}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);	

	//Some specifications about glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 

	//Initial position of window
	glutInitWindowPosition(POSITION_WINDOW_X,POSITION_WINDOW_Y); 

	//Windows size
	glutInitWindowSize(450,450); 

	// Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("3D movement");

	//Function that's draw in window
	glutDisplayFunc(draw);

	//Function that's resize windows
	glutReshapeFunc(changeSizeWindow);

	//Handle keyboard
	glutKeyboardFunc(keyboard);

	//Handle special keyboard
	glutSpecialFunc(specialKey);

	//Window background color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	//Enable depth-buffering
	glEnable(GL_DEPTH_TEST);

	//starts
	glutMainLoop();

	return 0;
}
