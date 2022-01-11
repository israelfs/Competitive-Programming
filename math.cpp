#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <ll, int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const int N = 2000005;

int add(int a, int b){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int mul(int a, int b){
	return 1ll * a * b % mod;
}

int pwr(int a, int b){
	int r = 1;
	for(; b; b>>=1, a = mul(a,a))
		if(b&1)
			r = mul(r, a);
	return r;
}

int fact[N], ifact[N];

void init(){
	fact[0] = 1;
	for(int i = 1; i < N; i++)
		fact[i] = mul(i, fact[i-1]);
	ifact[N-1] = pwr(fact[N-1], mod-2);
	for(int i = N-2; i >= 0; i--)
		ifact[i] = mul(ifact[i+1], i+1);
}

int ncr(int n, int r){
	if(n < r) return 0;
	return mul(fact[n], mul(ifact[r], ifact[n-r]));
}

void solve(){
	init();
	
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
