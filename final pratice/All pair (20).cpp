#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 510
using namespace std;

ll v[MAX][MAX];

void init(){
    ll i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            v[i][j]=INF;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    ll n,m,q;
    ll i,j,t,k,w;
    cin >> n >> m >> q;
    init();
    for(i=0;i<m;i++){
        cin >> t >> k >> w;
        if(w<v[t][k]){
            v[t][k]=w;
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
        cin >> t >> k;
        if(v[t][k]==INF||v[k][t]==INF){
            cout << -1 << endl;
        }
        else{
            cout << max(v[t][k],v[k][t]) << '\n';
        }
    }
    return 0;
}