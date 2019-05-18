#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
int main(){
	int n, qt, k;
	cin>>n>>qt>>k;
	int a[n+2];
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	map<int, int> ans;
	deque<int> q;
	int str = 0;
	int stt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			str++;
		}
		if(a[i] == 0 && str!=0){
			q.pb(str);
			ans[str]++;
			str = 0;
		}
		if(a[i] == 0){
			stt++;
		}
		if(a[i] == 1 && stt!=0){
			q.pb(-1*stt);
			ans[-1*stt]++;
			stt = 0;
		}
	}
	if(str!=0){
		q.pb(str);
		ans[str]++;
		str = 0;
	}
	if(stt!=0){
		q.pb(-1*stt);
		ans[-1*stt]++;
		stt = 0;
	}
	string qr;
	cin>>qr;
	for(auto i: qr){
		if(i == '?'){
			int pr = 0;
			auto hh = ans.lower_bound(k);
			if(hh == ans.end()){
				pr = (ans.rbegin()->first);
			}
			else if(hh->first >= k){
				pr = k;
			}
			if(pr <= 0){
				cout<<0<<endl;
			}
			else
			cout<<pr<<endl;
		}
		else{
			int y = q.back();
			if(y > 0){
				y--;
				ans[q.back()]--; if(ans[q.back()]==0){ans.erase(ans.find(q.back()));}
				q.pop_back();
				if(y!=0){
					q.push_back(y);
					ans[y]++;
				}
				if(!q.empty() && q.front() > 0){
					int yu = q.front();
					yu++;
					int bb = q.front(); ans[bb]--; if(ans[bb]==0){ans.erase(ans.find(bb));}
					q.pop_front();
					ans[yu]++;
					q.push_front(yu);
				}
				else{
					q.push_front(1);
					ans[1]++;
				}
			}
			else{
				y++;
				int bb = q.back(); ans[bb]--; if(ans[bb]==0){ans.erase(ans.find(bb));}
				q.pop_back();
				if(y!=0){
					ans[y]++;
					q.push_back(y);
				}
				if(!q.empty() && q.front() < 0){
					int yu = q.front();
					yu--;
					int bb = q.front(); ans[bb]--; if(ans[bb]==0){ans.erase(ans.find(bb));}
					q.pop_front();
					ans[yu]++;
					q.push_front(yu);
				}
				else{
					ans[-1]++;
					q.push_front(-1);
				}
			}
		}
	}
}
