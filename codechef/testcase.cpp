#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	int t;
	//srand(time(0));
	// cin>>t;
	t = 1+rand()%10+4;
	cout<<t<<endl;
	while(t--){
		int n = 1+rand()%10+3;
		int k = 1+rand()%(n-3);
		cout<<n<<" "<<k<<endl;
		while(n--){
			cout<<1+rand()%9985+10<<" ";
		}
		cout<<endl;
	}
}
