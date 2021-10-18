class Solution {
public:
bool isCousins(TreeNode* root, int x, int y) {

    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        bool foundX = false;
        bool foundY = false;
        
        for(int i=0;i<size;i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == x)
                foundX = true;
            if(curr->val == y)
                foundY = true;
            
            if(curr->left && curr->right)  // check if x and y are children of the same parent 
            {
                if((curr->left->val == x && curr->right->val == y) || (curr->left->val == y && curr->right->val == x))
                    return false;
            }
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
        
        if(foundX && foundY)  // if x and y are cousins 
            return true;
    }
    
    return false;
}
};