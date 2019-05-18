#include<bits/stdc++.h>
using namespace std;
#define pb push_back
inline bool see(int i, int j, int p, int q, int x, int y){
	if(i == p && abs(j-q)==1){
		return true;
	}
	if(j==q&&abs(i-p)==1){
		return true;
	}
	if(abs(i-p) == abs(j-q) && abs(i-p)==1){
		return true;
	}
	if(i == p || j == q || abs(i-p) == abs(j-q)){
		int a = (y-j)*(p-x)*(p-i);
		int b = (q-y)*(x-i)*(p-i);
		int c = (q-j)*(p-x)*(x-i);
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if(a==b && b==c){
			return false;
		}
		else{
			return true;
		}
	}else{
		return false;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long ans = 0;
		int n, m, x, y;
		cin>>n>>m>>x>>y;
		for(int i = 1; i <=n;i++){
			for(int j=1;j<=m;j++){
				if(i==x&&j==y)continue;
				for(int p=1;p<=n;p++){
					for(int q=1;q<=m;q++){
						if(i==p&&q==j)continue;
						if((i == x && j == y)||(p==x &&q==y)){
							continue;
						}
					//	cout<<see(1, 1, 3, 3, 2, 2)<<"fgf"<<endl;
						if(!see(i, j, p, q, x, y)){
						//	cout<<i<<" "<<j<<" | "<<p<<" "<<q<<endl;
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
