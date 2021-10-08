#include <bits/stdc++.h>
typedef unsigned long long int ll;

using namespace std;

// autosave : onFocusChange

const int64_t INF64  = int64_t(2e18) + 5;

int64_t ceil_div(int64_t a, int64_t b){
    return a / b + ((a ^ b) > 0 && a %b != 0);
}


int64_t solve(int64_t R, int64_t C, int64_t K){
    int64_t inner_columns = ceil_div(C-1, K);
    int64_t ans_r = (R-1)*ceil_div(C,K);
    ans_r += inner_columns * ceil_div(R,K);
    ans_r += (C-1-inner_columns)*R;

    int64_t inner_rows = ceil_div(R-1, K);
    int64_t ans_c = (C-1)*ceil_div(R,K);
    ans_c += inner_rows * ceil_div(C,K);
    ans_c += (R-1-inner_rows)*C;
    
    return min(ans_r, ans_c);
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    //main
    int64_t t;
    int64_t u = 1;
    cin >> t;

    
    
    
    while(t--) {

        int64_t R, C ,K;
        cin >> R >> C >> K;
        int64_t R1, C1, R2, C2;
        cin >> R1 >> C1 >> R2 >> C2;

        R1--; C1--;

        int64_t R_len = R2 - R1;
        int64_t C_len = C2 - C1;

        int skip_R = (R1 == 0) + (R2 == R);
        int skip_C = (C1 == 0) + (C2 == C);

       

        //bool on_border = R1 == 0 || R2 == R || C1 == 0 || C2 == C;
        int64_t border_cost = INF64;

        if (skip_R > 0 || skip_C > 0){
            border_cost = (2 - skip_R)* ceil_div(C_len, K)+ (2 - skip_C)* ceil_div(R_len, K);
        } 
        else{
            int64_t R_dist = min(R1, R-R2);
            int64_t C_dist = min(C1, C-C2);
            border_cost = min(border_cost, ceil_div(R_len + R_dist, K) + ceil_div(R_len, K) + 2*ceil_div(C_len, K));
            border_cost = min(border_cost, ceil_div(C_len + C_dist, K) + ceil_div(C_len, K) + 2*ceil_div(R_len, K));
        }

        int64_t grid_cost = ceil_div(R_len,K) * ((C_len-1) / K) + ceil_div(C_len,K) * ((R_len-1)/K);

        int64_t inner_cost = R_len * C_len - ceil_div(R_len, K) * ceil_div(C_len, K);

        int64_t ans = border_cost + grid_cost + inner_cost;

        cout << " Case #" << u << ": " << ans << '\n';
        u++;

    }
}
