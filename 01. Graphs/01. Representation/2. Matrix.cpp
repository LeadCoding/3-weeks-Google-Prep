#include<bits/stdc++.h>
using namespace std;

int main() {
	int n=6;
	vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

	int matrix[n][n];
	memset(matrix,0,sizeof matrix);

	for(int i=0;i<edges.size();i++) {
		matrix[edges[i][0]][edges[i][1]]=1;
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}