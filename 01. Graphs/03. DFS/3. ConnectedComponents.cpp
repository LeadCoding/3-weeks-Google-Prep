//https://leetcode.com/problems/couples-holding-hands/

/*
        In this questions we just need to form components.
        Lets say one partner is present in NodeA and another in NodeB then join them.

        Node numebr is i/2;
        
        Then lets say a component has n nodes then swapping will be btw only these n node 
        hence n-1 swappings 

        so do the same for all components

        OR

        C1size - 1 + C2size -1 + C3size -1 ..
        = V - number of components
*/


void dfs(int node,map<int,vector<int>>&m,vector<int>&visited) {
        visited[node]=1;
        for(auto a:m[node]) {
            if(visited[a]==0)
            dfs(a,m,visited);
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        map<int,int> m;
        for(int i=0;i<row.size();i++) {
            m[row[i]]=i;
        }
        map<int,vector<int>> g;
        for(int i=0;i<n;i++) {
            int coupleA = row[i];
            int coupleB;
            if(coupleA%2) coupleB = coupleA - 1;
            else coupleB = coupleA + 1;
            int nodeOfA = i/2;
            int nodeOfB = m[coupleB]/2;
            g[nodeOfA].push_back(nodeOfB);
            g[nodeOfB].push_back(nodeOfA);  
        }
        int c=0;
        vector<int> visited(n/2,0);
        for(int i=0;i<n/2;i++) {
            if(visited[i]==0) {
                dfs(i,g,visited);
                c++;
            }
        }
        return n/2-c;
    }