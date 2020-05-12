#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int construct(int a[],int* b,int l,int r,int now){
    if(l==r){
        b[now]=a[l];
        return a[l];
    }
    int mid=(l+r)/2;
    b[now]=construct(a,b,l,mid,now*2+1)+construct(a,b,mid+1,r,now*2+2);
    return b[now];
}

void updatevalue(int *b,int l,int r,int now,int diff,int i){
    if(i<l||i>r){
        return ;
    }
    b[now]+=diff;
    if(l!=r){
        int mid=(l+r)/2;
        updatevalue(b,l,mid,now*2+1,diff,i);
        updatevalue(b,mid+1,r,now*2+2,diff,i);
    }
}

int getvalue(int *b,int l,int r,int askl,int askr,int now){
    if(askl<=l&&askr>=r){
        return b[now];
    }
    if(askl>r||askr<l){
        return 0;
    }
    int mid=(l+r)/2;
    return getvalue(b,l,mid,askl,askr,now*2+1)+getvalue(b,mid+1,r,askl,askr,now*2+2);
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n,i;
    int t;
    while(cin >> n){
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        int *b=new int[2*n+1];
        for(i=0;i<2*n+1;i++){
            b[i]=0;
        }
        construct(a,b,0,n-1,0);
        for(i=0;i<2*n+1;i++){
            cout << b[i] << " ";
        }
        cout << endl;
        int m;
        cin >> t >> m;
        int diff;
        diff=m-a[t];
        cout << diff << endl;
        a[t]=m;
        updatevalue(b,0,n-1,0,diff,t);
        for(i=0;i<2*n+1;i++){
            cout << b[i] << " ";
        }
        int l,r;
        while(cin >> l >> r){
            cout << getvalue(b,0,n-1,l,r,0) << endl;
        }
        cout << endl;
    }
    return 0;
}

