#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int c = 0;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			if(temp%m == 0){
				c++;
			}
		}
		if(c == 0){
			cout<<0<<endl;
		}
		else{
			ll ans = 1LL;
			for(int i=0;i<c;i++){
				ans *= 2LL;
			}
			cout<<ans-1LL<<endl;
		}
	}
}
