#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N,Q;
	cin >> N >> Q;
	
	vector<int> pos(N+1,0);
	
	for(int i = 1;i <= N;i++){
		int val;
		cin >> val;
		
		pos[val] = i;
	}
	
	int nxtpos = N+1;
	
	while(Q--){
		int up;
		cin >> up;
		
		pos[up] = nxtpos++;
	}
	
	vector<pair<int,int>> arr;
	
	for(int i = 1;i<=N;i++){
		arr.push_back({pos[i],i});
	}
	
	sort(arr.begin(),arr.end());
	
	for(auto it:arr){
		cout << it.second << " ";
	}
	cout << endl;
}