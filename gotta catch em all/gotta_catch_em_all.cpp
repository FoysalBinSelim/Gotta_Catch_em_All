#include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>

int a_x= rand();
int b_x = 850;

int c_x= 0;
int d_y = rand();

int m_x= rand();
int n_y= 0;

int p_x= 850;
int q_y= rand();

int x=200;
int y=50;

int goal_x=ran();
int goal_y=rand();

int life=50;

int score = 0;

int time = 60;

int page = 0;

char scores[30];

char HP[30];


void animateball(){

if(b_y>=800){
	a_x=rand()%800;
	}

	b_y -= 20;

	if(b_y<=0){
		b_y=900;
		time--;
		}
	if(a_x>=x && a_x<=x+200 && b_y>y && b_y<=y+200){
		b_y=900;
		life--;
		}
	if(life==0){
		exit(0);
	}

}

void animateball2(){
if(c_x<=0){
	d_y=rand()%800;
	}
	c_x += 20;
	if(c_x>=800){
		c_x = 0;
		}
	if(c_x>=x && c_x<=x+200 &&  d_y>y && d_y<=y+200){
		c_x = 0;
		life--;
		}
	if(life==0){
		exit(0);
	}

}

void animateball3(){
if(n_y<=0){
	m_x=rand()%800;
	}

	n_y += 30;

	if(n_y<=900){
		n_y=0;
		
		}

	if(m_x>=x && m_x<=x+200 && n_y>y && n_y<=y+200){
		n_y=0;
		life--;
		}

	if(life==0){
		exit(0);
	}

}

void animateball4(){
if(p_x>=850){
	q_y=rand()%800;
	}

	p_x -= 30;

	if(p_x<=0){
		p_x = 850;
		}

	if(p_x>=x && p_x<=x+200 && q_y>=y && q_y<=y+200){
		p_x = 850;
		life--;
		}

	if(life==0){
		exit(0);
	}

}

void animateball5(){
	if(goal_x>=x && goal_x<=x+200 && goal_y>=y && goal_y<=y+200){
		goal_x=rand();
		goal_y=rand();
		scaore=score+1;}
}



void iDraw()
{
	iClear();
	if(page==0)
	{
		iShowBMP(0,0,"menu.bmp");
		iSetColor(250,0,0);
		iText(200,50,"For Next page>>Press N",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(page==1)
	{
		iShowBMP(0,0,"menu.bmp");
		iSetColor(3,4,28);
		iText(100,350,"PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,250,"Control",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,150,"High Score",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,50,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//Game page
	else if(page==2)
	{
	
	iShowBMP(0,0,"Wild_Plains.bmp");
	

	iSetColor(64,0,0);
	iFilledCircle(a_x,b_y,20);

	iSetColor(0,64,64);
	iFilledCircle(c_x,d_y,30);

	iSetColor(128,0,255);
	iFilledCircle(m_x,n_y,20);

	iSetColor(255,128,0);
	iFilledCircle(p_x,q_y,20);

	iShowBMP2(x,y,"pikachu.bmp",255);
	iSetColor(168,255,255);

	
	iShowBMP2(goal_x,goal_y,"PokeBall.bmp",255);
	iSetColor(118,255,90);
	

	iText(0,760,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);//Score
	itoa(score,scores,10);

	iText(175,760,scores,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700,760,"LIFE: ",GLUT_BITMAP_TIMES_ROMAN_24);//Life
								 
	iText(740,740,HP,GLUT_BITMAP_TIMES_ROMAN_24);
 
	sprintf(HP,"%d",life);
	}


	//control
	else if(page==3)
	{
		
	}

	//high_score
	else if(page==4)
	{
		iSetColor(0,0,0);
	}
	
}


void iMouseMove(int mx, int my)
{
	x = mx;
	y = my;
}

void iMouse(int button, int state, int mx, int my)
{
	if(button==GLUT_LEFT && state==GLUT_DOWN)
	{
		
		if((mx>100 && mx<150)&&(my>40 && my<100))
		{
			if(page==1)
			{
				exit(1);
			}
		}
	
		
		if((mx>100 && mx<300)&&(my>340 && my<400))
		{
			page=2;
		}

		
		if((mx>100 && mx<300)&&(my>240 && my<300))
		{
			page=3;
		}

		
		if((mx>100 && mx<300)&&(my>140 && my<200))
		{
			page=4;
		}
	}
}

void iKeyboard(unsigned char key)
{
	if(key=='n' || key=='N')//to continue
	{
		page++;
	}
	if(key=='b' || key=='B')//to go back;
	{
		page--;
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if(key==GLUT_KEY_RIGHT){
		x+=30;
	}else if(key==GLUT_KEY_LEFT){
		x-=30;
	}else if(key==GLUT_KEY_UP){
		y+=30;
	}else if(key==GLUT_KEY_DOWN){
		y-=30;
	}
}
int main()
{
	
	iSetTimer(20,animateball);
	iSetTimer(30,animateball2);
	iSetTimer(30,animateball3);
	iSetTimer(20,animateball4);
	iSetTimer(3000,animateball5);
	
	iInitialize(800, 800,"Pikachuu!! gotta catch em' all");
	return 0;
}