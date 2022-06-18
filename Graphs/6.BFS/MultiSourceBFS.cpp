/* 
    This is a really good usecase of multi-source BFS 
    In this question we see how we can traverse from a point to tht point itself
    using minimum path.
    We can go back and forth btw nodes but should never land on the same config again
    
*/

//847. Shortest Path Visiting All Nodes



int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int,vector<int> > m;
        for(int i=0;i<n;i++) {
            for(auto a:graph[i])
            m[i].push_back(a);
        }
        
        queue<vector<int>> q;
        set<vector<int>>s;
        
        for(int i=0;i<n;i++) {
            q.push({i,0,(1<<i)});
            s.insert({i,(1<<i)});
        }
        
        while(q.size()) {
            auto a = q.front();
            q.pop();
            if(a[2] == (1<<n)-1) {
                return a[1];
            }
            for(auto nbr:m[a[0]]) {
                int mask = a[2] | (1<<nbr);
                if(s.find({nbr,mask})==s.end()) {
                    s.insert({nbr,mask});
                    q.push({nbr,a[1]+1,mask});
                }
            }
        }
        return -1;
    }