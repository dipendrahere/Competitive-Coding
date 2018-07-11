#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, k;
	cin>>t>>k;
	int minus ;
	cin>>minus;
	minus = minus/2;
	string s;
	for(int i=0;i<t-k;i++){
		s.push_back('0');
	}
	for(int i=0;i<k;i++){
		s.push_back('1');
	}
	int a[t];
	int b[t];
	int c[t];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	do{
		int cr=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				cr++;
				if(cr <= minus || cr >= k+1-minus){
					b[i]++;
				}
				else{
					a[i]++;
				}
				c[i]++;
			}
		}

	}while(next_permutation(s.begin(), s.end()));
	for(int i =0 ;i < t;i++){
		cout<<a[i]<<" ";
	}cout<<endl;
	for(int i =0 ;i < t;i++){
		cout<<b[i]<<" ";
	}cout<<endl;
	for(int i =0 ;i < t;i++){
		cout<<c[i]<<" ";
	}cout<<endl;
}
