#include <iostream>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  int NUM[N+2];
  for(int i=0;i<N+2;i++){
    NUM[i]=0;
  }
  for(int i=0;i<M;i++){
    int w1,w2;
    cin>>w1>>w2;
    NUM[w1]++;
    NUM[w2+1]--;
  }
  int mini=200005;
  for(int i=1;i<=N;i++){
    NUM[i]+=NUM[i-1];
    mini=min(NUM[i],mini);
  }
  cout<<mini<<endl;
}
  