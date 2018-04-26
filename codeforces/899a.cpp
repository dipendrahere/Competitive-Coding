#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int c1=0;
	int c2=0;
	while(n--){
		int temp;
		cin>>temp;
		if(temp == 	1){
			c1++;
		}
		else{
			c2++;
		}
	}
	if(c1 >= c2){
		cout<<c2+(c1-c2)/3<<endl;
	}
	else {
		cout<<c1<<endl;
	}
}
