#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, h; cin >> n >> h;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int max = a[0];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int mid = b[i];
        if(h <= 0){
            break;
        }
        if(mid < max){
            break;
        }
        h -= mid;
        ans++;
    }
    if(h <= 0){
        cout << ans << endl;
        return 0;
    }
    if(h % max == 0){
        ans += (h / max);
    }else{
        ans += (h/max) + 1;
    }
    cout << ans << endl;
}