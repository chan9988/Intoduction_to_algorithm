#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long,long long> >a;
long long **t;

long long f(long long n,long long m){
//    cout << n << " " << m <<endl;
    if(t[n][m]>0){
        return t[n][m];
    }
    else if(m<=0){
        return 0;
    }
    else{
        if(n==0){
            if(a[n].second<=m){
                t[n][m]=a[n].first;
            }
            else{
                t[n][m]=0;
            }
        }
        else{
            t[n][m]=0;
            if(a[n].second>m){
                t[n][m]=f(n-1,m);
            }
            else{
                t[n][m]=max(f(n-1,m),a[n].first+f(n-1,m-a[n].second));
            }
        }
        return t[n][m];
    }
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    a.clear();
    long long k1,k2;
    long long i,j;
    t=new long long*[n];
    for(i=0;i<n;i++){
        t[i]=new long long[m+1];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m+1;j++){
            t[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        cin >> k1 >> k2;
        a.push_back(make_pair(k1,k2));
    }
    cout << sizeof(t) << endl;
    cout << f(n-1,m) << endl;
/*
    for(i=0;i<n;i++){
        for(j=0;j<m+1;j++){
            cout << t[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
*/
    return 0;
}
