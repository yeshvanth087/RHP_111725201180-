#include<iostream>
#include<vector>

using namespace std;

int find(vector<int>& ldr, int node) {
	
	if (ldr[node] != node) {
		ldr[node] = find(ldr, ldr[node]);
	}
	return ldr[node];
}

void join(vector<int>& ldr, int lt, int rt) {
    ldr[find(ldr, rt)] = find(ldr, lt);
}

int main(){
	
	int N,E;
	cin >> N >> E;
	
	vector<int> ldr(N+1);
	
	for(int node = 1;node<=N;node++) ldr[node] = node;
	
	vector<int> dr(N+1);
	
	for(int i = 1;i<=E;i++){
		int a,b;
		cin >> a >> b;
		join(ldr,a,b);
		dr[i] = a;
	}
	
	vector<int> gcnt(N+1,0),ecnt(N+1,0);
	
	for(int node = 1; node <= N;node++){
		gcnt[find(ldr,node)]++;
	}
	
	for(int a:dr){
		ecnt[find(ldr,a)]++;
		
	}
	
	long long ans = 0;
	
	for(int node=1;node<=N;node++){
		long long curr = ((1LL*gcnt[node]*(gcnt[node]-1))/2)-ecnt[node];
		ans += curr;
	}
	cout << ans << endl;
	
}