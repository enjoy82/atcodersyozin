#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1; i < x2; i++){
        cout << "R";
    }
    for(int i = y1; i < y2; i++){
        cout << "U";
    }
    for(int i = x2; i > x1; i--){
        cout <<"L";
    }
    for(int i = y2; i > y1; i--){
        cout << "D";
    }
    cout << "L";
    for(int i = y1; i < y2+1; i++){
        cout << "U";
    }
    for(int i = x1-1; i < x2; i++){
        cout << "R";
    }
    cout << "D";
    cout << "R";
    for(int i = y2; i > y1-1; i--){
        cout << "D";
    }
    for(int i = x2+1; i > x1; i--){
        cout << "L";
    }
    cout << "U";
    return 0;
}