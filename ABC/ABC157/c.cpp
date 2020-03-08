#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> lis1(10, 0), lis2(10,0), lis3(10, 0);
    for(int i = 0; i < m; i++){
        int s, c; cin >> s >> c;
        if(s == 1){
            lis1[c]++;
        }else if(s == 2){
            lis2[c]++;
        }else{
            lis3[c]++;
        }
    }
    if(n != 1){
        if(lis1[0] > 0){
            cout << -1 << endl;
            return 0;
        }
    }
    int f = 0, f1 = 0, f2 = 0;
    if(n == 1){
        for(int i = 0; i < 10; i++){
            if(lis1[i] > 0){
                f++;
            }
        }
        if(f > 1){
            cout << -1 << endl;
            return 0;
        }
        for(int i = 0; i < 10; i++){
            if(lis1[i] > 0){
                cout << i << endl;
                return 0;
            }
        }
        cout << 0;
        return 0;
    }
    else if(n == 2){
        for(int i = 0; i < 10; i++){
            if(lis1[i] > 0){
                f++;
            }
            if(lis2[i] > 0){
                f1++;
            }
        }
        if(f > 1 || f2 > 1){
            cout << -1 << endl;
            return 0;
        }
        for(int i = 0; i < 10; i++){
            if(lis1[i] > 0){
                cout << i;
            }
        }
        if(f == 0){
            cout << 1;
        }
        for(int i = 0; i < 10; i++){
            if(lis2[i] > 0){
                cout << i;
                return 0;
            }
        }
        if(f1 == 0){
            cout << 0;
        }
        return 0;
    }
    else{
        for(int i = 0; i < 10; i++){
            if(lis1[i] > 0){
                f++;
            }
            if(lis2[i] > 0){
                f1++;
            }
            if(lis3[i] > 0){
                f2++;
            }
        }
        if(f > 1 || f1 > 1 || f2 > 1){
            cout << -1 << endl;
            return 0;
        }
        for(int i = 0; i < 10; i++){
            if(lis1[i] > 0){
                cout << i;
            }
        }
        if(f == 0){
            cout << 1;
        }
        for(int i = 0; i < 10; i++){
            if(lis2[i] > 0){
                cout << i;
            }
        } 
        if(f1 == 0){
            cout << 0;
        }
        for(int i = 0; i < 10; i++){
            if(lis3[i] > 0){
                cout << i;
            }
        } 
        if(f2 == 0){
            cout << 0;
        }
        return 0;
    }
}