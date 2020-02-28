#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class minus{
public:
    int cost;
    int sa;
    bool operator< (const minus &m1, const minus &m2){
    return m1.cost < m2.cost;
}
};


int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    sort(a.begin(), a.end());
    priority_queue<minus> q;
    for(int i = 0; i < n; i++){
        q.push(a[i]*b[i], b[i]);
    }
    for(int i = 0; i < min(k, n); i++){
        minus m = q.top();
        q.pop;
        m.cost = m.cost - m.sa;
        q.push(m);
    }
    cout << q.top().cost() << endl;
}