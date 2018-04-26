#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	t = rand()%10;
	cout<<t<<endl;
	while(t--){
	int n = (rand()%100)+1;
	cout<<n<<endl;
	int a[n+1];
	int b[n+2];
	for(int i = 0; i < n;i++){
		a[i] = (rand()%105)+5;
		b[i] = rand()%(a[i])+1;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
}
