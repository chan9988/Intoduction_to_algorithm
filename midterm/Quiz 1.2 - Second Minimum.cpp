#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    long long n1,n2;
};

point *b;

point constuct(long long *a,long long l,long long r,long long n){
    if(l==r){
        b[n].n1=a[l];
        return b[n];
    }
    long long m;
    m=(l+r)/2;
    point pre1,pre2;
    pre1=constuct(a,l,m,n*2+1);
    pre2=constuct(a,m+1,r,n*2+2);
    vector<long long> ne;
    if(pre1.n1<=pre2.n1){
        b[n].n1=pre1.n1;
        if(pre2.n1<=pre1.n2){
            b[n].n2=pre2.n1;
        }
        else{
            b[n].n2=pre1.n2;
        }
    }
    else{
        b[n].n1=pre2.n1;
        if(pre1.n1<=pre2.n2){
            b[n].n2=pre1.n1;
        }
        else{
            b[n].n2=pre2.n2;
        }
    }
    return b[n];
}

point ask(long long al,long long ar,long long l,long long r,long long n){
    long long m;
    if(ar<l||al>r){
        point mm;
        mm.n1=10000000000;
        mm.n2=10000000000;
        return mm;
    }
    else if(al<=l&&r<=ar){
        return b[n];
    }
    point pre1,pre2;
    m=(l+r)/2;
    pre1=ask(al,ar,l,m,n*2+1);
    pre2=ask(al,ar,m+1,r,n*2+2);
    point ans;
    if(pre1.n1<=pre2.n1){
        ans.n1=pre1.n1;
        if(pre2.n1<=pre1.n2){
            ans.n2=pre2.n1;
        }
        else{
            ans.n2=pre1.n2;
        }
    }
    else{
        ans.n1=pre2.n1;
        if(pre1.n1<=pre2.n2){
            ans.n2=pre1.n1;
        }
        else{
            ans.n2=pre2.n2;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    long long a[n];
    int i;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    long long num;
    num=ceil(log2(n))+1;
    num=pow(2,num);
    b=new point[num];
    for(i=0;i<num;i++){
        b[i].n2=10000000000;
    }
    constuct(a,0,n-1,0);
    long long k1,k2;
    point pp;
    for(i=0;i<m;i++){
        cin >> k1 >> k2;
        pp=ask(k1,k2,0,n-1,0);
        cout << pp.n2 << '\n';
    }
    return 0;
}
