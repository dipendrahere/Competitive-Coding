#include<bits/stdc++.h>
using namespace std;
long dp[100001];
void sets(){
	for(long i = 0; i < 100001; i++){
		dp[i] = (i*i)/4;
	}
}
void print(int n){
	int low = 0;
	int high = 100000;
	int ans;
	while(high >= low){
		int mid = (low+high)/2;
		//cout<<"->"<<mid<<" "<<dp[mid]<<endl;
		if(dp[mid] >= n){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	bool a[ans];
	memset(a, 0, sizeof(a));
	int v = 0;
	int count = 0;
	for(int i=0;i<ans;i++){
		if(n == v){
			break;
		}
		else{
			if(v - count + ans - i - 1 <= n){
				a[i] = 1;
				v = v - count + ans-i-1;
				count++;
			}
			else{
				a[i] = 0;
			}
			//cout<<"at i = "<<i<<" setting "<<a[i]<<" and v = "<<v<<endl;
		}
	}
	for(int i=0;i<ans;i++){
		if(a[i] == 1){
			cout<<"X";
		}
		else{
			cout<<"D";
		}
	}
	cout<<endl;
}

int main(){
	int t;
	memset(dp, 0, sizeof(dp));
	cin>>t;
	sets();
	while(t--){
		int n;
		cin>>n;
		print(n);
	}
}
