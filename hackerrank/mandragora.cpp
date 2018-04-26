#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        long long s[n+2];
        s[0]  = v[0];
        for(int i=1;i<n;i++){
            s[i] = s[i-1]+v[i];
        }
        long long max = s[n-1];
        int mul = 2;
        for(int i=0;i<n;i++){
            if(max < mul*(s[n-1]-s[i])){
                max = mul*(s[n-1]-s[i]);
            }
            mul++;
        }
        
        cout<<max<<endl;
    }
    return 0;
}
