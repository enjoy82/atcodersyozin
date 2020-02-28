#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int n; cin >> n;
    vector<vector<ll> > lis(n, vector<ll>(2, 0));
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        lis[i][0] = a - b;
        lis[i][1] = a + b;
    }
    int count = 0;
    sort(lis.begin(), lis.end(), [](auto& x, auto& y){return x[1] < y[1];});
    for(int i = 0; i < n-1; i++){
        int d = 1;
        while(i+d < n && lis[i][1] > lis[i+d][0]){
            d++;
            count++;
        }
        i += d-1;
    }
    cout << n - count << endl;
}