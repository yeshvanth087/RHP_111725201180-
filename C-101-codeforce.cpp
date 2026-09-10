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
		
		for(int i = 0;i<N;i++){
			cin >> arr[i];
		}
		
		int lt = 0;
		int rt = N-1;
		
		while(lt < N && arr[lt] == 0) lt++;
		while(rt >= 0 && arr[rt] == 0) rt--;
		
		if(lt < N && rt >= 0){
			arr[lt] = arr[rt] = 1;
			}
		
		if(lt < rt){
			for(int i = 0;i<N;i++){
				if(i != lt && i != rt && arr[i] != 1){
					arr[i] = 0;
				}
			}
		}
		
		for(int i = 0;i<N;i++){
			cout << arr[i] << (i == N-1?"\n":" ");
		}
	}
}