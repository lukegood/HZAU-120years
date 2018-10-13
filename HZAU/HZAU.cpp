#include "stdafx.h"
#include <GL/glut.h>
#include<stdio.h>

//static int base = 1000;
int i = 0;//控制色块颜色变化
int j = 0;//控制HZAU颜色变化
float color1 = 1.0;//四周色块的颜色
float color2 = 0.0;
float color3 = 0.0;
float color4 = 0.0;//HZAU的颜色
float color5 = 1.0;
float color6 = 0.0;
float RecLeftBotx = -0.5;
float RecLeftBoty = -0.75;
float RecRightTopx = -0.45;
float RecRightTopy = -0.7;

void drawAround(void) {//绘制四周的色块
	glColor3f(color1, color2, color3);

	glBegin(GL_POLYGON);//上
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.8f);
	glVertex2f(-1.0f, 0.8f);
	glEnd();

	glBegin(GL_POLYGON);//下
	glVertex2f(-1.0f, 0.8f);
	glVertex2f(-0.8f, 0.8f);
	glVertex2f(-0.8f, -0.8f);
	glVertex2f(-1.0f, -0.8f);
	glEnd();

	glBegin(GL_POLYGON);//左
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, -0.8f);
	glVertex2f(-1.0f, -0.8f);
	glEnd();

	glBegin(GL_POLYGON);//右
	glVertex2f(1.0f, 0.8f);
	glVertex2f(0.8f, 0.8f);
	glVertex2f(0.8f, -0.8f);
	glVertex2f(1.0f, -0.8f);
	glEnd();

	glFlush();//立即刷新
}

void drawHZAU(void) {
	glColor3f(color4, color5, color6);
	glBegin(GL_POLYGON);//绘制H
	glVertex2f(-0.7, 0.5);
	glVertex2f(-0.65, 0.5);
	glVertex2f(-0.65, -0.5);
	glVertex2f(-0.7, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.65, 0.05);
	glVertex2f(-0.55, 0.05);
	glVertex2f(-0.55, -0.05);
	glVertex2f(-0.65, -0.05);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.55, 0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.55, -0.5);
	glEnd();

	glBegin(GL_POLYGON);//绘制Z
	glVertex2f(-0.4f, 0.5f);
	glVertex2f(-0.2f, 0.5f);
	glVertex2f(-0.2f, 0.45f);
	glVertex2f(-0.4f, 0.45f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.4f, -0.5f);
	glVertex2f(-0.2f, -0.5f);
	glVertex2f(-0.2f, -0.45f);
	glVertex2f(-0.4f, -0.45f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.2f, 0.5f);
	glVertex2f(-0.2f, 0.45f);
	glVertex2f(-0.4f, -0.5f);
	glVertex2f(-0.4f, -0.45f);
	glEnd();

	glBegin(GL_POLYGON);//绘制A
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.0f, 0.45f);
	glVertex2f(-0.05f, -0.5f);
	glVertex2f(-0.1f, -0.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.0f, 0.45f);
	glVertex2f(0.05f, -0.5f);
	glVertex2f(0.1f, -0.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.045f, 0.05f);
	glVertex2f(-0.045f, -0.05f);
	glVertex2f(0.045f, -0.05f);
	glVertex2f(0.045f, 0.05f);
	glEnd();

	glBegin(GL_POLYGON);//绘制U
	glVertex2f(0.2f, 0.5f);
	glVertex2f(0.25f, 0.5f);
	glVertex2f(0.25f, -0.5f);
	glVertex2f(0.2f, -0.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.25f, -0.45f);
	glVertex2f(0.25f, -0.5f);
	glVertex2f(0.35f, -0.5f);
	glVertex2f(0.35f, -0.45f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.4f, 0.5f);
	glVertex2f(0.35f, 0.5f);
	glVertex2f(0.35f, -0.5f);
	glVertex2f(0.4f, -0.5f);
	glEnd();
	
	glFlush();
}

void drawTriangle(void) {
	glColor3f(color4, color5, color6);
}

void drawRectangle(void) {
	glColor3f(color1, color2, color3);
	//glBegin(GL_POLYGON);
	glRectf(RecLeftBotx, RecLeftBoty, RecRightTopx, RecRightTopy);
	glFlush();
}

void myDisplay(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置清空背景色为黑色
	glClear(GL_COLOR_BUFFER_BIT);//清空背景为黑色
	drawAround();
	drawHZAU();
	drawRectangle();
}

void Timer1(int value)
{
	i = i + 0.1;
	color1 = color1 - i;
	color2 = color2 + i + 0.12;
	color3 = color3 + i + 0.21;
	if (color1 <= 0.0) {
		color1 = 1.0;
	}
	if (color2 >= 1.0) {
		color2 = 0.0;
	}
	if (color3 >= 1.0) {
		color3 = 0.0;
	}
	if (i >= 1) {
		i = 0;
	}
	glutPostRedisplay(); //刷新画面
	glutTimerFunc(1000, Timer1, 1);
}

void Timer2(int value)
{
	j = j + 0.1;
	color5 = color5 - j;
	color4 = color4 + j + 0.12;
	color6 = color6 + j + 0.21;
	if (color5 <= 0.0) {
		color5 = 1.0;
	}
	if (color4 >= 1.0) {
		color4 = 0.0;
	}
	if (color6 >= 1.0) {
		color6 = 0.0;
	}
	if (j >= 1) {
		j = 0;
	}
	glutPostRedisplay(); //刷新画面
	glutTimerFunc(500, Timer2, 1);
}

void Timer3(int value) {
	RecLeftBotx = RecLeftBotx + 0.05;
	RecRightTopx = RecRightTopx + 0.05;
	if (RecRightTopx >= 0.75) {
		RecLeftBotx = -0.5;
		RecRightTopx = -0.45;
	}
	glutTimerFunc(400, Timer3, 1);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("缤纷HZAU120周年"); // 设置窗口标题
	glutDisplayFunc(&myDisplay);
	glutTimerFunc(1000, Timer1, 1);
	glutTimerFunc(500, Timer2, 1);
	glutTimerFunc(400, Timer3, 1);
	glutMainLoop();
	return 0;
}