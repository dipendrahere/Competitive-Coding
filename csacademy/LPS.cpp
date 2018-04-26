
#include<bits/stdc++.h>
using namespace std;

int longestParenthesisedSubstring(const string& S) {
    vector<int> v;
    v.push_back(-2);
    v.push_back(-2);
    for(int i=0;i<S.size();i++){
        if(S[i]=='('){
            v.push_back(-1);
        }
        else if(S[i] == ')'){
            if(v[v.size()-1]==-1 && v[v.size()-2]==-1){
                v.pop_back();
                v.push_back(2);
            }
            else if(v[v.size()-1]==-1 && v[v.size()-2]>0){
                v.pop_back();
                int p = v[v.size()-1]+2;
                v.pop_back();
                v.push_back(p);
            }
            else if(v[v.size()-1]>0 && v[v.size()-2]==-1){
                int y = v[v.size()-1];
                v.pop_back();
                v.pop_back();
                v.push_back(y+2);
            }
            else if(v[v.size()-1]==-1 && v[v.size()-2] == -2){
                v.pop_back();
                v.push_back(2);
            }
            else{
                v.push_back(-2);
            }
        }
        if(v[v.size()-1] >0 && v[v.size()-2]>0){
            int u = v[v.size()-1]+v[v.size()-2];
            v.pop_back();
            v.pop_back();
            v.push_back(u);
        }
        
        //cout<<endl;
    }
    int ans = -1;
    int vr = 0;
    for(auto i : v){
        if(i < 0){
            vr=0;
        }
        else{
            vr+= i;
            if(ans < vr){
                ans = vr;
            }
        }
    }
    return ans;
}
   
int main() {
    string S;
    cin >> S;
    cout << longestParenthesisedSubstring(S) << "\n";
    return 0;
}
