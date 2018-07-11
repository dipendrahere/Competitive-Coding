#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
	return a>b?a:b;
}
int check(int a[], int n, int time, int x){
	int maxw = x/time;
	int sum = 0;
	int c = 0;
	for(int i=0;i<n;i++){
		if(a[i] > maxw){
			return INT_MAX;
		}
		if(sum+a[i] > maxw){
			sum = a[i];
			c++;
		}
		else{
			sum = sum+a[i];
		}
	}
	if(sum > 0){
		c++;
	}
	return c;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int ans = INT_MAX;
		int n, k, time;
		cin>>n>>k>>time;
		int a[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long low = 0;
		long long high = INT_MAX;
		while(high >= low){
			long long mid = (high - low)/2 + low;
			int val = check(a, n, time, mid);
			if(val > k){
				low = mid+1;
			}
			else if(val < k){
				high = mid-1;
			}
			else{
				ans = min(mid, ans);
				high = mid-1;
			}
		}
		cout<<ans<<endl;
	}
}
