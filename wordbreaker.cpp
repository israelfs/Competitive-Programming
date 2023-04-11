#include <bits/stdc++.h>

using namespace std;

struct node{
    bool leaf; // Is Terminal
    node* child[26];
};

node* create(){
    node *ret = new node();
    for(int i = 0; i < 26; i++) ret->child[i] = NULL;
    ret->leaf = false;
    return ret;
}

node* root = create();

void add(string s){
    node *ex=root;
    for(int i = 0; i < (int)s.size(); i++){
        if(root->child[s[i] - 'a'] == NULL){
            root->child[s[i] - 'a'] = create();
        }
        root = root->child[s[i] - 'a'];
    }
    root->leaf = true;
    root = ex;
}

bool search(string s){
    node *ex = root;
    
    for(int i = 0; i < (int)s.size(); i++){
        if(root->child[s[i] - 'a'] == NULL){
            return false;
        }
        root = root->child[s[i] - 'a'];
    }
    bool ans = (root != NULL and root->leaf);
    root = ex;
    return ans;
}

bool solve(string s){
    if((int)s.size())
        return true;
    for(int i = 1; i <= (int)s.size(); i++){
        if(search(s.substr(0, i)) and solve(s.substr(i, (int)s.size() - i)))
            return true;
    }
    return false;
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        add(t);
    }
    
    cout << (solve(s) ? "true" : "false") << "\n";

    return 0;
}
