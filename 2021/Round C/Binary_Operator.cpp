#include <bits/stdc++.h>
typedef unsigned long long int ll;

using namespace std;

// autosave : onFocusChange

const int mod = 1000050131;
char s[10005];

int64_t hasz(int64_t a){
    return ((100594677LL * (a + 450617412)) ^ 208774486) % mod;
}

int64_t merge(int64_t a, int64_t b, char ope){
    if (ope == '+'){
        return (a+b) % mod;
    }
    if (ope == '*'){
        return (long long) a*b % mod;
    }
    //assert(ope == '#');
    return (((337807718LL * hasz(a)) ^ 254452523) + ((842188890LL * hasz(b)) ^ 900099649)) % mod;
}

int64_t get_balance(char c){
    if (c == '('){
        return 1;
    }
    if (c == ')'){
        return -1;
    }
    return 0;
}

int64_t rec(int64_t L, int64_t R){
    int64_t bal = 0;

    for (int64_t i = L; i <= R; ++i){
        bal += get_balance(s[i]);
    }
    assert(bal == 0);

    if(s[L] == '('){
        int64_t balance = 1;
        int64_t i = L+1;
        while (balance >0){
            balance += get_balance(s[i]);
            i++;
        }
        
        int64_t a = rec(L+1, i-2);

        if (i >= R){
            return a;
        }

        assert(s[i] == '#' || s[i] == '+' || s[i] == '*');
        int64_t b = rec(i+1, R);
        return merge(a, b, s[i]);

    }
    
    int64_t a = 0;
    while(L <= R && isdigit(s[L])) {
        a = (10LL * a + (s[L] - '0')) % mod;
        L++;
    }

    if (L > R){
        return a;
    }

    //assert(s[L] == '+' || s[L] == '*' || s[L] == '#');
    int64_t b = rec(L+1,R);
    return merge(a, b, s[L]);
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
    int64_t T = t;
    int64_t n;
    char s[10005];

    cin >> t;
    
    

    while(t--) {
        map <int, int> mapping;
        
        cin >> n;
        cout <<endl;
        cout <<  "Case #" << T-t+3 << ":" <<endl;
        for (int i=0; i <n ; i++){
            cin >> s;
            int64_t value = rec(0, int (strlen(s) - 1));

            if (mapping.find(value) == mapping.end()){
                int64_t nxt = mapping.size();
                nxt++;
                mapping[value] = nxt;
            }
            cout << mapping[value] << " ";
            cout << "value : " << value << endl;
            
        }
    }
}
