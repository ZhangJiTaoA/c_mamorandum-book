struct fris{          //�����ṹ�� 
	int n;
	char name[20];
	char num1[20];
	char num2[20];
	char note[100];
	struct fris *next;
};
typedef struct fris friends;

int N(friends*head){                   //�ж�������������� 
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


void clear(int y){               //���һ�����ݺ��� 
	int x;
	for(x=2;x<116;x++){
		gotoxy(x,y);
		printf(" ");
	}
}
void clear2(int x,int y){             //����������������ݺ��� 
	int a;
	for(a=x;a<x+20;a++){
		gotoxy(a,y);
		printf(" ");
	}
	gotoxy(x,y);
}

void cleardata(friends*head){            //���ȫ������������ 
	setbkcolor(15);
	int a=N(head);
	int i;
	for(i=7;i<=7+a;i++){
		clear(i);
	}
}

void mov(int x,int y){                //����������������ƶ����� 
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
