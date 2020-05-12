#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll p[100010];
ll s[100010];

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

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);    
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<100010;i++){
        p[i]=i;
        s[i]=1;
    }
    int i,j;
    ll a,b;
    for(i=0;i<m;i++){
        cin >> a >> b;
        uni(a,b);
    }
    for(i=1;i<=n;i++){
        cout << s[findset(i)]-1 << " ";
    }
    cout << endl;
    return 0;
}