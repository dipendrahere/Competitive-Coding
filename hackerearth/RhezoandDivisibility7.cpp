#include<bits/stdc++.h>
using namespace std;
long long power(long long x, unsigned long long y, long long p)
{
    long long res = 1; 
    x = x % p;
    while (y > 0)
    {
        
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    long long n = s.size();
    long long a[n+2];
    long long c = 0;
    for(auto i : s){
        a[c++]=i-'0';
    }
    
    long long mod[n+2];
    mod [n-1] = a[n-1]%7;
    for(long long i = n-2; i >=0 ;i--){
        long long v = (mod[i+1] + ((a[i]%7)*(power(10, n-1-i, 7)))%7)%7;
        mod[i] = v;
    }
    
    long long q;
    cin>>q;
    while(q--){
        long long x,y;
        cin>>x>>y;
        if(y == n){
            if(mod[x-1]==0)cout<<"YES\n";else cout<<"NO\n";
            continue;
        }
        x=x-1;
        y=y-1;
        long long v = mod[x] - mod[y+1];
        if(v < 0){
            v = v+7;
        }
        long long d = power(10, 5*(n-1-y), 7);
        if((v*d)%7==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}