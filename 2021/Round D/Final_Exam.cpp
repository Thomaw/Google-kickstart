#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, i, j, n, m, l, r, m1, m2, l1, r1;
    cin>>t;
    
    for(j=1; j<=t; j++)
    {
        cin>>n>>m;
        ll ans[m], a[m];
        map<ll, ll> mp;
        //cout<<mp.size();
        
        for(;n--;)
        {
            cin>>l>>r;
            mp[l]=r;
        }
        
        for(i=0; i<m; i++)
        {
            cin>>a[i];
            auto k=mp.upper_bound(a[i]);
            auto k1 = k;
            if(k==mp.begin())
            {
                l=(*k).first;
                r=(*k).second;
                
                ans[i]=l;
                
                mp.erase(l);
                
                if(l+1<=r)
                {
                    mp[l+1]=r;
                }
            }else if(k==mp.end()){
                k--;
                l=((*k)).first;
                r=((*k)).second;
                
                if(a[i]>r)
                {
                    ans[i]=r;
                    mp.erase(l);
                    if(l<=r-1)
                    {
                        mp[l]=r-1;
                    }
                }
                else{
                    ans[i]=a[i];
                    mp.erase(l);
                    
                    if(l<=a[i]-1)
                    mp[l]=a[i]-1;
                    
                    if(a[i]+1<=r)
                    mp[a[i]+1]=r;
                }
            }else{
                k1=k;
                k1--;
                l=((*k1)).first;
                r=((*k1)).second;
                l1=(*k).first;
                r1=(*k).second;
                
                if(l<=a[i] && r>=a[i])
                {
                    ans[i]=a[i];
                    mp.erase(l);
                    
                    if(l<=a[i]-1)
                    mp[l]=a[i]-1;
                    
                    if(a[i]+1<=r)
                    mp[a[i]+1]=r;
                }else{
                    if((a[i]-r)<=(l1-a[i])){
                        ans[i]=r;
                        
                        mp.erase(l);
                        
                        if(l<=r-1)
                        mp[l]=r-1;
                        
                    }else{
                        ans[i]=l1;
                        
                        mp.erase(l1);
                        if(l1+1<=r1)
                        mp[l1+1]=r1;
                    }
                }
            }
        }
        cout<<"Case #"<<j<<": ";
        for(i=0; i<m; i++)
        cout<<ans[i]<<" ";
        cout<<"\n";
        
    }
}
