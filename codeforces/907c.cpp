#include<bits/stdc++.h>
using namespace std;

void print(int a[30]){
	cout<<endl;
	for(int i=0;i<30;i++){
		cout<<(char)('a'+i)<<" "<<a[i]<<", ";
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int flag = 0;

	int ans = 0;
	int count[30]={0};
	string abhitk = "";
	int cy[30]={0};
	while(n--){

		char c;
		string a;
		cin>>c;
		cin>>a;
		
		if(flag == 1){
			if(c == '!'){
				ans++;
			}
			if(c == '?' && n!=0){
				ans++;
			}
			continue;
		}
		if(c == '!'){
			if(abhitk == ""){
				for(auto i : a){
					count[i-'a']= 1;
				}
				abhitk = a;
			}
			else{
				string mark="";
				memset(cy, 0, sizeof(cy));
				for(auto pp:abhitk){
					cy[pp-'a']=1;
				}
				for(auto rr:a){
					if(cy[rr-'a'] == 1){
						cy[rr-'a']=2;
					}
				}
				memset(count, 0, sizeof(count));
				for(int i =0 ; i< 30;i++){
					if(cy[i] == 2){
						abhitk.clear();
						abhitk.push_back('a'+i);
					//	cout<<"abhitk : "<<abhitk<<endl;
						count[i] = 1;
						cy[i] = 1;
					}
				}
			}
		}
		if(c == '.'){
			for(auto i : a){
				count[i-'a']=0;
				cy[i-'a']=0;
			}
		}
		if(c == '?'){
			if(n != 0){
				count[a[0]-'a']= 0;
				cy[a[0]-'a'] = 0;
			}
		}
		int cou = 0;
		for(int i = 0 ;i < 30;i++){
			if(count[i] == 1){
				cou++;
			}
		}
		int coul = 0;
		for(int i = 0 ;i < 30;i++){
			if(cy[i] == 1){
				coul++;
			}
		}
		if(cou == 1 || coul == 1){
			flag = 1;
		}
	//	print(count);
		//cout<<" n: "<<n;;
	}
	cout<<ans<<endl;
}
