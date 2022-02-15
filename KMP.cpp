#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
/*#include <stack>
#include <queue>
#include <map>
#include <set>
 */

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define snd second
#define fst first

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef pair<ii,int> iii;
const int mod = 1e9+7;  
const ll INF = 1e18;
const int N = 2e5 + 5;
vi prefix_function(string s) {
    int n = (int)s.length();
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void KMP(string pattern, string text){
    int n = sz(text), m = sz(pattern);
    vi Lps = prefix_function(pattern);
    int i=0, j=0;
    while(i < n){
        if(pattern[j]==text[i]){i++;j++;} // If there is a match continue.

        if(j == m){ 
            cout<< i - m << "\n";    // if j==m it is confirmed that we have found the pattern and we output the index
            j = Lps[j - 1];         // and update j as Lps of last matched character.
        } 
        else if(i < n && pattern[j] != text[i]){  // If there is a mismatch
            if(j == 0)          // if j becomes 0 then simply increment the index i
                i++;
            else
                j = Lps[j - 1];  //Update j as Lps of last matched character
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        string pat, s;
        cin >> pat >> s;
        if(sz(pat) <= sz(s)){
            KMP(pat, s);
            cout << "\n";
        }
    }
    return 0;
}
