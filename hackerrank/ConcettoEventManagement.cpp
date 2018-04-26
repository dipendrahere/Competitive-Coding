#include<bits/stdc++.h>
using namespace std;
#define mod 935329793
#define N 20005
#define sc(n) scanf("%d",&n);
int facts[N];
int ans[N];
int main(){
	facts[0] = 1;
	facts[1] = 1;
	for(int i=2;i<N;i++){
		facts[i] = (1LL*i*facts[i-1])%mod;
	}
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 3;
	int i,j,sum,v;
	for(i = 3;i < N; i++){
//		cout<<i<<" ";
		v = (1LL*i*facts[i])%mod;
		sum = 0;
		for(j = 1; j <= i; j++ ){
			sum += (1LL*facts[j]*ans[i-j])%mod;
			if(sum >= mod){
				sum -= mod;
			}
		}
		v = v - sum;
		if(v < 0){
			v+=mod;
		}
		ans[i] = v;
	}
	for(i = 19000;i < 19010;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	int t,n;
	sc(t);
	while(t--){
		sc(n);
		if(n < N){
			printf("%d\n",ans[n-1]);
		}
		else{
			printf("0\n");
		}
	}
}
