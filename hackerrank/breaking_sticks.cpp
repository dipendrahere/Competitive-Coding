#include<bits/stdc++.h>
using namespace std;
int s[1000005];
void sieve(){
	for(int i = 2; i*i < 1000005; i++){
		if(s[i] == -1)
		for(int j = 2*i;j < 1000005; j+=i){
			if(s[j] == -1)
			s[j] = i;
			//cout<<j<<i<<endl;
		}
	}
}
long long calmin(long long n){
	long long till = sqrt(n)+10;
	for(long long i=2;i < till;i++){
		if(n%i == 0){
			return i;
		}
	}
	return -1;
} 
int main(){
	s[0] = 0;
	s[1] = -1;
	s[2] = -1;
	for(int i = 0; i < 1000005;i++){
		s[i] = -1;
	}
	sieve();
	//for(int i=0;i<15;i++)cout<<s[i]<<endl;
	int t;
	cin>>t;
	long long ans = 0;
	while(t--){
		long long n;
		cin>>n;
		if(n == 1){
			ans+= 1;
		}
		else if(n < 1000000){
			ans += n;
			while(s[n] != -1){
				ans += n/s[n];
				n = n/s[n];
			}
			ans++;
			//cout<<ans;
		}
		else{
			ans += n;
			int hogya = 0;
			while(n >= 1000000){
				long long d = calmin(n);
				if(d == -1){
					ans+=1;
					hogya = 1;
					break;
				}
				else{
					ans+=( n/d);
					n = n /d;
				}
			}
			if(hogya == 1){
				continue;
			}
			if(n < 1000000){
			
			while(s[n] != -1){
				ans += n/s[n];
				n = n/s[n];
			}
			ans++;
			//cout<<ans;
		}

		}
	}
	cout<<ans<<endl;
}
