#include<bits/stdc++.h>
using namespace std;
int prime[1000];
void pre(){
	for(int i=2;i<1000;i++){
		if(prime[i] == -1){
			for(int j=i+i;j<1000;j+=i){
				prime[j]=1;
			}
		}
	}
	//cout<<"Y";
}
int main(){
	memset(prime, -1, sizeof(prime));
	pre();
	int t;
	cin>>t;
	prime[0] = 1;
	prime[1] = 1;
	while(t--){
		int n;
		cin>>n;
		int o = 0;
		int mx = 9999999;
		for(int i=0;i<n;i++){
			int y;
			cin>>y;
			if(y == 1){
				o++;
			}
			else if(prime[y] == -1){
				mx = min(mx, y);
			}
		}
		if(mx == 9999999){
			mx = -1;
		}
		if(n == 1){
			cout<<"-1\n";
			continue;
		}
		if(o > 0){
			cout<<mx<<endl;
		}
		else if(n == 1){
			if(prime[mx] == -1){
				cout<<mx<<endl;
			}
			else{
				cout<<"-1\n";
			}
		}
		else{
			cout<<"-1\n";
		}
	}
	

}
