#include <bits/stdc++.h>
#define  ll  long long

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
    ll N,n,w;
    cin >> N >> n >> w ;
    point a[N+1];
    int i;
    for(i=0;i<=N;i++){
        a[i].length=1;
        a[i].p=&a[i];
        a[i].x=i;
    }
    ll t,k,m;
    priority_queue< pair<ll,pair<ll,ll> >, vector< pair<ll,pair<ll,ll> > > , greater< pair<ll,pair<ll,ll> > > > v;
    for(i=0;i<n;i++){
        cin >> t >> k >> m;
        v.push(make_pair(m,make_pair(t,k) ) );
    }
    pair<ll,pair<ll,ll> > ti;
    ll ch=0,ans=0;
    while(v.size()!=0){
        ti=v.top();
        v.pop();
        if(ti.first<=w){
            if(find(&a[ti.second.first])!=find(&a[ti.second.second])){
                ch++;
                ans+=ti.first;
                Union(&a[ti.second.first],&a[ti.second.second]);
            }
        }
        else{
            ans=ans+(N-1-ch)*w;
            ch=N-1;
            break;
        }
        if(ch==N-1){
            break;
        }
    }
    if(ch<N-1){
        ans=ans+(N-1-ch)*w;
    }
    cout << ans << '\n';
    return 0;

}