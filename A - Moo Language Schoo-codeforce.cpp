#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;cin>>n;
	while(n--){
		int N,K;cin>>N>>K;
		string s;
		cin >> s;
int F=N/K;
		vector<bool>own(F,false);
		for(unsigned int i=0;i<s.length();i++){
			if(s[i]=='0'){
				int idx=i/K;
				own[idx]=true;
				
			}
		}
		int ans=0;
		for(int i =0;i<F;i++){
			if(!own[i]) ans++;
			
		}
		cout<<ans<<endl;
	}

}