#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a , ll b)
{
   if(a==0) return b;
   
   return gcd(b%a,a);
}
int main(){
	ll n, k;
	cin>>n;
	cin>>k;
	ll a[30]={0};
	int ans = 0;
	for(int i=0;i<k;i++){
		cin>>a[i];
		if(a[i] == 1){
			ans = -1;
		}
	}
	ans = 0;
	ll uans = 0;
	ll val[30] = {0};
	for(ll i = 1; i <= (1<<k)-1; i++){
		bitset<25> b(i);
		int count = 0;
		ll div = 1;
		int flag = 0;
		for(int y = 0; y < k; y++){
			int x = b[y];
			if(x == 1){
				count++;
				ll temp = div;
				ll g = gcd(div, a[y]);
				div = (div * a[y])/g;
				ll r = a[y]/gcd(temp, a[y]);
				ll rr = div/r;
				if(temp!=rr){
					count = 0;
					break;
				}
			}
		}
		
		ll v = n/div;
		val[count] += v;
		if(count%2 == 0){
			if(count != 0)
			uans+=v;
		}
		else{
			uans-=v;
		}
		//cout<<b<<" "<<v<<" "<<div<<" "<<val[count]<<" "<<count<<endl;
	}

	ans = 0;
	for(int i = 1; i < 30; i++){
		if(i%2 == 1){
			ans += val[i];
		}
		else{
			ans -= val[i];
		}
	}
	ans = n + uans;
	cout<<ans<<endl;
}
