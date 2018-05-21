#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int x1,x2,x3,v1,v2;
		cin>>x1>>x2>>x3>>v1>>v2;
		long long ans = abs(x3 - x1)*v2 - abs(x2-x3)*v1;
		if(ans == 0){
			cout<<"Draw\n";
		}
		else if(ans < 0){
			cout<<"Chef\n";
		}
		else{
			cout<<"Kefa\n";
		}
	}
}
