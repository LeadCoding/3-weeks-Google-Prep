void dfs(int parent,int node) {

	visited[node]=1;
	low[node]=in[node]=time;
	time++;

	for(auto ch:m[node]) {
		if(ch == parent)continue;
		else if(visited[ch]==1) {
			low[node]=min(low[node],in[ch]);
		} else {
			dfs(node,ch);
			if(in[node]<low[ch]) {
				cout<<"the bridge is "<<node<<"--"<<ch<<endl;
			}
			low[node]=min(low[node],low[ch]); 
		}
	}
}
