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
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        string pat, s;
        cin >> pat >> s;
        if(n > sz(s)){
            cout << "\n";
            continue;
        }
        vi pf = prefix_function(pat + "#" + s);
        reverse(all(pf));
        for(int i = 0; i < n + 1; i++)pf.pop_back();
        reverse(all(pf));
        for(int i = 0; i < sz(pf); i++){
            if(pf[i] == n){
                cout << i - n + 1 << "\n";
            }
        }
    }
    return 0;
}
