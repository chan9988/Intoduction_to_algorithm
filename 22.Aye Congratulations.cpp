#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 270

using namespace std;

ll c[MAX][MAX],f[MAX][MAX],gcf[MAX][MAX];

void init(){
    ll i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            c[i][j]=0;
            f[i][j]=0;
        }
    }
}

void setgcf(){
    ll i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            gcf[i][j]=c[i][j]-f[i][j];
        }
    }
}

bool findpath(ll n){
    bool ch[n]={false};
    ll pre[n]={0};
    ll b[n]={0};
    queue<ll> q;
    ll i,j;
    ch[0]=true;
    for(i=0;i<n;i++){
        if(ch[i]==false&&gcf[0][i]>0){
            q.push(i);
            ch[i]=true;
            pre[i]=0;
            b[i]=gcf[0][i];
        }
    }
    ll now;
    while(q.size()!=0){
        now=q.front();
        q.pop();
        for(i=0;i<n;i++){
            if(ch[i]==false&&gcf[now][i]>0){
                ch[i]=true;
                q.push(i);
                pre[i]=now;
                b[i]=min(gcf[now][i],b[now]);
            }
        }
    }
    if(b[n-1]==0){
        return false;
    }
    else{
        ll pr;
        now=n-1;
        pr=pre[now];
        while(now!=0){
            f[pr][now]+=b[n-1];
            f[now][pr]-=b[n-1];
            gcf[pr][now]-=b[n-1];
            gcf[now][pr]+=b[n-1];
            now=pr;
            pr=pre[pr];
        }
    }
    return true;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    init();
    ll i,j,t,k;
    ll sum=0;
    for(i=0;i<n;i++){
        cin >> t;
        c[m+i+1][m+n+1]=t;
        sum+=t;
    }
    for(i=0;i<m;i++){
        cin >> t;
        c[0][i+1]=t;
    }
    for(i=0;i<n;i++){
        cin >> k;
        for(j=0;j<k;j++){
            cin >> t;
            c[t+1][m+i+1]=INF;
        }
    }
    setgcf();
    while(findpath(n+m+2)){

    }
    ll ans=0;
    for(i=0;i<n+m+2;i++){
        if(f[0][i]>0){
            ans+=f[0][i];
        }
    }
  //  cout << sum << " " << ans << endl;
    cout << sum-ans << endl;
    return 0;
}