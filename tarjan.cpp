#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstring>
 

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
const int N = 4e5 + 5; 

int n, m, foundat = 1, disc[N], low[N];
vi adj[N];
int comp = 0;
bool onstack[N];
vector<vi> scc;

void tarjan(int u){
    static stack<int> st;
    disc[u] = low[u] = foundat++;
    st.push(u);
    onstack[u] = true;
    
    for(auto i:adj[u]){
        if(disc[i] == -1){
            tarjan(i);
            low[u] = min(low[u], low[i]);
        }
        else if(onstack[i])
            low[u] = min(low[u], disc[i]);
    }
    
    if(disc[u] == low[u]){
        vi scctem;
        while(true){
            int v = st.top();
            st.pop();
            onstack[v] = false;
            scctem.pb(v);
            if(u == v)
                break;
        }
        comp++;
        //scc.pb(scctem);
    }
}
int deg[N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        deg[u]++, deg[v]++;
        adj[u].pb(v);
    }
    memset(disc, -1, sizeof(disc));
    int aux = 0;
    for(int i = 1; i <= n; i++){
        aux += (deg[i] == 0);
        if(disc[i] == -1)
            tarjan(i);
    }
    
    cout << 2*n - comp - aux << "\n";
    return 0;
}