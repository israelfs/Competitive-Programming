#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
/*#include <stack>
#include <set>
#include <map>
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
//const int N = 2e5 + 5;

const int N = 1e2 + 5;
vi adj[N];
int capacity[N][N], flowpassed[N][N], parent[N], pathcap[N], n;
int bfs(int s, int t){
    memset(parent, -1, sizeof(parent));
    memset(pathcap, 0, sizeof(pathcap));
    queue<int> q;
    q.push(s);
    parent[s] = -2;
    pathcap[s] = mod;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto i:adj[now]){
            if(parent[i] == -1 and capacity[now][i] > flowpassed[now][i]){
                parent[i] = now;
                pathcap[i] = min(pathcap[now], capacity[now][i] - flowpassed[now][i]);
                if(i == t){
                    return pathcap[t];
                }
                q.push(i);
            }
        }
    }
    return 0;
}
int maxflow(int s, int t) {
    int maxflow = 0;
    while(true){
        int flow = bfs(s, t);
        if(flow == 0) break;
        maxflow += flow;
        int now = t;
        while(now != s){
            int prev = parent[now];
            flowpassed[prev][now] += flow;
            flowpassed[now][prev] -= flow;
            now = prev;
        }
    }
    return maxflow;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cc = 1;
    while(cin >> n and n){
        memset(capacity, 0, sizeof(capacity));
        memset(flowpassed, 0, sizeof(flowpassed));
        int s, t, c;
        cin >> s >> t >> c;
        while(c--){
            int x, y, w;
            cin >> x >> y >> w;
            capacity[x][y] += w;
            capacity[y][x] += w;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        cout << "Network " << cc << "\nThe bandwidth is " << maxflow(s, t) << ".\n\n";
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        cc++;
    }
    return 0;
}