#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		
		string s;
		int k;
		cin>>s;
		cin>>k;
		int c[7000][26] = {0};
		int x = 1;
		for(auto i : s){
			for(int k=0;k<26;k++){
				c[x][k] = c[x-1][k];
			}
			c[x++][i-'a']++;
		}
		int ans = 0;
		for(int i = 0; i < s.size(); i++){
			int ck = 0;
			int mx = INT_MIN;
			int cnt[26] = {0};
			for(int j=i; j >= 0;j--){
				if(++cnt[s[j]-'a']== 1)
					ck++;
				mx = max(mx, cnt[s[j]-'a']);
				if(ck >= k && mx*ck-1 == i-j){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
