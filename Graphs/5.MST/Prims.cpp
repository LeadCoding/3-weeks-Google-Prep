/*
	Notes :
	1- No self loop or parelled edges 
	2- We try to connect all the nodes 
	3- We start by picking 1 node 
	4- Then we select the smallest edge from this node 
	5- Now we have 2 nodes
	6- Now we select the min edge from these 2 nodes
	7- This way we keep including nodes and covers up all nodes
	8- In total we have V nodes and V-1 edges
	9- We use adj list 
	Complexity :- O((V+E)Log(V))
	Space 	   :- O(E+V)

*/

#include<bits/stdc++.h>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> mst(V,0);
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,-1);
        int ans=0;
        priority_queue<vector<int>> q;
        q.push({0,0});
        key[0]=0;
    
        while(q.size()) {
            int u = q.top()[1];
            mst[u]=1;
            q.pop();
            
            for(int v=0;v<V;v++) {
                if(v == u || mst[v] == 1 ) continue;
                int w = abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
                if(w < key[v]) {
                    key[v] = w;
                    parent[v]=u;
                    q.push({-key[v],v});
                }
            }
        }

        for(auto &a:key) {
            ans+=a;
        }
        return ans;
    }











