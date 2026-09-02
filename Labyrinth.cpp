#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
const int diff[5] = {0,-1,0,1,0};
string dir = "LURD";
string getPath(int R, int C , int prow, int pcol, vector<string> &g){
	string ans = "";
	while(g[prow][pcol]!='A'){
		ans+=g[prow][pcol];
		char ch = g[prow][pcol];
		if(ch == 'L') pcol++;
		else if(ch == 'R') pcol--;
		else if(ch == 'U') prow++;
		else if(ch == 'D') prow--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
 
void solve(){
	int R,C;
	cin>>R>>C;
	vector<string> g(R);
	for(int i=0;i<R;i++){
		cin>>g[i];
	}
	queue<pair<int,int>> q;
	for(int row=0;row<R;row++){
		for(int col=0;col<C;col++){
			if(g[row][col]=='A'){
				q.push(make_pair(row,col));
				row=R;
				break;
			}
		}
	}
	int hops = -1,bcol = -1, brow=-1;
	bool found = false;
	while(!q.empty()){
		int qsize = q.size();
		hops++;
		if(found){
			cout<<"YES"<<endl;
			cout<<hops<<endl;
			cout<<getPath(R,C,brow,bcol,g);
			return;
		}
		while(qsize--){
			auto[row,col]= q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int ar = row+diff[i];
				int ac = col+diff[i+1];
				if(ac>=0 && ar>=0 && ar<R && ac<C){
					if(g[ar][ac]=='.'){
						g[ar][ac]=dir[i];
						q.push(make_pair(ar,ac));
					}
					else if(g[ar][ac]=='B'){
						g[ar][ac]= dir[i];
						brow = ar;
						bcol = ac;
						found = true;
						q.push(make_pair(ar,ac));
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
}