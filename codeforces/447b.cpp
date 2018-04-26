#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int k;
	cin>>s;
	cin>>k;
	int w[26];
	int mx=0;
	for(int i=0;i<=25;i++){
		cin>>w[i];
		if(w[i]>mx){
			mx = w[i];
		}
	}
	//cout<<"mx = "<<mx<<endl;
	int sum=0;
	for(int i=0;i<s.size()+k;i++){
		if(i >= s.size()){
			sum+=mx*(i+1);
			continue;
		}
		sum+=(w[s[i]-'a']*(i+1));
	}
	
	cout<<sum<<endl;
}
