// Notes

/*
    Notes
    1-We can easily solve the problem of IsBipartite graph by DFS/BFS alternate colouring
    2-Property to be Bipartite ( either no cyle ie Tree. OR even len cycles ) 
    3-Odd len cycles simply means not bipartite
    4-We can use this colouring technique to find if there is odd len cycle ( just check if graph is not Bipartite)
    
*/
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& color,int req_color)
    {
        
        if(color[i]==-1)
        {
            color[i]=req_color;
            int ans=1;
            for(auto a:graph[i])
            {
                ans&=dfs(a,graph,color,1-req_color);
            }
            return ans;
        }
        else
        {
            return color[i]==req_color;
        }
    }
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            if(!dfs(i,graph,color,0))return false;
        }
        return true;
        
    }
