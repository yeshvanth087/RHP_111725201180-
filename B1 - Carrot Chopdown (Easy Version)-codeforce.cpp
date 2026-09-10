#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(M + 1, 0);
    for (int ctr = 1; ctr <= N; ctr++) {
        int curr; 
        cin >> curr;
        cnt[curr]++;
    }
    vector<int> psum(M + 1, 0);
    for (int i = 1; i <= M; i++) {
        psum[i] = psum[i - 1] + cnt[i];
    }
    int ans = 0;
    for (int c = 1; c <= M; c++) {
    }
    cout << ans << endl;
}
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int M,N;
		cin >> M >>N;
		
		vector<int> cnt(N+1,0);
		
		for(int i = 1;i<=M;i++){
			int carlen;
			cin >> carlen;
			cnt[carlen]++;
		}
	
	
	vector<int> psum(N+1,0);
	
	for(int i = 1;i<=N;i++){
		psum[i] = psum[i-1] + cnt[i];
	}
	
	int ans = 0;
	
	for(int i = 1;i<=N;i++){
		int carlencnt = psum[N] - psum[i-1];
		if(2*i <= N){
			carlencnt += cnt[2*i];
		}
		ans = max(ans,carlencnt);
	}
	cout << ans << endl;
	
}
}