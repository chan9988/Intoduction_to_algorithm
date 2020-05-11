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

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);    
    ll n,m,w;
    cin >> n >> m >> w;
    init();
    ll i,j,t,k;
    ll a,b;
    priority_queue< pair<ll,pair<ll,ll> >,vector< pair<ll,pair<ll,ll> > > ,greater < pair<ll,pair<ll,ll> > > > q;
    for(i=0;i<m;i++){
        cin >> a >> b >> t;
        q.push(make_pair(t,make_pair(a,b)));    
    }
    ll now=0,sum=0;
    pair<ll,pair<ll,ll> > ne;
    while(q.size()!=0){
        ne=q.top();
        q.pop();
        if(ne.first>w){
            break;
        }
        else{
            if(findset(ne.second.first)!=findset(ne.second.second)){
                sum+=ne.first;
                uni(ne.second.first,ne.second.second);
                now++;
            }
        }
        if(now==n-1){
            break;
        }
    }
    if(now<n-1){
        sum=sum+(n-1-now)*w ;
    }
    cout << sum << endl;
    return 0;
}