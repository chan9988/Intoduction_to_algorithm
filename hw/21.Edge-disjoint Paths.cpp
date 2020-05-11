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
    cf=new ll*[n];
    f=new ll*[n];
    gcf=new ll*[n];
    for(i=0;i<n;i++){
        cf[i]=new ll[n];
        f[i]=new ll[n];
        gcf[i]=new ll[n];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cf[i][j]=0;
            f[i][j]=0;
        }
    }
    for(i=0;i<m;i++){
        cin >> t >> k;
        cf[t][k]++;
        cf[k][t]++;
    }
    set_gcf();
    while(find_path()){
        set_gcf();
    }
    ll ans=0;
    for(i=0;i<n;i++){
        ans+=f[0][i];
    }
    cout << ans << '\n';
    return 0;
}