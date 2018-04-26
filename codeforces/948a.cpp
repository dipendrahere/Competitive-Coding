#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char a[n+2][m+2];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j] == 'S'){
				if(i > 0 && a[i-1][j] == '.'){
					a[i-1][j]='D';
				}
				else if(i > 0 && a[i-1][j] == 'W'){
					cout<<"No\n";
					return 0;
				}
				if(i < n-1 && a[i+1][j] == '.'){
					a[i+1][j]='D';
				}
				else if(i < n-1 && a[i+1][j] == 'W'){
					cout<<"No\n";
					return 0;
				}
				if(j < m-1 && a[i][j+1] == '.'){
					a[i][j+1]='D';
				}
				else if(j < m-1 && a[i][j+1] == 'W'){
					cout<<"No\n";
					return 0;
				}
				if(j > 0 && a[i][j-1] == '.'){
					a[i][j-1]='D';
				}
				else if(j > 0 && a[i][j-1] == 'W'){
					cout<<"No\n";
					return 0;
				}
			}
		}
	}
	cout<<"Yes\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
