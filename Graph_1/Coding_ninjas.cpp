#include<bits/stdc++.h>
using namespace std;
// #define maxx 1000
const int N=1000;
int cnt;

void solve(vector<vector<char>>&graph,vector<vector<int>>&visited,int i,int j,int n,int m,string str)
{
    if(str.size()==0)
    {
        cnt++;
        return;
    }
    
    if(i<0 || j<0 || i>=n || j>=m)
        return;
    
    if(visited[i][j]==1)
        return;
    
    if(str[0]!=graph[i][j])
        return;
    
    visited[i][j]=1;
    
    solve(graph,visited,i-1,j-1,n,m,str.substr(1));
    solve(graph,visited,i-1,j,n,m,str.substr(1));
    solve(graph,visited,i-1,j+1,n,m,str.substr(1));
    solve(graph,visited,i,j+1,n,m,str.substr(1));
    solve(graph,visited,i+1,j+1,n,m,str.substr(1));
    solve(graph,visited,i+1,j,n,m,str.substr(1));
    solve(graph,visited,i+1,j-1,n,m,str.substr(1));
    solve(graph,visited,i,j-1,n,m,str.substr(1));
    
    visited[i][j]=0;    
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        vector<vector<char>>graph(N,vector<char>(N));
        vector<vector<int>>visited(N,vector<int>(N));
        
        char ch;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ch;
                graph[i][j]=ch;
                visited[i][j]=0;
            }
        }
        
       cnt=0;
        string str="CODINGNINJA";
        
        bool flag=false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(graph[i][j]==str[0])
                {
                    solve(graph,visited,i,j,n,m,str);
                    if(cnt>0)
                    {
                    	cout<<"1"<<endl;
                        flag=true;
                        break;
                    }
                }
                    
            }
            if(flag)
                break;
        }
        
        if(!flag)
        cout<<"0"<<endl;
    }
    return 0;
}


