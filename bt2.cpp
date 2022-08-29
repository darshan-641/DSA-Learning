#include<bits/stdc++.h>

using namespace std;



class Node{ 

    public:
    int data;
    Node* left;
    Node* right;


    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};


Node* buildTree( Node* root){

    cout<<"Enter data : "<<endl;

    int data;
    cin>>data;

    root = new Node(data);

    if( data == -1){

        return NULL;

    }

    cout<<"Inserting to left side : "<<endl;
    root -> left = buildTree( root -> left);

    cout<<"Inserting to right side : "<<endl;
    root -> right = buildTree( root -> right);


    return root;

}

void levelOrderTraversal( Node* root){

    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if( temp == NULL){
            cout<<endl;
            
            if( !q.empty()){

                q.push(NULL);
            }
        }

        else{
            cout<< temp -> data<<" ";

            if( temp -> left){
                q.push(temp->left);
            }
            if( temp -> right){
                q.push(temp-> right);
            }
        }

    }
}

void inorder( Node* root){

    if( root == NULL){
        return ;
    }

    inorder( root -> left);
    cout<< root -> data<<" ";
    inorder( root-> right);


}

void preorder( Node* root){

    if( root == NULL){
        return;
    }

    cout<< root -> data<< " ";
    preorder( root->left);
    preorder( root -> right);

}

void postorder( Node* root){

    if( root == NULL){

        return ;
    }

    postorder(root->left);
    postorder( root-> right);
    cout<<root -> data<< " ";

}

void buildLevelOrder( Node* &root){

    queue<Node*> q;
    
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);



    while( !q.empty()){

        Node* temp = q.front();
        q.pop();
        
        cout<<"Enter data for left node: "<< temp -> data<<endl;
        int leftData;
        cin>>leftData;
        if( leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout<<"Enter data for right node: "<< temp -> data<<endl;        
        int rightData;
        cin>>rightData;

        if( rightData != -1){
            temp -> right = new Node(rightData);
            q.push( temp -> right);
        }


    }
}
int main(){

    Node* root = NULL;
// 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 -1
//    root = buildTree(root);

    buildLevelOrder(root);

   levelOrderTraversal( root);
    cout<< endl<<" Inorder Walk"<<endl;
   inorder( root);

   cout<< endl<<" Preorder Walk"<<endl;
   preorder(root);

   cout<< endl<<" PostOrder Walk"<<endl;
   postorder( root);

    cout<<endl;
    return 0;
}

