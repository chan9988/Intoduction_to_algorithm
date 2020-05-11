#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long construct(long long a[],long long* b,long long l,long long r,long long now){
    if(l==r){
        b[now]=a[l];
        return a[l];
    }
    long long mid=(l+r)/2;
    b[now]=max(construct(a,b,l,mid,now*2+1),construct(a,b,mid+1,r,now*2+2));
    return b[now];
}

long long updatevalue(long long *b,long long l,long long r,long long now,long long j,long long k){
    if(j>=l&&j<=r){
        if(l!=r){
            long long mid=(l+r)/2;
            b[now]=max(updatevalue(b,l,mid,now*2+1,j,k),updatevalue(b,mid+1,r,now*2+2,j,k));
        }
        if(l==r){
            b[now]=k;
        }
        return b[now];
    }
    return b[now];

}

long long getvalue(long long *b,long long l,long long r,long long askl,long long askr,long long now){
    if(askl<=l&&askr>=r){
        return b[now];
    }
    if(askl>r||askr<l){
        return -10000000001;
    }
    long long mid=(l+r)/2;
    return max(getvalue(b,l,mid,askl,askr,now*2+1),getvalue(b,mid+1,r,askl,askr,now*2+2));
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    long long a[n+5];
    long long i,j,k;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    long long x;
    x=(long long)(ceil(log2(n)));
    long long *b=new long long[2*(long long)pow(2,x)+1];
    construct(a,b,0,n-1,0);
     while(m--){
        cin >> i >> j >> k;
        if(i==1){
            updatevalue(b,0,n-1,0,j,k);
        }
        else if(i==2){
            cout << getvalue(b,0,n-1,j,k,0) << endl;
        }
     }

    return 0;
}

