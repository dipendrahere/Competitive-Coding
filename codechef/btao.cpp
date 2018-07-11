#include<bits/stdc++.h>
using namespace std;
int fu(vector<int> v){
	int n=v.size();
	int ans = 0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(v[j]>v[i]){
					ans++;
				}
			}
		}
		return ans;
}
int main(){
	int t;
	cin>>t;while(t--){
	string s;
	cin>>s;
		int n = s.size();
		vector<int> v;
		for(int i=0; i<s.size(); i++){
			v.push_back(s[i]-'a');
		}
		int by,which;
		int mn = fu(v);
		for(int i=0;i<n;i++){
			for(int j=0;j<26;j++){
				int x = v[i];
				v[i] = j;
				int y = fu(v);
				if(mn >abs(x-v[i])+y){
					mn = abs(x-v[i])+y;
					by = j;
					which = i;
				}
				v[i] = x;
			}
		}
		//cout<<which<<" "<<by<<endl;
		cout<<mn<<endl;
	}
}
