#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	srand(time(0));
	int t = rand()%20+1;
	cout<<t<<endl;
	while(t--){
		ll n = rand()%10 + 1;
		ll k = rand()%10;
		cout<<n<<" "<<k<<endl;
	}
}
