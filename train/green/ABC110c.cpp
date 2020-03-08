#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s, t; cin >> s >> t;
    vector<int> salpha(26, 0), talpha(26, 0);
    for(int i = 0; i < s.size(); i++){
        salpha[s[i]-'a']++;
        talpha[t[i]-'a']++;
    }
    vector<int> lis1(3*1e5, 0), lis2(3*1e5, 0);
    for(int i = 0; i < 26; i++){
        lis1[salpha[i]]++;
        lis2[talpha[i]]++;
    }
    for(int i = 0; i < lis1.size(); i++){
        if(!(lis1[i] == lis2[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}