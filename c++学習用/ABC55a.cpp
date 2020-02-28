#include <iostream>
using namespace std;
int main(){
    int i;
    cin >> i;
    int ans = 800 * i - 200 * int(i/15);
    cout << ans << endl;
    return 0;
}