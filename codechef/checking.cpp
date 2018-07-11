#include<bits/stdc++.h>
using namespace std;
int main(){
	set<pair<int, int > >  st;
	int n = 10;
	for(int i=0;i<n;i++){
		st.insert(make_pair(i, i));
	}
	auto i = st.lower_bound(make_pair(5, -10));
	i++;
	cout<<i->first<<" "<<i->second;
}
