#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define left 0x4b
#define right 0x4d
#define up 0x48
#define down 0x50
#define enter 0x0d
void gotoxy(int x,int y){
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos); 
}

void setcolor(unsigned short ForeColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(ForeColor%16));
}
void setbkcolor(unsigned short BackGroundColor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(BackGroundColor%16*16));
} 

void bkcolor(int x1,int y1,int x2,int y2,unsigned short n){               //确定位置设置背景色函数 
	setbkcolor(n);
	int x,y;
	x=x1;
	y=y1;
	for(;y<=y2;y++){
		for(;x<=x2;x++){
			gotoxy(x,y);
			printf(" ");
		}
		x=x1;
	}
}

void color(){                                             //画颜色函数 
	bkcolor(2,3,115,5,7);     //表头区 
	bkcolor(2,6,115,27,15);   //输入区 

	bkcolor(1,1,1,28,9);    //边框区 
	bkcolor(1,2,116,2,9);
	bkcolor(1,28,116,28,9);
	bkcolor(116,1,116,28,9);
	bkcolor(117,0,117,28,7);
	bkcolor(0,0,0,28,7);
	setbkcolor(9); 
	int i;
		for(i=1;i<117;i++){
		gotoxy(i,0);
		printf(" ");
	}
	gotoxy(50,0);
	printf("个人备忘录"); 
	setbkcolor(12);
		for(i=2;i<116;i++){
		gotoxy(i,4);
		putch(0xbb);
	}
		for(i=2;i<116;i++){
		gotoxy(i,6);
		putch(0x2d);
	} 

	
}









