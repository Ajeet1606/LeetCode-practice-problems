class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inPos = 0;
        int prePos = 0;
        return build(preorder, inorder, INT_MIN,    inPos,      prePos);
    }//                                 ⬆️stop, ⬆️inorderPtr  ⬆️preorderPtr.
    
    //as we know the left elements of inorder from root are left subtree so now we'll be traversing till that point and for every recursive call we'll tell when it should stop instead of getting root idx from map. we save O(n) space.
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop, int& inPos, int& prePos){
        if(prePos >= preorder.size()) return NULL;
        if(inorder[inPos] == stop) {inPos++; return NULL;} // ➡️when we reach stop, we'll go for right subtree.
        
        TreeNode* node = new TreeNode(preorder[prePos]);//➡️ create new node with root value.
        prePos++; //➡️next value will be new root.
        
        node->left = build(preorder, inorder, node->val, inPos, prePos);//➡️until we reach 'stop' all comes under left subtree.
        node->right = build(preorder, inorder, stop , inPos, prePos);//➡️after that right subtree.
        return node; //➡️return node of curr call.
    }
};