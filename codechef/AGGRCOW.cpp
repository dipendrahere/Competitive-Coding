#include<bits/stdc++.h>
using namespace std;
long long maxx(long long a, long long b){
	return a>b?a:b;
}
int main(){
	long long t;
	cin>>t;
	while(t--){
		long long n,c;
		cin>>n>>c;
		long long a[n+2];
		long long min = INT_MAX;
		long long max = -10;
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a, a+n);
		min = a[0];
		max = a[n-1];
		long long diff = max-min;
		c--;
		long long dist = diff/(c);
		long long ans = INT_MIN;
		if(c == 1){
			cout<<dist<<endl;
			continue;
		}
		long long st = min;
		for(long long i = 0;i < c-1;i++){
			auto j = lower_bound(a, a+n, st+dist) - a;
			if(a[j]*c-st*c-diff >= -1*a[j-1]*c+st*c+diff){
				j--;
			}
			int pic = st;
			st = a[j];
			ans = maxx(st-pic,ans);
		}
		cout<<ans<<endl;
	}
}
