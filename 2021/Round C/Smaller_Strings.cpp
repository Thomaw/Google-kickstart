#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
#define endl "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353
 
// pow(a,b) in log(N) time
ll binpow(ll a,ll b){
	ll ans = 1;
	while(b>0){
		if(b%2)
			ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}
 
ll solve()
{
	ll n,k;string s;
	cin>>n>>k>>s;
 
	ll ans = 0;
	string str = s;
	ll mid = (n+1)/2;
	for(ll i=0;i<mid;i++){
		ll mn = min((ll)(s[i]-'a'),k);
		ll curr = (mn*binpow(k,mid-i-1));
		ans = (ans+curr)%MOD;
		str[n-i-1] = str[i];
	}
	if(str<s)
		ans++;
	return ans%MOD;
}
 
signed main()
{
	FIO;
 
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
	    cout<<"Case #"<<i<<": ";
 
	    cout<<solve()<<endl;
	}
 
}
