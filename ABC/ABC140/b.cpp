#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    int ans = 0;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        a[i] = mid;
    }
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        b[i] = mid;
    }
    for(int i = 0; i < n-1; i++){
        int mid; cin >> mid;
        c[i] = mid;
    }
    int d = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == d+1){
            ans += c[d-1];
        }
        d = a[i];
        ans += b[d-1];
        //cout << ans << endl;
    }  
    cout << ans << endl;
}