#include<bits/stdc++.h>
using namespace std;
int val[100501];
int ans[100501];
void cal(){
	int count=0;
	for(int i = 2; i <= 100500; i++){
		if(val[i] < 0){
				count++;
		}
		for(int j = i; j <=100500; j+=i){
			val[j] = 1;
		}
		ans[i] = count;
	}
}
int main(){
	int t;
	cin>>t;
	memset(val, -1, sizeof(val));
	cal();
	while(t--){
		int n;
		cin>>n;
		//if(n == 1){cout<<1<<endl;continue;}
		cout<<ans[n+1]<<endl;
	}
}
