#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long unsigned int ans, temp;
		n--;
		cin>>ans;
		ans = ans<<1;
		while(n--){
			cin>>temp;
			temp = temp<<1;
			ans = ans^temp;
		}
		cout<<ans<<endl;
	}
}
