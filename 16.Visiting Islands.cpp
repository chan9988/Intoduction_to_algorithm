#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 100010

using namespace std;

ll p[MAX],s[MAX];

void init(){
    ll i,j;
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

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,m;
    ll i,j,t,k;
    cin >> n >> m;
    init();
    for(i=0;i<m;i++){
        cin >> t >> k;
        uni(t,k);
    }
    for(i=1;i<=n;i++){
        cout << s[findset(i)]-1 << " ";
    }
    cout << endl;
    return 0;
}