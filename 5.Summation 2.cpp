#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n;
    cin >> n;
    long long i,t;
    multiset<long long> a;
    multiset<long long>::iterator it;
    for(i=0;i<n;i++){
        cin >> t;
        a.insert(t);
    }
    long long x,y,sum=0;
    while(a.size()>1){
        it=a.begin();
        x=*it;
        a.erase(it);
        it=a.begin();
        y=*it;
        a.erase(it);
        sum=sum+x+y;
        sum%=524287;
        a.insert(x+y);
    }
    cout << sum << endl;
    return 0;
}

