#include<bits/stdc++.h>
using namespace std;
bool all(int a[3],int y){
	if(a[0]==a[1] && a[1]==a[2] && a[2]==a[0] &&a[0] == y){
		return false;
	}return true;
}
int main(int argc, char const *argv[])
{
	int x,y;
	cin>>x>>y;
	int a[3]={x,x,x};
	string answ;
	int count = 0;
	int ans = INT_MAX;
	for(int i=y;i<=x;i++){count=0;
		a[0] = i;a[1]=x;a[2]=x;
		string temp="";
	while(all(a,y)){
		count++;
		sort(a, a+3);
		int v = a[1]+1-a[0];
		if(v<y){			
			a[2] = y;
			//continue;
		}
		else{
		a[2] = a[1]+1-a[0];
	}
		temp+=to_string(a[0])+" "+to_string(a[1])+" "+to_string(a[2])+"\n";
		//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	}
	if(all(a,y) == true){

	}	
	if(count < ans){ans=count;answ = temp;}
}
cout<<endl;
	cout<<answ<<endl;
	;
	cout<<ans+1<<endl;
	return 0;
}
