#include<bits/stdc++.h>


using namespace std;


class Node{
    public:

    Node* left;
    Node* right;
    int data;

    Node( int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }



};


Node* buildTree( Node* root){

    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);
    
    if( data == -1) return NULL;

    cout<< "Enter the data for left Node"<<endl;
    
    root -> left = buildTree( root -> left);

    cout<< "Enter the data for right Node"<<<endl;
    root ->right = buildTree( root -> right);


    return root;

}


void LevelOrderTraversal( Node* root){

    

}
int main(){

    Node* root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 -1
    LevelOrderTraversal(root);
    
    return 0;
}