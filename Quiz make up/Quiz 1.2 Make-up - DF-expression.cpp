#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int i,j;
    vector< pair<ll,ll> > a;
    pair<ll,ll> change;
    n*=n;
    ll sum=0;
    for(i=0;i<s.size();i++){
        if(s[i]=='2'){
            n/=4;
            a.push_back(make_pair(n,4));
        }
        else if(s[i]=='1'){
            if(a.size()==0){
                sum+=n;
                break;
            }
            change=a[a.size()-1];
            change.second--;
            a.push_back(change);
            sum+=change.first;
            while(a[a.size()-1].second==0){
                for(j=0;j<5;j++){
                    a.pop_back();
                }
                n*=4;
                if(a.size()==0){
                    break;
                }
                else{
                    change=a[a.size()-1];
                    change.second--;
                    a.push_back(change);
                }
            }
            
        }
        else if(s[i]=='0'){
            if(a.size()==0){
                break;
            }
            change=a[a.size()-1];
            change.second--;
            a.push_back(change);
            while(a[a.size()-1].second==0){
                for(j=0;j<5;j++){
                    a.pop_back();
                }
                n*=4;
                if(a.size()==0){
                    break;
                }
                else{
                    change=a[a.size()-1];
                    change.second--;
                    a.push_back(change);
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}