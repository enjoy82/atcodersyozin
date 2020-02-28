#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int t1, t2, f; cin >> t1 >> t2;
    ll a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    ll ans = 0;
    if(a1 + a2 == b1 + b2){
        cout << "infinity" << endl;
        return 0; 
    }
    if(a1 > b1){
        f = 1;
    }else{
        f = 2;
    }
    ll mid1 = t1*a1+t2*a2, mid2 = t1*b1 + t2*b2;
    if(mid1 > mid2){
        /*if(f == 1){
            cout << 0 << endl;
            return 0;
        }*/
        ll dif = mid1 - mid2;
        ll dif2 = abs(a1-b1);
        cout << dif << " " << dif2 << endl;
        cout << dif2 / dif + 1 << endl;
    }else{
        /*if(f == 2){
            cout << 0 << endl;
            return 0;
        }*/
        ll dif = mid2 - mid1;
        ll dif2 = abs(a1-b1);
        cout << dif << " " << dif2 << endl;
        cout << dif2 / dif + 1 << endl;
    }
}