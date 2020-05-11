#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    vector<pair<long long,long long> > a;
    long long k1,k2;
    long long i,j;
    for(i=0;i<n;i++){
        cin >> k1 >> k2;
        a.push_back(make_pair(k1,k2));
    }
    long long ans1[m+1]={0},ans2[m+1]={0};
    for(j=0;j<m+1;j++){
        if(a[0].second<=j){
            ans1[j]=a[0].first;
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<m+1;j++){
            if(a[i].second>j){
                ans2[j]=ans1[j];
            }
            else{
                ans2[j]=max(ans1[j],ans1[j-a[i].second]+a[i].first);
            }
        }
        for(j=0;j<m+1;j++){
            ans1[j]=ans2[j];
        }
    }
    cout << ans1[m];
    return 0;
}
