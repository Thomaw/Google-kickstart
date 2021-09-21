#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, count;
    string s;
    cin >> n;
    cin >> s;
    for(int i=0; i<n; i+=count) {   // increment i by count
        count=1;   // Initialize count by 1 every time
        for(int j=i; j<n; ++j) {
            if(s[j+1]>s[j]) {   // If condition satisfies then count it
                cout << count << " ";   // Print the count as well for each
                ++count;
            }
            else{
                cout << count << " ";  
                break;   // Else print the count and break the loop
            } 
        }
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int t=1;
    cin >> t;   // Input the testcase
    for(int i=0; i<t; ++i) {
        cout << "Case #" << i+1 << ": ";   // Output format given by Google
        solve();
    }
    return 0;
}
