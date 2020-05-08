#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    vector<int> a,ans;
    int i;
    int k,t;
    bool ch=false,ch1=false,ch2=false;
    while(cin >> k){
        a.clear();
        ans.clear();
        if(k==0){
            return 0;
        }
        if(ch1){
            cout << '\n';
        }
        ch1=true;
        for(i=0;i<k;i++){
            cin >> t;
            ans.push_back(t);
            if(i<6){
                a.push_back(0);
            }
            else{
                a.push_back(1);
            }
        }
       do{
            if(ch){
                cout << '\n';
            }
            ch=true;
            ch2=false;
            for(i=0;i<a.size();i++){
                if(a[i]==0){
                    if(ch2){
                        cout << " ";
                    }
                    ch2=true;
                    cout << ans[i] ;
                }
            }
        } while(next_permutation(a.begin(),a.end()));
    }


    return 0;
}
