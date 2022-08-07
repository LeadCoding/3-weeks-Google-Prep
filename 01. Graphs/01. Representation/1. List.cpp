#include<bits/stdc++.h>
using namespace std;

int main() {
	int n=6;
	vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

	map<int,vector<int>> graph;

	for(int i=0;i<edges.size();i++) {
		int a=edges[i][0];
		int b=edges[i][1];
		graph[a].push_back(b);
	}

	for(auto a:graph) {
		cout<<a.first<<"---->";
		for(int i=0;i<a.second.size();i++) {
			cout<<a.second[i]<<" ";
		}
		cout<<endl;
	}
}