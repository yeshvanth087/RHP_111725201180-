#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;cin>>n;
	while(n--){
		int N;cin>>N;
		vector<int>arr(N);
		int oc=0;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			oc+=arr[i];
			
		}
		int zc=N-oc;
		if(zc<2){
			cout<<"-1"<<endl;
			
		}else{
			int ans=0;
			if(arr[0]) ans++;
			if(arr[N-1])ans++;
			cout<<ans<<endl;
		}
	}
}