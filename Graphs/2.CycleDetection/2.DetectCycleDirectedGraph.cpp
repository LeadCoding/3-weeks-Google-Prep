#include<bits/stdc++.h>
using namespace std;

bool detectCycle(unordered_map<int, vector<int>>& m, unordered_set<int>& visited, int node, int parent, unordered_set<int>& bag) {
	visited.insert(node);
	bag.insert(node);
	for(auto nbr: m[node]) {
	    if(bag.find(nbr) != bag.end()) return true;
		else if(visited.find(nbr) == visited.end()) {
	        if(detectCycle(m, visited, nbr, node, bag)) return true;
		}
	}
	bag.erase(node);
	return false;
}

bool solve(int n, vector<vector<int> > edges) 
{	
	unordered_map<int, vector<int>> graph;

	for(auto a: edges) {
		graph[a[0]].push_back(a[1]);
	}
	unordered_set<int> visited;
	unordered_set<int> bag;
	for(int i = 1; i < n; i++) {
	    if(visited.find(i) == visited.end()) {
	        if(detectCycle(graph, visited, i, -1, bag)) {
	            return true;
	        }
	    }
	    
	}
	return false;
	

}