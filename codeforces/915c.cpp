#include<bits/stdc++.h>
using namespace std;
string a, b;
#define ll long long
char ans[100];
ll h[10];
ll atooll(char ans[], int i, int n){
	char ret[100];
	for(int j=0;j<=i;j++){
		ret[j]=ans[j];
	}
	for(int j=i+1;j<n;j++){
		ans[j]='0';
	}
	ans[n]='\0';
	return atoll(ans);
}
bool solve(int i){
	if(i == a.size())return true;
	
	ll bb = stoll(b);
	ans[a.size()]='\0';
	//ans[0]='9';
	//cout<<atoi(ans);
	//for(ll i=0;i<=9;i++)cout<<h[i]<<" ";
	
		for(ll j=9;j>=0;j--){
			if(h[j]>0){
				ans[i]='0'+j;
				h[j]--;
			//	cout<<atoi(ans)<<endl;;
				if(atooll(ans, i, a.size()) > bb){
					h[j]++;
					continue;
				}
				if(solve(i+1))return true;
				else{
					h[j]++;
					continue;
				}
			}
		}

	return false;
}
void prllmax(string a){
	ll i = 0;
	for(auto o : a){
		ans[i++] = o;
	}
	sort(ans, ans+a.size(), greater<char>());
	cout<<ans<<endl;
	return;
}
int main(){
	for(ll i=0;i<a.size();i++){
		ans[i]='0';
	}
	cin>>a>>b;
	if(stoll(a) == stoll(b)){
		cout<<a<<endl;
		return 0;
	}
	if(a.size() < b.size()){
		prllmax(a);
		return 0;
	}
	for(auto i : a){
		h[i-'0']++;
	}
	solve(0);
	cout<<ans<<endl;
	return 0;
}
