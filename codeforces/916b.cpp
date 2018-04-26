#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct cmp {
    bool operator() (const ll& lhs, const ll& rhs) const {
        return lhs > rhs;
    }
};
int main(){
	ll sum, n;
	multiset<ll, cmp > se;
	cin>>sum>>n;
	string ans = bitset<64>(sum).to_string();
	for(int i  =0 ;i<64;i++){
		if(ans[i]=='1'){
			se.insert(64-i-1);
		}
	}
	if(se.size() >  n){
		cout<<"No\n";
		return 0;
	}
	while(se.size() < n){
		int s = *se.begin();
		se.erase(se.begin());
		se.insert(s-1);
		se.insert(s-1);
	}
	cout<<"Yes\n";
	for(auto i :se){
		cout<<i<<" ";
	}
	cout<<endl;
}
