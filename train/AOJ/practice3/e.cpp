#pragma region Macros
#include <bits/stdc++.h>
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int(i) = (n)-1; (i) >= 0; (i)--)
#define FOR(i, m, n) for (int(i) = (m); (i) < (n); (i)++)
#define ROF(i, m, n) for (int(i) = (n)-1; (i) >= (m); (i)--)
#define ALL(v) (v).begin(), (v).end()
#define LLA(v) (v).rbegin(), (v).rend()
#define SZ(v) (int)(v).size()
#define INT(...)     \
    int __VA_ARGS__; \
    read(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    read(__VA_ARGS__)
#define DOUBLE(...)     \
    double __VA_ARGS__; \
    read(__VA_ARGS__)
#define CHAR(...)     \
    char __VA_ARGS__; \
    read(__VA_ARGS__)
#define STRING(...)     \
    string __VA_ARGS__; \
    read(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    read(name)
#define VEC2(type, name, height, width)                     \
    vector<vector<type>> name(height, vector<type>(width)); \
    read(name)
#define DVEC(type, name1, name2, size)     \
    vector<type> name1(size), name2(size); \
    read(name1, name2);
#define TVEC(type, name1, name2, name3, size)           \
    vector<type> name1(size), name2(size), name3(size); \
    read(name1, name2, name3);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;
const char newl = '\n';
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
template <class T>
inline bool between(T x, T l, T r) { return l <= x && x < r; }
template <class T>
inline vector<T> make_vec(size_t a, T val) { return vector<T>(a, val); }
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec(ts...))>(a, make_vec(ts...)); }
void read() {}
template <class T>
inline void read(T &a) { cin >> a; }
template <class T, class S>
inline void read(pair<T, S> &p) { read(p.first), read(p.second); }
template <class T>
inline void read(vector<T> &v)
{
    for (auto &&a : v)
        read(a);
}
template <class T, class U>
inline void read(vector<T> &a, vector<U> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        read(a[i]);
        read(b[i]);
    }
}
template <class T, class U, class V>
inline void read(vector<T> &a, vector<U> &b, vector<V> &c)
{
    for (int i = 0; i < a.size(); i++)
    {
        read(a[i]);
        read(b[i]);
        read(c[i]);
    }
}
template <class Head, class... Tail>
inline void read(Head &head, Tail &...tail) { read(head), read(tail...); }
template <class T>
void write(const T &a) { cout << a << '\n'; }
template <class T>
void write(const vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
}
template <class Head, class... Tail>
void write(const Head &head, const Tail &...tail)
{
    cout << head << ' ';
    write(tail...);
}
template <class T>
void writel(const T &a) { cout << a << '\n'; }
template <class T>
void writel(const vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << '\n';
}
template <class Head, class... Tail>
void writel(const Head &head, const Tail &...tail)
{
    cout << head << '\n';
    write(tail...);
}
template <class T>
auto sum(const vector<T> &a) { return accumulate(ALL(a), T(0)); }
template <class T>
auto min(const vector<T> &a) { return *min_element(ALL(a)); }
template <class T>
auto max(const vector<T> &a) { return *max_element(ALL(a)); }
template <class T, class U>
void msort(vector<T> &a, vector<U> &b)
{
    assert(a.size() == b.size());
    vector<pair<T, U>> ab(a.size());
    for (int i = 0; i < a.size(); i++)
        ab[i] = {a[i], b[i]};
    sort(ALL(ab));
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = ab[i].first;
        b[i] = ab[i].second;
    }
}
template <class T, class U, class V>
void msort(vector<T> &a, vector<U> &b, vector<V> &c)
{
    assert(a.size() == b.size() && b.size() == c.size());
    vector<tuple<T, U, V>> abc(a.size());
    for (int i = 0; i < a.size(); i++)
        abc[i] = {a[i], b[i], c[i]};
    sort(ALL(abc));
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = get<0>(abc[i]);
        b[i] = get<1>(abc[i]);
        c[i] = get<2>(abc[i]);
    }
}
template <class T, class U>
inline bool chmax(T &a, U b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T, class U>
inline bool chmin(T &a, U b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
inline int bsf(int v) { return __builtin_ctz(v); } // 最下位の1が下から何番目か
inline int bsf(ll v) { return __builtin_ctzll(v); }
inline int bsr(int v) { return 31 - __builtin_clz(v); } // 最上位の1が下から何番目か
inline int bsr(ll v) { return 63 - __builtin_clzll(v); }
inline int lsb(int v) { return v & -v; } // 最上位の1だけ残す
inline ll lsb(ll v) { return v & -v; }
inline int msb(int v) { return 1 << bsr(v); } // 最上位の1だけ残す
inline ll msb(ll v) { return 1LL << bsr(v); }
struct IO
{
    IO()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} io;
#pragma endregion

void out_table(vector<vector<int>> &vv)
{
    cerr << "======" << endl;
    for (auto v : vv)
    {
        cerr << "[ ";
        for (auto c : v)
        {
            cerr << c << " ";
        }
        cerr << " ]" << endl;
    }
}

void solve()
{
    int n;
    while (cin >> n, n)
    {
        int m;
        cin >> m;
        vector<vector<int>> table(n, vector<int>(n));
        rep(i, m)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            table[x][y] = 1;
            table[y][x] = -1;
        }
        int res = 0;
        auto dfs = [&](auto &&dfs, int team, vector<vector<int>> table)
        {
            // out_table(table);
            if (team == n)
            {
                res++;
                return;
            }
            vector<int> no_match;
            for (int i = team + 1; i < n; i++)
            {
                if (table[team][i] == 0)
                {
                    no_match.push_back(i);
                }
            }
            int match_num = no_match.size();

            for (int bit = 0; bit < (1 << match_num); bit++)
            {
                vector<int> win, lose;
                rep(i, match_num)
                {
                    if (bit & 1 << i)
                    {
                        win.push_back(no_match[i]);
                    }
                    else
                    {
                        lose.push_back(no_match[i]);
                    }
                }
                for (auto d : win)
                {
                    table[team][d] = 1;
                    table[d][team] = -1;
                }
                for (auto d : lose)
                {
                    table[team][d] = -1;
                    table[d][team] = 1;
                }
                int wcount = 0;
                rep(i, n)
                {
                    if (table[team][i] == 1)
                        wcount++;
                }
                if (wcount == n / 2)
                {
                    dfs(dfs, team + 1, table);
                }
            }
        };
        dfs(dfs, 0, table);
        cout << res << endl;
    }
}

int main()
{
    // INT(t);
    int t = 1;
    while (t--)
    {
        solve();
    }
}