#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long int
int main(){
	int n;
	cin >> n;
	
	vector<int> a(n),b(n);
	
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 0;i<n;i++){
		cin >> b[i];
	}
	
	ll aw = 0,bw = 0;
	
	for(int i = 0;i<n;i++){
		if(a[i] > b[i]){
			aw += (a[i]-b[i]);
		}
		if(a[i] < b[i]){
			bw += (b[i] - a[i]);
		}
	}
	
	if(aw == 0){
		cout << "No" << endl;
		return 0;
	}
	
	ll amt = (bw/aw) + 2;
	vector<ll> ans;
	
	for(int i = 0;i<n;i++){
		if(a[i] <= b[i]){
			ans.push_back(1);
		}else{
			ans.push_back(amt);
		}
	}
	
	cout << "Yes" << endl;
	for(ll wt:ans) cout << wt << " ";
	cout << endl;
}