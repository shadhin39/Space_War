#include<stdio.h>
#include "iGraphics.h"
#include "KeyAir.h"
#include "background.h"



int Screen = 1,yb=300;
int screenwidth=1000,screenheight=600,dx=10,dy=10,dz=10,dn=10;
bool musicOn= true;

int xcord = 10;
int ycord = 500;
int BulletCount = 0;
int BulletTimer = 0;
int enemyX = 1000,enemyY = 600,enemy_Speed = 10;
int dx1 = -10;
int dy1 = -40;
int dx2= 40,dy2 = 40;
int x1 ;
//int y1;
int x2;
int y2;
//int flag = 0;
//int playerLife=1;

int point = 0;
char string[10] ;


//home
void Home()
{
	iShowBMP(0, 0, "images\\cover for game1.bmp");
	iSetColor(255, 255, 255);
	iShowBMP2(200,250,"images\\kill1.bmp",0);
	iText(200, 30, "Press F1 for continue,Press F2 to ON or OFF the Music", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,0,0);
	

}
//menu
void Menu()
{
	iShowBMP(0, 0, "images\\menu.bmp");
	iShowBMP2(500, 500, "bmp1\\start.bmp",255);
	iShowBMP2(500, 400, "bmp1\\highscores.bmp",255);
	iShowBMP2(500, 300, "bmp1\\aboutus.bmp",255);
	iShowBMP2(500, 200, "bmp1\\ins.bmp",255);
	iShowBMP2(500, 100, "bmp1\\exit.bmp",255);
}
//pause or resume game
void pause()
{
	iShowBMP2(0, 0, "images\\pausemenu.bmp",255);
	iShowBMP2(650, 450, "images\\Resume.bmp",255);
	iShowBMP2(650, 350, "images\\Main_Menu.bmp",255);
	iShowBMP2(650, 250, "images\\Exit.bmp",255);
}
/*void change()
{
	//Enemy_change();
	z-=dz;
   
	
}*/


//bullet
struct Bullet{
	int x,y;
	bool  hasShot;

}bullet[100];


//enemy
struct Enemy{
	int x,y;
	bool active;

}enemy[6];


void Enemy()
{

	for (int i = 0,x1=100 ; i < 6 ; i++,x1+=100)
	{enemy[i].x -= 20;
		if(enemy[i].x<0 )
		{	enemy[i].x =enemyX + x1;
			enemy[i].y = (enemyY-100)- rand() % 500;
			enemy[i].active = true;
		}
	}
}

void showEnemy()
{
	for (int i = 0 ; i < 6 ; i++)
		{
			if (enemy[i].active==true)
				{
					iShowBMP2(enemy[i].x,enemy[i].y,"bmp1//enemy.bmp",0);
				}
		}
}


void bulletShow()//call from doWork function which Call from iDraw function for Show the Bullet
{
	for(int i = 0; i < BulletCount ; i++)
		{
			if(bullet[i].hasShot== true )
				{
					iShowBMP2(bullet[i].x,bullet[i].y,"bmp1//bullet1.bmp",0);
				}	
		}	
}


void BulletShoot()
{
	for(int i = 0 ; i < BulletCount ; i++)
	{
		
		if(bullet[i].hasShot)
			bullet[i].x += 20;

		if(bullet[i].x > 1370)
			bullet[i].hasShot = false;

	}
}


int mposx,  mposy;
/*
	function iDraw() is called again and again by
	the system.
*/
void iDraw()
{
	iClear();
	if (Screen==1)
	{
		Home();
	}
	if (Screen==2)
	{
		Menu();
	}
	if (Screen==3)
	{
		iShowBMP(0,0,"images\\farback.bmp");
		KeyAir_change();
		showEnemy();
		bulletShow();
	    //change();
		
		
	}
	if (Screen==6)
	{
		pause();

	}
	if(Screen==7)
	{
		iShowBMP(0,0,"images\\ins1.bmp");
	}
	if(Screen==10){
		iShowBMP2(250,100,"images\\game over.bmp",0);
		
	}
	if(Screen==5)
	{
		iShowBMP(0,0,"images\\AboutUs.bmp");
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x : %d\ty: %d\n", mx, my);
		if (mx >= 500 && mx <= 900 && my >= 500 && my <= 570 && Screen == 2)
			Screen = 3; //Play Game
		if (mx >= 500 && mx <= 900 && my >= 400 && my <= 470 && Screen == 2)
			Screen = 4; //Show High Score
		if (mx >= 500 && mx <= 900 && my >= 300 && my <= 370 && Screen == 2){
			Screen = 5;
			//About
		}
		if (mx >= 500 && mx <= 900 && my >= 200 && my <= 270 && Screen == 2)
		
			Screen = 7; //Instructions
			
	
			
		if (mx >= 500 && mx <= 900 && my >= 100 && my <= 170 && Screen == 2)
			exit(0);
		if (mx >= 500 && mx <= 850 && my >= 450 && my <= 520 && Screen == 6)
		{
			
			Screen = 3;
			iResumeTimer(0);
		    iResumeTimer(1);

		}
			
		if (mx >= 650 && mx <= 850 && my >= 350 && my <= 420 && Screen == 6)
			Screen = 2;
		if (mx >= 650 && mx <= 850 && my >= 250 && my <= 320 && Screen == 6)
			exit(0);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		Screen = 6;
	}
	if (key =='r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
		Screen = 3;
	}
	if (key == '\r')
	{
		if(Screen==4||Screen==5||Screen==6||Screen==7)
			Screen = 2;
	}
	if(key=='w')
		n+=dn;
	if(key=='s')
	   n-=dn;
	if(key=='a')
		z-=dz;
	if(key=='d')
		z+=dz;
	if(key == 32)
	{
		if(BulletCount<100)
			BulletCount++;
		else if(BulletCount==100)
			BulletCount=0;

		bullet[BulletCount-1].hasShot=true;
		bullet[BulletCount-1].x=x+120;
		bullet[BulletCount-1].y=y+50;
	}
}
	//place your codes for other keys here


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key ==GLUT_KEY_F1)
	{
		if (Screen == 1)
			Screen = 2;
	}
	if(key == GLUT_KEY_F2)
	{
		if(musicOn){
			musicOn=false;
			PlaySound(0,0,0);
		}
	else
	{
		
			musicOn=true;
			PlaySound("music//23.wav",NULL,SND_LOOP|SND_ASYNC);
		} 
	}

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if(key== GLUT_KEY_UP)
	{
		//y+=dy;
		if(y<450)
		{
			y+=dy;
		}
		
		
	   /* if(y==screenheight)
		{
			Screen=10;
		}*/
		    
	}
	else if(key== GLUT_KEY_DOWN)
	{
		//y-=dy;
		if(y>10)
		{
			y-=dy;
		}
		 /*if(y==0)
		{
			Screen=10;
		}*/
	}
		
	else if(key== GLUT_KEY_RIGHT)
	{
		if(x>0)
		
		x+=dx;
		
		//if(x>=screenwidth||x<=0)
		//dx*=(-1);
		/*
		if(x==screenwidth)
			Screen=10;
			*/
	}
		
	else if(key== GLUT_KEY_LEFT)
     {
		 if(x>600)
		x-=dx;
		//if(x>=screenwidth||x<=0)
		//dx*=(-1);
		/*if(x==0)
			Screen=10;*/
	}
	//place your codes for other keys here
}

//

int main()
{
	//place your own initialization codes here.
	setBackground();
	KeyAir_change();
	//iSetTimer(25,change);
	if (musicOn)
	{
		PlaySound("music//23.wav",NULL,SND_LOOP|SND_ASYNC);
	}
	BulletTimer = iSetTimer(10,BulletShoot);
	iSetTimer(300,Enemy);
	//iSetTimer(100000,change);
	iInitialize(screenwidth, screenheight, "Space War");
	return 0;
}