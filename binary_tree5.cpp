#include<bits/stdc++.h>

using namespace std;


class Node{
    public:
    int data;
    Node* right;
    Node* left;


    Node(int d){

        this -> data = d;
        this -> right = NULL;
        this -> left = NULL;

    }
};

Node* buildTree( Node* root){

    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if( data == -1) return NULL;

    cout<<"Enter data for left data : "<<endl;
    root -> left = buildTree( root -> left);

    cout<<"Enter data for right data : "<< endl;
    root -> right = buildTree( root -> right);

    return root;
}

void LevelOrderTraversal( Node* root){

    queue<Node*> q;
    q.push(root);
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
            cout<<temp -> data<<" ";

            if( temp -> left){
                q.push( temp -> left);
            }
            if( temp -> right){
                q.push( temp -> right);
            }
            
        }

    }
}


void buildLevelOrder( Node* &root){

    cout<<"Enter the data : "<<endl;

    int data;
    cin>>data;

    root = new Node(data);
    queue<Node*> q;
    q.push(root);
    if( data == -1){
        return ;
    }

    while( !q.empty()){

        Node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left side : "<< temp -> data;
        int leftData;
        cin>>leftData;

        if( leftData != -1){
            temp -> left = new Node( leftData);

        }
        

        cout<<"Enter the data for right side : "<< temp -> data;
        int rightData;
        cin>>rightData;

        if( rightData != -1){
            temp -> right = new Node( rightData);
            
        }
    }
}


void Inorder( Node* root){

    if( root == NULL) return ;

    Inorder(root -> left);
    cout<< root -> data;
    Inorder( root -> right);
}


void Preorder( Node* root){

    if( root == NULL) return ;

    cout<<root -> data<<" ";
    Preorder( root -> left);
    Preorder( root -> right);
}

void PostOrder( Node* root){

    if( root == NULL) return ;

    PostOrder( root -> left);
    PostOrder( root -> right);

    cout<< root -> data<< " ";

}
int main(){

    Node* root = NULL;
    root = buildTree(root);


    return 0;
}