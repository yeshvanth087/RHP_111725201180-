#include<iostream>
 
using namespace std;
 
void solve(){
 
	int N;
	string s;
	cin >> N >> s;
	if(s[0] == '0' || s.find("00") != string::npos){
		cout << "-1" << endl;
		return;
	}
 
	int ans = -1;
	if(s.find("-+") != string::npos || s.find("+-") != string::npos){
		if(s.find("+--+") != string::npos || s.find("-++-") != string::npos){
			ans = 3;
		}else{
			ans = 2;
		}
 
	}else{
		ans = 1;
		for(int i = 0;i<N;i+=2){
			if(s[i] == '0'){
				ans = 2;
				break;
			}
		}
	}
	cout << ans << endl;
}
 
int main(){
	int n;
	cin >> n;
	while(n--){
		solve();
	}
 
}