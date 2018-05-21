#include<bits/stdc++.h>
using namespace std;
int nott(int k){
	bitset<100> b(k);
	bitset<100> ans(0);
	//cout<<b<<endl;
	int flag = 0;
	for(int j=0;j<100;j++){
		int i = b[99 - j];
		//cout<<i<<endl;
		if(i == 0 && flag == 0){
			ans[99 - j] = 0;
		}
		else if(flag == 1 && i == 0){
			ans[99 - j] = 1;
		}
		else if(flag == 1 && i != 0){
			ans[99 - j] = 0;
		}
		else{
			flag = 1;
			ans[99 - j] = 0;
		}
	}
	//cout<<ans<<endl;
	return ans.to_ulong();
}
int main(){
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	int nt = nott(k);
	vector<int> ans;
	//cout<<nt<<endl;
	if(k == 1){
		for(int i=0;i<n;i++)cout<<1<<" ";cout<<endl;
			continue;
	}
	if(k == 2){
		if(n%2 == 0){
			cout<<2<<" "<<1<<" ";
			for(int i=0;i<n-2;i++){
				cout<<1<<" "; 
			}
			cout<<endl;
		}
		else{
			cout<<2<<" ";
			for(int i=0;i<n-1;i++){
				cout<<1<<" ";
			}
			cout<<endl;
		}
		continue;
	}
	if(nt == 0){
		if(n%2 == 1){
			cout<<k<<" ";
			for(int i=0;i<n-1;i++)cout<<1<<" ";
				cout<<endl;
		}
		else{
			if(n==2){
				cout<<k-1<<" "<<1<<endl;
			}
			else{
				cout<<k<<" "<<2<<" "<<1<<" "<<3<<" ";
				for(int i=0;i<n-3;i++){
					cout<<1<<" ";
				}
				cout<<endl;
			}
		}
	}
	else if(n == 1){
		cout<<k<<endl;
	}
	else if(n == 2){
		cout<<k<<" "<<nt<<endl;
	}
	else if(n == 3){
		if(k%2 == 0){
			cout<<k<<" "<<nt-1<<" "<<1<<endl;
		}
		else{
			cout<<k-1<<" "<<nt<<" "<<1<<endl;
		}
	}
	else{
		if(n%2 == 0){
			cout<<k<<" "<<nt<<" ";
			for(int i = 0; i < n-2;i++){
				cout<<1<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<1<<" "<<2<<" "<<3<<" "<<k<<" "<<nt<<" ";
			for(int i = 0;i<n-5;i++){
				cout<<1<<" ";
			}
			cout<<endl;
		}

	}
}
	return 0;
}
