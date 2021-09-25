#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, d, k, ans, sum, i, j, l, si, s, e, h, i1, p, v1, v2, j1, j2;
    
    cin>>t;
    
    
    for(j=1; j<=t; j++)
    {
        cin>>d>>n>>k;
        
        si=0;
        
        vector<pair<ll, ll>> in[d+2];
        vector<pair<ll, ll>> out[d+2];
        
        sum=ans=0;
        
        multiset<pair<ll, ll>> top_k;
        
        multiset<pair<ll, ll>, greater<pair<ll, ll>>> available;
        
        
        for(i=0; i<n; i++)
        {
            cin>>h>>s>>e;
            
            in[s].push_back({h, i});
            out[e+1].push_back({h, i});
        }
        
        for(i=1; i<=d; i++)
        {
            l=in[i].size();
            
            for(i1=0; i1<l; i1++)
            {
                available.insert({in[i][i1].first, in[i][i1].second});
            }
            
            l=out[i].size();
            
            for(i1=0; i1<l; i1++)
            {
                available.erase({out[i][i1].first, out[i][i1].second});
                
                p=top_k.erase({out[i][i1].first, out[i][i1].second});
                
                if(p==1)
                {
                    sum=sum-out[i][i1].first;
                    si--;
                }
            }
            multiset<pair<ll, ll>, greater<pair<ll, ll>>>::iterator itr;
            multiset<pair<ll, ll>>::iterator itr1;
            while(si<k && available.empty()==false)
            {
                itr = available.begin();
                
                sum=sum+(*itr).first;
                top_k.insert(*itr);
                
                available.erase(itr);
                
                si++;
            }
            
            
            while(si==k && available.empty()==false)
            {
                itr = available.begin();
                itr1 = top_k.begin();
                
                if((*itr1).first<(*itr).first)
                {
                    v1=(*itr).first;
                    v2=(*itr1).first;
                    
                    j1=(*itr).second;
                    j2=(*itr1).second;
                    
                    sum=sum-v2+v1;
                    
                    available.erase(itr);
                    top_k.erase(itr1);
                    
                    available.insert({v2, j2});
                    top_k.insert({v1, j1});
                    
                    
                }else{
                    break;
                }
            }
            
            ans=max(ans, sum);
        }
        
        cout<<"Case #"<<j<<": "<<ans<<"\n";
        
        
    }
}
