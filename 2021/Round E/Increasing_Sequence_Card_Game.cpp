#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, i, j, k;
    
    long double ans[1000001], x, y, z, a1;
    
    ans[1]=1;
    
    for(i=2; i<=1000000; i++)
    {
        y=i;
        ans[i]=ans[i-1]+((1.0)/(y));
    }
    
    cin>>t;
    
    for(j=1; j<=t; j++)
    {
        cin>>n;
        cout<<"Case #"<<j<<": ";
        
        if(n<=1000000)
        {
            cout<<fixed<<setprecision(10)<<ans[n]<<"\n";
        }else{
            a1=ans[1000000];
            y=n;
            a1=a1+log(y+1)-log(1000001);
            
            
            
            cout<<fixed<<setprecision(10)<<a1<<"\n";
        }
    }
    
    
}
