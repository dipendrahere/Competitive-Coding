#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i = a ; i <= 2*a; i++){
		for(int j = b; j <= min(2*b, i-1); j++){
			for(int k = c; k <= min(j-1, min(2*b, 2*c));k++){
				if(d <= i && d <= j && d <= k && k <= 2*d && j > 2*d && i > 2*d){
					cout<<i<<endl<<j<<endl<<k<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"-1\n";return 0;
}
