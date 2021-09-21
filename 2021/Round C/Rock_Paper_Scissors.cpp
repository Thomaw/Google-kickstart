#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
    string res;
    if(x == 0) res.push_back('0');
    while(x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
struct P {
    D x, y;
};
int w, e;
        
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
D dp[63][63][63];
int u[63][63][63];
int main() {
    int t, x;
    scanf("%d%d", &t, &x);

    D sum = 0;

    for(int qq = 1; qq <= t; qq++) {
        scanf("%d%d", &w, &e);
/*w = v[(qq - 1) / 4] * 10;
sv += w / 10;
cout << (qq - 1) / 4 << endl;
e = qq % 4 == 1 ? w : qq % 4 == 2 ? w/  2 : qq % 4 == 3 ? w / 10 : 0;*/
        int c[3];
        for(int sum = 60; sum >= 0; sum--) {
        for(c[0] = 0; c[0] <= sum; c[0]++) {
        for(c[1] = 0; c[0] + c[1] <= sum; c[1]++) {
            c[2] = sum - c[0] - c[1];
            if(sum == 60) {
                dp[c[0]][c[1]][c[2]] = 0;
                continue;
            }
            if(sum == 0) {
                dp[0][0][0] = dp[1][0][0] + w / 3. + e / 3.;
                u[0][0][0] = 0;
                continue;
            }
            D mx = -1;
            int mxd = -1;
            for(int d = 0; d < 3; d++) {
                D tmp = 0;
                for(int f = 0; f < 3; f++) {
                    if((d + 1) % 3 == f) {
                        tmp += (c[(f + 1) % 3]) / (D)sum * w;
                    }else if(d == f) {
                        tmp += (c[(f + 1) % 3]) / (D)sum * e;
                    }
                }
                int nwc[3];
                memcpy(nwc, c, sizeof(c));
                nwc[d]++;
                tmp += dp[nwc[0]][nwc[1]][nwc[2]];
                if(tmp > mx) {
                    mx = tmp;
                    mxd = d;
                }
            }
            dp[c[0]][c[1]][c[2]] = mx;
            u[c[0]][c[1]][c[2]] = mxd;
        }
        }
        }
        memset(c, 0, sizeof(c));
        printf("Case #%d: ", qq);
        for(int i = 1; i <= 60; i++) {
            printf("%c", u[c[0]][c[1]][c[2]] == 0 ? 'R' : u[c[0]][c[1]][c[2]] == 1 ? 'S' : 'P');
            c[u[c[0]][c[1]][c[2]]]++;
        }
        sum += dp[0][0][0];
        printf("\n");
    }
/*printf("%f\n", sum / 200.);
printf("%f\n", sv / 200.);
printf("%f\n", sum / 200 / (sv / 200) * 50);*/
}
