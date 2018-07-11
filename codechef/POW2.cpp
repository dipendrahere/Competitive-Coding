#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long a[n+2];
		for(long long i=0;i<n;i++)
			cin>>a[i];
		long long c = 0;
		long long ans = 0;
		for(long long i=0;i<n;i++){
			if((c+a[i])%2 == 0){
				c += a[i];
				c = c/2;
			}
			else{
				ans++;
				c+=a[i];
				c = c/2;
			}
		}
		ans += __builtin_popcountll(c);
		cout<<ans<<endl;
	}
}
