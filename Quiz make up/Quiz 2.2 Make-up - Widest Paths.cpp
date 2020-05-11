#include <bits/stdc++.h>
#define ll long long
#define MAX 1010
#define INF 0x3f3f3f3f
using namespace std;

/*
    先用kruskal找出maximum spanning tree，在最每個點做Dijkstra。
*/

ll ans[MAX][MAX];
vector<pair<ll,ll> > v[MAX];
ll p[MAX];
ll s[MAX];

ll findset(ll x){
    if(p[x]!=x){
        p[x]=findset(p[x]);
    }
    return p[x];
}

void uni(ll x,ll y){
    x=findset(x);
    y=findset(y);
    if(x==y) return;
    if(s[x]>s[y]){
        p[y]=x;
        s[x]+=s[y];
    }
    else{
        p[x]=y;
        s[y]+=s[x];
    }
}

void init(){
    ll i,j;
    for(i=0;i<MAX;i++){
        p[i]=i;
        s[i]=1;
        for(j=0;j<MAX;j++){
            ans[i][j]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,t;
    ll i,j,k;
    init();
    cin >> n >> m >> t;
    ll a,b,w;
    priority_queue< pair<ll,pair<ll,ll> > > q1;
    for(i=0;i<m;i++){
        cin >> a >> b >> w;
        q1.push(make_pair(w,make_pair(a,b)));
    }
    pair<ll,pair<ll,ll> > ne1;
    ll no=0;
    while(q1.size()!=0){
        ne1=q1.top();
        q1.pop();
        if(findset(ne1.second.first)!=findset(ne1.second.second)){
            uni(ne1.second.first,ne1.second.second);
            no++;
            v[ne1.second.first].push_back(make_pair(ne1.first,ne1.second.second));
            v[ne1.second.second].push_back(make_pair(ne1.first,ne1.second.first));
        }
        if(no==n-1){
            break;
        }
    }
    for(i=0;i<n;i++){
        bool ch[n]={false};
        priority_queue<pair<ll,ll> > q;
        ch[i]=true;
        pair<ll,ll> ne;
        ll now=0;
        for(j=0;j<v[i].size();j++){
            q.push(v[i][j]);
        }
        while(q.size()!=0){
            ne=q.top();
            q.pop();
            if(ch[ne.second]==false){
                ch[ne.second]=true;
                ans[i][ne.second]=ne.first;
                now++;
                for(j=0;j<v[ne.second].size();j++){
                    if(ne.first>=v[ne.second][j].first){
                        q.push(v[ne.second][j]);
                    }
                    else{
                        q.push(make_pair(ne.first,v[ne.second][j].second));
                    }
                }
            }
            if(now==n-1){
                break;
            }
        }
    }
    for(i=0;i<t;i++){
        cin >> a >> b;
        cout << ans[a][b] << '\n';
    }
    return 0;
}