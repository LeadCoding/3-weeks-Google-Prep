#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
	int siz;
	

	void buildSegmentTree(int startOfRange, int endOfRange, int indexOfSegmentTree, vector<int>&v) {
		if(startOfRange == endOfRange) {
			segmentTreeArray[indexOfSegmentTree] = v[startOfRange];
			return;
		}
		int mid = (startOfRange + endOfRange)/2;

		buildSegmentTree(startOfRange, mid, indexOfSegmentTree*2 + 1, v);
		buildSegmentTree(mid + 1, endOfRange, indexOfSegmentTree*2 + 2,v);

		segmentTreeArray[indexOfSegmentTree] = segmentTreeArray[indexOfSegmentTree*2 + 1] + segmentTreeArray[indexOfSegmentTree*2 + 2]; 
	}

	int query(int startOfRange, int endOfRange, int indexOfSegmentTree, int l, int r) {
		if(endOfRange < l || startOfRange > r) {
			return 0;
		}

		if(startOfRange >= l && endOfRange <= r) {
			return segmentTreeArray[indexOfSegmentTree];
		}
		
		int mid = (startOfRange + endOfRange)/2;
		int leftSide = query(startOfRange, mid, indexOfSegmentTree*2 + 1, l, r);
		int rightSide = query(mid+1, endOfRange, indexOfSegmentTree*2 + 2, l, r);
		return leftSide + rightSide;

	}

	void update(int startOfRange, int endOfRange, int indexOfSegmentTree, int index, int val) {
		if(startOfRange == endOfRange) {
			segmentTreeArray[indexOfSegmentTree] = val;
			return;
		}
		int mid = (startOfRange + endOfRange)/2;
		if(mid >= index) {
			update(startOfRange, mid, indexOfSegmentTree*2 + 1, index, val);
		} else {
			update(mid + 1, endOfRange, indexOfSegmentTree*2 + 2, index, val);
		}
		segmentTreeArray[indexOfSegmentTree] = segmentTreeArray[indexOfSegmentTree*2 +1] + segmentTreeArray[indexOfSegmentTree*2 +2];
	}
public:
	vector<int> segmentTreeArray;
	SegmentTree(int siz):siz(siz) {
		segmentTreeArray.resize(siz*4);
	}

	void buildSegmentTree(vector<int>&v) {
		buildSegmentTree(0, siz - 1, 0, v);
	}

	int query(int l, int r) {
		return query(0, siz - 1, 0, l, r);
	}

	void update(int index, int val) {
		update(0, siz - 1, 0, index, val);
	}
};

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	SegmentTree segmentTree(5);
	segmentTree.buildSegmentTree(v);
	// for(auto a:segmentTree.segmentTreeArray) cout<<a<<" ";
	segmentTree.update(2,10);
	cout<<segmentTree.query(2,4);
}