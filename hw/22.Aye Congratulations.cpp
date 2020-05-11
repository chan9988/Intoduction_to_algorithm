#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll **cf,**f,**gcf;
ll n,m;

void set_gcf(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            gcf[i][j]=cf[i][j]-f[i][j];
        }
    }
}

bool find_path(){
    ll a[n]={0};
    a[0]=INF;
    ll ch[n]={0};
    ll q[n]={0};
    queue<ll> ind;
    int i,j;
    ll now;
    ind.push(0);
    while(ind.size()!=0){
        now=ind.front();
        ind.pop();
        ch[now]=2;
        q[0]=0;
        for(i=0;i<n;i++){
            if(ch[i]==0&&gcf[now][i]!=0){
                ch[i]=1;
                a[i]=min(a[now],gcf[now][i]);
                q[i]=now;
                ind.push(i);    
            }
            else if(ch[i]==1&&gcf[now][i]!=0){
                if(a[i]<min(a[now],gcf[now][i])){
                    a[i]=min(a[now],gcf[now][i]);
                    q[i]=now;
                }
            }
        }
    }
    if(a[n-1]==0||a[n-1]==INF){
        return false;
    }
    else{
        now=n-1;
        ll pre;
        pre=q[now];
        while(now!=0){
            f[pre][now]+=a[n-1];
            f[now][pre]-=a[n-1];
            now=pre;
            pre=q[pre];
        }
        return true;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    cin >> n >> m;
    int i,j;
    ll t,k;
    ll sum=0;
    cf=new ll*[n+m+2];
    f=new ll*[n+m+2];
    gcf=new ll*[n+m+2];
    for(i=0;i<n+m+2;i++){
        cf[i]=new ll[n+m+2];
        f[i]=new ll[n+m+2];
        gcf[i]=new ll[n+m+2];
    }
    for(i=0;i<n+m+2;i++){
        for(j=0;j<n+m+2;j++){
            cf[i][j]=0;
            f[i][j]=0;
        }
    }  
    for(i=1;i<=n;i++){
        cin >> t;
        cf[i][n+m+1]=t;
        sum+=t;
    }
    for(i=1;i<=m;i++){
        cin >> t;
        cf[0][n+i]=t;
    }
    for(i=1;i<=n;i++){
        cin >> k;
        for(j=0;j<k;j++){
            cin >> t;
            cf[n+t+1][i]=INF;
        }
    }
    n=n+m+2;
    set_gcf();
    while(find_path()){
        set_gcf();
    }
    ll ans=0;
    for(i=0;i<n;i++){
        ans+=f[0][i];
    }
    cout << sum-ans << '\n';
    return 0;
}