#include<bits/stdc++.h>
using namespace std;
long long ni(long long i, int k){
	if(i == 0)return 0;
	long l = 1;
	long ans;
	long h = 100000500;
	while(h >= l){
		long long mid = l + (h-l)/2;
		if(pow(mid,k) <= i){
			ans = mid;
			l = mid+1;
		}
		else{
			
			h = mid-1;
		}
	}
	return ans;
}
int main(){
	long long l,r;
	int q;
	cin>>q;
	//cout<<ni(q,2)<<endl;
	while(q--){
		cin>>l>>r;
		long long ans = 0;
		for(int i = 2; i<= log(r)/log(2); i++){
			ans+= ni(r,i) - ni(l-1,i);
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
