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
    vector<long long> a;
    cin >> n;
    long long t,t1;
    if(n==1){
        cin >> t ;
        cout << t <<endl;
        return 0;
    }
    if(n==2){
        cin >> t >> t1;
        cout << max(t,t1) <<endl;
        return 0;
    }
    int i;
    for(i=0;i<n;i++){
        cin >>t;
        a.push_back(t);
    }
    long long b[n]={0},c[n]={0};
    b[0]=a[0];
    b[2]=a[0]+a[2];
    for(i=3;i<n-1;i++){
        b[i]=max(b[i-2],b[i-3])+a[i];
    }
    c[0]=0;
    c[1]=a[1];
    c[2]=a[2];
    for(i=3;i<n;i++){
        c[i]=max(c[i-2],c[i-3])+a[i];
    }
    long long m1,m2;
    m1=max(b[n-2],b[n-3]);
    m2=max(c[n-1],c[n-2]);

    cout << max(m1,m2) << endl;
    return 0;
}
