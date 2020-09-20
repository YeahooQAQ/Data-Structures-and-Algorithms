#include <stdio.h>  
#include <malloc.h>  
#include <stdlib.h>  
#include <queue>  
#include <stack>  
#include <iostream> 
using namespace std;
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int flag;
};

typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
	SElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

void CreateBiTree(BinTree & T)//建树，按先序顺序输入节点  
{  
    char ch;  
    scanf("%c",&ch);  
    if(ch=='*'){  
        T=NULL;  
        return;  
    }  
    else{  
        T = (BinTree)malloc(sizeof(TNode));  
        if(!T) exit(1);  
        T->Data=ch;  
        CreateBiTree(T->Left);  
        CreateBiTree(T->Right);  
    }  
}  

void InorderTraversal( BinTree BT ){
    //Stack S = CreateStack();
    stack<BinTree> S;
	BinTree T = BT;
	while(T || S.empty() == false){
    //while(T || IsEmpty(S) == false){
        while(T){
            //Push(S,T);
            S.push(T);
			T = T->Left;
        }
        T = S.top();
        S.pop();
        //T = Pop( S );
        
        printf(" %c",T->Data);             
        T = T->Right;
    }
}

void PreorderTraversal( BinTree BT ){
    //Stack S = CreateStack();
    stack<BinTree> S;
    BinTree T = BT;
	while(T || S.empty() == false){
    //while(T || IsEmpty(S) == false){
        while(T){
            //Push(S,T);
            S.push(T);
			printf(" %c",T->Data);
            T = T->Left;
        }
        
        T = S.top();
        S.pop();
        //T = Pop( S );
        T = T->Right;
    }
}

void PostorderTraversal( BinTree BT ){
    if(!BT) return;
    //Stack S = CreateStack();
    stack<BinTree> S;
    BinTree T = BT;
    S.push(T);
	//Push(S,T);
    T->flag = 0;
	while(S.empty() == false){
    //while(T || IsEmpty(S) == false){
		T = S.top();
		//printf("\n %c %d\n",T->Data,T->flag);
		//T = Peek(S);			    
		if(T->flag == 0){ 
			T->flag = 1;
			//if(T->Left) Push(S,T->Left);
			if(T->Left){
				T->Left->flag = 0;				
				S.push(T->Left);	
			} 
		}					
        else if(T->flag == 1){
        	T->flag = 2;
        	//if(T->Right) Push(S,T->Right);
        	if(T->Right){
				T->Right->flag = 0;       		
				S.push(T->Right);        		
        	}
		}
        else if(T->flag == 2){
        	printf(" %c",T->Data);
        	//Pop(S);
        	S.pop();
        }
    }
}
int main(){  
	freopen("D:\\1.txt","rb",stdin);
    BinTree T;  
    CreateBiTree(T);  
    PreorderTraversal(T);  
    printf("\n");  
    InorderTraversal(T);  
    printf("\n");  
    PostorderTraversal(T);  
    printf("\n");  
}  
