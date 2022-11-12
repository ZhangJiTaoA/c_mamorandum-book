void graph(int x1,int y1,int x2,int y2){             //主要界面函数 
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


void proj1(){                              //开始界面函数 
	setbkcolor(7); 
	gotoxy(2,3);
	printf("打开（ctrl+k）");
	gotoxy(42,3);
	printf("新建（ctrl+n）"); 
	gotoxy(82,3);
	printf("删除文件（ctrl+q）");


	gotoxy(2,5);
	printf("序号");
	gotoxy(20,5);
	printf("姓名"); 
	gotoxy(42,5);
	printf("号码1"); 
	gotoxy(64,5);
	printf("号码2"); 
	gotoxy(85,5);
	printf("备注");
}

void proj2(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("新建中");
	setbkcolor(15);
}

void proj3(){
	setbkcolor(7);
	clear(3);
	gotoxy(2,3);
	printf("删除文件（ctrl+q）");
	gotoxy(21,3);
	printf("修改文件名（ctrl+e）");
	gotoxy(42,3);
	printf("删除项目（ctrl+d）");
	gotoxy(61,3);
	printf("修改内容（ctrl+z）");
	gotoxy(80,3);
	printf("搜索（ctrl+s）");
	gotoxy(95,3);
	printf("添加(ctrl+a)");
	gotoxy(109,3);
	printf("退出esc"); 
	setbkcolor(15);
}

void proj4(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("正在删除！"); 
	setbkcolor(15);
}

void proj5(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("正在修改文件名！"); 
	setbkcolor(15);
}

void proj6(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("正在删除项目！"); 
	setbkcolor(15);
}

void proj7(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("正在修改项目内容！"); 
	setbkcolor(15);
}

void proj8(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("正在搜索项目！"); 
	setbkcolor(15);
}

void proj9(){
	setbkcolor(7);
	clear(3);
	gotoxy(2,3);
	printf("删除项目（ctrl+d）");
	gotoxy(50,3);
	printf("修改内容（ctrl+z）");
	gotoxy(109,3);
	printf("退出esc"); 
	setbkcolor(15);
} 

void proj0(){
	setbkcolor(7);
	clear(3);
	gotoxy(52,3);
	printf("正在添加项目！"); 
	setbkcolor(15);
}



