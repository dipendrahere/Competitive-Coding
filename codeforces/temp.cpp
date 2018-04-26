#include<bits/stdc++.h>
using namespace std;
void change(multiset<long> s[], int x, int y, int l, int r){
    for(int i = x-1; i < y; i++){
        s[i].insert(l);
        s[i].insert(r);
    }
}
void check(multiset<long> s[], int x, int y){
    multiset<long>::iterator xi = s[x].begin();
    multiset<long>::iterator yi = s[y].begin();
    while(xi != s[x].end() && yi != s[y].end()){
        int xc = *xi, yc = *yi;
        if(xc != yc){
            cout<<"NO\n";
            return;
        }
        else{
            int cx=0;
            int cy=0;
            while(*xi == xc && xi!=s[x].end()){
                xi++;
                cx++;
            }
            while(*yi == yc && yi!=s[y].end()){
                yi++;
                cy++;
            }
            if(cx != cy){
                cout<<"NO\n";
                return;
            }
        }
    }
    if(xi != s[x].end() || yi != s[y].end()){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        multiset<long> s[n+10];
        while(q--){
            int ch;
            scanf("%d", &ch);
            if(ch == 1){
                int x, y, l, r;
                scanf("%d", &x);
                scanf("%d", &y);
                scanf("%d", &l);
                scanf("%d", &r);
                change(s, x-1, y-1, l, r);
            }
            else{
                int x,y;
                check(s, x, y);
            }
        }
    }
}
