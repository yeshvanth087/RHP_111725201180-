#include<iostream>
#include<vector>
using namespace std;
int solve(){
        string text1,text2;
        cin>>text1>>text2;
        int r=text1.length();
        int c=text2.length();
        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        vector<int> pa(r+1,0);
       vector<int> pb(c+1,0);
        for(int i=1;i<=r;i++){
          pa[i]=(pa[i-1]+(text1[i-1]-'0'))%10;
        }
        for(int i=1;i<=c;i++){
          pb[i]=(pb[i-1]+(text2[i-1]-'0'))%10;
        }
        if(pa[r]!=pb[c]){
            cout<<"-1"<<endl;
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(pa[i-1] == pb[j-1]){
                   dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout<<dp[r][c]<<endl;
        return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}