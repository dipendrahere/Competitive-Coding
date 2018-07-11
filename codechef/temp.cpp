#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int k;
	string s;
	cin>>k;
	for(int i=0;i<t-k;i++){
		s.push_back('0');
	}
	for(int i=0;i<k;i++){
		s.push_back('1');
	}
	int h[t];
	memset(h, 0, sizeof(h));
	int p;
	do{
		p = 0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				p++;
				if(p == 1 || p== k){
					continue;
				}
				h[i]++;
			}
		}
	}while(next_permutation(s.begin(), s.end()));
	for(int i=0;i<t;i++){
		cout<<h[i]<<" ";
	}
	cout<<endl;
}
