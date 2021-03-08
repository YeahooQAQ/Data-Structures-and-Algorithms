#include<iostream> 
#include<algorithm>
using namespace std;

struct Node{
	int val;
	int height;
	Node* left;
	Node* right; 
	Node(int n):val(n),left(NULL),right(NULL){}
};

int getHeight(Node* root){
	if(!root){
		return 0;
	}
	else{
		return max(getHeight(root->left),getHeight(root->right))+1;		
	} 
}

int getBalenceFactor(Node* root){
	return (getHeight(root->left) - getHeight(root->right));
}

Node* leftRotate(Node* root){
	Node* rChild = root->right;
	
	root->right = rChild->left;
	rChild->left = root;
	
	rChild->height = getHeight(rChild);
	root->height = getHeight(root);
	
	return rChild;
}

Node* rightRotate(Node* root){
	Node* lChild = root->left;
	
	root->left = lChild->right;
	lChild->right = root;
	
	lChild->height = getHeight(lChild);
	root->height = getHeight(root);
	
	return lChild;
}

Node* treeBalence(Node* root){
	int factor = getBalenceFactor(root);
	if(factor == 2 && getBalenceFactor(root->left) == 1){//LL
		return rightRotate(root);
	}
	else if(factor ==  -2 && getBalenceFactor(root->right) == -1){//RR
		return leftRotate(root);
	} 
	else if(factor == 2 && getBalenceFactor(root->left) == -1){//LR
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	else if(factor == -2 && getBalenceFactor(root->right) == 1){//RL
		root->right = rightRotate(root->right);
		return leftRotate(root); 
	}
	else{
		return root;
	}
}

void treeInsert(Node* & root, int val){
	if(!root){
		root = new Node(val);
		return;
	} 
	else if(root->val == val){
		return;
	}
	else if(root->val > val){
		treeInsert(root->left,val);
	}
	else if(root->val < val){
		treeInsert(root->right,val);
	}
	

	root = treeBalence(root);
}

void treeDelete(Node* & root, int val){
	Node* t = root;
	if(root){
		if(root->val == val){
			if(root->right){
				 
			}
			else{
				t = root;
				root = t->left;
				delete t;
			}
		}
		else if(root->val < val){
			treeDelete(root->right, val);
		}
		else{
			treeDelete(root->left, val);
		}
		treeBalence(root);
	}
}

int main(){
	Node* root = NULL;
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		int t;
		cin>>t;
		treeInsert(root,t);
	} 
	cout<<root->val;
	return 0;
}
