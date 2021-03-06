#include "stdafx.h"
#include <GL/glut.h>
#include <Windows.h>

int i = 0;//控制颜色变化1
int j = 0;//控制颜色变化2
int k = 0;//控制颜色变化3

float color1 = 1.0;//颜色RGB1
float color2 = 0.0;
float color3 = 0.0;
float color4 = 0.0;//颜色RGB2
float color5 = 1.0;
float color6 = 0.0;
float color7 = 0.0;//颜色RGB3
float color8 = 0.0;
float color9 = 1.0;

float Starx = -0.82;//风筝形状初始位置
float Stary = -0.1;

float CloudLx = -0.5;//云初始位置
float CloudRx = -0.4;

float SmallTreeLx = -0.7;//小树初始位置
float SmallTreeLy = -0.54;

void drawAround(void) {//绘制四周的色块
	glColor3f(color1, color2, color3);

	glBegin(GL_POLYGON);//上
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.8f);
	glVertex2f(-1.0f, 0.8f);
	glEnd();

	glBegin(GL_POLYGON);//左
	glVertex2f(-1.0f, 0.8f);
	glVertex2f(-0.9f, 0.8f);
	glVertex2f(-0.9f, -0.8f);
	glVertex2f(-1.0f, -0.8f);
	glEnd();

	glBegin(GL_POLYGON);//下
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, -0.8f);
	glVertex2f(-1.0f, -0.8f);
	glEnd();

	glBegin(GL_POLYGON);//右
	glVertex2f(1.0f, 0.8f);
	glVertex2f(0.9f, 0.8f);
	glVertex2f(0.9f, -0.8f);
	glVertex2f(1.0f, -0.8f);
	glEnd();

	glFlush();//立即刷新
}

void drawHZAU(void) {//绘制HZAU
	glColor3f(color4, color5, color6);//设置颜色
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

	glColor3f(color1, color2, color3);//设置颜色
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

	glColor3f(color7, color8, color9);//设置颜色
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

	glColor3f(color4, color5, color6);//设置颜色
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

void drawTree(void) {//绘制树
	glColor3f(0.0f, 1.0f, 0.0f);//设置颜色
	glBegin(GL_POLYGON);
	glVertex2f(0.64f, 0.48f);
	glVertex2f(0.5f, 0.1f);
	glVertex2f(0.78f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.57f, 0.1f);
	glVertex2f(0.45f, -0.2f);
	glVertex2f(0.83f, -0.2f);
	glVertex2f(0.71f, 0.1f);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(0.62f, -0.2f);
	glVertex2f(0.66f, -0.2f);
	glVertex2f(0.66f, -0.8f);
	glVertex2f(0.62f, -0.8f);
	glEnd();
	glFlush();
}

void drawSmallTree1(void) {//绘制第一组小树
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);//第一棵
	glVertex2f(SmallTreeLx, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.05, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.08, SmallTreeLy - 0.06);
	glVertex2f(SmallTreeLx + 0.08, SmallTreeLy - 0.12);
	glVertex2f(SmallTreeLx + 0.05, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx - 0.03, SmallTreeLy - 0.1);
	glVertex2f(SmallTreeLx - 0.03, SmallTreeLy - 0.04);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.04, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.01, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.01, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.04, SmallTreeLy - 0.26);
	glEnd();

	glColor3f(0.0f, 0.9f, 0.0f);
	glBegin(GL_POLYGON);//第二棵
	glVertex2f(SmallTreeLx + 0.1, SmallTreeLy + 0.05);
	glVertex2f(SmallTreeLx + 0.15, SmallTreeLy + 0.05);
	glVertex2f(SmallTreeLx + 0.18, SmallTreeLy - 0.01);
	glVertex2f(SmallTreeLx + 0.18, SmallTreeLy - 0.07);
	glVertex2f(SmallTreeLx + 0.15, SmallTreeLy - 0.11);
	glVertex2f(SmallTreeLx + 0.1, SmallTreeLy - 0.11);
	glVertex2f(SmallTreeLx + 0.07, SmallTreeLy - 0.05);
	glVertex2f(SmallTreeLx + 0.07, SmallTreeLy + 0.01);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.14, SmallTreeLy - 0.11);
	glVertex2f(SmallTreeLx + 0.11, SmallTreeLy - 0.11);
	glVertex2f(SmallTreeLx + 0.11, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.14, SmallTreeLy - 0.26);
	glEnd();
	glColor3f(0.0f, 0.8f, 0.0f);
	glBegin(GL_POLYGON);//第三棵
	glVertex2f(SmallTreeLx + 0.2, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.25, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.28, SmallTreeLy - 0.06);
	glVertex2f(SmallTreeLx + 0.28, SmallTreeLy - 0.12);
	glVertex2f(SmallTreeLx + 0.25, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.2, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.17, SmallTreeLy - 0.1);
	glVertex2f(SmallTreeLx + 0.17, SmallTreeLy - 0.04);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.24, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.21, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.21, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.24, SmallTreeLy - 0.26);
	glEnd();
}

void drawSmallTree2(void) {//绘制第二组小树
	glColor3f(0.0f, 0.7f, 0.0f);
	glBegin(GL_POLYGON);//第四棵
	glVertex2f(SmallTreeLx + 0.4, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.45, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.48, SmallTreeLy - 0.06);
	glVertex2f(SmallTreeLx + 0.48, SmallTreeLy - 0.12);
	glVertex2f(SmallTreeLx + 0.45, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.4, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.37, SmallTreeLy - 0.1);
	glVertex2f(SmallTreeLx + 0.37, SmallTreeLy - 0.04);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.44, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.41, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.41, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.44, SmallTreeLy - 0.26);
	glEnd();
	glColor3f(0.0f, 0.85f, 0.0f);
	glBegin(GL_POLYGON);//第五棵
	glVertex2f(SmallTreeLx + 0.5, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.55, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.58, SmallTreeLy - 0.06);
	glVertex2f(SmallTreeLx + 0.58, SmallTreeLy - 0.12);
	glVertex2f(SmallTreeLx + 0.55, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.5, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.47, SmallTreeLy - 0.1);
	glVertex2f(SmallTreeLx + 0.47, SmallTreeLy - 0.04);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.54, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.51, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.51, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.54, SmallTreeLy - 0.26);
	glEnd();
	glColor3f(0.0f, 0.68f, 0.0f);
	glBegin(GL_POLYGON);//第六棵
	glVertex2f(SmallTreeLx + 0.6, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.65, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.68, SmallTreeLy - 0.07);
	glVertex2f(SmallTreeLx + 0.68, SmallTreeLy - 0.12);
	glVertex2f(SmallTreeLx + 0.65, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.6, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.57, SmallTreeLy - 0.1);
	glVertex2f(SmallTreeLx + 0.57, SmallTreeLy - 0.04);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.64, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.61, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.61, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.64, SmallTreeLy - 0.26);
	glEnd();
}

void drawSmallTree3(void) {//绘制第三组小树
	glColor3f(0.0f, 0.9f, 0.0f);
	glBegin(GL_POLYGON);//第七棵
	glVertex2f(SmallTreeLx + 0.8, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.85, SmallTreeLy);
	glVertex2f(SmallTreeLx + 0.88, SmallTreeLy - 0.06);
	glVertex2f(SmallTreeLx + 0.88, SmallTreeLy - 0.12);
	glVertex2f(SmallTreeLx + 0.85, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.8, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.77, SmallTreeLy - 0.1);
	glVertex2f(SmallTreeLx + 0.77, SmallTreeLy - 0.04);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.84, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.81, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.81, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.84, SmallTreeLy - 0.26);
	glEnd();
	glColor3f(0.0f, 0.75f, 0.0f);
	glBegin(GL_POLYGON);//第八棵
	glVertex2f(SmallTreeLx + 0.9, SmallTreeLy + 0.03);
	glVertex2f(SmallTreeLx + 0.95, SmallTreeLy + 0.03);
	glVertex2f(SmallTreeLx + 0.98, SmallTreeLy - 0.03);
	glVertex2f(SmallTreeLx + 0.98, SmallTreeLy - 0.09);
	glVertex2f(SmallTreeLx + 0.95, SmallTreeLy - 0.13);
	glVertex2f(SmallTreeLx + 0.9, SmallTreeLy - 0.13);
	glVertex2f(SmallTreeLx + 0.87, SmallTreeLy - 0.07);
	glVertex2f(SmallTreeLx + 0.87, SmallTreeLy - 0.01);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 0.94, SmallTreeLy - 0.13);
	glVertex2f(SmallTreeLx + 0.91, SmallTreeLy - 0.13);
	glVertex2f(SmallTreeLx + 0.91, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 0.94, SmallTreeLy - 0.26);
	glEnd();
	glColor3f(0.0f, 0.88f, 0.0f);
	glBegin(GL_POLYGON);//第九棵
	glVertex2f(SmallTreeLx + 1.0, SmallTreeLy);
	glVertex2f(SmallTreeLx + 1.05, SmallTreeLy);
	glVertex2f(SmallTreeLx + 1.08, SmallTreeLy - 0.06);
	glVertex2f(SmallTreeLx + 1.08, SmallTreeLy - 0.12);
	glVertex2f(SmallTreeLx + 1.05, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 1.0, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 0.97, SmallTreeLy - 0.1);
	glVertex2f(SmallTreeLx + 0.97, SmallTreeLy - 0.04);
	glEnd();
	glColor3f(1.0f, 0.5f, 0.14f);
	glBegin(GL_POLYGON);
	glVertex2f(SmallTreeLx + 1.04, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 1.01, SmallTreeLy - 0.16);
	glVertex2f(SmallTreeLx + 1.01, SmallTreeLy - 0.26);
	glVertex2f(SmallTreeLx + 1.04, SmallTreeLy - 0.26);
	glEnd();
	glFlush();
}
	
void drawStar(void) {//绘制星型风筝
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(Starx, Stary);
	glVertex2f(Starx - 0.04, Stary - 0.18);
	glVertex2f(Starx, Stary - 0.48);
	glVertex2f(Starx + 0.04, Stary - 0.18);
	glEnd();
	glFlush();
}

void drawCloud(void) {//绘制云彩
	glColor3f(0.57f, 0.88f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(CloudLx, 0.7f);
	glVertex2f(CloudLx + 0.05, 0.75f);
	glVertex2f(CloudLx + 0.1, 0.75f);
	glVertex2f(CloudLx + 0.15, 0.7f);
	glVertex2f(CloudLx + 0.1, 0.65f);
	glVertex2f(CloudLx + 0.05, 0.65f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(CloudLx, 0.7f);
	glVertex2f(CloudLx + 0.15, 0.75f);
	glVertex2f(CloudLx + 0.2, 0.75f);
	glVertex2f(CloudLx + 0.25, 0.7f);
	glVertex2f(CloudLx + 0.2, 0.65f);
	glVertex2f(CloudLx + 0.15, 0.65f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(CloudLx + 0.3, 0.7f);
	glVertex2f(CloudLx + 0.35, 0.75f);
	glVertex2f(CloudLx + 0.4, 0.75f);
	glVertex2f(CloudLx + 0.45, 0.7f);
	glVertex2f(CloudLx + 0.4, 0.65f);
	glVertex2f(CloudLx + 0.35, 0.65f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(CloudLx + 0.3, 0.7f);
	glVertex2f(CloudLx + 0.45, 0.75f);
	glVertex2f(CloudLx + 0.5, 0.75f);
	glVertex2f(CloudLx + 0.55, 0.7f);
	glVertex2f(CloudLx + 0.5, 0.65f);
	glVertex2f(CloudLx + 0.45, 0.65f);
	glEnd();
	glFlush();
}

void selectFont(int size, int charset, const char* face) { //用于设置字体的函数
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}void CreateCharacter(const char* str) {//进一步处理
	int len = 0, i;//指示字符数组是否到头
	wchar_t* wstring;//用于保存转换字节后的String
	HDC hDC = wglGetCurrentDC();//wglUseFontBitmapsW函数需要用到的参数，必须通过这种方法生成
	GLuint list = glGenLists(1);//定义一个保存一个字符的显示列表	//len = 0;
	for (i = 0; str[i] != '\0'; ++i)//计算一共有多少个字符，如果是汉字则每两个字节算一个字符
	{
		if (IsDBCSLeadByte(str[i]))//
			++i;
		++len;
	}
	// 由于英文、汉字所占字节不同，所以统一转换为占用相同的字节数
	wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';
	// 逐个输出字符
	for (i = 0; i<len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);// 把每个字符的绘制命令都装到对应的显示列表中
		glCallList(list);//调用显示列表
	}
	// 回收所有临时资源
	free(wstring);
	glDeleteLists(list, 1);
}void showString(void) {//显示文字
	selectFont(25, GB2312_CHARSET, "微软雅黑");//调用设置字体函数
	glColor3f(color7, color8, color9);
	glRasterPos2f(0.6f, 0.6f);
	CreateCharacter("热烈庆祝");	glRasterPos2f(0.45f, 0.5f);	CreateCharacter("华中农业大学建校120周年");	glFlush();}
void TimerColor1(int value)//第一种色彩变化
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
	glutTimerFunc(1000, TimerColor1, 1);
}

void TimerColor2(int value)//第二种色彩变化
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
	glutTimerFunc(500, TimerColor2, 1);
}

void TimerColor3(int value)//第三种色彩变化
{
	k = k + 0.1;
	color9 = color9 - k;
	color8 = color8 + k + 0.12;
	color7 = color7 + k + 0.21;
	if (color9 <= 0.0) {
		color9 = 1.0;
	}
	if (color8 >= 1.0) {
		color8 = 0.0;
	}
	if (color7 >= 1.0) {
		color7 = 0.0;
	}
	if (k >= 1) {
		k = 0;
	}
	glutPostRedisplay(); //刷新画面
	glutTimerFunc(500, TimerColor3, 1);
}

void TimerMove1(int value) {//第一种移动方式
	Stary += 0.1;
	if (Stary >= 0.8) {
		Stary = -0.1;
	}
	glutTimerFunc(700, TimerMove1, 1);
}

void TimerMove2(int value) {//第二种移动方式
	CloudLx = CloudLx + 0.05;
	
	if (CloudLx + 0.55 >= 0.5) {
		CloudLx = -0.5;
	}
	glutTimerFunc(700, TimerMove2, 1);
}

void myDisplay(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置清空背景色为黑色
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清空背景为黑色
	drawAround();//绘制色块
	drawHZAU();//绘制HZAU
	showString();//显示文字
	drawTree();//绘制树
	drawStar();//绘制星型风筝
	drawCloud();//绘制云彩
	drawSmallTree1();//绘制小树
	drawSmallTree2();
	drawSmallTree3();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("缤纷HZAU120周年"); // 设置窗口标题
	glutDisplayFunc(&myDisplay);
	glutTimerFunc(1000, TimerColor1, 1);//实现移动和变色效果
	glutTimerFunc(500, TimerColor2, 1);
	glutTimerFunc(700, TimerColor3, 1);
	glutTimerFunc(400, TimerMove1, 1);
	glutTimerFunc(400, TimerMove2, 1);
	glutMainLoop();
	return 0;
}