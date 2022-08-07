/*

	 either there are 2 indegree of a node or there will be a cycle or both 

	 so first find those 2 edges which are causing indegree as 2
	 then we try to remove the later one to see that if skipping tht will avoid cycle or not, if yes then its the answer 
	 else second edge 
	 if we could not find edge 1 or 2 then return the edge which causes cycle
	 

*/


class Solution {
public:
    int *p,*r;
    int find(int x) {
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }
    void unite(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return ;
        if(r[x]>r[y]) {
            p[y]=x;
            r[x]++;
        } else {
            p[x]=y;
            r[y]++;
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> inDegree(n+1,-1);
        int rem1=-1,rem2=-1;
        for(int i=0;i<edges.size();i++) {
            vector<int> e=edges[i];
            if(inDegree[e[1]]!=-1) {
                rem2=i;
                rem1=inDegree[e[1]];
            }
            inDegree[e[1]]=i;
        }

        p = new int[n+1];
        r = new int [n+1];
        for(int i=0;i<n+1;i++) {
            p[i]=i;
            r[i]=0;
        }
        int flag =1;
        for(int i=0;i<edges.size();i++) {
            if(rem2 == i) continue;
            if(find(edges[i][0])==find(edges[i][1])) {
                if(rem1!=-1)return edges[rem1];
                else return edges[i];
            }
            unite(edges[i][0],edges[i][1]);
        }
        return edges[rem2];
        
    }
};