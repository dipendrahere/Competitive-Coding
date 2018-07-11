#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[2*n+2];
		memset(a, 0, sizeof(a));
		int b[n+2];
		for(int i=0;i<n;i++){
			cin>>b[i];
			a[b[i]]++;
		}
		set<int> s;
		for(int i=1;i<=n+n;i++){
			if(a[i]==0){
				s.insert(i);
			}
		}
		int alice = 0;
		int bob = 0;
		for(int i=0;i<n;i++){
			auto x = s.lower_bound(b[i]);
			if(x == s.end()){
				bob++;
				s.erase(s.begin());
			}
			else{
				alice++;
				s.erase(x);
			}
		}
		if(alice > bob){
			cout<<"Alice\n";
		}
		else if(bob>alice){
			cout<<"Bob\n";
		}
		else{
			cout<<"Tie\n";
		}
	}
}
