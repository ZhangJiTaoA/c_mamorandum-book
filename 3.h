void graph(int x1,int y1,int x2,int y2){             //��Ҫ���溯�� 
	setbkcolor(9);
	int m=y1;
	for(m=y1;m<=y2;m++){
		gotoxy(x1,m);
		putch(0xcd);
		gotoxy(x2,m);
		putch(0xcd);
	}
	for(m=x1+1;m<x2;m++){
		gotoxy(m,y1);
		putch(0xbb); 
		gotoxy(m,y2);
		putch(0xbb);
	}
	
}


void proj1(){                              //��ʼ���溯�� 
	setbkcolor(7); 
	gotoxy(2,3);
	printf("�򿪣�ctrl+k��");
	gotoxy(42,3);
	printf("�½���ctrl+n��"); 
	gotoxy(82,3);
	printf("ɾ���ļ���ctrl+q��");


	gotoxy(2,5);
	printf("���");
	gotoxy(20,5);
	printf("����"); 
	gotoxy(42,5);
	printf("����1"); 
	gotoxy(64,5);
	printf("����2"); 
	gotoxy(85,5);
	printf("��ע");
}

void proj2(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("�½���");
	setbkcolor(15);
}

void proj3(){
	setbkcolor(7);
	clear(3);
	gotoxy(2,3);
	printf("ɾ���ļ���ctrl+q��");
	gotoxy(21,3);
	printf("�޸��ļ�����ctrl+e��");
	gotoxy(42,3);
	printf("ɾ����Ŀ��ctrl+d��");
	gotoxy(61,3);
	printf("�޸����ݣ�ctrl+z��");
	gotoxy(80,3);
	printf("������ctrl+s��");
	gotoxy(95,3);
	printf("���(ctrl+a)");
	gotoxy(109,3);
	printf("�˳�esc"); 
	setbkcolor(15);
}

void proj4(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("����ɾ����"); 
	setbkcolor(15);
}

void proj5(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("�����޸��ļ�����"); 
	setbkcolor(15);
}

void proj6(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("����ɾ����Ŀ��"); 
	setbkcolor(15);
}

void proj7(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("�����޸���Ŀ���ݣ�"); 
	setbkcolor(15);
}

void proj8(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("����������Ŀ��"); 
	setbkcolor(15);
}

void proj9(){
	setbkcolor(7);
	clear(3);
	gotoxy(2,3);
	printf("ɾ����Ŀ��ctrl+d��");
	gotoxy(50,3);
	printf("�޸����ݣ�ctrl+z��");
	gotoxy(109,3);
	printf("�˳�esc"); 
	setbkcolor(15);
} 

void proj0(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("���������Ŀ��"); 
	setbkcolor(15);
}



