#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(ll n, ll k){
	if(k == 0){
		return n;
	}
	if(n == 1 || n == 0){
		return -1;
	}
	if(n == 2){
		return -1;
	}
	ll oo = n/4LL;
	if(oo*4LL+1LL == n){
		return rec(n/2LL+1LL,k-1);
	}
	if(oo*4LL == n){
		return rec(n/2LL, k-1);
	}
	return rec(n/2LL+1LL, k-1);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll k;
		cin>>k;
		if(n == 2){
			cout<<"0.500000\n";
			continue;
		}
		if(n == 1){
			cout<<"1.000000\n";
			continue;
		}
		if(k > 500){
			cout<<"1.000000\n";
			continue;
		}
		if(n == 1){
			cout<<"1.000000\n";
			continue;
		}
		if(n == 2){
			cout<<"0.500000\n";
			continue;
		}
		ll rest = rec(n, k);
		if(rest == 0 || rest == -1 || rest == 1){
			cout<<"1.000000\n";
		}
		else{
			if(rest > 1e9){
				cout<<"0.000000\n";
			}
			else
				printf("%.6lf\n",1.00/(rest+0.0));
		}
	}
}
