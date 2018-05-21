#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int n, m;
	cin>>n>>m;
	vector<long long> a;
	vector<long long> sum;
	long long temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.pb(temp);
		if(i == 0){
			sum.pb(temp);
		}
		else{
			temp = sum[i-1]+a[i];
			sum.pb(temp);
		}
	}


	long long b[m+2];
	for(int i=0;i<m;i++){
		cin>>b[i];
		int x = lower_bound(sum.begin(), sum.end(), b[i]) - sum.begin();
		if(x == 0){
			cout<<x+1<<" "<<b[i]<<endl;
		}
		else
		cout<<x+1<<" "<<b[i]-sum[x-1]<<endl;
	}
}
