#include<iostream>
#include<vector>
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	int start = 0,end = 10;
	
	for(int i = 1; i <= n;i++){
		int ctr;
		cin >> ctr;
		
		if(!(ctr >= start && ctr <= end)){
			cout << "No" << endl;
			return;
		}
		if(i%10 == 0){
			start += 10;
			end += 10;
		}
	}
	cout << "Yes" << endl;
}

int main(){
	solve();
}