#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,i;
    ll t,k;
    cin >> n;
    bool ch[n+1]={false};
    vector<pair<pair<ll,ll>,ll> > a;
    for(i=1;i<=n;i++){
        cin >> t >> k;
        a.push_back(make_pair(make_pair(t,k),i));
    }
    stable_sort(a.begin(),a.end());
    ll m,n1;
    ch[a[a.size()-1].second]=true;
    m=a[a.size()-1].first.second;
    n1=a[a.size()-1].first.first;
    for(i=a.size()-2;i>=0;i--){
        if(a[i].first.second>m||(a[i].first.second==m&&a[i].first.first==n1)){
            ch[a[i].second]=true;
            m=a[i].first.second;
            n1=a[i].first.first;
        }
    }
  //  cout << ans[0] << " 123" << '\n';
    for(i=1;i<=n;i++){
        if(ch[i]){
            cout << i << " " ;
        }
    }
    cout << '\n';
    return 0;
}