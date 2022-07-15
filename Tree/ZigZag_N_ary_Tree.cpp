/**************************************************
   
    class TreeNode
    {
    public:
        int val;
        vector < TreeNode* > child;
        
        TreeNode(int val)
        {
            this->val = val;
        }

        ~TreeNode()
        {
            for( int i=0 ; i<child.size();i++)
            {
                delete child[i];
            }
        }
    };
    
*****************************************************/

vector<int> zigzagLevelOrder(int n, TreeNode* root)
{
    // Write your code here.
    vector<int>ans;
    queue<TreeNode*>q;
    
    q.push(root);
    bool LtoR=true;
    // ans[0]=root->key;
    
    while(!q.empty())
    {
        int cnt=q.size();
        vector<int>row(cnt);
        
		for(int i=0;i<cnt;i++)
        {
            TreeNode *node=q.front();
            q.pop();
            
            int ind=LtoR?i: cnt-i-1;
            row[ind]=node->val;
        
            for(auto v: node->child)
            {
                q.push(v);
            }
            
        }
        
        LtoR=!LtoR;
  
        for(auto i:row)
            ans.push_back(i);
    }
    
    return ans;
}
