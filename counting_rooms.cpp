#include<iostream>
#include<vector>
using namespace std;


void dfs(vector<vector<char>> &grid, int i ,int j){
	if(i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] == '#'){
		return;
	}
	
	grid[i][j] = '#';
	
	dfs(grid,i+1,j);
	dfs(grid,i-1,j);
	dfs(grid,i,j+1);
	dfs(grid,i,j-1);
	
}

int main(){
	int n,m;
	cin >> n >>m;
	
	vector<vector<char>> grid(n,vector<char>(m));
	
	for(int i = 0;i < n;i++){
		for(int j=0; j<m; j++){
			cin >> grid[i][j];
		}
	}
	
	int roomcnt = 0;
	
	for(int i = 0;i < n;i++){
		for(int j=0; j<m; j++){
			
			if(grid[i][j] == '.'){
				dfs(grid,i,j);
				roomcnt++;
			}
			
		}
	}
	cout << roomcnt << endl;
	
}