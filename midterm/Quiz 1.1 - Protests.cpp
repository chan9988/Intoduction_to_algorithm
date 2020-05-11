#include <iostream>

using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    cin >> n;
    long long t,m;
    int i;
    for(i=0;i<n;i++){
        cin >>t;
        if(i==0){
            m=t;
        }
        else{
            if(t>m){
                m=t;
            }
        }
    }
    cout << m << endl;
    return 0;
}