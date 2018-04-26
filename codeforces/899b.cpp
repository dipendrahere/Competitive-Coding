#include<bits/stdc++.h>
using namespace std;
string check="";
bool found(string a){
	//cout<<check<<endl;;
	for(int i =0 ;i <= a.size()-check.size();i++){
		int flag = 1;
		for(int j = 0; j < check.size(); j++){
			if(check[j]!=a[i+j]){
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			return true;
		}
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	check="";
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		temp = 31-temp;
		char rr= '0'+temp;
		check+=to_string(temp);
	}
	string b = "030101001010";
	string a = "020101001010";
	
	string s1 = a+b+b;
	string s4 = b+b+b;
	string s2 = b+a+b;
	string s3 = b+b+a;
	if(found(s1) || found(s2) || found(s3) || found(s4)){
		cout<<"Yes\n";
		return 0;
	}
	cout<<"No"<<endl;return 0;
}
