#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n;
		cin>>n;
		int ca = 0,cb = 0;
		long long count = 0;
		for(int i = 0; i < n;i++){
			for(int j = 0; j < s.size(); j++){
				if(s[j] == 'a')ca++;
				else{
					cb++;
				}
				if(ca - cb > 0){
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
}
