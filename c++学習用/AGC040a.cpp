#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string a; cin >> a;
    vector<ll> lis(a.size()+2, 0);
    lis[0] = 0;
    int count = 0;
    ll check = 0;
    ll ans = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '<'){
            count = 0;
            lis[i+1] = lis[i] + 1;
            ans += lis[i+1];
        }else{
            count++;
            if(lis[i] == 0){
                if(check >= count){
                    ans+=count-1;
                }else{
                    ans+=count;
                }
            }else{
                check = lis[i];
            }
            lis[i+1] = 0;
        }
        //cout << a[i] <<count   << "ans is"<< ans << endl;
    }
    cout << ans << endl;
}