#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct point{
    ll num,time;
    point *p;
};

point **v;
bool *ch;
ll max1=0;

ll DFS(ll ind){
    ch[ind]=true;
    ll ma1=0,ma2=0;
    ll s=0,s1;
    while(v[ind]!=NULL){
        if(ch[v[ind]->num]==false){
            s1=DFS(v[ind]->num);
            s1+=v[ind]->time;
            if(s1>s){
                s=s1;
            }
            if(s1>=ma1){
                ma2=ma1;
                ma1=s1;
            }
            else if(ma1>=s1&&s1>=ma2){
                ma2=s1;
            }
        }
        v[ind]=v[ind]->p;
    }
    if(ma1+ma2>=max1){
        max1=(ma1+ma2);
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    ll a,b,l,sum=0;
    int i;
    v=new point*[n+1];
    ch=new bool[n+1];
    for(i=0;i<=n;i++){
        v[i]=NULL;
        ch[i]=false;
    }
    point *n1,*n2;
    for(i=0;i<n-1;i++){
        cin >> a >> b >> l;
        sum+=l;
        n1=new point;
        n1->num=b;
        n1->time=l;
        n1->p=v[a];
        v[a]=n1;
        n2=new point;
        n2->num=a;
        n2->time=l;
        n2->p=v[b];
        v[b]=n2;
    }
    ll tr;
    for(i=1;i<=n;i++){
        if(v[i]->p==NULL){
            tr=DFS(i);
            break;
        }
    }
    if(tr>=max1){
        cout << sum*2-tr << '\n';
    }
    else{
        cout << sum*2-max1 << '\n';
    }    
    return 0;
}