#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll **c,**f,**gcf;

void init(ll n){
    ll i,j;
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
            f[i][j]=0;
            gcf[i][j]=0;
        }
    }
}

void findgcf(ll n){
    ll i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
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
                b[i]=min(gcf[now][i],b[now]);
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
        a=pre[now];
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
    init(n+m+2);
    ll i,j,t,k;
    ll sum=0;
    for(i=0;i<n;i++){
        cin >> t;
        sum+=t;
        c[m+i+1][m+n+1]=t;
    }
    for(i=0;i<m;i++){
        cin >> k;
        c[0][i+1]=k;
    }
    for(i=0;i<n;i++){
        cin >> t;
        for(j=0;j<t;j++){
            cin >> k;
            c[k+1][m+i+1]=INF;
        }
    }
    findgcf(n+m+2);
    while(findpath(n+m+2)){

    }
    for(i=0;i<n+m+2;i++){
        if(f[0][i]>0){
            sum-=f[0][i];
        }
    }
    cout << sum << endl;
    return 0;
}