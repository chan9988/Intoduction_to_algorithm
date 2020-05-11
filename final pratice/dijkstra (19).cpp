#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 2010
using namespace std;

ll v[MAX][MAX];

void init(){
    ll i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(i==j){
                v[i][j]=0;
            }
            else{
                v[i][j]=INF;
            }
        }
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);    
    ll n,m;
    cin >> n >> m;
    init();
    ll i,j,t,k;
    for(k=0;k<m;k++){
        cin >> i >> j >> t;
        v[i][j]=t;
    }
    bool ch[n+1]={false};
    ch[0]=true;
    priority_queue< pair<ll,ll> , vector< pair<ll,ll> >, greater< pair<ll,ll> > > q;
    for(i=0;i<=n;i++){
        if(ch[i]==false&&v[0][i]!=INF){
            q.push(make_pair(v[0][i],i));
        }
    }
    pair<ll,ll> ne;
    ll now=0;
    ll ans=0;
    while(q.size()!=0){
        ne=q.top();
        q.pop();
        if(ch[ne.second]==false){
            ch[ne.second]=true;
            ans+=ne.first;
            now++;
            for(i=0;i<=n;i++){
                if(ch[i]==false&&v[ne.second][i]!=INF){
                    q.push(make_pair(ne.first+v[ne.second][i],i));
                }
            }
        }
        if(now==n){
            break;
        }
    }

    for(i=0;i<=n+1;i++){
        ch[i]=false;
    }
    ch[0]=true;
    priority_queue< pair<ll,ll> , vector< pair<ll,ll> >, greater< pair<ll,ll> > > q1;
    for(i=0;i<=n;i++){
        if(ch[i]==false&&v[i][0]!=INF){
            q1.push(make_pair(v[i][0],i));
        }
    }
    now=0;
    while(q1.size()!=0){
        ne=q1.top();
        q1.pop();
        if(ch[ne.second]==false){
            ch[ne.second]=true;
            ans+=ne.first;
            now++;
            for(i=0;i<=n;i++){
                if(ch[i]==false&&v[i][ne.second]!=INF){
                    q1.push(make_pair(ne.first+v[i][ne.second],i));
                }
            }
        }
        if(now==n){
            break;
        }
    }
    cout << ans << endl;
    return 0;
}