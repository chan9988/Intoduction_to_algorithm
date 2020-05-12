#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 100010
using namespace std;

vector< pair<ll,ll> > v[MAX];
ll m=0;
bool ch[MAX]={false};

ll DFS(ll n){
    ll max1=0,max2=0;
    ll i,j;
    ll now;
    ch[n]=true;
    for(i=0;i<v[n].size();i++){
        if(ch[v[n][i].first]==false){
            now=DFS(v[n][i].first)+v[n][i].second;
            if(now>max1){
                max2=max1;
                max1=now;
            }
            else if(now>max2){
                max2=now;
            }
        }
    }
    if(max1+max2>m){
        m=max1+max2;
    }
    return max1;
}


int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);    
    ll n,a,b,l;
    ll i,j;
    ll sum=0;
    cin >> n ;
    for(i=0;i<n-1;i++){
        cin >> a >> b >> l;
        v[a].push_back(make_pair(b,l));
        v[b].push_back(make_pair(a,l));
        sum+=l;
    }
    DFS(1);
    cout << sum*2-m << endl;
    return 0;
}