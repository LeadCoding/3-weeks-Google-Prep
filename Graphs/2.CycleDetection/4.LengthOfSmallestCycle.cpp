/*
	Notes 
	1- So the min len cycle can be found by using BFS 
	2- we can go to all the edges (u,v) and then find the min dis btw u and v using BFS
	 (excluding edge (u,v)) and then add 1.  compexity is E(E+V)
	3- Or we can do BFS from every node to detect the cycle and keep updating answer.

*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> edges){
     int ans = INT_MAX;
    unordered_map<int, vector<int>> m;
    for(auto a : edges) {
        m[a[0]].push_back(a[1]);
        m[a[1]].push_back(a[0]);
        if(a[0] == a[1]) return 1;
    }
    for(int i = 0; i < n; i++) {
       
        vector<int> parent(n,-1);
        vector<int> dis(n,20000);
        
        queue<int> q;
        q.push(i);
        dis[i] = 0;
        parent[i] = i;
        
        while(q.size()) {
            auto a = q.front();
            q.pop();
            for(auto n : m[a]) {
                if(parent[n] == -1) {
                    parent[n] = a;
                    dis[n] = dis[a] + 1;
                    q.push(n);
                } else if(parent[a] != n) {
                    ans = min(ans, dis[n] + dis[a] + 1);
                    break;
                }
            }
        }
        
    }
    return ans == INT_MAX ? -1 : ans;
    
}