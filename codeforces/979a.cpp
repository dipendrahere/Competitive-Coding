#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	if(n == 0){
		cout<<0<<endl;
		return 0;
	}
	n++;
	if(n&1){
		cout<<n<<endl;
	}
	else{
		cout<<(n>>1)<<endl;
	}
}
