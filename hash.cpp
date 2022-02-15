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
int mul(int a, int b){
    return 1ll * a * b % mod;
}
int add(int a, int b){
    a += b;
    if(a >= mod) a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0) a += mod;
    return a;
}

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int b = uniform_int_distribution<int>(0, mod-1)(rng);
struct hash_str{
    vi h, p;
    hash_str(string s) : h(sz(s)) , p(sz(s)) {
        int n = sz(s);
        h[0] = s[0];
        for(int i = 1; i < n; i++){
            h[i] = add(mul(h[i-1], b), s[i]);
        }

        p[0] = 1;
        for(int i = 1; i < n; i++){
            p[i] = mul(p[i-1], b);
        }
    }
    int get_hash(int l, int r){
        if(l == 0)
            return h[r];
        return sub(h[r], mul(h[l-1], p[r-l+1]));
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        string pat, s;
        cin >> pat >> s;

        hash_str hp(pat), hs(s);

        int n = sz(s), m = sz(pat);
        for(int i = 0; i < n - m + 1; i++){
            if(hp.get_hash(0, m-1) == hs.get_hash(i, i + m - 1)){
                cout << i << "\n";
            }
        }

        cout << "\n";


    }
    return 0;
}
