#include <bits/stdc++.h>
#define ll long long
#define MAX 2020
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<ll,ll> > c[MAX],f[MAX],gcf[MAX];

void getgcf(){
    ll i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<c[i].size();j++){
            gcf[i][j].second=c[i][j].second-f[i][j].second;
        }
    }
}

bool findpath(ll n){
    ll i,j,t,k;
    ll p[n]={0};
    ll b[n]={0};
    bool ch[n]={false};
    ch[0]=true;
    queue<ll> q;
    for(i=0;i<gcf[0].size();i++){
        if(ch[gcf[0][i].first]==false&&gcf[0][i].second>0){
            ch[gcf[0][i].first]=true;
            q.push(gcf[0][i].first);
            p[gcf[0][i].first]=0;
            b[gcf[0][i].first]=gcf[0][i].second;
        }
    }
    ll now,pre;
    while(q.size()!=0){
        now=q.front();
        q.pop();       
        for(i=0;i<gcf[now].size();i++){ 
            if(ch[gcf[now][i].first]==false&&gcf[now][i].second>0){
                ch[gcf[now][i].first]=true;
                q.push(gcf[now][i].first);
                p[gcf[now][i].first]=now;
                b[gcf[now][i].first]=min(b[now],gcf[now][i].second);
            }
        }
        if(b[n-1]!=0){
            break;
        }
    }
    if(b[n-1]==0){
        return false;
    }
    else{
        now=n-1;
        pre=p[n-1];
        while(now!=0){
            for(i=0;i<f[pre].size();i++){
                if(f[pre][i].first==now){
                    f[pre][i].second+=b[n-1];
                }
            }
            for(i=0;i<f[now].size();i++){
                if(f[now][i].first==pre){
                    f[now][i].second-=b[n-1];
                }
            }
            for(i=0;i<gcf[pre].size();i++){
                if(gcf[pre][i].first==now){
                    gcf[pre][i].second-=b[n-1];
                }
            }
            for(i=0;i<gcf[now].size();i++){
                if(gcf[now][i].first==pre){
                    gcf[now][i].second+=b[n-1];
                }
            }
            now=pre;
            pre=p[pre];
        }
    }
    return true;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,m,r;
    cin >> n >> m >> r;
    ll i,j,t,k;
    ll a,b;
    for(i=1;i<=n;i++){
        c[0].push_back(make_pair(i,1));
        c[i].push_back(make_pair(0,0));
        f[0].push_back(make_pair(i,0));
        f[i].push_back(make_pair(0,0));
        gcf[0].push_back(make_pair(i,0));
        gcf[i].push_back(make_pair(0,0));
    }
    for(i=n+1;i<n+m+1;i++){
        c[i].push_back(make_pair(n+m+1,1));
        c[n+m+1].push_back(make_pair(i,0));
        f[i].push_back(make_pair(n+m+1,0));
        f[n+m+1].push_back(make_pair(i,0));
        gcf[i].push_back(make_pair(n+m+1,0));
        gcf[n+m+1].push_back(make_pair(i,0));
    }
    for(i=0;i<r;i++){
        cin >> a >> b;
        a++;
        b++;
        b+=n;
        c[a].push_back(make_pair(b,1));
        c[b].push_back(make_pair(a,0));
        f[a].push_back(make_pair(b,0));
        f[b].push_back(make_pair(a,0));
        gcf[a].push_back(make_pair(b,0));
        gcf[b].push_back(make_pair(a,0));
    }


    ll ans=0;
    getgcf();
    while(findpath(n+m+2)){

    }

    for(i=0;i<f[0].size();i++){

        ans+=f[0][i].second;
    }

    cout << ans << endl;
    return 0;
}