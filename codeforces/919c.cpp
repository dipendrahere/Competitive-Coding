#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int mat[n+2][m+2];
	for(int i =0; i < n;i++){
		for(int j=0;j<m;j++){
			char t;
			scanf(" %c",&t);
			if(t=='*'){
				mat[i][j]=1;
			}
			else{
				mat[i][j]=0;
			}
		}
	}
	vector<int> v;
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j] == 0){
				l++;
			}
			else{
				if(l >= k){
					v.push_back(l);
				}
				l=0;
			}
		}
		if(l >= k){
			v.push_back(l);
		}
		l=0;
	}
	l=0;
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(mat[i][j] == 0){
				l++;
			}
			else{
				if(l >= k){
					v.push_back(l);
				}
				l=0;
			}
		}
		if(l >= k){
			v.push_back(l);
		}
		l=0;
	}
	if(k == 1){
		int ans = 0;
		for(int i =0;i<v.size();i++){
			ans+=v[i];
		}
		cout<<ans/2<<endl;
		return 0;
	}
	int ans = 0;
	for(int i =0;i<v.size();i++){
			ans+=(v[i]-k+1);
		}
	printf("%d\n",ans);
}
