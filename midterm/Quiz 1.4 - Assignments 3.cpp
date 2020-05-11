#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    ll n;
    cin >> n;
    ll i,j,t,k,s,d;
    vector< pair<ll,pair<ll,ll> > > a;
    for(i=0;i<n;i++){
        cin >> s >> d >> t;
        a.push_back(make_pair(d,make_pair(s,t)));
    }
    stable_sort(a.begin(),a.end());
    ll b[30010]={0};
    for(k=0;k<n;k++){
        for(i=a[k].first;i>=0;i--){
            if(a[k].second.second<=i){
                b[i]=max(b[i],a[k].second.first+b[i-a[k].second.second]);
            }
        }
    }
    ll m=0;
    for(i=0;i<30010;i++){
        if(m<b[i]){
            m=b[i];
        }
    }
    cout << m << '\n';
    return 0;
}