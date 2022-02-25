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
const int N = 2e5 + 5;
int getSize(long num){
    int count = 0;
    while (num > 0){
        count++;
        num /= 10;
    }
    return count;
}
long karatsuba(long X, long Y){
    if (X < 10 && Y < 10) return X * Y;
    int size = fmax(getSize(X), getSize(Y));
    int n = (int)ceil(size / 2.0);
    long p = (long)pow(10, n);
    long a = (long)floor(X / (double)p);
    long b = X % p;
    long c = (long)floor(Y / (double)p);
    long d = Y % p;
    long ac = karatsuba(a, c);
    long bd = karatsuba(b, d);
    long e = karatsuba(a + b, c + d) - ac - bd;
    return (long)(pow(10 * 1L, 2 * n) * ac + pow(10 * 1L, n) * e + bd);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}