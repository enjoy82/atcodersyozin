#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int check(vector<string>&list, string a){
    for(int i = 0; i < list.size(); i++){
        if(list[i] == a){
            return -1;
        }
    }
    return 1;
}

int main(){
    vector<string> list;
    string s; cin >> s;
    int k; cin >> k;
    for(int i = 0; i < s.size(); i++){
        string a;
        for(int l = 0; l < k; l++){
            if(l+i == s.size()){
                break;
            }
            a.push_back(s[i+l]);
            if(check(list, a) == 1){
                list.push_back(a);
            }
        }
    }
    sort(list.begin(), list.end());
    /*for(int i = 0; i < list.size(); i++){
        cout << list[i] << endl; 
    }
    cout << endl;*/
    cout << list[k-1] << endl;
}