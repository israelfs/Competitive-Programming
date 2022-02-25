#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <climits>
/*#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <queue>
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

struct ed{
    int to, f, c;
}ed[N];
vi adj[N];
int cur = 0, tempo, seen[N];
void add_ed(int a, int b, int cp, int rc){ // rc = capacity of reverse edge (0 if normal graph)
    ed[cur].to = b, ed[cur].f = 0, ed[cur].c = cp;
    adj[a].pb(cur++);
    ed[cur].to = a, ed[cur].f = 0, ed[cur].c = rc;
    adj[b].pb(cur++);
}
int dfs(int s, int t, int f){
    if(s == t) return f;
    seen[s] = tempo;
    for(int e : adj[s]){
        if(seen[ed[e].to] < tempo and ed[e].c - ed[e].f > 0){
            if(int a = dfs(ed[e].to, t, min(f, ed[e].c - ed[e].f))){
                ed[e].f += a;
                ed[e ^ 1].f -= a;
                return a;
            }
        }
    }
    return 0;
}
int ford_fulkerson(int s, int t){
    int flow = 0;
    tempo = 1;
    while(int a = dfs(s, t, INT_MAX)){
        flow += a;
        tempo++;
    }
    return flow;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char a, b; int c;
        cin >> a >> b >> c;
        add_ed(a - 'A', b - 'A', c, 0);
    }
    cout << ford_fulkerson(0, 25) << "\n";
    return 0;
} 
