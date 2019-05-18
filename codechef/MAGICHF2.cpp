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
	if(n%3==0||n%3==1)
	return rec((n+n)/3, k-1);
	else
		return rec((n+n)/3+2, k-1);
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
		
		ll rest = rec(n, k);
		//cout<<rest<<endl;
		if(rest == -1){
			cout<<"1.00000000\n";
		}
		else{
			if(rest == 0){
				cout<<"1.00000000\n";
			}
			else{
				if(rest > 1e9){
					cout<<"0.0000000\n";
					continue;
				}
				double ui = rest;
				printf("%.9lf\n",1.00/(ui));
			}
		}
	}
}
