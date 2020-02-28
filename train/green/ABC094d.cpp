#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<double> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = a[n-1];
    double b = ans*1.00 / 2;
    double mid = 1000000009;
    int ans2;
    for(int i = 0; i < n; i++){
        if(mid > abs(a[i] - b)){
            ans2 = a[i];
            mid = abs(a[i] - b);
        }
    }

    cout << ans << " " << ans2 << endl;
}