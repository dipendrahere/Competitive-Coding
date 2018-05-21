#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a[n+2];
	cin>>a[0];
	long long mind = 9999999999;
	long long maxd = -9999999999;
	int u;
	for(int i = 1 ;i < n; i++){
		cin>>a[i];
		if(a[i] - a[i-1] > maxd){
			maxd = a[i]-a[i-1];
		}
		if(a[i] - a[i-1] < mind){
			mind = a[i] - a[i-1];
		}
	}
	if(n == 1){
		cout<<"0"<<endl;
		return 0;
	}
	long long ans = 999999999;
	for(long long i = a[1]-a[0] - 10; i <= a[1] - a[0]+ 10; i++){
		//cout<<i<<" ";
		for(long long j = -1; j <= 1; j++){
			long long count = 0;
			int flag = 1;
			long long s = a[0] + j;
			if(j != 0)count++;
			for(long long k = 1; k < n;k++){
				if(abs(a[k] - i - s) == 1){
					count++;
				}
				else if(abs(a[k] - i - s) > 1){
					flag = 0;
					break;
				}
				s = s+i;
			}
			if(flag == 0){
				continue;
			}
			else{
				if(count < ans){
					ans = count;
				}
			}
		}
	}
	if(ans == 999999999){
		cout<<"-1"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
}
