#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++){
        ll mid; cin >> mid;
        pq.push(mid);
    }
    for(int i = 0; i < m; i++){
        ll k = pq.top() / 2;
        pq.pop();
        pq.push(k);
    }
    ll sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
}