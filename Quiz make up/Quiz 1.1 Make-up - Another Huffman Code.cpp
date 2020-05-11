#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,i;
    long long t,k;
    priority_queue< long long ,vector< long long >, greater< long long > > a;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> t ;
        a.push(t)  ;
    }
    long long ans1,ans2;
    while(a.size()>1){
        ans1=a.top();
        a.pop();
        ans2=a.top();
        a.pop();
        a.push(ans1*2+ans2*2); 
    }
    cout << a.top() << endl;
 
    system("Pause");
    return 0;
}