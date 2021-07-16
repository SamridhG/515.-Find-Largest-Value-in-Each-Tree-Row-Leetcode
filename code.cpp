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
    vector<int> largestValues(TreeNode* root) {
         vector<int>res;
        if(root!=NULL)
        {
        vector<vector<int>>A;
        queue<TreeNode*>q;
        q.push(root);
            while(!q.empty())
            {
                int size=q.size();
                for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                res.push_back(temp->val);
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
                }
                A.push_back(res);
                res.clear();
            }
            for(int i=0;i<A.size();i++)
            {
                res.push_back(*max_element(A[i].begin(),A[i].end()));
            }
        }
        return res;
    }
};
