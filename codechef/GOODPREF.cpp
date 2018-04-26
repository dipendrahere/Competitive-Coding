#include<bits/stdc++.h>
using namespace std;
double z = 0.0;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		char s[10000];
		scanf("%s", s);
		long long n;
		scanf("%lld", &n);
		long long l = strlen(s);
		long long h[l+10];
		memset(h, 0, sizeof(h));
		long long ca=0,cb=0;
		for(int i = 0;i<l;i++){
			if(s[i]=='a')ca++;
			else cb++;
			h[i] = ca-cb;
		}
		long long count = 0;
		long long ans = 0;
		for(int i = 0; i < l; i++){
			if(h[i] > 0){
				count++;
			}
		}
		if(h[l-1] == 0){
			ans = count*n;
			cout<<ans<<endl;

		}
		else if(h[l-1] > 0){
			ans = count*n;
			for(int i = 0; i < l; i++){
				if(h[i] <= 0){
					z = 0;
					z = (-1*h[i]+z)/(z+h[l-1]);
					long long x = ceil(z);
					if((-1*h[i])%h[l-1]==0)x++;
					long long ad = n-x;
					if(n - x < 0){
						ad = 0;
					}
					ans+=ad;
				}
			}
			cout<<ans<<endl;
			if(ans < 0)return 1;
		}
		else{
			count = l-count;
			ans = count*n;
			for(int i = 0; i < l; i++){
				if(h[i] > 0){
					z = 0.0;
					z = (z+h[i])/(-1*h[l-1]+z);
					long long x = ceil(z);
					long long ad = n-x;
					if(n - x < 0){
						ad = 0;
					}
					ans+=ad;
				}
			//	cout<<ans<<endl;
			}
			long long answ = n*l-ans;
			cout<<answ<<endl;
		}
	}
}
