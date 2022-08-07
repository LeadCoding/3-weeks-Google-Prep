//https://leetcode.com/problems/maximum-path-quality-of-a-graph/

/*
    In this problem we get to know a differet variety of DFS with a stopping condition 
    of time rather than all visited.
*/


void dfs(int &ans ,map<int,vector<vector<int>>>&m,int maxTime,int time,vector<int>&visited,int score, vector<int>&values,int node) {
        
        
        if(time>maxTime) return ;
        
        if(visited[node]==0){
            score+=values[node];
        }
        visited[node]++;
        
        if(node==0) {
            ans=max(ans,score);
        }
        
        for(auto &nbr:m[node]) {
            dfs(ans,m,maxTime,time+nbr[1],visited,score,values,nbr[0]);
        }
        visited[node]--;
        
        
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        map<int,vector<vector<int>>> m;
        int n=values.size();
        for(auto &a: edges) {
            m[a[0]].push_back({a[1],a[2]});
            m[a[1]].push_back({a[0],a[2]});
        }
        vector<int> visited(n,0);
        int ans=0;
        dfs(ans,m,maxTime,0,visited,0,values,0);
        return ans;
    }