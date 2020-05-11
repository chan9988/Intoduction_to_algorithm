#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    cin >> n;
    int sum=0,t;
    int i;
    bitset<150005> b;
    b.reset();
    b[0]=true;
    for(i=0;i<n;i++){
        cin >> t;
        b=b|(b<<t);
        sum+=t;
    }
    int ans=sum;
    for(i=0;i<150005;i++){
        if(b[i]==true){
            if(abs(sum-i-i)<ans){
               ans=abs(sum-i-i);
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
