#include<bits/stdc++.h>
using namespace std;
 map<string, int> m;
 bool func(set<string> a, set<string> b){
     int sca =0 ;
     int scb = 0;
     for(auto i : a){
         if(m[i] == 1){
             sca++;
         }
     }
     for(auto i:b){
         if(m[i] == 1){
             scb++;
         }
     }
     return sca > scb;
 }

 void print(set<string> v[],int n){
    for(int i=0;i<n;i++){
        for(auto o:v[i]){
            cout<<o<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
 }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       m.clear();
        set<string> v[n+10];
        for(int j=0;j<n;j++){
            int r;
            cin>>r;
            for(int i=0;i<r;i++){
                string temp;
                cin>>temp;
                m[temp] =1;
                v[j].insert(temp);
            }
        }
        if(m.size() < k){
            cout<<"-1\n";
            continue;
        }
        int count = 0;
        int ans = 0;
        while(count < k){
            sort(v, v+n,func);
            ///print(v,n);
            set<string> tw = v[0];
            int sc=0;
            for(auto i : tw){
            if(m[i] == 1){
                 sc++;
            }
            }
            for(auto i:tw){
                m[i]=0;
            }
            count+=sc;
            ans++;
        }
        cout<<ans<<endl;
    }
}
