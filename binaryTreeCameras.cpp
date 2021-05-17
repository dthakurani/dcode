/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    int helperFunction(TreeNode* root, int &minCameraCount) {
        if(root == NULL)
            return 0;
        
        int leftSubtreeStatus = helperFunction(root->left, minCameraCount);
        int rightSubtreeStatus = helperFunction(root->right, minCameraCount);
        
        if(leftSubtreeStatus == 0 && rightSubtreeStatus == 0)
            return -1;
        
        if(leftSubtreeStatus == -1 || rightSubtreeStatus == -1) {
            minCameraCount++;
            return 1;
        }
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        int minCameraCount = 0;
        int rootStatus = helperFunction(root, minCameraCount);
        int noToAdd = (rootStatus == -1) ? 1 : 0;
        return minCameraCount + noToAdd;
    }
};