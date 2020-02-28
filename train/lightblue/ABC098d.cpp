#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int ch(vector<int> li){
    for(int i = 0; i < 23; i++){
        if(li[i] >= 2){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n; cin >> n;
    vector<vector<int> >lis(n, vector<int>(23, 0));
    for(int i = 0; i < n; i++){
        ll k; cin >> k;
        int c = 0;
        while(k > 0){
            lis[i][c] = k % 2;
            k = k / 2;
            c++;
        }
    }
    vector<int>check(23, 0);
    int ans = n, s = 0, t = 0;
    for(;;){
        t = max(s, t);
        while(t < n && ch(check) == 1){
            for(int l = 0; l < 23; l++){
                check[l] += lis[t][l];
            }
            if(ch(check) == 1){
                t++;
            }else{
                break;
            }
        }
        for(int l = 0; l < 23; l++){
            check[l] -= lis[s][l];
        }
        ans += max(0, (t-1) - s);
        cout << s << " " << t << endl;
        cout << ans << endl;
        s++;
        if(s == n){break;}
    }
    cout << ans << endl;
}