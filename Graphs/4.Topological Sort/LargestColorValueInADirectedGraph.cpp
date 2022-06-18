//DP + DAG 

    bool dfs(string &colors, unordered_map<int,vector<int>>&g, vector<int> &v, vector<int>&bag,vector<vector<int>>& colourValue, int node,int& maxColorValue) {
        v[node]  = 1;
        bag[node] = 1;
       colourValue[node][colors[node]-'a']=1;
        for(auto nbr : g[node]) {
            if(bag[nbr] == 1) {
                return true;
            } else if(v[nbr] == 0) {
                if(dfs(colors, g, v, bag, colourValue, nbr, maxColorValue))return true;
                
                
            }
            for(int i=0;i<26;i++) {

                colourValue[node][i] = max(colourValue[nbr][i] + (i==(colors[node]-'a')),colourValue[node][i]);
                maxColorValue=max(maxColorValue, colourValue[node][i]);
            }
        }
        
        bag[node] = 0;
        return false;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> visited(n);
        vector<int> bag(n);
        vector<vector<int>> colourValue(n,vector<int>(26,0));
        int maxColorValue=1;
        unordered_map<int,vector<int>> m;
        for(auto a:edges) {
            m[a[0]].push_back(a[1]);
        }
        for(int i=0;i<n;i++) {
            if(visited[i]==0) {
                if(dfs(colors,m,visited,bag,colourValue,i,maxColorValue)) return -1;
            }
        }
        return maxColorValue;
    }




