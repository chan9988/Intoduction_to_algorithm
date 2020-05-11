#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll **a,**b;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n,x;
    cin >> n >> x;
    ll a[n+5],b[n+5],c[n+5],d[n+5];
    int i,j;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    for(i=1;i<=n;i++){
        cin >> b[i];
    }
    for(i=1;i<=n;i++){
        cin >> c[i];
    }
    for(i=1;i<=n;i++){
        cin >> d[i];
    }
    vector<pair<ll,ll> > sum1,sum2;
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            sum1.push_back(make_pair(a[i]+b[j],j));
        }
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            sum2.push_back(make_pair(c[i]+d[j],i));
        }
    }
    stable_sort(sum1.begin(),sum1.end());
    stable_sort(sum2.begin(),sum2.end());    
    ll index1,index2,target1,target2,mid;
    ll ans=0;
    for(i=0;i<sum1.size();i++){
        index1=-1;
        index2=sum1.size();
        target1=x-sum1[i].first;
        target2=sum1[i].second;
        while(index1+1<index2){
            mid=(index1+index2)/2;
            if(sum2[mid].first>target1){
                index2=mid;
            }
            else{
                index1=mid;
            }
        }
        if(index1>=0){
            ans+=index1;
            index1=-1;
            index2=sum1.size();
            target1=x-sum1[i].first;
            target2=sum1[i].second;
            while(index1+1<index2){
                mid=(index1+index2)/2;
                if(sum2[mid].first>target1||(sum2[mid].first==target1&&sum2[mid].second>target2)){
                    index2=mid;
                }
                else{
                    index1=mid;
                }
            }
            ans-=index1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}