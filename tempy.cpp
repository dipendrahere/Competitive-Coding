#include<bits/stdc++.h>
using namespace std;
 bool rec(int i, vector<int> given , int k, int ch, int ay, vector<int> &v){
        int gh= given.size();
        if(k < 0)return false;
        if(i > gh){
            return false;
        }
        cout<<"aya: ";
        for(auto it : v){
            cout<<it<< " ";
        }
        cout<<endl;
        cout<<"i  = "<<i<<" | k = "<<k<<" | ch = "<<ch<<" | ay = "<<ay<<endl;
        if(i == gh && k== 0){
            return (ay == ch);
        }
        if(k == 0){
            return (ay == ch);
        }
        if(v.size() == 0){
            v.push_back(given[i]);
            bool y = true;
            y = rec(i+1, given, k-1, ch, ay|given[i], v);
            v.pop_back();
            return y;
        }
        else{
            for(int j : v){
                if(j & given[i]){
                    cout<<"and failed at "<<i<<" by "<<j<<" & "<<given[i]<<endl;
                    return rec(i+1, given, k, ch, ay, v);
                }
            }
            bool ans = rec(i+1, given, k, ch, ay, v);
            if(ans == true){
                return true;
            }
            else{
                v.push_back(given[i]);
                bool t = rec(i+1, given, k-1, ch, ay|given[i], v);
                v.pop_back();
                return t;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=0;
        for(auto i : nums){
            s+=i;
        }
        if(s%k != 0){
            return false;
        }
        int req = s/k;
        vector<int> given;
        int n = nums.size();
        int vl = 1<<n;
        vl--;
        cout<<"req "<<req<<endl;
        for(int i = 1; i <= vl; i++){
            int sum = 0;
            for(int j = 1, c = 0; j <= i; j = j*2, c++){
                if((i & j) != 0){
                    //cout<<"mila "<<c<<" "<<nums[c]<<endl;
                    sum+=nums[c];
                }
            }
            if(sum == req){
                //cout<<i<<" "<<sum<<endl;
                given.push_back(i);
            }
        }
        vector<int> v;
        if(given.size() == 0){
            return false;
        }
        for(auto i : given)
        {cout<<i<<" ";
        }
        cout<<endl;
        return rec(0, given, k, vl, 0, v);
        return true;
    }
    int main(){
        int n;
        cin>>n;
        vector<int>a;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            a.push_back(t);
        }
        int k;
        cin>>k;
        cout<<canPartitionKSubsets(a, k)<<endl;
    }
