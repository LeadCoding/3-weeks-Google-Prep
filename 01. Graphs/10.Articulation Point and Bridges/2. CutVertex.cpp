void dfs(int parent,int node) {

	visited[node]=1;
	low[node]=in[node]=time;
	time++;

	int children=0;
	for(auto ch:m[node]) {
		
		if(ch == parent)continue;
		else if(visited[ch]==1) {
			low[node]=min(low[node],in[ch]);
		} else {
			dfs(node,ch);
			if(in[node]<=low[ch]&&parent!=-1) {
				cout<<"Vertex "<<node<<" is a cut vertex";
			}
			low[node]=min(low[node],low[ch]); 
			children++;
		}
	}
	if(parent==-1&&children>1) {
		cout<<"Vertex "<<node<<" is a cut vertex"; 
	}
}
