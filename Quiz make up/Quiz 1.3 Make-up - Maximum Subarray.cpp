#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    vector<long long> a;
    int i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> m;
        a.push_back(m);
    }
    long long max_l,max_r,max_sum,l;
    long long sum;
    max_sum=a[0];
    max_l=0;
    max_r=0;
    sum=0;
    l=0;
    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum>max_sum){
            max_sum=sum;
            max_l=l;
            max_r=i;
        }
        if(sum<0){
            sum=0;
            l=i+1;
        }
    }
    cout << max_l+1 << " " << max_r+1 << '\n';
    return 0;
}