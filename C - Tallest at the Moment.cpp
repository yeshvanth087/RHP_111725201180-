#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
	int N;cin>>N;
	vector<pair<int,int>>a(N);
	for(int i=0;i<N;i++){
		int h ,l;
		cin>>h >>l;
		a[i]=make_pair(h,l);
		
		
	}
	sort(a.begin(),a.end(),greater<>());
	int p=0;
	vector<int> la,ha;
	for(auto it:a){ 
		if(it.second>p){
			p=it.second;
			la.push_back(it.second);
			ha.push_back(it.first);
			//cout<<p<<endl;
		}
	}
	 int q;cin>>q;
	 while(q--){
	 	int t;
	 	cin>>t;
	 	auto it=upper_bound(la.begin(),la.end(),t);
	 	int idx =it -la.begin();
	 	cout<<ha[idx]<<endl;
	 }
}