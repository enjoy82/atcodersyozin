#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s; cin >> s;
    string st, fi = "";
    string make;
    string c = "keyence";
    for(int i = 0; i < s.size(); i++){
        for(int l = 1; l <= 7 && i+l < s.size(); l++){
            st = s.substr(i, l);
            for(int m = i+l; m < s.size(); m++){
                if(i == 0){
                    fi = s.substr(m, 7-l);
                    make = st + fi;
                    if(make == c){
                        if(m == i+l){
                            cout << "YES" << endl;
                            return 0;
                            return 0;
                        }else{
                            if(m + 7 - l == s.size()){
                                cout << "YES" << endl;
                                return 0;
                            }
                        }
                    }
                }else{
                    fi = s.substr(i+l, 7-l);
                    make = st + fi;
                    if(make == c && i+7 == s.size()){
                        cout << "YES" << endl;
                        return 0;
                    }
                }
                fi = "";
            }
            st = "";
        }
    }
    cout << "NO" << endl; 
    return 0;
}