#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    long long int a = -1,b = -1 ,c = -1;
    int count = 0;
    int ac = 0, bc = 0, cc = 0;
    for(int i = 0 ;i<n; i++){
        int mid;cin >> mid;
        if(mid == a){ac++;}
        if(mid == b){bc++;}
        if(mid == c){cc++;}
        if(a == -1){a = mid;count++;ac++;}
        else if(b == -1 && mid != a){b = mid;count++;bc++;}
        else if(c == -1 && mid != b && mid != a){c = mid;count++;cc++;}
        else if(mid != a && mid != b && mid != c){cout << "No" << endl; count++;return 0;}
    }
    if(count == 1){
        if(a == 0){
            cout << "Yes" << endl; return 0;
        }else{
            cout << "No" << endl; return 0;
        }
    }else if(count == 2){
        if(a*b != 0){cout << "No" << endl; return 0;}
        else if(a == 0){
            if(2 * ac == bc){cout << "Yes" << endl; return 0;}
        }else if(b == 0){
            if(2 *bc == ac){cout << "Yes" << endl; return 0;}
        }
        cout << "No" << endl; return 0;
    }else if(count == 3){
        if(ac == bc && bc == cc){    
        }else{cout << "No" << endl; return 0;}
        while(a != 0 || b != 0 || c != 0){
            int a1 = a%2;
            int b1 = b%2;
            int c1 = c%2;
            a = a/2;b = b/2;c = c/2;
            if((a1 == 0 && b1 == 1 && c1 == 1)||(a1 == 1 && b1 == 1 && c1 == 0)||(a1 == 1 && b1==0 && c1 ==1) || (a1 == 0 && b1 == 0 && c1 == 0)){}
            else{cout << "No" << endl; return 0;}
        }
    }
    cout << "Yes" << endl;
}