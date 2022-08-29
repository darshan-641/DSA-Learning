#include<bits/stdc++.h>

using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;


    Node( int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};


Node* buildTree( Node* root){

    cout<<"Enter the data : "<<endl;
    int data;
    cin>> data;

    root = new Node(data);
    
    if( data == -1){
        return NULL;
    }

    cout<<"Enter data for left node of "<< root ->data<<endl;
    root -> left = buildTree( root -> left);

    cout<< "Enter data for right node of "<< root -> data<<endl;
    root -> right = buildTree( root -> right);

    return root;
}

void LevelOrderTraversal( Node* root){

    queue<Node*> q;
    q.push( root);
    q.push(NULL);

    while( !q.empty()){

        Node* temp = q.front();
        q.pop();


        if( temp == NULL){

            cout<<endl;

            if( !q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp -> data<< " ";

            if( temp -> left){
                q.push( temp -> left);
            }
            if( temp -> right){
                q.push( temp -> right);
            }
        
        }
    }
}

void Inorder( Node* root){

    if( root == NULL) return ;

    Inorder(root -> left);
    cout<< root -> data<< " ";
    Inorder( root -> right);

    return;
}

void PreOrder( Node* root){

    if( root == NULL) return ;

    cout<< root -> data<< " ";
    PreOrder( root -> left);
    PreOrder( root -> right);

    return;
}

void PostOrder( Node* root){

    if( root == NULL) return ;

    PostOrder( root -> left);
    PostOrder( root -> right);
    cout<< root -> data<< " ";

    return;
}

void LeveLOrderBuild( Node* &root){

    cout<<"Enter the data : "<< endl;
    int data;
    cin>> data;
    root = new Node( data);

    queue<Node*> q;
    q.push( root);

    if( data == -1){
        return ;
    }

    while( !q.empty()){

            Node* temp = q.front();
            q.pop();

            cout<<"Inserting data for left side of : "<< temp -> data<< endl;
            int leftData;
            cin>> leftData;

            if( leftData != -1){
                temp -> left = new Node(leftData);
                q.push( temp -> left);
            }

            cout<<"Inserting data for right side of : "<< temp -> data<< endl;
            int rightData;
            cin>> rightData;

            if( rightData != -1){
                temp -> right = new Node(rightData);
                q.push( temp -> right);
            }
            
    }
}
int main(){

    Node* root = NULL;
    // root = buildTree(root);

    LeveLOrderBuild(root);

    LevelOrderTraversal(root);

    // Print Inorder
    cout<< endl<< "Print Inorder"<< endl;
    Inorder(root);

    // Print Preorder
    cout<< endl << "Print PreOrder"<< endl;
    PreOrder( root);

    // Print PostOrder
    cout<< endl << "Print PostOrder"<< endl;
    PostOrder(root);


    return 0;
}