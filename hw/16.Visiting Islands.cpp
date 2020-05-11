#include <bits/stdc++.h>
#define  ll   long long

using namespace std;

struct    point{
    point *p;
    ll length,x;
};


point *  find(point * a);

void Union (point *a1 , point  *b1){
        point *a,*b;
        a=find(a1);
        b=find(b1);
        if(a!=b){
            if(a->length<b->length){
                    b->length+=a->length;
                    a->p=b;    
            }
            else{
                    a->length+=b->length;
                    b->p=a;
            }
        }
}

point *  find(point * a){
    point  *ne;
    ne=a->p;
    if(a->x!=ne->x){
            a->p= find(ne);
    }
    return a->p;
}

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N,n;
    cin >> N >> n;
    point a[N+1];
    int i;
    for(i=0;i<=N;i++){
        a[i].length=1;
        a[i].p=&a[i];
        a[i].x=i;
    }
    ll t,k;
    for(i=0;i<n;i++){
        cin >> t >> k;
        Union(&a[t],&a[k]);
    }
    for(i=1;i<=N;i++){
        point *ans;
        ans=find(&a[i]);
        cout  <<  ans->length-1 << " ";
    }
    cout << '\n';
    return 0;

}