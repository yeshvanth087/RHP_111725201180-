#include<iostream>
using namespace std;
void solve(){
	int N;
	cin>>N;
	int a[N+1];
	for(int i=1;i<=N;i++){
	  cin>>a[i];
	}
	int samecnt=0, exchcnt=0;
	for(int i=1;i<=N;i++){
		if(i==a[i]){
			samecnt++;}
		else if(i==a[a[i]]){
				exchcnt++;
			}}
			cout<<exchcnt/2+1LL*samecnt*(samecnt-1)/2;
		
	}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	while(tc--){
		solve();
	}
}