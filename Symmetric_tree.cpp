class Solution {
    bool check( TreeNode* p, TreeNode* q){
        
       if( p == NULL && q == NULL) return true;
        
        if( p != NULL && q == NULL) return false;
        
        if( p == NULL && q != NULL) return false;
        
        bool left = check( p -> left, q -> right);
        
        bool right = check( p -> right, q -> left);
        
        bool same = p -> val == q -> val;
        
        if( left && right && same ) return true;
        else return false;
        
        
        
    }
public:
    bool isSymmetric(TreeNode* root) {
     
        if( root == NULL) return true;
        
        return check(root -> left, root -> right);
    }
};