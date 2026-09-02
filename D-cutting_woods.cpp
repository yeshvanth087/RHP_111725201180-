#include<iostream>
#include<set>
using namespace std;
int main(){
	int l,q;cin>>l>>q;
	set<int> st={0,l};
	//set.insert(0);
	//set.insert(l);
	while(q--){
		int qt,x;cin>>qt>>x;
		if(qt==1) st.insert(x);
		else{
			auto it=st.upper_bound(x);
			cout<<*it-*(prev(it))<<endl;
		}
	}
}