#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 100000000

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        a[i] = mid;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int count1 = 0;
    int b = a[0];
    for(int i = 1; i < n; i++){
        if(b == a[i]){

        }else{
            ans++;
            b = a[i];
        }
    }
    ans++;
    if(ans%2 == 0){
        ans--;
    }
    cout << ans << endl;
}