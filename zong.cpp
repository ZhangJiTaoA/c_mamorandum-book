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
	for(;;){                              //主函数循环 
	setbkcolor(7); 
	clear(3);
	proj1();
	cleardata(head);
	clear(1);
	gotoxy(2,1);
	printf("请输入命令！"); 
	butt=getch();
	for(;butt!=0xb&&butt!=0xe&&butt!=0x1b&&butt!=0x13&&butt!=0x11;){
		clear(1);
		gotoxy(2,1);
		printf("无法识别命令，请重新输入!      请输入命令！");
		butt=getch();
	}
	if(butt==0xe){                         //新建一个文件          
	for(;;){                               //新建循环 
	proj2(); 
	head=news();
	clear(1);
	gotoxy(2,1);
	printf("是否保存？(y/n)");
		butt=getch();
		for(;butt!=0x79&&butt!=0x6e;){
			clear(1);
			gotoxy(2,1);
			printf("无法识别命令，请重新输入！     是否保存？(y/n) ");
			butt=getch(); 
		}
    	if(butt==0x79){
    		save(head);	
    		clear(1);
    		gotoxy(2,1);
    	
    		printf("是否继续新建？（y(继续)/n(退出)）");
    		butt=getch();
    		for(;butt!=0x79&&butt!=0x6e;){
				clear(1);
				gotoxy(2,1);
				printf("无法识别命令，请重新输入！          是否继续新建？（y(继续)/n(退出)）");
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
			printf("是否继续新建？（y(继续)/n(退出)）");
			butt=getch();
    		for(;butt!=0x79&&butt!=0x6e;){
				clear(1);
				gotoxy(2,1);
				printf("无法识别命令，请重新输入！        是否继续新建？（y(继续)/n(退出)）");
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
	printf("退出程序（esc）；继续（enter）");
	butt=getch();
    	for(;butt!=0x1b&&butt!=0xd;){
			clear(1);
			gotoxy(2,1);
			printf("无法识别命令，请重新输入！         退出（esc）；继续（enter）");
			butt=getch(); 
			} 
		if(butt==0x1b)
		return 0;
}	



	else if(butt==0xb){                                //打开一个建好的文件 
		int i;
		head=readfil();
		if(head==NULL){                                 //防错 
			continue;
		}
		for(;;)	{                                       //对打开文件操作的循环 
		read(head);
		proj3();
		clear(1);
		gotoxy(2,1);
		printf("请输入命令！");
		butt=getch();
 		for(;butt!=0x4&&butt!=0x1a&&butt!=0x1&&butt!=0x1b&&butt!=0x13&&butt!=0x5&&butt!=0x11;){
 			if(butt==0x1b)
 			return 0;
		clear(1);
		gotoxy(2,1);
		printf("无法识别命令，请重新输入!");
		butt=getch(); 
	}
		switch(butt){
			case 0x11:                                         //判断是否执行删除文件 
				proj4(); 
				clear(1);
				gotoxy(2,1);
				printf("确定要删除该文件？（y/n）");
				butt=getch();
    			for(;butt!=0x79&&butt!=0x6e;){
					clear(1);
					gotoxy(2,1);
					printf("无法识别命令，请重新输入！          是否继续删除该文件？（y/n）：");
					butt=getch(); 
				}
				if(butt==0x6e){ 
					break;
					} 
				if(remove(filena)==0){
					clear(1);
					gotoxy(2,1);
					printf("删除文件成功！（按任意键继续）");
					getch(); 
			} 
				else{
				clear(1);
				gotoxy(2,1);
				printf("删除文件失败！（按任意键继续）");
				getch(); 
			}		
			break;
			case 0x5:                                         //判断是否执行修改文件名操作 
				proj5();
				clear(1);
				gotoxy(2,1);
				printf("请输入新的文件名:");
				char newname[20];
				scanf("%s",&newname);
				if(rename(filena,newname)==0){
					clear(1);
					gotoxy(2,1);
					printf("已经将文件名%s修改为%s！   修改成功！(按任意键继续)",filena,newname);
					getch(); 
				} 
				else{
					clear(1);
					gotoxy(2,1);
					printf("修改失败！(按任意键继续)"); 
					getch(); 
					break;
				}
			break; 
			case 0x4:                                                //判断是否要对文件中的内容进行删除操作 
				for(;;){
					proj6(); 
					clear(1);
					gotoxy(2,1);
					printf("请输入要删除的内容的序号：");
					scanf("%d",&i);
					head=del(head,i);
					clear(1);
					gotoxy(2,1);
					printf("是否继续删除？（y/n）：");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("无法识别命令，请重新输入！          是否继续删除？（y/n）：");
						butt=getch(); 
					}
					if(butt==0x6e)
				break;
				}
				clear(1);
				gotoxy(2,1);
				printf("是否保存？（y/n）：");
				butt=getch();
    			for(;butt!=0x79&&butt!=0x6e;){
					clear(1);
					gotoxy(2,1);
					printf("无法识别命令，请重新输入！          是否保存？（y/n）：");
					butt=getch(); 
				}
				if(butt==0x79){
				save(head);
				clear(1);
				gotoxy(2,1);
				printf("退出（esc），继续（enter）；");
				butt=getch();
				for(;butt!=0x1b&&butt!=0xd;){
					clear(1);
					gotoxy(2,1);
					printf("无法识别命令，请重新输入！         退出（esc）,继续（enter）; ");
					butt=getch();
				}
			}
				if(butt==0x1b){
					return 0;
				} 
			break;
			case 0x1a:                                          //判断是否要对文件中的内容进行修改操作 
				for(;;){
					proj7();
					clear(1);
					gotoxy(2,1);
					printf("请输入要修改的内容的序号：");
					scanf("%d",&i);
					head=mod(head,i); 
					clear(1);
					gotoxy(2,1);
					printf("是否继续修改本文件？（y/n）");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("无法识别命令，请重新输入！          是否继续修改本文件？（y/n）");
						butt=getch(); 
					}
					if(butt==0x6e) 
					break;
				}	
				clear(1);
				gotoxy(2,1);
				printf("是否保存？（y/n）");
				butt=getch();
    			for(;butt!=0x79&&butt!=0x6e;){
					clear(1);
					gotoxy(2,1);
					printf("无法识别命令，请重新输入！          是否保存？（y/n）");
					butt=getch(); 
				}
				if(butt==0x79) {
					save(head);
					clear(1);
					gotoxy(2,1);
					printf("退出（esc），继续（enter）；");
					butt=getch();
					for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！         退出（esc）,继续（enter）; ");
							butt=getch(); 
						}
					if(butt==0x1b){
						return 0;
					} 
				}
			break;
			case 0x13:                                          //判断是否对文件中的内容进行搜索操作 
				for(;;){
					proj8(); 
					K=sort(head);
					if(K==NULL){
						break;
					}
					proj9();
					clear(1);
					gotoxy(2,1);
					printf("对选中项进行操作！（esc退出）！"); 
					butt=getch();
					for(;butt!=0x1a&&butt!=0x4&&butt!=0x1b;){
						clear(1);
						gotoxy(2,1);
						printf("命令无法识别！请重新输入!           对选中项进行操作！（esc退出）！ ");
						butt=getch();
					}
					if(butt==0x1a){
						clear(7);
						read(head);
						mod(head,K->n);
						clear(1);
						gotoxy(2,1);
						printf("是否保存？（y/n）");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！          是否保存？（y/n）");
							butt=getch(); 
						}
						if(butt==0x79) {
							save(head);
							clear(1);
							gotoxy(2,1);
							printf("退出（esc），继续（enter）；");
							butt=getch();
							for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！         退出（esc）,继续（enter）; ");
							butt=getch(); 
							}
							if(butt==0x1b){
								return 0;
						} 
						}
						clear(1);
						gotoxy(2,1);
						printf("是否继续搜索？（y/n）");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！          是否继续搜索？（y/n）");
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
						printf("是否保存？（y/n）");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！          是否保存？（y/n）");
							butt=getch(); 
						}
						if(butt==0x79) {
							save(head);
							clear(1);
							gotoxy(2,1);
							printf("退出（esc），继续（enter）；");
							butt=getch();
							for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！         退出（esc）,继续（enter）; ");
							butt=getch(); 
							}
							if(butt==0x1b){
								return 0;
						} 
						} 
						clear(1);
						gotoxy(2,1);
						printf("是否继续搜索？（y/n）");
						butt=getch();
    					for(;butt!=0x79&&butt!=0x6e;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！          是否继续搜索？（y/n）");
							butt=getch(); 
						}
						if(butt==0x6e)
							break;
					}
					clear(1);
					gotoxy(2,1);
					printf("继续搜索按enter，返回按n：");
					butt=getch();
					for(;butt!=0xd&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("无法识别命令，请重新输入！         继续搜索按enter，返回按n：");
						butt=getch();
					} 
					if(butt==0x6e){
					break;
				}
			}
			break;
			case 0x1:                                  //判断是否对文件中的内容进行添加操作 
				int a;
				for(;;){
				proj0();
				clear(1);
				gotoxy(2,1);
				printf("添加到第几个内容之后：");
				scanf("%d",&a);
				if(a==0){
					head=insert1(head);
					clear(1);
					gotoxy(2,1);
					clear(1);
					gotoxy(2,1);
					printf("是否保存？（y/n）");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("无法识别命令，请重新输入！          是否保存？（y/n）");
						butt=getch(); 
					}
					if(butt==0x79) {
						save(head);
						clear(1);
						gotoxy(2,1);
						printf("退出（esc），继续（enter）；");
						butt=getch();
						for(;butt!=0x1b&&butt!=0xd;){
							clear(1);
							gotoxy(2,1);
							printf("无法识别命令，请重新输入！         退出（esc）,继续（enter）; ");
							butt=getch(); 
						}
						if(butt==0x1b){
							return 0;
						} 
					}
					printf("是否继续添加？(y/n)");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("无法识别命令，请重新输入！          是否继续添加？(y/n)");
						butt=getch(); 
					}
					if(butt==0x6e)
					break;
				}
				else {
					head=insert2(head,a);
					clear(1);
					gotoxy(2,1); 
					printf("是否保存？（y/n）");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("无法识别命令，请重新输入!          是否保存？（y/n）");
						butt=getch(); 
					}
					if(butt==0x79) {
						save(head);
						clear(1);
						gotoxy(2,1);
						printf("退出（esc），继续（enter）；");
						butt=getch();
							for(;butt!=0x1b&&butt!=0xd;){
								clear(1);
								gotoxy(2,1);
								printf("无法识别命令，请重新输入！         退出（esc）,继续（enter）; ");
								butt=getch(); 
							}
						if(butt==0x1b){
							return 0;
						} 
					}
					clear(1);
					gotoxy(2,1);
					printf("是否继续添加？(y/n)");
					butt=getch();
    				for(;butt!=0x79&&butt!=0x6e;){
						clear(1);
						gotoxy(2,1);
						printf("无法识别命令，请重新输入!          是否继续添加？(y/n)");
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
		printf("是否继续操作此文件？（y/n）:");
		butt=getch();
		for(;butt!=0x79&&butt!=0x6e;){
			clear(1);
			gotoxy(2,1);
			printf("无法识别命令，请重新输入!          是否继续操作此文件？（y/n）:");
			butt=getch(); 
		}
		if(butt==0x6e)
			break;
					
	}
}
	
	else if(butt==0x11){                           //删除文件 
		clear(1);
		gotoxy(2,1);
		printf("请输入要删除的文件名：");
		char name[20];
		scanf("%s",&name);
		if(remove(name)==0){
			clear(1);
			gotoxy(2,1);
			printf("删除文件成功！（按任意键继续）");
			getch(); 
		} 
		else{
			clear(1);
			gotoxy(2,1);
			printf("删除文件失败！（按任意键继续）");
			getch(); 
		}
	}
	
	else if(butt==0x1b){                       //退出 
			return 0;
		}
	clear(1);
	gotoxy(2,1);
	printf("退出（esc）,继续（enter）;");
	butt=getch();
	for(;butt!=0x1b&&butt!=0xd;){
		clear(1);
		gotoxy(2,1);
		printf("无法识别命令，请重新输入！         退出（esc）,继续（enter）; ");
		butt=getch(); 
	}
	if(butt==0x1b){
		return 0;
	}
}
} 






