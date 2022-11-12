char filena[20];
void save(friends*head){                            //保存文件函数 
	FILE*fp=NULL;
	char filename[20];
	clear(1);
	gotoxy(2,1);
	printf("请输入文件名：");
	scanf("%s",&filename);
	fp=fopen(filename,"wb");
	if(fp==NULL){
		gotoxy(2,1);
		printf("文件保存失败！");
		exit(0); 
	}
	
	int i;
	friends*A,*B;
	A=head;
	for(i=0;i<N(head);i++){
		if(fwrite(A,sizeof(friends),1,fp)==0){
			gotoxy(2,1);
			printf("写入失败！");
			exit(0); 
		}
		B=A;
		A=B->next;
	}
	fclose(fp); 
	clear(1);
	gotoxy(2,1);
	printf("保存成功！按任意键继续！ ");	
	getch(); 
	read(head);
	
}

friends*readfil(){                                     //读取文件函数 
	FILE*fp=NULL;
	char filename[20];
	for(;;){
	clear(1); 
	gotoxy(2,1);
	printf("请输入目录名：");
	scanf("%s",&filename);
	strcpy(filena,filename);
	fp=fopen(filename,"rb");
	if(fp==NULL){
		clear(1);
		gotoxy(2,1);
		printf("打开失败！");
	gotoxy(20,1);
	printf("是否重新输入目录？（y/n）");
	butt=getch();
    	for(;butt!=0x79&&butt!=0x6e;){
			clear(1);
			gotoxy(2,1);
			printf("无法识别命令，请重新输入   否重新输入目录？（y/n）");
			butt=getch(); 
		} 
		if(butt==0x6e) {
		return NULL;
	}
	}
	else
	break; 
} 
	friends *head,*A,*B;
	head=(friends*)malloc(sizeof(friends));
	if(head==NULL){
		printf("申请内存失败！");
		return NULL; 
	}
	A=head;
	while(1){
		if(fread(A,sizeof(friends),1,fp)==0){
			break;
		}
		else{
			A->next=(friends*)malloc(sizeof(friends));
			if(A->next==NULL){
				printf("申请内存失败！");
				return NULL; }
				B=A;
				A=A->next;
			}	
	
		}
		B->next=NULL;
		fclose(fp);
    	clear(1);
    	gotoxy(2,1);
    	printf("读取成功！"); 
		return head;
}





