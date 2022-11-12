struct fris{          //建立结构体 
	int n;
	char name[20];
	char num1[20];
	char num2[20];
	char note[100];
	struct fris *next;
};
typedef struct fris friends;

int N(friends*head){                   //判断链表结点个数函数 
	friends*A,*B;
	A=head;
	int n=0;
	while(A!=NULL){
		B=A->next;
		A=B;
		n++;
	}
	return n;
}


void clear(int y){               //清除一行内容函数 
	int x;
	for(x=2;x<116;x++){
		gotoxy(x,y);
		printf(" ");
	}
}
void clear2(int x,int y){             //清除输入区单个内容函数 
	int a;
	for(a=x;a<x+20;a++){
		gotoxy(a,y);
		printf(" ");
	}
	gotoxy(x,y);
}

void cleardata(friends*head){            //清除全部输入区函数 
	setbkcolor(15);
	int a=N(head);
	int i;
	for(i=7;i<=7+a;i++){
		clear(i);
	}
}

void mov(int x,int y){                //光标利用上下左右移动函数 
int n;
gotoxy(x,y);
n=getch();
while(n!=enter){
	switch(n){
		case left:
			x--;
		gotoxy(x,y);
	break;
		case right:
			x++;
			gotoxy(x,y);
	break;
		case up:
			y--;
			gotoxy(x,y);
		break;
	case down:
			y++;
			gotoxy(x,y);
		break;
}
n=getch();
}
}
