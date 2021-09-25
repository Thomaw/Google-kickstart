#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, i, j, k, l, ma, m;
    ll c[26], d[26];
    string a, b;
    
    cin>>t;
    
    for(j=1; j<=t; j++)
    {
        cin>>a;
        l=a.size();
        vector<pair<ll, char>> c1;
        
        for(i=0; i<26; i++)
        {
            c[i]=0;
            d[i]=0;
        }
        
        for(i=0; i<l; i++)
        {
            if(a[i]>=97)
            c[a[i]-97]++;
            else
            d[a[i]-65]++;
        }
        
        ma=0;
        
        for(i=0; i<26; i++)
        {
            ma=max(ma, c[i]);
            ma=max(ma, d[i]);
        }
        
        for(i=0; i<26; i++)
        {
            c1.push_back({c[i], char(i+97)});
            c1.push_back({d[i], char(i+65)});
        }
        
        sort(c1.begin(), c1.end());
        reverse(c1.begin(), c1.end());
        
        //sort(c2.begin(), c2.end());
        //reverse(c2.begin(), c2.end());
        
        if(2*ma>l)
        {
            cout<<"Case #"<<j<<": IMPOSSIBLE\n";
        }else{
            b=a;
            for(m=0; m<52; m++)
            {
                for(i=0; i<l; i++)
                {
                    if(a[i]==c1[m].second && a[i]==b[i])
                    {
                        for(k=51; k>=0; k--)
                        {
                            if(c1[k].first>0 && c1[k].second!=c1[m].second)
                            {
                                b[i]=c1[k].second;
                                c1[k].first--;
                                break;
                            }
                        }
                    }
                }
                //cout<<char(c1[m].second)<<" "<<b<<"\n";
                //cout<<char(c1[m].second+97)<<" "<<b<<"\n";
            }
            cout<<"Case #"<<j<<": "<<b<<"\n";
        }
        
    }
}
