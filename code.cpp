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

int main(){
    string s;
    cin >> s;
    vector<string> dict;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        add(t);
    }

    bool ans = false;
    node *ex = root;
    for(int i = 0; i < s.size(); i++){
        root = root->child[s[i] - 'a'];
        if(root == NULL) break;
        // cout << s[i] << " " << root->leaf << "\n";
        if(root->leaf){
            root = ex;
            if(i == s.size() - 1)
                ans = true;
        }
    }
    cout << (ans ? "True" : "False") << "\n";

    return 0;
}