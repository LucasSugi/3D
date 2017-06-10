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

#define WINDOW_SIZE_H 800
#define WINDOW_SIZE_W 600
#define WINDOW_INIT_POS_X 100
#define WINDOW_INIT_POS_Y 100

#define PI 3.141592654f

// Object's aspect
GLfloat fAspect;

// Angle used for zoon-in/zoon-out
GLfloat angleVerticalVision = 70.0f;

// Object position
GLfloat objectX = 0.0f, objectY = 0.0f, objectZ = 0.0f;

// Vision position
//GLfloat visionX = 0.0f, visionY = 0.0f, visionZ = 0.0f;

// Last positions get from mouse movement
GLfloat lastX = 0.0f, lastY = 0.0f;

// Parameters to rotation of scene
GLfloat rotate_x = 0.0f, rotate_y = 0.0f;

// Store the screen center position
GLint sc_x = 300, sc_y = 400;

/**	Draws our character on screen	*/
void drawCharacter(){
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(rotate_x, 1.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(2);
}

/**	Draws the obstacles on screen	*/
void drawObstacles() {
	glColor3f(1.0f, 1.0f, 0.0f);	
	glPushMatrix();
	glTranslatef(10.0f, 0.0f, -20.0f);
	glutSolidCube(2);
	glPopMatrix();
	glColor3f(0.0f, 1.0f, 1.0f);	
	glPushMatrix();
	glTranslatef(-10.0f, 0.0f, -10.0f);
	glutSolidCube(2);
	glPopMatrix();
}

/**	Function that draw the grid on the screen	*/
void drawGrid() {
	for(float i = -500; i <= 500; i += 5) {
		glBegin(GL_LINES);
			glColor3ub(150, 190, 150);
			glVertex3f(-500, 0, i);
			glVertex3f(500, 0, i);
			glVertex3f(i, 0,-500);
			glVertex3f(i, 0, 500);
		glEnd();
	}
}

/**	Function that creates a light effect on the scene  */
void setEffect() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
}

/**	Rendering function	*/
void draw(){
	
	//Sets the clear color to white and clean the scene
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	setEffect();
	
	// Initialize the matrix
	glLoadIdentity();

	//Draws our character
	drawCharacter();
	
	//Sets the Camara on the y-Axis	and translate the screen to the camera position
	glRotatef(rotate_y, 0.0f, 1.0f, 0.0f);
	glTranslatef(-objectX, -objectY, -objectZ);

	//Draws the obstacles
	drawObstacles();

	//Draws the grid
	drawGrid();

	// Swap the buffers
	glutSwapBuffers();
}

/**	Function that reshapes the window	*/
void alterWindowSize(GLsizei w, GLsizei h){

	sc_x = w / 2;
	sc_y = h / 2;

	// Prevents division by zero
	if(h == 0) h = 1;

	// Sets the viewport to the current window specifications
	glViewport(0, 0, w, h);
	
	// Sets the matrix to projection
	glMatrixMode(GL_PROJECTION);

	// Initializes the matrix
	glLoadIdentity();

	// Sets the perspective
	fAspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(angleVerticalVision, fAspect, 0.1, 100.0);

	// Resets the matrix back to modelview
	glMatrixMode(GL_MODELVIEW);

}

/**	Handling the mouse movement	*/
void mouse(int x, int y){
	int varX, varY;
	int dX, dY;
	
	// Compute the difference between current/last mouse position
	//varX = x - lastX;
	//varY = y - lastY;
	varX = x - sc_x;
	varY = y - sc_y;
	glutWarpPointer(sc_x, sc_y);
	
	// Stores the current position
	lastX = x;
	lastY = y;

	// Sets the rotation parameters
	rotate_x += (GLfloat)varY;
	rotate_y += (GLfloat)varX;
}


/**	Handling the keyboard interaction	*/
void keyboard(unsigned char key, int x, int y) {
	
	// Moves the character forward
	if (key == 'w') {
		GLfloat rotate_aux_x, rotate_aux_y;
		rotate_aux_x = (rotate_x / 180 * PI);
		rotate_aux_y = (rotate_y / 180 * PI);
		objectX += float(sin(rotate_aux_y));
		objectY -= float(sin(rotate_aux_x));
		objectZ -= float(cos(rotate_aux_y));
	}
	// Moves the character back
	if (key == 's')	{
		GLfloat rotate_aux_x, rotate_aux_y;
		rotate_aux_x = (rotate_x / 180 * PI);
		rotate_aux_y = (rotate_y / 180 * PI);
		objectX -= float(sin(rotate_aux_y));
		objectY += float(sin(rotate_aux_x));
		objectZ += float(cos(rotate_aux_y));
	}
	// Moves the character right
	if (key == 'd')	{
		GLfloat rotate_aux_y;
		rotate_aux_y = (rotate_y / 180 * PI);
		objectX += float(cos(rotate_aux_y)) * 0.2;
		objectZ += float(sin(rotate_aux_y)) * 0.2;
	}
	// Moves the character left
	if (key == 'a') {
		GLfloat rotate_aux_y;
		rotate_aux_y = (rotate_y / 180 * PI);
		objectX -= float(cos(rotate_aux_y)) * 0.2;
		objectZ -= float(sin(rotate_aux_y)) * 0.2;
	}
	// Moves the character up
	if(key == 'q') {
		objectY++;
	}
	// Moves the character down
	if(key == 'z') {
		objectY--;
	}
}

/**	Main Funcion	*/
int main(int argc, char *argv[]){

	glutInit(&argc, argv);	

	//Some specifications about glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); 

	//Windows size
	glutInitWindowSize(WINDOW_SIZE_H, WINDOW_SIZE_W); 

	//Initial position of window
	glutInitWindowPosition(WINDOW_INIT_POS_X, WINDOW_INIT_POS_Y); 

	//Create the Window 
	glutCreateWindow("3D Movement");

	//Hide Cursor
	//glutSetCursor(GLUT_CURSOR_NONE);

	//Function that draw in window
	glutDisplayFunc(draw);

	//Function that sets the idle callback function 
	glutIdleFunc(draw);

	//Function that's resize windows
	glutReshapeFunc(alterWindowSize);

	//Handle keyboard
	glutKeyboardFunc(keyboard);

	//Check for Mouse Moviment
	glutPassiveMotionFunc(mouse);

	//Starts
	glutMainLoop();

	return 0;
}

