#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 100010

using namespace std;

ll p[MAX],s[MAX];

void init(){
    ll i;
    for(i=0;i<MAX;i++){
        p[i]=i;
        s[i]=1;
    }
}

ll findset(ll n){
    if(p[n]!=n){
        p[n]=findset(p[n]);
    }
    return p[n];
}

void uni(ll x,ll y){
    x=findset(x);
    y=findset(y);
    if(x!=y){
        if(s[x]>s[y]){
            p[y]=x;
            s[x]+=s[y];
        }
        else{
            p[x]=y;
            s[y]+=s[x];
        }
    }
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,m,w;
    ll i,j,t,k,w1;
    cin >> n >> m >> w;
    init();
    priority_queue< pair<ll,pair<ll,ll> >,vector< pair<ll,pair<ll,ll> > >,greater< pair<ll,pair<ll,ll> > > > q;
    for(i=0;i<m;i++){
        cin >> t >> k >> w1;
        q.push(make_pair(w1,make_pair(t,k)));
    }
    ll now=0;
    ll ans=0;
    pair<ll,pair<ll,ll> > ne;
    while(q.size()!=0){
        ne=q.top();
        q.pop();
        if(ne.first>w){
            break;
        }
        if(findset(ne.second.first)!=findset(ne.second.second)){
            ans+=ne.first;
            uni(ne.second.first,ne.second.second);
            now++;
        }
        if(now==n-1){
            break;
        }
    }
    if(now<n-1){
        ans+=(n-1-now)*w;
    }
    cout << ans << '\n' ;
    return 0;
}