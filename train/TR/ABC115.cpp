#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 100000000

int main(){
    int n, k; cin >> n >> k;
    vector<int> lis(n);
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        lis[i] = mid;
    }
    sort(lis.begin(), lis.end());
    int a = 1, b = k;
    int ans = lis[b-1] - lis[a-1];
    int ans1 = ans;
    while(1){
        if(b == n){break;}
        int ans1 = lis[b] - lis[a];
        ans = min(ans, ans1);
        a++;
        b++;
    }
    cout << ans << endl;
}