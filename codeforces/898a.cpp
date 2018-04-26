#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int count = 0;
	if(n%10 == 0){
		cout<<n<<endl;
		return 0;
	}
	for(int i = n;i >= n-15; i--){
		if(i%10 == 0){
			break;
		}
		count++;
	}
	int coun = 0;
	for(int i = n;i < n+10;i++){
		if(i %10 == 0){
			break;
		}
		coun++;
	}
	if(coun > count){
		cout<<n-count<<endl;
	}
	else{
		cout<<n+coun<<endl;
	}
}
