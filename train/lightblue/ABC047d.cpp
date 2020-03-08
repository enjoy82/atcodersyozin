#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, t; cin >> n >> t;
    vector<ll> lis(n, 0);
    priority_queue<ll, vector<ll>, greater<ll>>  pq;
    ll a; cin >> a;
    pq.push(a);
    ll dif = 0, count = 0;
    for(int i = 1; i < n; i++){
        ll mid; cin >> mid;
        ll k = pq.top();
        if(dif < mid - k){
            dif = mid - k;
            count = 1;
        }else if(dif == mid - k){
            count++;
        }
        pq.push(mid);
    }
    cout << count << endl;
}