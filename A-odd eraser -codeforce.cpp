#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int siz;cin >> siz;
		vector<int> arr(siz);
		
		for(int i = 0;i<siz;i++){
			cin >> arr[i];
		}
		
		int a = arr[0];
		int b = arr[siz-1];
		
		while(b != 0){
			int temp = a%b;
			a = b;
			b = temp;
		}
		
		cout << a << endl;
	}
}