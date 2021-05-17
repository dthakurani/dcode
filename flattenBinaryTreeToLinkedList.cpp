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

// 1st Approach

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL || (root->right == NULL && root->left == NULL))
            return;
        if(root->left != NULL) {
            flatten(root->left);
            
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            
            TreeNode* curr = root->right;
            while(curr->right) 
                curr = curr->right;
            curr->right = temp;
        }
        flatten(root->right);
    }
};


// 2nd Approach


TreeNode* helperFunction(TreeNode* root) {
        if(root == NULL || (root->right == NULL && root->left == NULL)) {
            return root;
        }
        else if(root->right == NULL) {
            TreeNode *temp = helperFunction(root->left);
            root->right = root->left;
            root->left = NULL;
            return temp;
        }
        else if(root->left == NULL) {
           TreeNode* temp = helperFunction(root->right);
            return temp;
        }
        else {
            TreeNode* tempFirst = helperFunction(root->left);
            TreeNode* tempSecond = helperFunction(root->right);
            tempFirst->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return tempSecond;
        }
    }
    
    TreeNode* flatten(TreeNode* root) {
        
        return helperFunction(root);
    }