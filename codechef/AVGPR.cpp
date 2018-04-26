#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int temp;
		long h[3010]={0};
		for(int i= 0; i < n; i++){
			cin>>temp;
			temp+=1500;
			h[temp]++;
		}
		long count = 0;
		for(int i = 0; i < 3010; i++){
			if(h[i] <= 0){
				continue;
			}
			for(int j = i+1; j < 3010; j++){
				if((i+j)%2 == 1)continue;
				if(h[(i+j)/2] > 0){
					count+=(h[i]*h[j]);
				}
			}
			count += (h[i]*(h[i]-1)/2);
		}
		cout<<count<<endl;
	}
}
