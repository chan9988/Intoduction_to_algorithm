#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int **t;
vector<int> a;

int f(int n,int m){
    if(t[n][m]>0){
        return t[n][m];
    }
    else if(m<=0){
        return 0;
    }
    else{
        if(n==0){
            if(a[n]<=m){
                t[n][m]=a[n];
            }
            else{
                t[n][m]=0;
            }
        }
        else{
            if(a[n]>m){
                t[n][m]=f(n-1,m);
            }
            else{
                t[n][m]=max(f(n-1,m),a[n]+f(n-1,m-a[n]));
            }
        }
        return t[n][m];
    }
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n,sum=0,k,s;
    cin >> n;
    int i,j;
    for(i=0;i<n;i++){
        cin >> k;
        sum+=k;
        a.push_back(k);
    }
    s=sum;
    sum/=2;
    t=new int*[n];
    for(i=0;i<n;i++){
        t[i]=new int[sum+1];
    }
    for(i=0;i<n;i++){
        for(j=0;j<sum+1;j++){
            t[i][j]=0;
        }
    }
    cout << abs(s-2*f(n-1,sum)) << endl;
/*
    for(i=0;i<n;i++){
        for(j=0;j<sum+1;j++){
            cout << t[i][j] << " ";
        }
        cout <<endl;
    }
    cout << endl;
*/
    return 0;
}
