#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

bool sort1(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second > b.second) ;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    string s;
    vector<pair<int,int> > a,ans;
    cin >> s;
    int n;
    int i;
    for(i=0;i<26;i++){
        a.push_back(make_pair(i,0));
    }
    for(i=0;i<s.size();i++){
        n=s[i]-'A';
        a[n].second++;
    }
    stable_sort(a.begin(),a.end(),sort1);
    bool ch=false;
    for(i=0;i<a.size();i++){
        if(a[i].second!=0){
            if(ch){
                cout << endl;
            }
            ch=true;
            cout << a[i].first+65 << " " << a[i].second ;
        }
        else{
            break;
        }
    }
    return 0;
}