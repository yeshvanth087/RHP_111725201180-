#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int N;cin >> N;
		
		int odd = 0,eoq = 0,eeq = 0;
		
		while(N--){
			int num;
			cin >> num;
			
			if(num&1){
				odd++;
			}
			else{
				int num1 = num/2;
				if(num1&1){
					eoq++;
				}else{
					eeq++;
				}
			}
		}
		int ans = max(odd,eoq);
		cout << max(ans,eeq) << endl;
	}
}