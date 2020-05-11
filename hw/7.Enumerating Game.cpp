#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int M;
    cin >> M;
    int a,b,c,d;
    vector<int> n;
    while(M--){
        n.clear();
        cin >> a >> b >> c >> d;
        while(c!=d){
            if(c==a&&d==b){
                break;
            }
            if(c>d){
                n.push_back(2);
                c-=d;
            }
            else if(c<d){
                n.push_back(1);
                d-=c;
            }
 //           cout << c << " " << d << endl ;
        }
        if(c!=a||d!=b){
            cout << -1 << endl;
        }
        else{
            int i;
            long long sum;
            sum=1;
            for(i=n.size()-1;i>=0;i--){
                if(n[i]==1){
                    sum=sum*2;
                    sum%=524287;
                }
                else{
                    sum=sum*2+1;
                    sum%=524287;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}
