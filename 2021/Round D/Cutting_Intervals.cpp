#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    ll t, i, j, c, ans, k, n, sum;
    
    cin>>t;
    
    for(j=1; j<=t; j++)
    {
        cin>>n>>c;
        ans=n;
        ll l[n], r[n];
        
        vector<pair<ll, ll>> p, p1;
        vector<pair<ll, ll>> q;
        
        for(i=0; i<n; i++)
        {
            cin>>l[i]>>r[i];
        }
        
        sort(l, l+n);
        sort(r, r+n);
        
        for(i=0; i<n;)
        {
            k=i;
            while(l[i]==l[k] && i<n)
            {
                i++;
            }
            p.push_back({l[k]+1, i-k});
        }
        
        for(i=0; i<n;)
        {
            k=i;
            while(r[i]==r[k] && i<n)
            {
                i++;
            }
            p.push_back({r[k], k-i});
        }
        
        sort(p.begin(), p.end());
        
        n=p.size();
        
        for(i=0; i<n;)
        {
            k=i;
            sum=0;
            while(p[i].first==p[k].first && i<n)
            {
                sum=sum+p[i].second;
                i++;
            }
            p1.push_back({p[k].first, sum});
            
        }
        
        n=p1.size();
        
        
        for(i=1; i<n; i++)
        {
            p1[i].second+=p1[i-1].second;
        }
        
        
        for(i=0; i<n-1; i++)
        {
            if(p1[i].second>0)
            {
                q.push_back({p1[i].second, p1[i+1].first-p1[i].first});
            }
        }
        
        sort(q.begin(), q.end());
        reverse(q.begin(), q.end());
        
        n=q.size();
        
        for(i=0; i<n; i++)
        {
            if(c==0)
            break;
            
            if(q[i].second>c)
            {
                ans=ans+q[i].first*c;
                c=0;
            }else{
                ans=ans+q[i].second*q[i].first;
                c=c-q[i].second;
            }
        }
        
        cout<<"Case #"<<j<<": "<<ans<<"\n";
        
        
        
        
    }
}
