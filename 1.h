char filena[20];
void save(friends*head){                            //�����ļ����� 
	FILE*fp=NULL;
	char filename[20];
	clear(1);
	gotoxy(2,1);
	printf("�������ļ�����");
	scanf("%s",&filename);
	fp=fopen(filename,"wb");
	if(fp==NULL){
		gotoxy(2,1);
		printf("�ļ�����ʧ�ܣ�");
		exit(0); 
	}
	
	int i;
	friends*A,*B;
	A=head;
	for(i=0;i<N(head);i++){
		if(fwrite(A,sizeof(friends),1,fp)==0){
			gotoxy(2,1);
			printf("д��ʧ�ܣ�");
			exit(0); 
		}
		B=A;
		A=B->next;
	}
	fclose(fp); 
	clear(1);
	gotoxy(2,1);
	printf("����ɹ���������������� ");	
	getch(); 
	read(head);
	
}

friends*readfil(){                                     //��ȡ�ļ����� 
	FILE*fp=NULL;
	char filename[20];
	for(;;){
	clear(1); 
	gotoxy(2,1);
	printf("������Ŀ¼����");
	scanf("%s",&filename);
	strcpy(filena,filename);
	fp=fopen(filename,"rb");
	if(fp==NULL){
		clear(1);
		gotoxy(2,1);
		printf("��ʧ�ܣ�");
	gotoxy(20,1);
	printf("�Ƿ���������Ŀ¼����y/n��");
	butt=getch();
    	for(;butt!=0x79&&butt!=0x6e;){
			clear(1);
			gotoxy(2,1);
			printf("�޷�ʶ���������������   ����������Ŀ¼����y/n��");
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
		printf("�����ڴ�ʧ�ܣ�");
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
				printf("�����ڴ�ʧ�ܣ�");
				return NULL; }
				B=A;
				A=A->next;
			}	
	
		}
		B->next=NULL;
		fclose(fp);
    	clear(1);
    	gotoxy(2,1);
    	printf("��ȡ�ɹ���"); 
		return head;
}





