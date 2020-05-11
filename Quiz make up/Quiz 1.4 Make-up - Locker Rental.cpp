#include <iostream>
#include <string>
#include <vector>
#include <bitset>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,s,k;
    ll i,j,sum=0;
    cin >> n >> m >> s ;
    bitset<50000> a;
    a.reset();
    a[0]=true;
    for(i=0;i<n;i++){
        cin >> k;
        sum+=k;
        a=a|(a<<k);
    }
    m-=s;
    while(a[m]!=true){
        m--;
    }
    cout << sum-m << '\n';
    return 0;
}