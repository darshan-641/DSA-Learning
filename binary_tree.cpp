#include<bits/stdc++.h>

using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node( int data ){
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};

Node* build_tree(Node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for the left subtree"<<data<<endl;
    Node* left_root = build_tree(root->left);
    cout<<"Enter data for the right subtree"<<data<<endl;
    Node* right_root = build_tree(root->right);



}
int main(){

    Node* root = NULL;

    build_tree(root);
    return 0;
}