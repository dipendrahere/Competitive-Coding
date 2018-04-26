#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
ll pow(ull x, ull y, ull p){
	x = x%p;
	ll res = 1;
	while(y > 0){
		if(y & 1){
			res = (res * x)%p;
			y--;
		}
		else{
			y = y/2;
			x = (x*x)%p;
		}
	}
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans;
		if(n <= k){
			ans = pow(2, k, MOD) - pow(2, k-n, MOD);
			if(ans < 0){
				ans = ans + MOD;
			}
		}
		else if((n-k)%2 == 1){
			ans = pow(2, k, MOD) - 2;
			if(ans < 0){
				ans = ans + MOD;
			}
		}
		else{
			ans = pow(2, k, MOD) - 1;
			if(ans < 0){
				ans = ans + MOD;
			}
		}
		cout<<ans<<endl;
	}

}
