#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    int i,j,t;
    vector<long long> a;
    vector<pair<long long,pair<long long,long long> > > p;
    cin >> n;
    while(n--){
        cin >> t;
        a.push_back(t);
    }
    for(i=0;i<a.size();i++){
        for(j=i+1;j<a.size();j++){
                p.push_back(make_pair(a[i]+a[j],make_pair(i,j)));
        }
    }
    stable_sort(p.begin(),p.end());
    i=0;
    j=p.size()-1;
    long long m;
    while(i<=j){
        m=p[i].first+p[j].first;
        if(m==0){
            if(p[i].second.first!=p[j].second.first&&p[i].second.second!=p[j].second.second){
                if(p[i].second.second!=p[j].second.first&&p[i].second.first!=p[j].second.second){
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
        if(m>0){
            j--;
        }
        else{
            i++;
        }
    }
    cout << 0 << endl;
    return 0;
}
