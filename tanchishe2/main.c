#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void printfGameMap(char gm[20][20],int len,int x[],int y[],int fcount,int fx,int fy);
void moveSnake(char s[],char gm[20][20],int *len,int x[],int y[],int *fcount,int *fx,int *fy,int *score);
void addFruit(int *fcount,int *fx,int *fy,int len,int x[],int y[]);
void Pos(int x,int y);
void welcometogame();

void addFruit(int *fcount,int *fx,int *fy,int len,int x[],int y[]){
if((*fcount)==0){
while(1){
  int tfx=rand()%20;
  int tfy=rand()%20;
  int i,have=0;//是否是蛇的一部分
  for(i=0;i<len;i++){
        if(tfx == x[i] && tfy ==y[i]){
            have=1;
            break;
        }
  }
  if(have==1){
            continue;
        }else{
            (*fcount)++;
            (*fx)=tfx;
            (*fy)=tfy;
            break;
}}}
};
void moveSnake(char s[],char gm[20][20],int *len,int x[],int y[],int *fcount,int *fx,int *fy,int *score){
  int cx[400];
  int cy[400];
  memcpy(cx, x,sizeof(int)*(*len));//memcpy数组的拷贝函数，可以把一串字节拷过去。格式：1.目的地址，2.拷贝的地址3.多少个字节
  memcpy(cy, y,sizeof(int)*(*len));
  int move=0;//头动身体才能动   利用了strcmp函数《eq:0 gt:正数 lt：负数》
  if(strcmp(s,"w")==0){
     move=1;
     x[0]=x[0]-1;
  }else if(strcmp(s,"s")==0){
     move=1;
     x[0]=x[0]+1;
  }else if(strcmp(s,"a")==0){
      move=1;
      y[0]=y[0]-1;
  }else if(strcmp(s,"d")==0){
      move=1;
      y[0]=y[0]+1;
  }else{
     printf("输入错误!!!\n");
  }
  if(move==1){

        if(x[0] == (*fx) && y[0]==(*fy)){
            memcpy(x+1, cx,sizeof(int)*(*len));  //
            memcpy(y+1, cy,sizeof(int)*(*len));  //保证头在变，身体不需要变
          (*len)++;
          (*fcount)--;
          (*fx)=0;
          (*fy)=0;
          (*score)++;
          addFruit(fcount,fx,fy,(*len),x,y);
        } else {
          int i;
          for(i=1;i<(*len);i++){
            x[i]=cx[i-1];
            y[i]=cy[i-1];
          }

        }

   system("cls");
   printfGameMap(gm,(*len),x,y,*fcount,*fx,*fy);
  }
  }
void printfGameMap(char gm[20][20],int len,int x[],int y[],int fcount,int fx,int fy){
 //printf("%d",len);

  int i,j;

   for(i=0;i<20;i++){
      for(j=0;j<20;j++){
            gm[i][j] = '.';
        int snake=0,k;
        for(k=0;k<len;k++){
            if(i==x[k]&&j==y[k]){  //判断蛇的纵坐标和横坐标是否为蛇身
                    if(k == 0){
                    snake=1;
                    }else{
                     snake=2;
                    }
                    break;
            }
        }

        if(snake==1){

            printf("* ");//蛇头Z

        }else if(snake==2){

            printf("o ");//蛇尾F

        }else{
            if(fcount&&fx==i&&j==fy){

             printf("+ ");

            }else{
             printf("%c ",gm[i][j]);
            }

        }
     }
   printf("\n");
  }
}
//void  getScore(){
//    FILE *fp;
//    char ch;
//    fp=fopen("score.txt","r");
//    while((ch=fgetc(fp))!=EOF){
//        fputc(ch,fp);
//    }
//    fclose(fp);
//
//
//}
void Pos(int x,int y)//设置光标位置
{
    COORD pos; //windows API
	HANDLE hOutput;
    pos.X=x;
    pos.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
}

void SetColor(unsigned short ForeColor,unsigned short BackGroundColor)
{
    HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));
}
void welcometogame()//开始界面
{
    int q,w,e;


    Pos(30,5);
	system("title 贪吃蛇v1.0");
    SetColor(7,0);
    printf("欢迎来到贪食蛇游戏！");
    SetColor(3,0);
    printf("★");
    SetColor(2,0);
    printf("★");
    SetColor(7,0);
    SetColor(4,0);
    printf("★");
    SetColor(7,0);
    Pos(30,20);
    printf("              制作人员:林金章&李家凯\n");
    Pos(30,21);
    printf("              版本号：1.0\n");
    system("pause");
    system("cls");
    for(q=7;q<10;q++){
    Pos(20,q);
    SetColor(q,0);
	printf("★");
    SetColor(7,0);
    }
    for(w=0;w<19;w++){
    Pos(w,7);
    for(e=0;e<16;e++){
    SetColor(e,0);
	printf("★");
    SetColor(7,0);
    }

    }
    for(w=0;w<19;w++){
    Pos(w,9);
    for(e=0;e<16;e++){
    SetColor(e,0);
	printf("★");
    SetColor(7,0);
    }

    }
    for(q=7;q<10;q++){
    Pos(50,q);
    SetColor(q,0);
	printf("★");
    SetColor(7,0);
    }
    Pos(23,8);
    printf("用W.S.A.D分别控制蛇的移动\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
    system("cls");
}
int main()
{

 // printf("*************************");
  //printf("\n*");
  //printf("【贪吃蛇v1.0】\t\t*\n");
 // printf("*制作人员:李家凯&林金章\t*");
 // printf("                                  得分排行版TOP\t*");
 // getScore();
 // printf("\n*");
 // printf("************************\n");



  welcometogame();
  srand(time(NULL));
  char gm[20][20];
  int x[400]={0};//行编号
  int y[400]={0};//列编号
  int len=0;
  x[len]=9;//蛇头
  y[len]=9;//蛇头
  len++;
  x[len]=9;
  y[len]=8;
  len++;
  int fx=0;//水果的坐标
  int fy=0;//水果的坐标
  int fcount=0;//水果的数量
  addFruit(&fcount,&fx,&fy,len,x,y);
  printfGameMap(gm,len,x,y,fcount,fx,fy);
  int score=0;
  while(1){
    printf("当前得分(%d)  请输入W向上，S向下，A向左，D向右\n",score);
    char s[2];
    s[0]=getch();
    //scanf("%1s",s);//强制只读一个字符
    moveSnake(s,gm,&len,x,y,&fcount,&fx,&fy,&score);
    int j,gameover=0;
    for(j=1;j<len+1;j++){
        if(x[0]==x[j] && y[0]==y[j]){
            printf("游戏结束！总共得分:%d分\n",score);
            printf("请选择：\n");
            printf("1.重新开始游戏\n");
            printf("2.退出游戏\n");
            int c;
            scanf("%d",&c);
            switch(c){
                case 1: system("cls");main();break;
                case 2: exit(0);break;
            }
            gameover=1;
            break;
    }
  }
    if(gameover==1){
        break;
    }


}
 return 0;
}
