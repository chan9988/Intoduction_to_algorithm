#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 505

ll v[MAX][MAX];

void init(){
    ll i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            v[i][j]=INF;
        }
    }
}

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,m,q,a,b,w;
    ll i,j,k,t;
    cin >> n >> m >> q;
    init();
    for(i=0;i<m;i++){
        cin >> a >> b >> w;
        if(w<v[a][b]){
            v[a][b]=w;
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                v[i][j]=min(v[i][j],max(v[i][k],v[k][j]));
            }
        }
    }
    for(i=0;i<q;i++){
        cin >> a >> b;
        if(v[a][b]==INF||v[b][a]==INF){
            cout << -1 << endl;
        }
        else{
            cout << max(v[a][b],v[b][a]) << endl;
        }
    }
    return 0;
}