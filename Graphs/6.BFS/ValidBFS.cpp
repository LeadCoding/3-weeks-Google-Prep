/*
	We can sort the adj list according to the give seq  and generate a BFS
	then compare
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<vector<int>> edges;
	vector<vector<int>> adjList(n+1);
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin>>a>>b;
		edges.push_back({a,b});
	}

	vector<int> seq(n);
	for(int i=0;i<n;i++)cin>>seq[i];

	vector<int> reorder(n+1);
	for(int i=0;i<n;i++) {
		reorder[seq[i]]=i;
	}
	sort(edges.begin(),edges.end(),[&reorder](vector<int>&a,vector<int>&b)->bool{
		if(a[0]==b[0]) {
			return reorder[a[1]]<reorder[b[1]];
		}
		return true;
	});

	for(auto a:edges) {
		adjList[a[0]].push_back(a[1]);
		adjList[a[1]].push_back(a[0]);
	}
	// for(int i=1;i<=n;i++)
 //    {
 //        sort(adjList[i].begin(),adjList[i].end(),[&reorder](int a,int b) -> bool {
 //            return reorder[a]<reorder[b];
 //        });
 //    }
	queue<int> q;
	q.push(1);
	vector<int> res;
	vector<int> vis(n+1,0);
	vis[seq[0]]=1;
	while(q.size()) {

		auto a = q.front();
		q.pop();
		res.push_back(a);

		for(auto nbr: adjList[a]) {
			if(vis[nbr]==0) {
				q.push(nbr);
				vis[nbr]=1;
			}
		}
	}
	if(res == seq)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}