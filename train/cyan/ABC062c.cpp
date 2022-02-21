#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll h, w; cin >> h >> w;
    ll ans1 = 10e11, ans2 = 10e11;
    for(int i = 1; i < h; i++){
        ll halfh = (h-i) / 2, halfw = w / 2, h2 = h - i;
        ll s1 = i * w;
        ll s2 = halfh * w;
        ll s3 = (h2 - halfh) * w;
        ll s4 = halfw * h2;
        ll s5 = (w - halfw) * h2;
        ll maxs1 = max(max(s1, s2), s3), mins1 = min(min(s1, s2), s3);
        ll maxs2 = max(max(s1, s4), s5), mins2 = min(min(s1, s4), s5);
        ans1 = min(min(abs(maxs1 - mins1), abs(maxs2 - mins2)), ans1);
    } 
    for(int i = 1; i < w; i++){
        ll halfh = h / 2, halfw = (w-i) / 2, w2 = w - i;
        ll s1 = i * h;
        ll s2 = halfh * w2;
        ll s3 = (h - halfh) * w2;
        ll s4 = halfw * h;
        ll s5 = (w2 - halfw) * h;
        ll maxs1 = max(max(s1, s2), s3), mins1 = min(min(s1, s2), s3);
        ll maxs2 = max(max(s1, s4), s5), mins2 = min(min(s1, s4), s5);
        ans2 = min(min(abs(maxs1 - mins1), abs(maxs2 - mins2)), ans2);
    }
    cout << min(ans1, ans2) << endl;
}