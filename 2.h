int butt;


void read(friends*head){             //��ȡ������ 
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



friends *news(){                             //�½������� 
	friends *tail,*head;
	head=(friends*)malloc(sizeof(friends));
	if(head==NULL){
		printf("�����ڴ�ʧ�ܣ�");
		return NULL; 
	}
	head->next=NULL;
	tail=head;
	
	friends *newfil;
	int i=7;
	int abc=0;
	clear(1);
	gotoxy(2,1); 
	printf("��ʼ�½����밴enter����������esc��"); 
	while((butt=getch())!=0x1b){
		newfil=(friends*)malloc(sizeof(friends));
		if(newfil==NULL){
			printf("�����ڴ�ʧ�ܣ�");
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


friends *insert1(friends*head){                               //��Ӳ����һ����� 
	int abc=0;
	friends*A;
	A=(friends*)malloc(sizeof(friends));
	if(A==NULL){
		gotoxy(2,1);
		printf("�����ڴ�ʧ�ܣ�");
		return NULL; 
	}
	cleardata(head);
	gotoxy(2,1);
	printf("��������λ������������ݣ�");
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

friends *insert2(friends*head,int i){          //��Ӳ���������֮�� 
	if(i>N(head)){
		clear(1);
		gotoxy(2,1); 
		printf("�޷���������֮�䣡����");
	}
	friends*A,*B;
	A=(friends*)malloc(sizeof(friends));
		if(A==NULL){
			gotoxy(2,1);
			printf("�����ڴ�ʧ�ܣ�");
			exit(0); 
		}
	cleardata(head);
	    clear(1);
		gotoxy(2,1);
		printf("��������λ���������ݣ�"); 
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

friends*del(friends*head,int z){                         //ɾ����㺯�� 
	if(z>N(head)){
		clear(1);
		gotoxy(2,1);
		printf("�����ڴ���Ŀ��(���������)");
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

friends*sort(friends*head){                         //���������㺯�� 
	friends*A,*B;
	char name2[20];
	clear(1);
	gotoxy(2,1);
	printf("������Ҫ�����ı��⣡(��������롰1�������������롰2��������1�����롰3��������2�����롰4��)��");
	int p;
	scanf("%d",&p); 
	switch(p){
		case 2:
			for(;;){
			clear(1); 
			gotoxy(2,1);
			printf("������Ҫ������������");
			scanf("%s",&name2); 
			A=head;
			while((A!=NULL)&&strcmp(A->name,name2)){ 
				B=A;
				A=B->next;
			}
	
			if(A==NULL){
				clear(1);
				gotoxy(2,1);
				printf("δ�ҵ���������������(�����������)��");
				getch();
				clear(1);
				gotoxy(2,1);
				printf("�Ƿ��������룿��y/n��");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("��������������������룡          �Ƿ��������룿��y/n��");
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
			printf("������Ҫ�����Ĵ��ţ�");
			scanf("%d",&a);
			A=head;
			while((A!=NULL)&&(A->n!=a)){
				B=A;
				A=B->next;
			} 
			if(A==NULL){
				gotoxy(60,1);
				printf("δ�ҵ�����Ĵ��ţ�(�����������)��"); 
				getch();
				clear(1);
				gotoxy(2,1);
				printf("�Ƿ��������룿��y/n��");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("��������������������룡          �Ƿ��������룿��y/n��");
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
			printf("������Ҫ�����ĺ��룺");
			scanf("%s",&c);
			A=head;
			while((A!=NULL)&&(A->num1!=c)){
				B=A;
				A=B->next;
			} 
			if(A==NULL){
				gotoxy(60,1);
				printf("δ�ҵ�����ĺ��룡�����������������"); 
				getch();
				clear(1);
				gotoxy(2,1);
				printf("�Ƿ��������룿��y/n��");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("��������������������룡          �Ƿ��������룿��y/n��");
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
			printf("������Ҫ�����ĺ��룺");
			char b[20];
			scanf("%s",&b);
			A=head;
			while((A!=NULL)&&(A->num2!=b)){
				B=A;
				A=B->next;
			} 
			if(A==NULL){
				gotoxy(60,1);
				printf("δ�ҵ�����ĺ��룡�����������������"); 
				getch();
				clear(1);
				gotoxy(2,1);
				printf("�Ƿ��������룿��y/n��");
				butt=getch();
				for(;butt!=0x6e&&butt!=0x79;){
					clear(1);
					gotoxy(2,1);
					printf("��������������������룡          �Ƿ��������룿��y/n��");
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



friends*mod(friends*head,int i){                             //�޸Ľ�㺯�� 
	if(i>N(head)){
		clear(1);
		gotoxy(2,1);
		printf("��Ų����ڣ�  �����������������");
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
	printf("������Ҫ�޸����%d����Ŀ��(���������롰1��������1�����롰2��������2�����롰3������ע�����롰4��):",A->n);
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
	 printf("�Ƿ�����޸ı������ݣ�(y/n) :");
	 if(getch()==0x6e)
	 	break;
	}
	return head;
} 



