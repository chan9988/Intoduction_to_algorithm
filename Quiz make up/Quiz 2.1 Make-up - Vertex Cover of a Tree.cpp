#include <bits/stdc++.h>
#define ll long long
#define MAX 100010
using namespace std;

vector<ll> v[MAX];

bool c[MAX]={false};
ll ans=0;

bool DFS(ll n){
 //   cout << n << " 111" << endl;
    c[n]=true;
    ll i,j;
    if(v[n].size()==1&&c[v[n][0]]==true){
        return false;
    }
    bool ch=false;
    bool has_false=false;
    for(i=0;i<v[n].size();i++){
        if(c[v[n][i]]==false){
            c[v[n][i]]=true;
            if(DFS(v[n][i])==false){
                has_false=true;
            }
        }
    }
    if(has_false==true){
        ch=true;
        ans++;
    }
    else{
        ch=false;
    }
    return ch;
}

int main()
{
    ll n;
    cin >> n;
    ll i,j,t,k;
    for(i=0;i<n-1;i++){
        cin >> t >> k;
        v[t].push_back(k);
        v[k].push_back(t);
    }
    DFS(0);
    cout << ans << endl;
    return 0;
}