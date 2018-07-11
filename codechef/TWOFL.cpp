#include<bits/stdc++.h>
using namespace std;
int a[2001][2001];
int dp[2001][2001];
void rec(int i, int j, int c, int p){
	if(i < 0 || j < 0 || i>= n || j>=m)return;
	if(dp[i][j] != 0){
		return;
	}
	if(a[i][j] == p){
		dp[i][j] = c;
	}
	rec(i+1, j, c, p);
	rec(i-1, j, c, p);
	rec(i, j-1, c, p);
	rec(i, j+1, c, p);
}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int c = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			if(dp[i][j] == 0){
				rec(i, j, c++, a[i][j]);
			}
		}
	}
	
	return 0;
}