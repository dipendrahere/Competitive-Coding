#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		bitset<64> b(n);
		string s = b.to_string();
		int count = 0;
		int flag = 0;
		for(int i=0;i<64;i++){
			if(s[i] == '1' && flag == 0){
				flag = 1;
			}
			if(flag == 1 && s[i] == '0'){
				count++;
			}
		}
		long long ans = 1;
		for(int i=0;i<count;i++){
			ans = ans*2;
		}
		cout<<ans<<endl;
	}
}
