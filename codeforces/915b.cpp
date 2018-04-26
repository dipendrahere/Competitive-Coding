#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,pos,l,r;
	cin>>n>>pos>>l>>r;
	int ans;
	if(l == 1 && r == n){
		ans = 0;
		goto l;
	}
	if(l==1){
		ans = abs(r-pos)+1;
		goto l;
	}
	if(r==n){
		ans = abs(l-pos)+1;
		goto l;
	}
	if(pos <=l){
		ans = l-pos+1+r-l+1;
		goto l;
	}
	if(pos>=r){
		ans = pos-r+1+r-l+1;
		goto l;
	}
	if(pos>l && pos <r){
		ans = min(pos-l+1+r-l+1, r-pos+1+r-l+1);
		goto l;
	}
	l:
	cout<<ans<<endl;
}
