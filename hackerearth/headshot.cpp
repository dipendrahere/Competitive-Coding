#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll dp[1000003];
ll rec(ll n){
    //cout<<n<<endl;
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    ll ans = 0;
    if(n%2==1)ans++;
    ll st = n%2 == 1 ? n-2 : n-1;
    for(ll i = st; i >= 1; i-=2){
        ans = (ans%mod + (rec(n-i)%mod))%mod;
    }
    dp[n] = ans;
    return ans;
}
int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<1000002;i++)dp[i]=-1;
    cout<<rec(n)<<endl;
    return 1;
}
