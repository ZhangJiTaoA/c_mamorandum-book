int butt;


void read(friends*head){             //读取链表函数 
	int i=7;
	friends *A,*B;
	A=head;
	while(A!=NULL){
		gotoxy(2,i);
		printf("%d",A->n);
		gotoxy(20,i);
		printf("%s",A->name);
		gotoxy(42,i);
		printf("%s",A->num1);
		gotoxy(64,i); 
		printf("%s",A->num2);
		gotoxy(85,i);
		printf("%s",A->note);	
		B=A->next;
		A=B;
		i++;
	}
}



friends *news(){                             //新建链表函数 
	friends *tail,*head;
	head=(friends*)malloc(sizeof(friends));
	if(head==NULL){
		printf("申请内存失败！");
		return NULL; 
	}
	head->next=NULL;
	tail=head;
	
	friends *newfil;
	int i=7;
	int abc=0;
	clear(1);
	gotoxy(2,1); 
	printf("开始新建，请按enter！结束按（esc）"); 
	while((butt=getch())!=0x1b){
		newfil=(friends*)malloc(sizeof(friends));
		if(newfil==NULL){
			printf("申请内存失败！");
			return NULL; 
		}
		gotoxy(20,i);
		scanf("%s",newfil->name);
		fflush(stdin);
		gotoxy(42,i);
		scanf("%s",&newfil->num1);
		fflush(stdin);
		gotoxy(64,i); 
		scanf("%s",&newfil->num2);
		fflush(stdin);
		gotoxy(85,i);
		scanf("%s",&newfil->note);
		fflush(stdin);	
	    tail->next=newfil;
	    tail=newfil;
		abc++;
		tail->n=abc;
		gotoxy(2,i);
		printf("%d",tail->n);
		gotoxy(20,i);
		printf("%s",tail->name);
		gotoxy(42,i);
		printf("%s",tail->num1);
		gotoxy(64,i); 
		printf("%s",tail->num2);
		gotoxy(85,i);
		printf("%s",tail->note);	
		i++;
	} 
	tail->next=NULL;
	head=head->next;
	return head;
}


friends *insert1(friends*head){                               //添加插入第一个结点 
	int abc=0;
	friends*A;
	A=(friends*)malloc(sizeof(friends));
	if(A==NULL){
		gotoxy(2,1);
		printf("申请内存失败！");
		return NULL; 
	}
	cleardata(head);
	gotoxy(2,1);
	printf("请在以下位置输入插入内容！");
		gotoxy(20,7);
		scanf("%s",&A->name);
		fflush(stdin);
		gotoxy(42,7);
		scanf("%s",&A->num1);
		fflush(stdin);
		gotoxy(64,7); 
		scanf("%s",&A->num2);
		fflush(stdin);
		gotoxy(85,7);
		scanf("%s",&A->note);
		fflush(stdin);
	A->next=head;
	head=A;
	abc++;
	friends*B;
	while(A->next!=NULL){
		A->n=abc;
		B=A;
		A=B->next;
		abc++;
	}
	A->n=abc;
	read(head); 
	return head;
}

friends *insert2(friends*head,int i){          //添加插入任意结点之后 
	if(i>N(head)){
		clear(1);
		gotoxy(2,1); 
		printf("无法插入内容之间！！！");
	}
	friends*A,*B;
	A=(friends*)malloc(sizeof(friends));
		if(A==NULL){
			gotoxy(2,1);
			printf("申请内存失败！");
			exit(0); 
		}
	cleardata(head);
	    clear(1);
		gotoxy(2,1);
		printf("请在以下位置输入内容！"); 
		gotoxy(20,7);
		scanf("%s",&A->name);
		fflush(stdin);
		gotoxy(42,7);
		scanf("%s",&A->num1);
		fflush(stdin);
		gotoxy(64,7); 
		scanf("%s",&A->num2);
		fflush(stdin);
		gotoxy(85,7);
		scanf("%s",&A->note);
		fflush(stdin);
	
		B=head;
		while(B->n!=i){
		B=B->next;
		}
		A->next=B->next;
		A->n=B->n+1;
		B->next=A;
		while(A->next!=NULL){
			B=A;
			A=B->next;
			A->n++;
		}
		read(head);
		return head;	
}

friends*del(friends*head,int z){                         //删除结点函数 
	if(z>N(head)){
		clear(1);
		gotoxy(2,1);
		printf("不存在此项目！(任意键继续)");
		getch();
		return head; 
		
	} 
	cleardata(head);
	friends*A,*B;
	B=A=head;
	if(z!=1){
	while(A->n!=z){
		B=A;
		A=A->next;
	}	
	B->next=A->next;
	free(A);
		if(B->next!=NULL){
			do{
				A=B->next;
				A->n--;
				B=A;
			}while(A->next!=NULL);
	}
	} 
	else{
		A=head;
		head=head->next;
		free(A);
		B=head;
		while(B!=NULL){
			B->n--;
			B=B->next;
	}
}
	read(head);
	return head;
}

friends*sort(friends*head){                         //搜索链表结点函数 
	friends*A,*B;
	char name2[20];
	clear(1);
	gotoxy(2,1);
	printf("请输入要搜索的标题！(序号请输入“1”，姓名请输入“2”，号码1请输入“3”，号码2请输入“4”)：");
	int p;
	scanf("%d",&p); 
	switch(p){
		case 2:
			for(;;){
			clear(1); 
			gotoxy(2,1);
			printf("请输入要搜索的姓名：");
			scanf("%s",&name2); 
			A=head;
			while((A!=NULL)&&strcmp(A->name,name2)){ 
				B=A;
				A=B->next;
			}
	
			if(A==NULL){
				clear(1);
				gotoxy(2,1);
				printf("未找到所搜索的姓名！(按任意键继续)；");
				getch();
				clear(1);
				gotoxy(2,1);
				printf("是否重新输入？（y/n）");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("输入命令错误，请重新输入！          是否重新输入？（y/n）");
					butt=getch(); 
				}
				if(butt==0x6e)
					break; 
			}
		
			else{
			cleardata(head);
			gotoxy(2,7);
			printf("%d",A->n);
			gotoxy(20,7);
			printf("%s",A->name);
			gotoxy(42,7);
			printf("%s",A->num1);
			gotoxy(64,7); 
			printf("%s",A->num2);
			gotoxy(85,7);
			printf("%s",A->note);	
			return A; 
		}
	}
		return A;
		case 1:
			for(;;){
			int a;
			clear(1);
			gotoxy(2,1);
			printf("请输入要搜索的代号：");
			scanf("%d",&a);
			A=head;
			while((A!=NULL)&&(A->n!=a)){
				B=A;
				A=B->next;
			} 
			if(A==NULL){
				gotoxy(60,1);
				printf("未找到相符的代号！(按任意键继续)；"); 
				getch();
				clear(1);
				gotoxy(2,1);
				printf("是否重新输入？（y/n）");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("输入命令错误，请重新输入！          是否重新输入？（y/n）");
					butt=getch(); 
				}
				if(butt==0x6e){
						break;
					}
			} 
			else{
				cleardata(head);
				gotoxy(2,7);
				printf("%d",A->n);
				gotoxy(20,7);
				printf("%s",A->name);
				gotoxy(42,7);
				printf("%s",A->num1);
				gotoxy(64,7); 
				printf("%s",A->num2);
				gotoxy(85,7);
				printf("%s",A->note);	
				return A;
			}
		}
			return A;
		case 3:
			for(;;){
			char c[20];
			clear(1);
			gotoxy(2,1);
			printf("请输入要搜索的号码：");
			scanf("%s",&c);
			A=head;
			while((A!=NULL)&&(A->num1!=c)){
				B=A;
				A=B->next;
			} 
			if(A==NULL){
				gotoxy(60,1);
				printf("未找到相符的号码！（按任意键继续）；"); 
				getch();
				clear(1);
				gotoxy(2,1);
				printf("是否重新输入？（y/n）");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("输入命令错误，请重新输入！          是否重新输入？（y/n）");
					butt=getch(); 
				}
				if(butt==0x6e)
						break; 
			}
			else{
				cleardata(head);
				gotoxy(2,7);
				printf("%d",A->n);
				gotoxy(20,7);
				printf("%s",A->name);
				gotoxy(42,7);
				printf("%s",A->num1);
				gotoxy(64,7); 
				printf("%s",A->num2);
				gotoxy(85,7);
				printf("%s",A->note);	
				return A;
			}
		}
			return A;
		case 4:
			for(;;){
			clear(1);
			gotoxy(2,1);
			printf("请输入要搜索的号码：");
			char b[20];
			scanf("%s",&b);
			A=head;
			while((A!=NULL)&&(A->num2!=b)){
				B=A;
				A=B->next;
			} 
			if(A==NULL){
				gotoxy(60,1);
				printf("未找到相符的号码！（按任意键继续）；"); 
				getch();
				clear(1);
				gotoxy(2,1);
				printf("是否重新输入？（y/n）");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("输入命令错误，请重新输入！          是否重新输入？（y/n）");
					butt=getch(); 
				}
				if(butt==0x6e)
						break; 
			}
			else{
				cleardata(head);
				gotoxy(2,7);
				printf("%d",A->n);
				gotoxy(20,7);
				printf("%s",A->name);
				gotoxy(42,7);
				printf("%s",A->num1);
				gotoxy(64,7); 
				printf("%s",A->num2);
				gotoxy(85,7);
				printf("%s",A->note);
				return A;	
			}
		}
			return A;
	}

}



friends*mod(friends*head,int i){                             //修改结点函数 
	if(i>N(head)){
		clear(1);
		gotoxy(2,1);
		printf("序号不存在！  （按任意键继续！）");
		getch();
		return NULL; 
	}
	friends*A,*B;
	B=A=head;
	while(A->n!=i){
		B=A->next;
		A=B;
	}
	for(;;){
	gotoxy(2,1);
	printf("请输入要修改序号%d的项目！(姓名请输入“1”，号码1请输入“2”，号码2请输入“3”，备注请输入“4”):",A->n);
	int b;
	scanf("%d",&b);
	switch(b){
		case 1:
			gotoxy(20,6+i);
			clear2(20,6+i);
			scanf("%s",&A->name);
		break;
		case 2:
			gotoxy(42,6+i);
			clear2(42,6+i);
			scanf("%s",&A->num1);
		break;
		case 3:
			gotoxy(64,6+i);
			clear2(64,6+i);
			scanf("%s",&A->num2);
		break;
		case 4:
			gotoxy(85,6+i);
			clear2(85,6+i);
			scanf("%s",&A->note);
		break;
	}
	 clear(1);
	 gotoxy(2,1);
	 printf("是否继续修改本行内容？(y/n) :");
	 if(getch()==0x6e)
	 	break;
	}
	return head;
} 



