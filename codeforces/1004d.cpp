#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin>>n;
	int x;
	map<int, int> mp;
	int mx = -10;
	for(int i=0;i<n;i++){
		cin>>x;
		mx = max(mx, x);
		mp[x]++;
	}
	int sub = 0;
	int st = 4;
	int y=-1;
	x = -1;
	if(mp[0] == 2){
		x = 0;
		y = 0;
	}
	else if(mp[0] == 3){
		x = 1;
		y = 0;
	}
	else{
		for(auto i: mp){
			if(i.first == 0)continue;
			if(i.second != st && x == -1){
				x = i.first-1;
				break;
			}
			st = st+4;
		}
		st = 4;
		for(auto i:mp){
			if(i.first == 0)continue;
			if(i.first == x+1){
				sub = 1;
			}
			else if(i.first > x+1){
				sub = 2;
			}
			if(i.second != st-sub){
				y = i.first-1;
				break;
			}
			st = st+4;
		}
	}
	cout<<x<<" "<<y<<endl;
	ll sum = x+y+mx+2;
	ll pro = n;
	ll diff = (sum*sum) - 4*pro;
	diff = sqrtl(diff);
	int a = (sum+diff)/2;
	int b = abs(sum-diff)/2;
	if(x < y){
		int temp = x;
		x = y;
		y = temp;
	}
	if(a < b){
		int temp = a;
		a = b;
		b = temp;
	}
	cout<<a<<" "<<b<<endl;
	cout<<x+1<<" "<<y+1<<endl;
}
