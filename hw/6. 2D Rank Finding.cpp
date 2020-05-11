#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> ans;
vector<pair<pair<long long,long long>,long long> > a;


void mergesort(int r,int l){
//    cout << r << " " << l << " 123" << endl;
    if(r>=l){
        return ;
    }
    int m;
    m=(r+l)/2;
    mergesort(r,m);
    mergesort(m+1,l);
    int i,j,k;
    vector<long long > c;
    vector<long long>::iterator it;
    for(i=r;i<=m;i++){
        c.push_back(a[i].first.second);
    }
    stable_sort(c.begin(),c.end());
    for(j=m+1;j<=l;j++){
        it=upper_bound(c.begin(),c.end(),a[j].first.second);
        ans[a[j].second]+=(it-c.begin());
    }
}


int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n;
    cin >> n;
    int i;
    a.clear();
    ans.clear();
    long long t,k;
    for(i=0;i<n;i++){
        cin >> t >> k;
        a.push_back(make_pair(make_pair(t,k),i));
        ans.push_back(0);
    }
    stable_sort(a.begin(),a.end());
    mergesort(0,n-1);
    for(i=0;i<n;i++){
        cout << ans[i] << " " ;
    }
    cout << endl;
    return 0;
}
