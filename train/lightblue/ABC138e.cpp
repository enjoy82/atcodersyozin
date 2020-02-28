#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    string s, t; cin >> s >> t;
    vector<vector<int> > lis(s.size(), vector<int>(26, s.size()*3));
    vector<vector<int> > alpha(26);
    for(int i = 0; i < s.size(); i++){
        alpha[s[i]-'a'].push_back(i+1);
    }
    if(alpha[t[0]-'a'].size() == 0){
        cout << -1 << endl;
        return 0;
    }
    ll ans = alpha[t[0]-'a'][0];
    int num = alpha[t[0]-'a'][0];
    for(int i = 1; i < t.size(); i++){
        if(alpha[t[i]-'a'].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        auto ind = lower_bound(alpha[t[i]-'a'].begin(), alpha[t[i]-'a'].end(), ans % t.size());
        if(alpha[t[i]-'a'][alpha[t[i]-'a'].size()-1] < ans%s.size()){
            ans = (ans/s.size()+1) * s.size() + alpha[t[i]-'a'][0];
            num = alpha[t[i]-'a'][0];
        }else{
            ans += *ind - num;
            num = *ind;
        }
    }
    cout << ans << endl;
}