#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	int t;
	t = 1+rand()%100000;
	cout<<t<<endl;
	int n =10;
	while(t--){
		if(t == 50000){
			n += 100;
		}		
		cout<<n<<" ";
	}
}
