#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll **a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    ll i,j,k;
    ll ans=0;
    cin >> n >> m;
    a=new ll*[n];
    for(i=0;i<n+1;i++){
        a[i]=new ll[n+1];
        for(j=0;j<n+1;j++){
            if(i==j){
                a[i][j]=0;
            }
            else{   
                a[i][j]=INF;
            }
        }
    }
    while(m--){
        cin >> i >> j >> k;
        a[i][j]=k;
    }
    bool ch[n+1]={false};
    ll d[n+1],now;
    for(i=0;i<n+1;i++){
        d[i]=INF;
    }
    priority_queue< pair<ll,ll>, vector<pair<ll,ll > >, greater<pair<ll,ll> > > q;
    d[0]=0;
    now=0;
    ch[0]=true;
    pair<ll,ll> c;
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            if(ch[j]==false){
                q.push( make_pair(d[now]+a[now][j],j ));
            }
        }
        while(q.size()!=0){
            c=q.top();
            q.pop();
            if(ch[c.second]==false){
                break;
            }
        }
        now=c.second;
        ch[c.second]=true;
        d[c.second]=c.first;
        ans+=c.first;
    }
    priority_queue< pair<ll,ll>, vector<pair<ll,ll > >, greater<pair<ll,ll> > > q1;
    for(j=0;j<n+1;j++){
        d[j]=INF;           
        ch[j]=false;
    }
    d[0]=0;        
    now=0;
    ch[0]=true;
    for(k=0;k<n;k++){
        for(j=0;j<=n;j++){
            if(ch[j]==false){
               q1.push( make_pair(d[now]+a[j][now],j ));
            }
        }
        while(q1.size()!=0){
            c=q1.top();
            q1.pop();
            if(ch[c.second]==false){
                break;
            }
        }
        now=c.second;
        ch[c.second]=true;
        d[c.second]=c.first;    
        ans+=c.first;
    }
    cout << ans << '\n';
    return 0;
}