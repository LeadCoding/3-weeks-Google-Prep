int gameRoutes(int n, vector<vector<int>> edges)
{
    vector<int> dp(n + 1), indeg(n + 1);
    dp[1] = 1;
    unordered_map<int, vector<int>> m1;
    
    for(auto e : edges)
    {
        indeg[e[1]]++;
        m1[e[0]].push_back(e[1]);
       
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(!indeg[i])
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        auto a = q.front();
        q.pop();
        
        for(auto b : m1[a])
        {
            indeg[b]--;
            if(!indeg[b])
            {
                q.push(b);
            }
            dp[b]+=dp[a];
            dp[b]%=1000000007;
        }
        
    }
    
    return dp[n];
}