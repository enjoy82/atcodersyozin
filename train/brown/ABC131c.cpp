#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n; cin >> n;
    vector<vector<ll> > a(n, vector<ll>(2, 0)); 
    for(int i = 0; i < n; i++){
        ll b, c; cin >> b >> c;
        a[i][0] = b;
        a[i][1] = c;
    }
    cout << " 3"<< endl;
    sort(a.begin(), a.end(), [](auto& x, auto& y){return x.second <= y.second;});
    cout << " 1 " << endl;
    ll time = 0;
    for(int i = 0; i< n; i++){
        time += a[i][0];
        if(time > a[i][1]){
            cout << "No" << endl;
            cout << time <<" " << a[i][0] << endl;
            return 0;
        }
        cout << time <<" " << a[i][0] << endl;
    }
    cout << "Yes" << endl;
   
    return 0;
}