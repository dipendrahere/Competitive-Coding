#include<bits/stdc++.h>
using namespace std;
bool in(char a){
	char x[] = {'a','e','i','o','u','1','3','5','7','9'};
	for(int i = 0; i < 10;i++){
		if(x[i] == a){
			return true;
		}
	}
	return false;
}
int main(){
	string s;
	cin>>s;
	int count = 0;
	for(auto i:s){
		if(in(i)){
			count++;
		}
	}
	cout<<count<<endl;
}
