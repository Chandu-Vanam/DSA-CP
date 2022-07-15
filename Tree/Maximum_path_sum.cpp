#include<bits/stdc++.h>
/************************************************************

   Following is the TreeNode class structure

   class TreeNode {
    public:
        int data;
        vector<TreeNode*> children;

        TreeNode(int data) {
            this->data = data;
        }
   }

************************************************************/
int maxans=0;
void dfs(TreeNode* root,int ans)
{
    ans+=root->data;
    maxans=max(maxans,ans);
    
    for(auto v:root->children)
    {
        dfs(v,ans);
    }
}

int findMaxSum(int n, TreeNode* root)
{
    // Write your code here.
    maxans=0;
    int ans=0;
    dfs(root,ans);
    return maxans;
}
