#include <iostream>
using namespace std;

int main(){
    double x, y, c;
    cin >> x >> y;    
    while(x <= y){   
        x = x * 2;
        c +=1;
    }
    cout << c << endl;
}