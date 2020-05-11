#include <bits/stdc++.h>
#define ll long long
#define MAX 500050
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<ll,ll> > v[MAX];
ll w[MAX]={0};


int main()
{
//   ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,m;
    ll i,j,t,k;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >>t;
        w[i]=t;
    }
    bool ch[n]={false};
    ll a,b;
    for(i=0;i<m;i++){
        cin >> a >> b >> t;
        v[a].push_back(make_pair(b,t));
        v[b].push_back(make_pair(a,t));
    }
    ll p[n]={0};
    ch[0]=true;
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > q;
    for(i=0;i<v[0].size();i++){
        q.push(make_pair(v[0][i].second+w[v[0][i].first],v[0][i].first));
    }
    pair<ll,ll> ne;
    ll now=0;
    while(q.size()!=0){
    /*
        for(i=0;i<n;i++){
            cout << p[i] << " ";
        }
    */

        ne=q.top();
        q.pop();
        if(ch[ne.second]==false){
            ch[ne.second]=true;
            p[ne.second]=ne.first;
            ll index;
            ll length;
            length=ne.first;
            index=ne.second;
            for(i=0;i<v[index].size();i++){
                q.push( make_pair( length+v[index][i].second+w[v[index][i].first],v[index][i].first ) ) ;
            }
            now++;
        }
        if(now==n){
            break;
        }
    }
    ll ans=0;
    for(i=0;i<n;i++){
        ans+=p[i];
    }
    cout << ans << '\n';
    return 0;
}