#include<bits/stdc++.h>
using namespace std;
int n, m;
bool check(int i, int j){
	if(i >= 0 && j >= 0 && i < n && j < m)return true;
	return false;
}
int main(){
	
	cin>>n>>m;
	string a[n];
	for(int i= 0;i<n;i++){
		cin>>a[i];
	}
	if(n == 1 && m == 1){
		if(a[0][0] == '*'){
			cout<<"YES\n";
			return 0;
		}
	}
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			if(a[i][j] != '*'){
				int count = 0;
				if(check(i-1, j-1) && a[i-1][j-1] == '*'){
					count++;
				}
				if(check(i-1, j) &&a[i-1][j] == '*'){
					count++;
				}
				if(check(i-1, j+1) &&a[i-1][j+1] == '*'){
					count++;
				}
				if(check(i, j-1) &&a[i][j-1] == '*'){
					count++;
				}
				if(check(i, j+1) &&a[i][j+1] == '*'){
					count++;
				}
				if(check(i+1, j-1) &&a[i+1][j-1] == '*'){
					count++;
				}
				if(check(i+1, j) &&a[i+1][j] == '*'){
					count++;
				}
				if(check(i+1, j+1) &&a[i+1][j+1] == '*'){
					count++;
				}
				if(a[i][j] == '.' && count != 0){
					cout<<"NO\n";return 0;
				}
				if(a[i][j]!='.' && count!=a[i][j]-'0'){
						cout<<"NO\n";return 0;
				} 
			}
		}
	}
	cout<<"YES\n";
}
