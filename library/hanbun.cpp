#include <bits/stdc++.h>
using namespace std;
int main() {
    // 入力
    int N, S;
    cin >> N >> S;
    vector<int> num(N);
    for (int i = 0; i < N; i++) {
        cin >> num.at(i);
    }
    // グループ１をビット全探索で全列挙 (前半の半分)
    vector<int> A;
    for (int bit = 0; bit < (1 << N / 2); bit++) {
        int sum = 0;
        for (int i = 0; i < (N / 2); i++) {
            int mask = 1 << i;
            if (bit & mask) {
                sum += num[i];
            }
        }
        A.push_back(sum);
    }
    // グループ2をビット全探索で全列挙 (後半の半分)
    vector<int> B;
    for (int bit = 0; bit < (1 << N / 2); bit++) {
        int sum = 0;
        for (int i = 0; i < (N / 2); i++) {
            int mask = 1 << i;
            if (bit & mask) {
                sum += num[N / 2 + i];
            }
        }
        B.push_back(sum);
    }
    sort(B.begin(), B.end());  // B をソート
    // A の要素を固定して二分探索
    int ans = 0;
    for (auto a : A) {
        if (S - a >= 0) {
            ans = max(ans, a + *(upper_bound(B.begin(), B.end(), S - a) - 1));
        }
    }
    cout << ans << endl;
    return 0;
}