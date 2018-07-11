#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll k, ll n){
	ll need;
	ll full = n;
	ll my=0;
	ll her=0;
	if((n&1) == 0){
		need = n/2LL;
	}
	else{
		need = n/2LL;
		need++;
	}
	ll c = n;
	while(n > 0LL){
		if(k > n){
			n = 0;
			my+=n;
			if(my >= n){
				return true;
			}
			else{
				return false;
			}
		//	cout<<"my eat "<<n<<"and total "<<my<<endl;
		}
		else{
			n = n -k;
			my+=k;
		//	cout<<"my eat "<<k<<"and total "<<my<<endl;
		}
		if(my >= need){
			return true;
		}
		ll eat = n/(10LL);
		if(n < 10LL){
			;;
		}
		else{
			n = n -eat;
			her+=eat;
			//cout<<"her eat "<<eat<<"and total "<<her<<endl;
		}
		//cout<<n<<endl;
		if(my >= need){
			return true;
		}
		if(her > full-need){
	//		cout<<full-need<<endl;
			return false;
		}
	}
	if(my >= need){
			return true;
	}
	if(her > full-need){
			return false;
	}
	return false;
}
int main(){
	// check(1, 42);
	// return 0;
	ll n;
	cin>>n;
	ll ans;
	ll low = 1LL;
	ll high = n;
	while(high >= low){
		ll mid = (high-low)/2LL +low;
		bool ch = check(mid, n);
	//	cout<<mid<<" "<<ch<<endl;
		if(ch){
			high = mid-1LL;
			ans = mid;
		}
		else{
			low = mid+1LL;
		}
	}
	ll uu = ans;
// 	if(n > 10){
// 	for(ll i = uu; i >= uu-10LL;i--){
// 		if(check(i, n)){
// 			ans = uu;
// 		}
// 	}
// }
	cout<<ans<<endl;
}
