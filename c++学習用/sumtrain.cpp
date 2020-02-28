# include<iostream>
# include<vector>
using namespace std;

int n,a;
vector<int> ans_list;
vector<vector <int>> DP;
vector<vector <int>> node;

int maxa(vector<int> a, int size){
    int ma = 0;
    for(int i =0; i < size; i++){
        if(a[i] > ma){
            ma = a[i];
        }
    }
    return ma;
}

int path(int count,int ans,int pos){
  if(count == a){
    ans_list.push_back(ans);
  }else{
    ans = ans + node[count][pos];
    if(ans > DP[count][pos]){
    DP[count][pos] = ans;
    path(count+1, ans, pos);
    path(count+1, ans, pos+1);
    }
  }
}

int main(){
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> a;
    ans_list = vector<int>(a, 0);
    DP = vector<vector <int>>(a, vector<int>(a, 0));
    node = vector<vector<int>>(a, vector<int>(a, 0));
    for(int l = 0; l < a; l++){
      for(int m =0; m <= l; m++){
        cin >> node[l][m];
      }
    }
    path(0, 0, 0);
    cout << maxa(ans_list, ans_list.size()) << endl;
  }
}