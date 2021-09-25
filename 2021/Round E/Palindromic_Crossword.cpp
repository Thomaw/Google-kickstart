#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
void fill(ll i, ll k, string a[], bool v[][1001], pair<ll, ll> row[][1001], pair<ll, ll> col[][1001])
{
    
    if(a[row[i][k].first][row[i][k].second]=='.')
    {
        ans++;
        v[row[i][k].first][row[i][k].second]=true;
        a[row[i][k].first][row[i][k].second]=a[i][k];
        fill(row[i][k].first, row[i][k].second, a, v, row, col);
    }
    
    if(a[col[i][k].first][col[i][k].second]=='.')
    {
        ans++;
        v[col[i][k].first][col[i][k].second]=true;
        a[col[i][k].first][col[i][k].second]=a[i][k];
        fill(col[i][k].first, col[i][k].second, a, v, row, col);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, m, i, j, k, l, x, y, z;
    
    cin>>t;
    
    for(j=1; j<=t; j++)
    {
        
        ans=0;
        
        
        cin>>n>>m;
        bool v[n][1001];
        pair<ll, ll> row[n][1001], col[n][1001];
        string a[n];
        
        
        for(i=0; i<n; i++)
        {
            for(k=0; k<m; k++)
            {
                v[i][k]=false;
            }
        }

        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        
        
        for(i=0; i<n; i++)
        {
            for(k=0; k<m; k++)
            {
                if(v[i][k]==false && a[i][k]!='#')
                {
                    for(l=k+1; l<m; l++)
                    {
                        if(a[i][l]=='#')
                        {
                            break;
                        }
                    }
                    l--;
                    
                    for(x=0; x+k<=l-x; x++)
                    {
                        row[i][x+k]={i, l-x};
                        row[i][l-x]={i, x+k};
                        v[i][x+k]=v[i][l-x]=true;
                    }
                }
            }
        }
        
        for(i=0; i<n; i++)
        {
            for(k=0; k<m; k++)
            {
                v[i][k]=false;
            }
        }
        
        
        
        for(i=0; i<n; i++)
        {
            for(k=0; k<m; k++)
            {
                if(v[i][k]==false && a[i][k]!='#')
                {
                    for(l=i+1; l<n; l++)
                    {
                        if(a[l][k]=='#')
                        {
                            break;
                        }
                    }
                    l--;
                    
                    for(x=0; x+i<=l-x; x++)
                    {
                        col[x+i][k]={l-x, k};
                        col[l-x][k]={x+i, k};
                        v[x+i][k]=v[l-x][k]=true;
                    }
                }
            }
        }
        
        for(i=0; i<n; i++)
        {
            for(k=0; k<m; k++)
            {
                v[i][k]=false;
            }
        }
        
        
        /*for(i=0; i<n; i++)
        {
            for(k=0; k<m; k++)
            {
                cout<<col[i][k].first<<" "<<col[i][k].second<<"   ";
            }
            cout<<"\n";
        }*/
        
        
        for(i=0; i<n; i++)
        {
            for(k=0; k<m; k++)
            {
                if(v[i][k]==false && a[i][k]!='#' && a[i][k]!='.')
                {
                    v[i][k]=true;
                    fill(i, k, a, v, row, col);
                }
            }
        }
        
        cout<<"Case #"<<j<<": "<<ans<<"\n";
        
        for(i=0; i<n; i++)
        {
            cout<<a[i]<<"\n";
        }
        
        
    }
    
}
