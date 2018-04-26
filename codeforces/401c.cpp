#include<bits/stdc++.h>
using namespace std;

void print(string a,int n, int m){
	char i;int o,z;
	z=0;
	o=0;
	for(int r=0;r<a.size();r++){
		i=a[r];
		if(i=='-')continue;
		if(i =='0' && z<n){
		//	cout<<i<<" z="<<z<<endl;
			cout<<i;
			z++;
			continue;
		}
		if(i == '1' && o<m){
		//	cout<<i<<" o="<<o<<endl;
			cout<<i;
			o++;
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	char a[m*2+5];
	if(n>m+1){
		cout<<"-1\n";return 0;
	}
	int con;
	con = m/2;
	if(!(m%2))
		con--;
	if(n < con){
		cout<<"-1\n";return 0;
	}
	int lst;
	for(int i=0;i<m*2+5;i++)
		a[i]= '-';
	for(int i=1,c=0;c<m;c++,i+=2){
		a[i] = '1';
		lst = i;
	}
	int cnt = 0;
	int r=0;
	for(int i=0,c=0;c<m;i++){
		if(a[i] == '1'){
			c++;
			cnt++;
			continue;
		}
		if(cnt == 2){
			a[i]='0';
			cnt=0;
			r++;
			if(r == n){
				break;
			}
		}
	}
	if(r<n)
	for(int i=0;i<m*2+5;i++){
		if(a[i]=='-'){
			a[i]='0';
			r++;
			if(r == n){
				break;
			}
		}
	}
	if(r!=n){
		cout<<"-1\n";return 0;
	}
	print(a,n,m);
	cout<<endl;
}
