#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long *b;

long long merges(long long l,long long r){
    if(l==r){
        return 0;
    }
    long long sum,m;
    m=(l+r)/2;
    sum=merges(l,m);
    sum+=merges(m+1,r);
    int i,j,k=0;
    long long a[r-l+5];
    for(i=l,j=m+1;i<=m&&j<=r;){
        if(b[i]<=b[j]){
            a[k]=b[i];
            i++;
            k++;
        }
        else{
            a[k]=b[j];
            sum+=(j-l-k);
            j++;
            k++;
        }
    }
    for(;i<=m;i++){
        a[k]=b[i];
        k++;
    }
    for(;j<=r;j++){
        a[k]=b[j];
        k++;
    }
    for(i=l,k=0;i<=r;i++,k++){
        b[i]=a[k];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    b=new long long[n];
    int i;
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    cout << merges(0,n-1) << '\n';
    return 0;
}
