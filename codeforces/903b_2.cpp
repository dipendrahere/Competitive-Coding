#include<bits/stdc++.h>
using namespace std;
int main(){
	int h1,a1,c1,h2,a2;
	cin>>h1>>a1>>c1>>h2>>a2;
	int minwar = h2/a1;
	if(h2 % a1 != 0){
		minwar++;
	}
	int h=0;
	while((minwar-1)*a2 >= h1){
		minwar++;
		h1+=c1;
		h++;
	}
	cout<<minwar<<endl;
	while(h--){
		cout<<"HEAL\n";
		minwar--;
	}
	while(minwar--){
		cout<<"STRIKE\n";
	}
}
