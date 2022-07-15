#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;

		vector<int> tree[n+1];
		vector<int> degree(n+1, 0);

		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
			degree[u] ++;
			degree[v] ++;
		}

		vector<int> timeOfRemoval(n+1, 0);

		queue<int> q;

		for(int i=1; i<=n; i++){
			if(degree[i] == 1){
				timeOfRemoval[i] = 1;
				q.push(i);
			}
		}

		while(!q.empty()){
			int u = q.front();
			q.pop();


			for(int v: tree[u]){
				degree[v] --;
				if(degree[v] <= 1 and timeOfRemoval[v] == 0){
					timeOfRemoval[v] = timeOfRemoval[u] + 1;
					q.push(v);
				}
			}
		}

		int ans = 0;
		for(int i=1; i<=n; i++){
			if(timeOfRemoval[i] > k) ans++;
		}

		cout<<ans<<"\n";
	}

	return 0;
}
