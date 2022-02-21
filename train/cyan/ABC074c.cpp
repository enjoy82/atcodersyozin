#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans1 = 100*a, ans2 = 0;
    for(int i = 1; i < f / 100; i++){
        int flag = 0;
        for(int l = 0; l*a <= i; l++){
            for(int m = 0; l*a+m*b <= i; m++){
                if(l*a+m*b == i){
                    flag = 1;
                }else{
                    continue;
                }
            }
        }
        if(flag == 0){
            continue;
        }
        int water = 100*i, sugar = 0;
        int maxs = min(e*i, f - i*100);
        for(int l = 0; l * c <= maxs; l++){
            for(int m = 0; l*c + m*d <= maxs; m++){
                sugar = l*c+m*d;
                if(ans2*(sugar+water) < sugar * ans1){
                    ans1 = water + sugar;
                    ans2 = sugar;
                }
            }
        }
    }
    cout << ans1 << " " <<  ans2 << endl;
}