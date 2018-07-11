#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum = 0;
	multiset<int> st;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		st.insert(t);
		sum+=t;
	}
	float work = (4.5*(n+0.0))-(sum+0.0);
	int c = ceil(work);
	if(work <= 0){
		cout<<"0\n";
		return 0;
	}
	int ans = 0;
	for(auto i: st){
		if(i < 5){
			work = work - (5-i);
			ans++;
		}
		if(work <= 0){{
			break;
		}}
	}
	cout<<ans<<endl;
}
