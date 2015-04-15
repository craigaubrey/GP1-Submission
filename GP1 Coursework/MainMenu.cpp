#include <windows.h>
#include "GL/glut.h" 
#include "cTexture.h"
#include "cSprite.h"
static int window;
static int menu_id;
static int submenu_id;
static int value = 1;
static GLint texture1;
static GLint texture2;

void menu(int num){
	if (num == 0){
		glutDestroyWindow(window);
		exit(0);
	}
	else{
		value = num;
	}
	glutPostRedisplay();
}

void createMenu(void){
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Start", 2);
	glutAddMenuEntry("Controls", 3);    
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 1);
	glutAddSubMenu("game", submenu_id);
	glutAddMenuEntry("Quit", 0);     
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	cTexture textureBkgd = cTexture("Images\\start_screen_bkg.png");
	cTexture textureContorls = cTexture("Images\\controls.png");
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);   if (value == 1){
		//draws a rectangle in value 1 (main menu page)
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, texture1);

		glBegin(GL_QUADS);

		glColor3f(1, 1, 1);

		glTexCoord2f(0, 1);
		glVertex2f(-1, -1);

		glTexCoord2f(1, 1);
		glVertex2f(1, -1);

		glTexCoord2f(1, 0);
		glVertex2f(1, 1);

		glTexCoord2f(0, 0);
		glVertex2f(-1, 1);

		glEnd();
		//return; //glutPostRedisplay();
	}
	else if (value == 2){
		WinMain(NULL, NULL, NULL, 0);
	}
	else if (value == 3){
		//draws a rectangle in value 3 (controls page)
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, texture2);

		glBegin(GL_QUADS);

		glColor3f(1, 1, 1);

		glTexCoord2f(0, 1);
		glVertex2f(-1, -1);

		glTexCoord2f(1, 1);
		glVertex2f(1, -1);

		glTexCoord2f(1, 0);
		glVertex2f(1, 1);

		glTexCoord2f(0, 0);
		glVertex2f(-1, 1);

		glEnd();

	}
	
	glFlush();
}
int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Menus and Submenus - Programming Techniques");
	//texture 1 for the main menu page
	cTexture textureBkgd = cTexture("Images\\MenuBkgd.png");
	texture1 = textureBkgd.getTexture();
	//texture 2 for the controls menu page
	cTexture textureControls = cTexture("Images\\controls.png");
	texture2 = textureControls.getTexture();
	createMenu();
	//plays background music
	mciSendString("open Audio/Main_Menu.mp3 type mpegvideo alias music", NULL, 0, 0);
	mciSendString("play music repeat", NULL, 0, 0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

//Wheres the controls texture
//still to make, was making sure i knew what i was doing 1st
