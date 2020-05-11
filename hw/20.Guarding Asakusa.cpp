#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll **a,**b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,q;
    ll i,j,k;
    cin >> n >> m >> q;
    a=new ll*[n];
    b=new ll*[n];
    for(i=0;i<n;i++){
        a[i]=new ll[n];
        b[i]=new ll[n];
        for(j=0;j<n;j++){  
            a[i][j]=INF;
        }
    }
    while(m--){
        cin >> i >> j >> k;
        if(k<a[i][j]){
            a[i][j]=k;
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j){
                    if(k!=i&&k!=j){
                       b[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
                    }
                    else{
                        b[i][j]=a[i][j];
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j]=b[i][j];
            }
        }
    }
    for(k=0;k<q;k++){
        cin >> i >> j;
        if(b[i][j]==INF||b[j][i]==INF){
            cout << -1 << '\n';
        }
        else{
            cout << max(b[i][j],b[j][i]) << '\n';
        }
    }
    return 0;

}