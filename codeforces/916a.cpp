#include<bits/stdc++.h>
using namespace std;
bool ha(int hh, int mm){
	string s = to_string(hh)+to_string(mm);
	for(auto i : s){
		if(i == '7'){
			return true;
		}
	}
	return false;
}
void changes(int &hh, int &mm, int x){
	if(mm >= x){
		mm = mm -x;
		return;
	}
	else{
		mm = mm + 60 - x;
		hh = hh - 1;
		if(hh < 0){
			hh+=24;
		}
	}
	return;
}
int main(){
	int x;
	cin>>x;
	int hh,mm;
	cin>>hh>>mm;
	for(int i = 0; i < INT_MAX;i++){
		if(ha(hh,mm)){
			cout<<i<<endl;
			break;
		}
		changes(hh,mm,x);
	}
	//cout<<hh<<mm<<endl;
}
