/*
    Learnings 
    We made the (DAG) using BFS traversal. 
    then applied DFS to find all (source to destination paths)
*/
    void dfs(vector<string>&temp, vector<vector<string>>&ans,string node,unordered_map<string,vector<string>>&adj,string endWord) {
        temp.push_back(node);
        if(node == endWord) {
            ans.push_back(temp);
        } else {
            for(auto nbr:adj[node]) {
                dfs(temp,ans,nbr,adj,endWord);
            }
        }
        temp.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> lvl;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> q;
        int l = 0;
        q.push(beginWord);
        lvl[beginWord]=0;
        while(q.size()) {
            int siz = q.size();
            while(siz--) {
                string a = q.front();
                q.pop();
                lvl[a]=l;
                for(int i=0;i<a.size();i++) {
                    string temp = a;
                    for(int j=0;j<26;j++) {
                        temp[i] = 'a'+j;
                        if(temp==a)continue;
                        if(dict.find(temp)!=dict.end()) {
                            
                            if(lvl.find(temp)==lvl.end()) {
                                 lvl[temp]=l+1;
                                 q.push(temp);
                                 adj[a].push_back(temp);
                            } else if(lvl[temp]>l) {
                                 adj[a].push_back(temp);
                            }
                           
                        }
                    }
                }
            }
            l++;
        }
        vector<string> temp;
        vector<vector<string>> ans;
        dfs(temp,ans,beginWord,adj,endWord);
        return ans;
    }