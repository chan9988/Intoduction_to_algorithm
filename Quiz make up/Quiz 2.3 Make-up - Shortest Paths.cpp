#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 10005

using namespace std;

vector<pair<ll,ll> > v[MAX];
pair<ll,ll> ans[MAX];

void init(){
    ll i,j;
    for(i=0;i<MAX;i++){
        ans[i].first=INF;
        ans[i].second=0;
    }
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    ll i,j,t,k;
    for(i=0;i<m;i++){
        cin >> t >> k >> j;
        v[t].push_back(make_pair(k,j));
        v[k].push_back(make_pair(t,j));
    }
    init();
    bool ch[n+1]={false};
    ch[0]=true;
    priority_queue< pair<ll,ll> ,vector< pair<ll,ll> > ,greater<pair<ll,ll> > > q;
    for(auto it:v[0]){
        q.push(make_pair(it.second,it.first));
        ans[it.first].first=it.second;
        ans[it.first].second=1;
    }
    pair<ll,ll> ne;
    ll now=0;
    ne=q.top();
    while(q.size()!=0){
        ne=q.top();
        q.pop();
        if(ch[ne.second]==false){
        //    cout << ne.second << "/" << ne.first << endl;
            ch[ne.second]=true;
            now++;
            for(auto it:v[ne.second]){
                if(ch[it.first]==false){
                    if(ans[it.first].first>ne.first+it.second){
                        ans[it.first].first=ne.first+it.second;
                        ans[it.first].second=ans[ne.second].second;
                    }
                    else if(ans[it.first].first==ne.first+it.second){
                        ans[it.first].second+=ans[ne.second].second;
                        ans[it.first].second%=524287;
                    }
                    q.push(make_pair(ne.first+it.second,it.first));
                }
            }
        }
        if(now==n){
            break;
        }
    }
    cout << ans[n-1].second%524287 << endl;
    return 0;
}