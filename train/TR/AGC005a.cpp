#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s; cin >> s;
    int size = s.size();
    int a = 0;
    int dif = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == 'S'){
            a++;
        }else{
            if(a > 0){
                a--;
                dif += 2;
            }
        }
    }
    cout << size - dif << endl;
    return 0;
}