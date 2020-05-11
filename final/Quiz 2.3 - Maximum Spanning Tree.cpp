#include <bits/stdc++.h>
#define ll long long
#define MAX 500010
using namespace std;

ll p[MAX],s[MAX];

void init(){
    ll i;
    for(i=0;i<MAX;i++){
        p[i]=i;
        s[i]=1;
    }
}

ll findset(ll x){
    if(p[x]!=x){
        p[x]=findset(p[x]);
    }
    return p[x];
}

void uni(ll x,ll y){
    x=findset(x);
    y=findset(y);
    if(x!=y){
        p[y]=x;
        s[x]+=s[y];
    }
    else{
        p[x]=y;
        s[y]+=s[x];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    init();
    ll a,b,w;
    priority_queue<pair<ll,pair<ll,ll> > > q;
    ll i,j,t,k;
    for(i=0;i<m;i++){
        cin >> a >> b >> w;
        q.push(make_pair(w,make_pair(a,b)));
    }
    ll now=0;
    ll ans=0;
    pair<ll,pair<ll,ll> >ne;
    while(q.size()!=0){
    //    cout << 123 << endl;
        ne=q.top();
        q.pop();
        if(findset(ne.second.first)!=findset(ne.second.second)){
            uni(ne.second.first,ne.second.second);
            ans+=ne.first;
            now++;
        }
        if(now==n-1){
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}