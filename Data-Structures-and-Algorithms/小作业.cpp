#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct studentData{
 char number[10];
 char name[15];
 char sex[3];
 char address[25];
 float chineseGrade;
 float mathGrade;  
 float englishGrade;
 float averGrade;
};
typedef struct studentData Data;
void mainMenu();
void lookUpMenu();
void lookUpSubMenu();
void changeImformMenu(); 
void selectMenu();
void sortMenu();
int readFile(Data *index[],char file[]);
void selectFunction(Data *index[],int *num,char file[]);
void selectLookupFunction(Data *index[],int *num);
int lookUpBy(Data *index[],int *num);
int lookUpPersonFuction(Data *index[],int *num);
int changeImormFuction(Data *index[],int point);
void lookupData(Data *index[],int *num);
void lookUpAll(Data *index[],int *num);
void lookUpPerson(Data *index[],int *num);
void lookUpByNumber(Data *index[],int *num);
void lookUpByName(Data *index[],int *num);

void addData(Data *index[],int *num);
void deleteData(Data *index[],int *num);
void changeData(Data *index[],int *num);
void sortData(Data *index[],int *num);
void selectData(Data *index[],int *num);
void saveData(Data *index[],int *num,char file[]);
void squeeze(Data *index[],int *num,int point);
void changeName(Data *index[],int num);
void changeNumber(Data *index[],int num);
void changeAddress(Data *index[],int num);
void changeSex(Data *index[],int num);
void changeCSore(Data *index[],int num);
void changeESorce(Data *index[],int num);
void changeMSorce(Data *index[],int num);
void sortByC(Data *index[],int *num);
void sortByM(Data *index[],int *num);
void sortByE(Data *index[],int *num);
void sortByA(Data *index[],int *num);
void selectByC(Data *index[],int *num);
void selectByM(Data *index[],int *num);
void selectByE(Data *index[],int *num);
void selectByA(Data *index[],int *num);
int main(){
 char file[30];
 Data *Index[2000];
 printf("初始化...\n\n");
 printf("请输入储存的文件名(完整路径 例如 D:\\1.txt):");
 scanf("%s",file); 
 
 getchar(); 
 int dataNumber = readFile(Index,file); 
 int *dataNumbeP = &dataNumber;
 
 while(1){
  mainMenu();
  selectFunction(Index,dataNumbeP,file);
 } 
 
 return 0;
}
void mainMenu(){
 system("cls");
 printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf(" ┃      学生成绩管理系统     ┃\n");
 printf(" ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 printf(" ┃                           ┃\n");
 printf(" ┃        0.成绩查询         ┃\n"); 
 printf(" ┃        1.添加信息         ┃\n");
 printf(" ┃        2.删除信息         ┃\n");
 printf(" ┃        3.修改信息         ┃\n");
 printf(" ┃        4.成绩排序         ┃\n");
 printf(" ┃        5.筛选成绩         ┃\n");
 printf(" ┃        6.  保存           ┃\n"); 
 printf(" ┃        7.  结束           ┃\n");
 printf(" ┃                           ┃\n");
 printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
 printf("           请选择:");
}

void lookUpMenu(){
 system("cls");
 printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf(" ┃           成绩查询         ┃\n");
 printf(" ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 printf(" ┃                            ┃\n"); 
 printf(" ┃          1.查看所有        ┃\n");
 printf(" ┃          2.查看个人        ┃\n");
 printf(" ┃          3.  返回          ┃\n");
 printf(" ┃                            ┃\n");
 printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
 printf("             请选择:");
}
void selectMenu(){
 system("cls");
 printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf(" ┃           筛选方式         ┃\n");
 printf(" ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 printf(" ┃                            ┃\n"); 
 printf(" ┃          1.语文成绩        ┃\n");
 printf(" ┃          2.数学成绩        ┃\n");
 printf(" ┃          3.英语成绩        ┃\n");
 printf(" ┃          4.平均成绩        ┃\n"); 
 printf(" ┃          5.  返回          ┃\n");
 printf(" ┃                            ┃\n");
 printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
 printf("             请选择:");
}
void sortMenu(){
 system("cls");
 printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf(" ┃           排序依据         ┃\n");
 printf(" ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 printf(" ┃                            ┃\n"); 
 printf(" ┃          1.语文成绩        ┃\n");
 printf(" ┃          2.数学成绩        ┃\n");
 printf(" ┃          3.英语成绩        ┃\n");
 printf(" ┃          4.平均成绩        ┃\n"); 
 printf(" ┃          5.  返回          ┃\n");
 printf(" ┃                            ┃\n");
 printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
 printf("             请选择:"); 
}
void lookUpSubMenu(){
 system("cls");
 printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf(" ┃           查询方式           ┃\n");
 printf(" ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 printf(" ┃                              ┃\n"); 
 printf(" ┃          1.学号查询          ┃\n");
 printf(" ┃          2.姓名查询          ┃\n");
 printf(" ┃          3.  返回            ┃\n");
 printf(" ┃                              ┃\n");
 printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
 printf("             请选择:");
}
void changeImformMenu(){
 system("cls");
 printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf(" ┃            信息更改           ┃\n");
 printf(" ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 printf(" ┃                               ┃\n"); 
 printf(" ┃           1.修改学号          ┃\n");
 printf(" ┃           2.修改姓名          ┃\n");
 printf(" ┃           3.修改性别          ┃\n");
 printf(" ┃           4.修改地址          ┃\n");
 printf(" ┃           5.语文成绩          ┃\n");
 printf(" ┃           6.数学成绩          ┃\n");
 printf(" ┃           7.英语成绩          ┃\n");
 printf(" ┃           8.  返回            ┃\n");
 printf(" ┃                               ┃\n");
 printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
}
int readFile(Data *index[],char file[]){
 int dataNumber = 0;
 FILE *fp = fopen(file,"rb");  
 Data t;
 while(fp != NULL && EOF != fscanf(fp,"%s %s %s %s %f %f %f %f",
    &t.number,t.name,&t.sex,&t.address,
    &t.chineseGrade,&t.mathGrade,&t.englishGrade,&t.averGrade) && dataNumber < 2000){
  index[dataNumber] = (Data*)malloc(sizeof(Data)); 
  strcpy(index[dataNumber]->number,t.number);
  strcpy(index[dataNumber]->name,t.name);
  strcpy(index[dataNumber]->sex,t.sex);
  strcpy(index[dataNumber]->address,t.address);  
  index[dataNumber]->chineseGrade = t.chineseGrade;
  index[dataNumber]->mathGrade = t.mathGrade;
  index[dataNumber]->englishGrade = t.englishGrade;
  index[dataNumber]->averGrade = t.averGrade;      
  dataNumber++;
 }
 if(fp != NULL)fclose(fp);
 return dataNumber;
}
 
void selectFunction(Data *index[],int *num,char file[]){
 char choice;
 scanf("%c",&choice);
 getchar();
 switch(choice){
  case '0':selectLookupFunction(index,num);break; 
  case '1':addData(index,num);break;
  case '2':deleteData(index,num);break;
  case '3':changeData(index,num);break;
  case '4':sortData(index,num);break;
  case '5':selectData(index,num);break;
  case '6':saveData(index,num,file);break; 
  case '7':exit(0); 
  default: printf("错误选项 按回车继续...");getchar();
 };
}
void selectLookupFunction(Data *index[],int *num){
 while(1){
  lookUpMenu();
  if(!lookUpBy(index,num)){
   return;
  }
 }
}
int lookUpBy(Data *index[],int *num){
 char choice;
 scanf("%c",&choice);
 getchar();
 switch(choice){
  case '1':lookUpAll(index,num);break;
  case '2':lookUpPerson(index,num);break;
  case '3':return 0; 
  default: printf("错误选项 按回车继续...");getchar();
 }; 
 return 1;
}
void lookUpPerson(Data *index[],int *num){
 while(1){
  lookUpSubMenu();
  if(!lookUpPersonFuction(index,num)){
   return;
  }
 }
}
void lookUpAll(Data *index[],int *num){
 system("cls");
 if((*num)){
  for(int i = 0;i < (*num);i++){
   printf("[%d] ",i+1);
   printf("%9s %14s %2s %24s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
     index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
     index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
  }
 }
 else{
  printf("无保存信息\n\n"); 
 }
 printf("\n按回车继续..."); 
 getchar();
}
int lookUpPersonFuction(Data *index[],int *num){
 char choice;
 scanf("%c",&choice);
 getchar();
 switch(choice){
  case '1':lookUpByNumber(index,num);break;
  case '2':lookUpByName(index,num);break;
  case '3':return 0; 
  default: printf("错误选项 按回车继续...");getchar();
 };
 return 1;
}
void lookUpByNumber(Data *index[],int *num){
 char c[20];
 printf("查询学号:");
 scanf("%s",&c);
 getchar();
 for(int i = 0;i < (*num);i++){
  if(!strcmp(index[i]->number,c)){
   printf("%s %s %s %s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
     index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
     index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade); 
   printf("\n\n按回车继续..."); 
   getchar();
   return;
  }
 }
 printf("\n未查询到信息\n\n按回车继续..."); 
 getchar();
}
void lookUpByName(Data *index[],int *num){
 char c[20];
 printf("查询姓名:");
 scanf("%s",&c);
 getchar(); 
 for(int i = 0;i < (*num);i++){
  if(!strcmp(index[i]->name,c)){
   printf("%s %s %s %s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
     index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
     index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade); 
   printf("\n\n按回车继续..."); 
   getchar();
   return;
  }
 }
 printf("\n未查询到信息\n\n按回车继续..."); 
 getchar();
}

void addData(Data *index[],int *num){
 system("cls");
 Data t;
 if(*num < 2000){
  index[(*num)] = (Data*)malloc(sizeof(Data)); 
  
  printf("学号:");
  scanf("%s",&t.number);
  getchar();
  
  printf("\n学生姓名:");
  scanf("%s",&t.name);
  getchar();
  
  printf("\n性别:");
  scanf("%s",&t.sex);
  getchar(); 
  
  printf("\n家庭住址:");  
  scanf("%s",&t.address);  
  getchar();
   
  printf("\n语文成绩:");  
  scanf("%f",&t.chineseGrade);
  getchar();
    
  printf("\n数学成绩:");
  scanf("%f",&t.mathGrade);
  getchar();
  
  printf("\n英语成绩:");
  scanf("%f",&t.englishGrade);
  getchar();
   
  t.averGrade = (t.chineseGrade+t.mathGrade+t.englishGrade)/3;
  
  for(int i = 0;i < (*num);i++){
   if(!strcmp(index[i]->number,t.number)){
    printf("\n已存在信息\n\n");
   
    printf("按回车继续..."); 
    getchar();
    return; 
   }
  }
  strcpy(index[*num]->number,t.number);
  strcpy(index[*num]->name,t.name);
  strcpy(index[*num]->sex,t.sex); 
  strcpy(index[*num]->address,t.address);
  index[*num]->chineseGrade = t.chineseGrade;
  index[*num]->mathGrade = t.mathGrade;
  index[*num]->englishGrade = t.englishGrade;
  index[*num]->averGrade = t.averGrade;
  printf("\n已保存信息\n\n");
  (*num)++; 
 }
 else{
  printf("空间已满\n\n");
 }
 printf("\n按回车继续..."); 
 getchar();
}
void deleteData(Data *index[],int *num){
 system("cls");
 char c[20];
 char t[5]; 
 printf("删除者姓名或学号:");
 scanf("%s",&c);
 getchar();
 for(int i = 0;i < (*num);i++){
  if(!strcmp(index[i]->number,c) || !strcmp(index[i]->name,c)){
   printf("%s %s %s %s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
     index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
     index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
   do{
    printf("确定要删除吗?yes/no:");
    scanf("%s",&t);
    getchar();
   }while(!strcmp(t,"yes") && !strcmp(t,"no")); 
   if(!strcmp(t,"yes")){
    free(index[i]);
    squeeze(index,num,i);
    printf("\n删除成功\n\n"); 
   }
   else{
    printf("\n取消成功\n\n");  
   }
   printf("按回车继续..."); 
   getchar();
   return;
  }
 }
 printf("未查询到信息\n\n按回车继续..."); 
}
void changeData(Data *index[],int *num){
 system("cls");
 char c[20];
 printf("修改者姓名或学号:");
 scanf("%s",&c);
 getchar();
 for(int i = 0;i < (*num);i++){
  if(!strcmp(index[i]->number,c) || !strcmp(index[i]->name,c)){
   changeImformMenu();   
   printf("%s %s %s %s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
     index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
     index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
   while(changeImormFuction(index,i));   
   
   return;
  }
 }
 printf("未查询到信息\n\n按回车继续..."); 
 getchar();
 
}
int changeImormFuction(Data *index[],int point){
 char choice;
 printf("\n请选择:");
 scanf("%c",&choice);
 getchar();
 switch(choice){
  case '1':changeNumber(index,point); break;
  case '2':changeName(index,point); break;
  case '3':changeAddress(index,point); break;
  case '4':changeSex(index,point); break; 
  case '5':changeCSore(index,point); break;
  case '6':changeESorce(index,point); break;
  case '7':changeMSorce(index,point); break;
  case '8': return 0;
  default:printf("错误选项 按回车继续...");getchar();
 };
 printf("\n修改成功 按回车继续"); 
 getchar();
 return 1;
}
void changeNumber(Data *index[],int num){
 char t[20];
 printf("学号修改为:");
 scanf("%s",&t);
 getchar();
 
 strcpy(index[num]->number,t);
}
void changeName(Data *index[],int num){
 char t[20];
 printf("姓名修改为:");
 scanf("%s",&t);
 getchar();
 
 strcpy(index[num]->name,t);
}
void changeSex(Data *index[],int num){
 char t[5];
 printf("性别修改为:");
 scanf("%s",&t);
 getchar();
 
 strcpy(index[num]->sex,t);
 
}
void changeAddress(Data *index[],int num){
 char t[5];
 printf("地址修改为:");
 scanf("%s",&t);
 getchar();
 
 strcpy(index[num]->address,t);
}
void changeCSore(Data *index[],int num){
 int t; 
 printf("语文成绩修改为:");
 scanf("%d",&t); 
 getchar();
 index[num]->chineseGrade = t;
 index[num]->averGrade = (index[num]->chineseGrade+index[num]->mathGrade+index[num]->englishGrade)/3;
 
}
void changeESorce(Data *index[],int num){
 int t; 
 printf("数学成绩修改为:");
 scanf("%d",&t); 
 getchar();
 
 index[num]->mathGrade = t;
 index[num]->averGrade = (index[num]->chineseGrade+index[num]->mathGrade+index[num]->englishGrade)/3;
 
}
void changeMSorce(Data *index[],int num){
 int t; 
 printf("英语成绩修改为:");
 scanf("%d",&t); 
 getchar();
 
 index[num]->englishGrade = t;
 index[num]->averGrade = (index[num]->chineseGrade+index[num]->mathGrade+index[num]->englishGrade)/3;
  
}
void sortData(Data *index[],int *num){
 char choice;
 sortMenu();
 scanf("%c",&choice);
 getchar();                
 switch(choice){
  case '1': sortByC(index,num);break;
  case '2': sortByM(index,num);break;
  case '3': sortByE(index,num);break; 
  case '4': sortByA(index,num);break;
  case '5':return;
  default: printf("错误选项 按回车继续...");getchar();return;
 };  
 lookUpAll(index,num);
}
          
void sortByC(Data *index[],int *num){
 Data *p;
 for(int i = 0;i < (*num);i++){
  for(int j = 0;j< (*num)-i-1;j++){
   if(index[j]->chineseGrade < index[j+1]->chineseGrade){
    p = index[j];
    index[j] = index[j+1];
    index[j+1] = p;
   }
  }
 }
}
void sortByM(Data *index[],int *num){
 Data *p;
 for(int i = 0;i < (*num);i++){
  for(int j = 0;j < (*num)-i-1;j++){
   if(index[j]->mathGrade < index[j+1]->mathGrade){
    p = index[j];
    index[j] = index[j+1];
    index[j+1] = p;
   }
  }
 }
}
void sortByE(Data *index[],int *num){
 Data *p;
 for(int i = 0;i < (*num);i++){
  for(int j = 0;j < (*num)-i-1;j++){
   if(index[j]->englishGrade < index[j+1]->englishGrade){
    p = index[j];
    index[j] = index[j+1];
    index[j+1] = p;
   }
  }
 }
}
void sortByA(Data *index[],int *num){
 Data *p;
 for(int i = 0;i < (*num);i++){
  for(int j = 0;j < (*num)-i-1;j++){
   if(index[j]->averGrade < index[j+1]->averGrade){
    p = index[j];
    index[j] = index[j+1];
    index[j+1] = p;
   }
  }
 }
}
void selectData(Data *index[],int *num){
 char choice;
 selectMenu();
 scanf("%c",&choice);
 getchar();
 switch(choice){
  case '1': selectByC(index,num);break;
  case '2': selectByM(index,num);break;
  case '3': selectByE(index,num);break; 
  case '4': selectByA(index,num);break;
  case '5': return;
  default: printf("错误选项 按回车继续...");getchar();
 };  
 printf("筛选完成\n\n");
 printf("按回车继续...");
 getchar();
}
void selectByC(Data *index[],int *num){
 int a, b;
 system("cls");
 sortByC(index,num);
 
 printf("上限分数:");
 scanf("%d",&b); 
 getchar(); 
 printf("下限分数:");
 scanf("%d",&a); 
 getchar();
 for(int i = 0;i < (*num);i++){
  if(index[i]->chineseGrade >= a && index[i]->chineseGrade <= b){
   printf("[%d] ",i+1);
   printf("%9s %14s %2s %24s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
    index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
    index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
  }
  else if(index[i]->chineseGrade < a){
   break;
  }
 }
}
void selectByM(Data *index[],int *num){
 int a, b;
 system("cls");
 sortByM(index,num);
 
 printf("上限分数:");
 scanf("%d",&b); 
 getchar(); 
 printf("下限分数:");
 scanf("%d",&a); 
 getchar();
 for(int i = 0;i < (*num);i++){
  if(index[i]->mathGrade >= a && index[i]->mathGrade <= b){
   printf("[%d] ",i+1);
   printf("%9s %14s %2s %24s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
    index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
    index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
  }
  else if(index[i]->mathGrade < a){
   break;
  }
 }
}
void selectByE(Data *index[],int *num){
 int a, b;
 system("cls");
 sortByE(index,num);
 printf("上限分数:");
 scanf("%d",&b); 
 getchar(); 
 printf("下限分数:");
 scanf("%d",&a); 
 getchar(); 
 for(int i = 0;i < (*num);i++){
  if(index[i]->englishGrade >= a && index[i]->englishGrade <= b){
   printf("[%d] ",i+1);
   printf("%9s %14s %2s %24s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
    index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
    index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
  }
  else if(index[i]->englishGrade < a){
   break;
  }
 }
}
void selectByA(Data *index[],int *num){
 int a, b;
 system("cls");
 sortByA(index,num);
 printf("上限分数:");
 scanf("%d",&b); 
 getchar(); 
 printf("下限分数:");
 scanf("%d",&a); 
 getchar();
 for(int i = 0;i < (*num);i++){
  if(index[i]->averGrade >= a && index[i]->averGrade <= b){
   printf("[%d] ",i+1);
   printf("%9s %14s %2s %24s 语文: %.2f 数学: %.2f 英语: %.2f 平均分: %.2f\n",
    index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
    index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
  }
  else if(index[i]->averGrade < a){
   break;
  }
 }
}
void squeeze(Data *index[],int *num, int point){
 for(int i = point+1;i < (*num);i++){
  index[i-1] = index[i];
 } 
 (*num)--;
}
void saveData(Data *index[],int *num,char file[]){
 FILE *fp = fopen(file,"wb");
 
 if((*num)){
  for(int i = 0;i < (*num);i++){
   fprintf(fp,"%s %s %s %s %f %f %f %f\n",
     index[i]->number,index[i]->name,index[i]->sex,index[i]->address,
     index[i]->chineseGrade,index[i]->mathGrade,index[i]->englishGrade,index[i]->averGrade);
  }
  printf("保存成功\n\n");  
 } 
 else{
  printf("无数据可保存\n\n"); 
 }
 
 fclose(fp);
 printf("按回车继续..."); 
 getchar();
}
