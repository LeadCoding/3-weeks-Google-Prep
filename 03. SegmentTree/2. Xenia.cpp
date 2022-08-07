#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    
    int n;
    int build(int segIndex,int s,int e,vector<int>&v) {
        if(s==e) {
            segmentTreeArray[segIndex] = v[s];
            return 0;
        }
        int m = (s+e)/2;
        int level;
        level=build(segIndex*2+1,s,m,v);
        level=build(segIndex*2+2,m+1,e,v);
        if(level%2==0)
        segmentTreeArray[segIndex] = segmentTreeArray[segIndex*2+1] | segmentTreeArray[segIndex*2+2];
        else segmentTreeArray[segIndex] = segmentTreeArray[segIndex*2+1] ^ segmentTreeArray[segIndex*2+2];

        return level+1;
    }
 
    int update(int segIndex,int s,int e,int idx,int val) {
        if(s==e) {
            segmentTreeArray[segIndex] = val;
            return 0;
        }
        int m = (s+e)/2;
        int level;
        if(idx<=m) {
            level=update(segIndex*2+1,s,m,idx,val);
        }
        else {
            level=update(segIndex*2+2,m+1,e,idx,val);
        }
        if(level%2==0)
        segmentTreeArray[segIndex] = segmentTreeArray[segIndex*2+1] | segmentTreeArray[segIndex*2+2];
        else segmentTreeArray[segIndex] = segmentTreeArray[segIndex*2+1] ^ segmentTreeArray[segIndex*2+2];

        return level+1;
 
    }
 
    int query(int segIndex,int s,int e,int l,int r) {
        if(l>e||r<s) return 0;
        if(l<=s&r>=e) return segmentTreeArray[segIndex];
        int m = (s+e)/2;
        int left = query(segIndex*2+1,s,m,l,r);
        int right = query(segIndex*2+2,m+1,e,l,r);
        return left+right;
    }
    
public:
    vector<int> segmentTreeArray;

    SegmentTree(int siz) {
        n=siz;
        segmentTreeArray.resize(4*n);
    }
    void build(vector<int>&v) {
        build(0,0,n-1,v);
    }
 
    void update(int idx,int val) {
        update(0,0,n-1,idx,val);
    }
 
    int query(int l, int r) {
        return query(0,0,n-1,l,r);
    }
 
};


int main() {
    int n,m;
    cin>>n>>m;
    SegmentTree segmentTree((1<<n));

    vector<int> v(1<<n);
    for(int i=0;i<(1<<n);i++) {
        cin>>v[i];
    }
    segmentTree.build(v);
    while(m--) {
        int p,b;
        cin>>p>>b;
        segmentTree.update(p-1,b);
        cout<<segmentTree.segmentTreeArray[0]<<endl;
    }
}