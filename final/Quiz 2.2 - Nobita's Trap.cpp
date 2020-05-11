#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll> > a;
    ll i,j,t,k;
    for(i=0;i<n;i++){
        cin >> t >> k;
        a.push_back(make_pair(t,1));
        a.push_back(make_pair(k,-1));
    }
    stable_sort(a.begin(),a.end());
/*
    for(i=0;i<a.size();i++){
        cout << a[i].first<< "/" << a[i].second << " ";
    }
    cout << endl;
*/
    ll max_t=0,m=0,now=0;
    for(i=0;i<a.size();i++){
        now+=a[i].second;
        if(now>m){
            m=now;
            max_t=a[i].first;
        }
     //   cout << max_t << " " << m << " " << now << endl;
    }
    cout << max_t << " " << m << endl;


    return 0;
}