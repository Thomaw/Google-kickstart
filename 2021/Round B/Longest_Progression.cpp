// LONGEST PROGRESSION
 
// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:- O(N)
 
#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
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
 
ll solve()
{
	ll n;
	cin>>n;
 
	vector<ll> v(n,0);
 
	for(ll i=0;i<n;i++)
		cin>>v[i];
 
	vector<ll> diff_pref(n,inf); // diff_pref[i] = v[i] - v[i-1]
	vector<ll> diff_suff(n,inf); // diff_suff[i] = v[i+1] - v[i]
 
	for(ll i=1;i<n;i++)
		diff_pref[i] = v[i]-v[i-1];
 
	for(ll i=n-2;i>=0;i--)
		diff_suff[i] = v[i+1]-v[i];
 
	vector<ll> pref(n,2);
	vector<ll> suff(n,2);
 
	pref[0] = suff[n-1] = 1;
 
	// calculate length of longest arithmetic subarray ending at every index in prefix manner
	for(ll i=2;i<n;i++)
	{
		if(diff_pref[i]==diff_pref[i-1])
			pref[i] = 1 + pref[i-1];
	}
 
	// calculate length of longest arithmetic subarray ending at every index in suffix manner
	for(ll i=n-3;i>=0;i--)
	{
		if(diff_suff[i]==diff_suff[i+1])
			suff[i] = 1 + suff[i+1];
	}
 
	// changing first element or last element
	ll ans = max(1+suff[1],1+pref[n-2]);
 
	// maximize answer now by changing a single element
 
	for(ll i=1;i<n-1;i++)
	{
	    // answer for subarray ending at current index without changing any element
	    ans = max(ans,1+suff[i+1]);
	    ans = max(ans,1+pref[i-1]);
 
	    // check if current element can be changed or not?
 
	    if((v[i+1]-v[i-1])%2)continue;
 
	    ll diff = (v[i+1]-v[i-1])/2;
 
	    if(i<2 or diff_pref[i-1]==diff)
	    	ans = max(ans,2+pref[i-1]);
 
	    if(i>n-3 or diff_suff[i+1]==diff)
	    	ans = max(ans,2 + suff[i+1]);
 
	    if((i>1 and diff_pref[i-1]!=diff) or (i<n-2 and diff_suff[i+1]!=diff))
	    	continue;
 
	    ans = max(ans,1 + pref[i-1] + suff[i+1]);
	}
 
	return ans;
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
