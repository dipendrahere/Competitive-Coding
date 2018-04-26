#include<bits/stdc++.h>
using namespace std;
struct node{
    int c;
    struct node* arr[26];
};

void print(struct node* root){
    for(int i=0;i<26;i++){
        if(root==NULL){
            cout<<"root is NULL";
            return;
        }
        if(root->arr[i] == NULL){
            continue;
        }
        else{
            char ch = i;
            cout<<ch<<" "<<root->arr[i]->c;
        }
    }
}
struct node* ass(){
    struct node* x= (struct node *)malloc(sizeof(struct node));
    for(int i=0;i<26;i++){
        x->arr[i] = NULL;
    }
    x->c = 0;
    return x;
}
void add(struct node* root, string op){
    if(op == ""){
        return;
    }
    if(root->arr[op[0]-'a'] == NULL){
        root->arr[op[0]-'a'] = ass(); 
    }
    (root->arr[op[0]-'a']->c)++;
    int ch = op[0]-'a';
    op.erase(0,1);
    add(root->arr[ch], op);
}
int count(struct node* root, string op, int ans){
    if(op == ""){
        return ans;
    }
    else if(root == NULL){
        return 0;
    }
    else if(root->arr[op[0]-'a'] == NULL){
        return 0;
    }
    else{
        char k = op[0]-'a';
        op.erase(0,1);
        return count(root->arr[k], op, root->arr[k]->c);
    }
}
int main() {
    struct node* root= ass();
    root->c = 0;
   
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string op;
        string s;
        cin>>op;
        cin>>s;
        if(op =="add"){
            add(root, s);
        }
        else {
            cout<<count(root, s, 0)<<endl;
        }
        
        
    }
    return 0;
}
