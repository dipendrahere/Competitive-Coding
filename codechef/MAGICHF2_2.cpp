#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(ll n, ll k){
	if(n == 1 && k >= 0){
		return -1;
	}
	if(k == 0){
		return n;
	}
	
	return rec((n+n)/3, k-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		if(n == 2){
			cout<<"0.50000000\n";
			continue;
		}
		if(k > 500){
			cout<<"1.00000000\n";
			continue;
		}
		ll res = 1;
		int flag = 0;
		while(k--){
			res = res*3;
			if(res >= 1e18){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout<<"1.00000000\n";
		}
		else{
			long double y = n+0.0;
			long double op = res;
			ll res = n - ceil(y/op);
			double hh = res;
			if(res == 0){
				cout<<"1.0000000\n";
			}
			printf("%.9lf\n",1.00/(res));
		}
	}
}
