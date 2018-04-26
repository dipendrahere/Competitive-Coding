#include<bits/stdc++.h>
using namespace std;
bool fil(string s){
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == s[i+1]){
            return false;
        }
    }
    return true;
}
string filter(string s){
    string u="";
    for(int i=0;i<s.size()-1;){
        if(s[i] == s[i+1]){
            while(s[i] == s[i+1]){
                i++;
            }
        }
        else{
            u+=s[i];
            i++;
        }
    }
    if(s[s.size()-1] == u[u.size()-1]){
        return u;
    }
    else{
        return u+s[s.size()-1];
    }
    return u;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        while(fil(s) != true){
            s = filter(s);
            cout<<s<<endl;
        }
        
    }
}
