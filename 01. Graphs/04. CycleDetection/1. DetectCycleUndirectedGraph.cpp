#include<bits/stdc++.h>
using namespace std;

bool detectCycle(unordered_map<int, vector<int>>& m, unordered_set<int>& visited, int node, int parent) {
	visited.insert(node);
	for(auto nbr: m[node]) {
		if(visited.find(nbr) == visited.end()) {
			if(detectCycle(m,visited,nbr,node)) return true;
		}
		else if(nbr != parent) {
			return true;
		}
	}
	return false;
}

bool solve(int n, vector<vector<int> > edges) 
{	
	unordered_map<int, vector<int>> graph;

	for(auto a: edges) {
		graph[a[0]].push_back(a[1]);
		graph[a[1]].push_back(a[0]);
	}
	unordered_set<int> visited;
	for(int i = 1; i < n; i++) {
	    if(visited.find(i) == visited.end()) {
	        if(detectCycle(graph, visited, i, -1)) {
	            return true;
	        }
	    }
	    
	}
	return false;
	

}