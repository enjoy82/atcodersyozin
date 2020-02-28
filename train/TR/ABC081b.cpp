#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    int ans = 100000000;
    for(int i = 0; i < n; i++){
        int count = 0;
        int mid;
        cin >> mid;
        while(mid % 2 == 0){
            mid = mid / 2;
            count++;
        }
        ans = min(count, ans);
    }
    cout << ans << endl;
}