  bool dfs(unordered_map<int,vector<int>> &graph, int node, vector<int> &visited, vector<int>& arrangedCourses, int& i, vector<int>& family) {
        visited[node] = 1;
        family[node] = 1;
        for(int nbr : graph[node]) {
            if(family[nbr] == 1) {
                return true;
            } else if(visited[nbr] == 0) {
                if(dfs(graph, nbr, visited, arrangedCourses, i, family)) return true;
            }
        }
        arrangedCourses[i--] = node;
        family[node] = 0;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>> graph;
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses);
        vector<int> arrangedCourses(numCourses);
        vector<int> family(numCourses);
        int n = numCourses - 1;
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(dfs(graph, i, visited, arrangedCourses, n, family) == true) {
                    return {};
                }
            }
        }
        return arrangedCourses;
    }
