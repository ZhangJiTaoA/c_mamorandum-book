#include"0.h"
#include"4.h"
#include"3.h"
#include"2.h"
#include"1.h"

int main(){
	color();
	graph(1,2,116,28);
	friends*head,*K;
	head=NULL;
	for(;;){                              //������ѭ�� 
	setbkcolor(7); 
	clear(3);
	proj1();
	cleardata(head);
	clear(1);
	gotoxy(2,1);
	printf("���������"); 
	butt=getch();
	for(;butt!=0xb&&butt!=0xe&&butt!=0x1b&&butt!=0x13&&butt!=0x11;){
		clear(1);
		gotoxy(2,1);
		printf("�޷�ʶ���������������!      ���������");
		butt=getch();
	}
	if(butt==0xe){                         //�½�һ���ļ�          
	for(;;){                               //�½�ѭ�� 
	proj2(); 
	head=news();
	clear(1);
	gotoxy(2,1);
	printf("�Ƿ񱣴棿(y/n)");
		butt=getch();
		for(;butt!=0x79&&butt!=0x6e;){
			clear(1);
			gotoxy(2,1);
			printf("�޷�ʶ��������������룡     �Ƿ񱣴棿(y/n) ");
			butt=getch(); 
		}
    	if(butt==0x79){
    		save(head);	
    		clear(1);
    		gotoxy(2,1);
    	
    		printf("�Ƿ�����½�����y(����)/n(�˳�)��");
    		butt=getch();
    		for(;butt!=0x79&&butt!=0x6e;){
				clear(1);
				gotoxy(2,1);
				printf("�޷�ʶ��������������룡          �Ƿ�����½�����y(����)/n(�˳�)��");
				butt=getch(); 
			}
    		if(butt==0x79){
				clear(1);
				cleardata(head);
				gotoxy(2,1);
		}
			else
				break;	
	}
		else{
			free(head);
			clear(1);
			gotoxy(2,1);
			printf("�Ƿ�����½�����y(����)/n(�˳�)��");
			butt=getch();
    		for(;butt!=0x79&&butt!=0x6e;){
				clear(1);
				gotoxy(2,1);
				printf("�޷�ʶ��������������룡        �Ƿ�����½�����y(����)/n(�˳�)��");
				butt=getch(); 
			}
				if(butt==0x79){
					clear(1);
					cleardata(head);
					gotoxy(2,1);
				}	
				else
					break;
		}
	}
	clear(1);
	gotoxy(2,1);
	printf("�˳�����esc����������enter��");
	butt=getch();
    	for(;butt!=0x1b&&butt!=0xd;){
			clear(1);
			gotoxy(2,1);
			printf("�޷�ʶ��������������룡         �˳���esc����������enter��");
			butt=getch(); 
			} 
		if(butt==0x1b)
		return 0;
}	



	else if(butt==0xb){                                //��һ�����õ��ļ� 
		int i;
		head=readfil();
		if(head==NULL){                                 //���� 
			continue;
		}
		for(;;)	{                                       //�Դ��ļ�������ѭ�� 
		read(head);
		proj3();
		clear(1);
		gotoxy(2,1);
		printf("���������");
		butt=getch();
 		for(;butt!=0x4&&butt!=0x1a&&butt!=0x1&&butt!=0x1b&&butt!=0x13&&butt!=0x5&&butt!=0x11;){
 			if(butt==0x1b)
 			return 0;
		clear(1);
		gotoxy(2,1);
		printf("�޷�ʶ���������������!");
		butt=getch(); 
	}
		switch(butt){
			case 0x11:                                         //�ж��Ƿ�ִ��ɾ���ļ� 
				proj4(); 
				clear(1);
				gotoxy(2,1);
				printf("ȷ��Ҫɾ�����ļ�����y/n��");
				butt=getch();
    			for(;butt!=0x79&&butt!=0x6e;){
					clear(1);
					gotoxy(2,1);
					printf("�޷�ʶ��������������룡          �Ƿ����ɾ�����ļ�����y/n����");
					butt=getch(); 
				}
				if(butt==0x6e){ 
					break;
					} 
				if(remove(filena)==0){
					clear(1);
					gotoxy(2,1);
					printf("ɾ���ļ��ɹ������������������");
					getch(); 
			} 
				else{
				clear(1);
				gotoxy(2,1);
				printf("ɾ���ļ�ʧ�ܣ����������������");
				getch(); 
			}		
			break;
			case 0x5:                                         //�ж��Ƿ�ִ���޸��ļ������� 
				proj5();
				clear(1);
				gotoxy(2,1);
				printf("�������µ��ļ���:");
				char newname[20];
				scanf("%s",&newname);
				if(rename(filena,newname)==0){
					clear(1);
					gotoxy(2,1);
					printf("�Ѿ����ļ���%s�޸�Ϊ%s��   �޸ĳɹ���(�����������)",filena,newname);
					getch(); 
				} 
				else{
					clear(1);
					gotoxy(2,1);
					printf("�޸�ʧ�ܣ�(�����������)"); 
					getch(); 
					break;
				}
			break; 
			case 0x4:                                                //�ж��Ƿ�Ҫ���ļ��е����ݽ���ɾ������ 
				for(;;){
					proj6(); 
					clear(1);
					gotoxy(2,1);
					printf("������Ҫɾ�������ݵ���ţ�");
					scanf("%d",&i);
					head=del(head,i);
					clear(1);
					gotoxy(2,1);
					printf("�Ƿ����ɾ������y/n����");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("�޷�ʶ��������������룡          �Ƿ����ɾ������y/n����");
						butt=getch(); 
					}
					if(butt==0x6e)
				break;
				}
				clear(1);
				gotoxy(2,1);
				printf("�Ƿ񱣴棿��y/n����");
				butt=getch();
    			for(;butt!=0x79&&butt!=0x6e;){
					clear(1);
					gotoxy(2,1);
					printf("�޷�ʶ��������������룡          �Ƿ񱣴棿��y/n����");
					butt=getch(); 
				}
				if(butt==0x79){
				save(head);
				clear(1);
				gotoxy(2,1);
				printf("�˳���esc����������enter����");
				butt=getch();
				for(;butt!=0x1b&&butt!=0xd;){
					clear(1);
					gotoxy(2,1);
					printf("�޷�ʶ��������������룡         �˳���esc��,������enter��; ");
					butt=getch();
				}
			}
				if(butt==0x1b){
					return 0;
				} 
			break;
			case 0x1a:                                          //�ж��Ƿ�Ҫ���ļ��е����ݽ����޸Ĳ��� 
				for(;;){
					proj7();
					clear(1);
					gotoxy(2,1);
					printf("������Ҫ�޸ĵ����ݵ���ţ�");
					scanf("%d",&i);
					head=mod(head,i); 
					clear(1);
					gotoxy(2,1);
					printf("�Ƿ�����޸ı��ļ�����y/n��");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("�޷�ʶ��������������룡          �Ƿ�����޸ı��ļ�����y/n��");
						butt=getch(); 
					}
					if(butt==0x6e) 
					break;
				}	
				clear(1);
				gotoxy(2,1);
				printf("�Ƿ񱣴棿��y/n��");
				butt=getch();
    			for(;butt!=0x79&&butt!=0x6e;){
					clear(1);
					gotoxy(2,1);
					printf("�޷�ʶ��������������룡          �Ƿ񱣴棿��y/n��");
					butt=getch(); 
				}
				if(butt==0x79) {
					save(head);
					clear(1);
					gotoxy(2,1);
					printf("�˳���esc����������enter����");
					butt=getch();
					for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡         �˳���esc��,������enter��; ");
							butt=getch(); 
						}
					if(butt==0x1b){
						return 0;
					} 
				}
			break;
			case 0x13:                                          //�ж��Ƿ���ļ��е����ݽ����������� 
				for(;;){
					proj8(); 
					K=sort(head);
					if(K==NULL){
						break;
					}
					proj9();
					clear(1);
					gotoxy(2,1);
					printf("��ѡ������в�������esc�˳�����"); 
					butt=getch();
					for(;butt!=0x1a&&butt!=0x4&&butt!=0x1b;){
						clear(1);
						gotoxy(2,1);
						printf("�����޷�ʶ������������!           ��ѡ������в�������esc�˳����� ");
						butt=getch();
					}
					if(butt==0x1a){
						clear(7);
						read(head);
						mod(head,K->n);
						clear(1);
						gotoxy(2,1);
						printf("�Ƿ񱣴棿��y/n��");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡          �Ƿ񱣴棿��y/n��");
							butt=getch(); 
						}
						if(butt==0x79) {
							save(head);
							clear(1);
							gotoxy(2,1);
							printf("�˳���esc����������enter����");
							butt=getch();
							for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡         �˳���esc��,������enter��; ");
							butt=getch(); 
							}
							if(butt==0x1b){
								return 0;
						} 
						}
						clear(1);
						gotoxy(2,1);
						printf("�Ƿ������������y/n��");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡          �Ƿ������������y/n��");
							butt=getch(); 
						}
						if(butt==0xe)
							break;
						}
					else if(butt==0x4){
						head=del(head,K->n);
						clear(7);
						read(head);
						clear(1);
						gotoxy(2,1);
						printf("�Ƿ񱣴棿��y/n��");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡          �Ƿ񱣴棿��y/n��");
							butt=getch(); 
						}
						if(butt==0x79) {
							save(head);
							clear(1);
							gotoxy(2,1);
							printf("�˳���esc����������enter����");
							butt=getch();
							for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡         �˳���esc��,������enter��; ");
							butt=getch(); 
							}
							if(butt==0x1b){
								return 0;
						} 
						} 
						clear(1);
						gotoxy(2,1);
						printf("�Ƿ������������y/n��");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡          �Ƿ������������y/n��");
							butt=getch(); 
						}
						if(butt==0x6e)
							break;
					}
					clear(1);
					gotoxy(2,1);
					printf("����������enter�����ذ�n��");
					butt=getch();
					for(;butt!=0xd&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("�޷�ʶ��������������룡         ����������enter�����ذ�n��");
						butt=getch();
					} 
					if(butt==0x6e){
					break;
				}
			}
			break;
			case 0x1:                                  //�ж��Ƿ���ļ��е����ݽ�����Ӳ��� 
				int a;
				for(;;){
				proj0();
				clear(1);
				gotoxy(2,1);
				printf("��ӵ��ڼ�������֮��");
				scanf("%d",&a);
				if(a==0){
					head=insert1(head);
					clear(1);
					gotoxy(2,1);
					clear(1);
					gotoxy(2,1);
					printf("�Ƿ񱣴棿��y/n��");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("�޷�ʶ��������������룡          �Ƿ񱣴棿��y/n��");
						butt=getch(); 
					}
					if(butt==0x79) {
						save(head);
						clear(1);
						gotoxy(2,1);
						printf("�˳���esc����������enter����");
						butt=getch();
						for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("�޷�ʶ��������������룡         �˳���esc��,������enter��; ");
							butt=getch(); 
						}
						if(butt==0x1b){
							return 0;
						} 
					}
					printf("�Ƿ������ӣ�(y/n)");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("�޷�ʶ��������������룡          �Ƿ������ӣ�(y/n)");
						butt=getch(); 
					}
					if(butt==0x6e)
					break;
				}
				else {
					head=insert2(head,a);
					clear(1);
					gotoxy(2,1); 
					printf("�Ƿ񱣴棿��y/n��");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("�޷�ʶ���������������!          �Ƿ񱣴棿��y/n��");
						butt=getch(); 
					}
					if(butt==0x79) {
						save(head);
						clear(1);
						gotoxy(2,1);
						printf("�˳���esc����������enter����");
						butt=getch();
							for(;butt!=0x1b&&butt!=0xd;){
								clear(1);
								gotoxy(2,1);
								printf("�޷�ʶ��������������룡         �˳���esc��,������enter��; ");
								butt=getch(); 
							}
						if(butt==0x1b){
							return 0;
						} 
					}
					clear(1);
					gotoxy(2,1);
					printf("�Ƿ������ӣ�(y/n)");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("�޷�ʶ���������������!          �Ƿ������ӣ�(y/n)");
						butt=getch(); 
					}
					if(butt==0x6e)
					break;
				}
			}
			break;
			default:;
		
		}
		clear(1);
		gotoxy(2,1);
		printf("�Ƿ�����������ļ�����y/n��:");
		butt=getch();
		for(;butt!=0x79&&butt!=0x6e;){
			clear(1);
			gotoxy(2,1);
			printf("�޷�ʶ���������������!          �Ƿ�����������ļ�����y/n��:");
			butt=getch(); 
		}
		if(butt==0x6e)
			break;
					
	}
}
	
	else if(butt==0x11){                           //ɾ���ļ� 
		clear(1);
		gotoxy(2,1);
		printf("������Ҫɾ�����ļ�����");
		char name[20];
		scanf("%s",&name);
		if(remove(name)==0){
			clear(1);
			gotoxy(2,1);
			printf("ɾ���ļ��ɹ������������������");
			getch(); 
		} 
		else{
			clear(1);
			gotoxy(2,1);
			printf("ɾ���ļ�ʧ�ܣ����������������");
			getch(); 
		}
	}
	
	else if(butt==0x1b){                       //�˳� 
			return 0;
		}
	clear(1);
	gotoxy(2,1);
	printf("�˳���esc��,������enter��;");
	butt=getch();
	for(;butt!=0x1b&&butt!=0xd;){
		clear(1);
		gotoxy(2,1);
		printf("�޷�ʶ��������������룡         �˳���esc��,������enter��; ");
		butt=getch(); 
	}
	if(butt==0x1b){
		return 0;
	}
}
} 






