#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    vector<pair<long long,long long > > a;
    priority_queue<long long,vector<long long>,greater<long long> > s;
    long long t,k;
    cin >> n;
    int i;
    for(i=0;i<n;i++){
        cin >> k >> t;
        a.push_back(make_pair(k,t));
    }
    stable_sort(a.begin(),a.end());
/*
    for(i=0;i<a.size();i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
*/
    long long ans=0;
    long long time,m;
    ans=n;
    for(i=a.size()-1;i>0;i--){
        time=a[i].first-a[i-1].first;
        s.push(a[i].second);
        if(s.size()!=0){
            while(time-s.top()>=0){
                m=s.top();
                s.pop();
                time=time-m;
                if(s.size()==0){
                    break;
                }
            }
            if(s.size()!=0){
                m=s.top();
                s.pop();
                m-=time;
                s.push(m);
            }
        }
    }
    time=a[0].first;
    s.push(a[0].second);
    if(s.size()!=0){
        time=a[i].first;
        while(time-s.top()>=0){
            m=s.top();
            s.pop();
            time=time-m;
            if(s.size()==0){
                break;
            }
        }
        if(s.size()!=0){
            m=s.top();
            s.pop();
            m-=time;
            s.push(m);
        }
    }
    cout << ans-s.size() << endl;
    return 0;
}