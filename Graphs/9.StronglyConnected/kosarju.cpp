/*
    TC O(E+V)
    SC O(E+V)

    1-  Apply DFS(same as in topo sort) and save outputs of this DSF and revserse it
    2-  take transpose of graph 
    3-  Apply DFS on transpose of graph and find connected comp.

*/


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int> adj[],vector<int>&visited,vector<int>&topo) {
	    visited[node]=1;
	    for(auto a:adj[node]) {
	        if(visited[a]==0)
	        dfs(a,adj,visited,topo);
	    }
	    topo.push_back(node);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> topo;
        vector<int> visited(V);
        vector<int> revAdj[V];
        
        for(int i=0;i<V;i++) {
            for(auto a:adj[i]) {
                revAdj[a].push_back(i);
            }
        }
        for(int i=0;i<V;i++) {
            if(visited[i]==0) {
                dfs(i,adj,visited,topo);
            }
        }
        reverse(topo.begin(),topo.end());
        //for(auto a:topo)cout<<a<<" ";
        vector<int> temp;
        int ans=0;
        for(int i=0;i<V;i++)visited[i]=0;
        for(auto i:topo) {
            if(visited[i]==0) {
                dfs(i,revAdj,visited,temp);
                ans++;
            }
        }
        return ans;
        
    }
};