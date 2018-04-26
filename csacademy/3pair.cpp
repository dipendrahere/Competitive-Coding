#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+2];
    int o=0;
    int t=0;
    int th=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%3 == 1){
            o++;
        }
        else if(a[i]%3==2){
            t++;
        }
        else{
            th++;;
        }
    }
    long long int ans = 0;
    for(int i=0;i<n;i++){
      if(a[i]%3 == 0){
          ans += (th-1);
      } 
      else if(a[i]%3 == 1){
          ans+=(t);
      }
      else{
          ans+=o;
      }
    }
    cout<<ans/2<<endl;
}
