#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll **c,**f,**gcf;

void init(ll n){
    int i,j;
    c=new ll*[n];
    f=new ll*[n];
    gcf=new ll*[n];
    for(i=0;i<n;i++){
        c[i]=new ll[n];
        f[i]=new ll[n];
        gcf[i]=new ll[n];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            gcf[i][j]=0;
            f[i][j]=0;
        }
    }
}

void setgcf(ll n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            gcf[i][j]=c[i][j]-f[i][j];
        }
    }
}

bool findpath(ll n){
    bool ch[n]={false};
    queue<ll> q;
    ll pre[n]={0};
    ll b[n]={0};
    ch[0]=true;
    int i,j;
    for(i=0;i<n;i++){
        if(gcf[0][i]>0){
            q.push(i);
            pre[i]=0;
            b[i]=gcf[0][i];
            ch[i]=true;
        }
    }
    ll now;
    while(q.size()!=0){
        now=q.front();
        q.pop();
        for(i=0;i<n;i++){
            if(ch[i]==false&&gcf[now][i]>0){
                q.push(i);
                pre[i]=now;
                b[i]=min(b[now],gcf[now][i]);
                ch[i]=true;
            }
        }
    }
    if(b[n-1]==0){
        return false;
    }
    else{
        now=n-1;
        ll a;
        a=pre[n-1];
        while(now!=0){
            f[a][now]+=b[n-1];
            f[now][a]-=b[n-1];
            gcf[a][now]-=b[n-1];
            gcf[now][a]+=b[n-1];
            now=a;
            a=pre[a];
        }
    }
    return true;
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);    
    ll n,m;
    cin >> n >> m;
    ll i,j,t,k;
    init(n);
    for(i=0;i<m;i++){
        cin >> t >> k;
        c[t][k]++;
        c[k][t]++;
    }
    setgcf(n);
    while(findpath(n)){
    }
    ll ans=0;
    for(i=0;i<n;i++){
        ans+=f[0][i];
    }
    cout << ans << endl;
    return 0;
}