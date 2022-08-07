class UnionFind {
    int * parent;
    int * rank;
    
    public:
    UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        
        for(int i = 0; i < n; i++) {
            parent[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int ele) {
        if(parent[ele] == ele) {
            return ele;
        } else return parent[ele] = find(parent[ele]);
    }
    
    void _union(int ele1, int ele2) {
        ele1 = find(ele1);
        ele2 = find(ele2);
        if(ele1 == ele2) return ;
        if(rank[ele1] > rank[ele2]) {
            parent[ele2] = ele1;
            rank[ele1] += rank[ele2];
        } else {
            parent[ele1] = ele2;
            rank[ele2] += rank[ele1];
        }
    }
};