#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



int n, m, k;
int l[16], r[16], a[16];
int g[16];
ll dp[(1 << 15) + 5];



void solve(int iteras) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> a[i];
    }
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x] |= (1 << y);
        g[y] |= (1 << x);
    }
    memset(dp, 0, sizeof(dp));
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == 1) {
            dp[mask] = 1;
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                if (sum >= l[i] && sum <= r[i]) {
                    if (g[i] & mask) {
                        dp[mask | (1 << i)] += dp[mask];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }
        if (sum == k) {
            ans += dp[mask];
        }
    }
    cout << "Case #" << iteras << ": ";
    cout << ans;
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    int it = 0;
    while (t--) {
        it++;
        solve(it);
    }
    return 0;
}
