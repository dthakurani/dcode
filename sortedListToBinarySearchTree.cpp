/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* helperFunction(ListNode* head) {
        
        if(!head) return NULL;
        if(!head->next) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = helperFunction(head);
        root->right = helperFunction(slow->next);
        
        return root;
    }
    
   
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        return helperFunction(head);
        
    }
};