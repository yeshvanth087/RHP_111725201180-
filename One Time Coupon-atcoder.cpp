#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<pair<int,int>> arr(n);
	int mini=2e9;
	long long int base=0;
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
		mini=min(mini,arr[i].first);
		base+=arr[i].first;
	}
	sort(arr.begin(),arr.end(),[](const pair<int,int>& a,const pair<int,int>& b){
		return a.first-a.second>b.first-b.second;
	});
	long long int ans=base;
	for(int i=1;i<=n;i++){
		base-=arr[i-1].first;
		base+=arr[i-1].second;
		long long int curr=base+(n-i>=i ? 0 : 1LL*mini*(i-(n-i)));
		ans=min(ans,curr);
	}
	cout<<ans<<endl;
}
}