#include <iostream>
#include <string>
using namespace std;

string b = "tokyo";
string c = "kyoto";
int syori(string a, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(a[i]=='t'){
            for(int l = 1; l < 5; l++){
                if(b[l] != a[i+l]){
                    break;
                }
                if(l == 4){
                    count += 1;i+=4;
                }
            }
        }else if(a[i]=='k'){
            for(int l = 1; l < 5; l++){
                if(c[l] != a[i+l]){
                    break;
                }
                if(l == 4){
                    count += 1;i+=4;
                }
            }
        }
    }
    cout << count << endl;
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        syori(a, a.length());
    }
    return 0;
}