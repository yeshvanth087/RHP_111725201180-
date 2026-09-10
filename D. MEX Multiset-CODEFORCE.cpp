#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int N;
		cin >> N;
		
		vector<int> arr(N);
		vector<int> zi;
		
		for(int i = 0;i<N;i++){
			cin >> arr[i];
			if(arr[i] == 0){
				zi.push_back(i);
			}
		}
		if(zi.size() == 1){
			cout << "NO" << endl;
		}
		else{
			string s(N,'C');
			
			if(zi.size() != 0){
				
				s[zi[0]] = 'B';
				
				for(unsigned int i = 1;i <zi.size();i++){
					s[zi[i]] = 'A';
				}
				
			}
			
			cout << "YES" << endl << s << endl;
		}
	}
}