#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int x=0,y=0;
	for(auto i :s){
		if(i == 'N'){
			x++;
		}
		else if(i == 'S'){
			x--;
		}
		else if(i == 'W'){
			y--;
		}
		else{
			y++;
		}
	}
	cout<<abs(x)+abs(y);
}