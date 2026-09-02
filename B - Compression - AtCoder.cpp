#include <iostream>
#include<set>
using namespace std;
int main(){
  int N;
  cin>>N;
  set<int> a;
  int c;
  for(int i=0;i<N;i++){
  	cin>>c;
  	a.insert(c);
  }
  int l=a.size();
  cout<<l<<endl;
  for(int x:a){
  	cout<<x<<" ";
  }
  cout<<endl;
}