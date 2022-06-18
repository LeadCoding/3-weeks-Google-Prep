/*
	Node 
	1- It used edge list 
	2- sort all edges according to the weights
	3- then start selecting edges 1 by 1 
	4- only select an edge if it doesnt form a cycle 
	5- use DSU for that 
	6- Time Complexity  ElogE
	7- Space O(V)
*/ 

int *rank,*parent;

int find(int x) {
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void unite(int x,int y) {
	x=find(x);
	y=find(y);

	if(x==y) return ;

	if(rank[x]>rank[y]) {
		parent[y]=x;
		rank[x]++;
	} else {
		parent[x]=y;
		rank[y]++;
	}
}

int wtMst(int n, vector<vector<int>>& edges,int skipEdge,int compulsoryEdge) {
    
    rank = new int[n];
    parent = new int[n];
	for(int i=0;i<n;i++) {
		rank[i]=0;
		parent[i]=i;
	}
    int totEdges=0;
	int ans=0;
	if(compulsoryEdge!=-1){
		unite(edges[compulsoryEdge][0],edges[compulsoryEdge][1]);
		ans+=edges[compulsoryEdge][2];
        totEdges++;
	}

	for(int i=0;i<edges.size();i++) {
		if(i==skipEdge)continue;
		if(find(edges[i][0])!=find(edges[i][1])) {
			unite(edges[i][0],edges[i][1]);
			ans+=edges[i][2];
            totEdges++;
		}
	}
    if(totEdges!=n-1)return INT_MAX;  // cnt make MST
	return ans;

}
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

	for(int i=0;i<edges.size();i++) {
		edges[i].push_back(i);
	}
     
	sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b)->bool{return a[2]<b[2];});
   
	int originalMst = wtMst(n,edges,-1,-1);
   
	vector<int> critical,psudo_critical;
    
	for(int i=0;i<edges.size();i++){
       
		if(wtMst(n,edges,i,-1)>originalMst) { 
			critical.push_back(edges[i][3]);
		} else if(wtMst(n,edges,-1,i)==originalMst) {
            
			psudo_critical.push_back(edges[i][3]);
		}
		
	}
	return {critical,psudo_critical};

}