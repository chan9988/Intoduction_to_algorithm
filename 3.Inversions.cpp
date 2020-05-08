#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;

long long mergesort(long long a[],int r,int l){
//    cout << r << " " << l << " 123" << endl;
    long long sum=0;
    if(r>=l){
        return 0;
    }
    int m;
    m=(r+l)/2;
    sum+=mergesort(a,r,m);
    sum%=524287;
    sum+=mergesort(a,m+1,l);
    sum%=524287;
    int i,j,t;
    int b[l-r+1];
    t=0;
    for(i=r,j=m+1;!(i>m||j>l);){
        if(a[i]<=a[j]){
            b[t]=a[i];
            i++;
            t++;
        }
        else{
            b[t]=a[j];
            j++;
            t++;
            sum+=(m-i+1);
        }
    }
    if(i<=m){
        while(i<=m){
            b[t]=a[i];
            t++;
            i++;
        }
    }
    if(j<=l){
        while(j<=l){
            b[t]=a[j];
            t++;
            j++;
        }
    }
    for(i=r,j=0;i<=l;i++,j++){
        a[i]=b[j];
    }
//    cout << sum << " 12345" << endl;
    return sum%524287;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n;
    cin >> n;
    long long a[n];
    int i;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    long long ans;
    ans=mergesort(a,0,n-1);
/*
    for(i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
*/
    cout << ans <<endl;
    return 0;
}
