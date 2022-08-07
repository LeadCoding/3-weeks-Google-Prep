/*
     Now in this question we just have to keep removing the edges 1 by 1
     Better to use multiset 
*/

void dfs( map<string,multiset<string>> &m,string node,vector<string>&ans) {
        vector<string> temp;
        for(auto a:m[node]) {
            temp.push_back(a);
        }
        for(auto a:temp) {
            if(m[node].find(a)!=m[node].end()) {
                m[node].erase(m[node].find(a));
                dfs(m,a,ans);
            }  
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> m;
        for(auto a : tickets) {
            m[a[0]].insert(a[1]);
        }
        vector<string> ans;
        dfs(m,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }