#include<bits/stdc++.h>
using namespace std;
bool deg(int i,int j, int k, int n){
	if(k < j || k > n){
		return true;
	}
	int s = i+j+k;
	return (s == 2*i || s == 2*j || s == 2*k);
}
int main(){
	int n;
	int count=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int c = 0^(i^j);
			if(!deg(i,j,c,n)){
				count++;
				//cout<<i<<" "<<j<<" "<<c<<endl;
			}
		}
	}
	cout<<count<<endl;
}
