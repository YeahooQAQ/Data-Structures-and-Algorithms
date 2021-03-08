#include<iostream>

using namespace std;

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput(List L){
	List t = L;
	ElementType tn;
	cin>>tn;
	while(tn != -1){
		t->Next = new Node;		
		t = t->Next;
		t->Data = tn;
		t->Next = NULL;  
		cin>>tn;		
	}
}

void PrintList( List L ){
	
	cout<<L->Data<<" ";			
	
	if(L->Next){
		PrintList(L->Next);		
	} 		
}

void K_Reverse(List L,int K){
    List Last = L;    
	List front = L->Next;
    List rear = front;
 
    while(rear != NULL){
        int n;
        for(n = 1;n < K;n++){
            if(rear != NULL){
                rear = rear->Next;
            }
            else{
                break;
            }
        }
		if(n == K && rear != NULL){
    		List curr = front;
    		List pre = NULL;
    		List next = curr->Next;
						
        	while(1){
           		curr->Next = pre;
				if(curr == rear) break;
				pre = curr;
            	curr = next;
            	next = next->Next;
        	}  
        	
        	Last->Next = rear;
        	front->Next = next;
        	Last = front;
        	front = next;
        	rear = front;
		}
    } 
}
	

int main()
{
    List L = new Node;
    int K;

    ReadInput(L);
    cin>>K;
    K_Reverse( L, K );
    PrintList( L );

    return 0;
}
