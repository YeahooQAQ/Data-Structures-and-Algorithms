BinTree Insert( BinTree BST, ElementType X ){
    if(BST == NULL){
        BST = (BinTree)malloc(sizeof(BinTree));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else if(BST->Data > X){
        BST->Left = Insert(BST->Left,X);
    }
    else if(BST->Data < X){
        BST->Right = Insert(BST->Right,X);
    }
    return BST;
}

BinTree Delete( BinTree BST, ElementType X ){
    BinTree t;
    if(BST == NULL){
        printf("Not Found\n");
    }
    else if(X < BST->Data){
        BST->Left = Delete(BST->Left,X);
    }
    else if(X > BST->Data){
        BST->Right = Delete(BST->Right,X);
    }
    else{
        if(BST->Left != NULL && BST->Right != NULL){
            t = FindMin(BST->Right);
            BST->Data = t->Data;
            BST->Right = Delete(BST->Right, BST->Data);
        }
        else{
            t = BST;
            if(BST->Left != NULL){
                BST = BST->Left;
            }
            else if(BST->Right != NULL){
                BST = BST->Right;
            }
            else{
                BST = NULL;
            }
            free(t);
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X ){
    if(BST == NULL) return NULL;
    if(BST->Data == X){
        return BST;
    }
    else if(BST->Data < X){
        return Find(BST->Right,X);
    }
    else{
        return Find(BST->Left,X);
    }
    return BST;
}

Position FindMin( BinTree BST ){
    if(BST == NULL) return NULL;
    while(BST->Left != NULL) BST = BST->Left;
    return BST;
}

Position FindMax( BinTree BST ){
    if(BST == NULL) return NULL;
    while(BST->Right != NULL) BST = BST->Right;
    return BST;
}