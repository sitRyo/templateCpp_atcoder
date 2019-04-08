#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define fore(i, x) for (auto &i : n)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(i, n) for (int i = n; i >= 0; --i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int mod = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = LLONG_MAX / 2;
const static double eps = 1e-10;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0;}

char field[2001][2001];
int left_cnt[2001][2001], right_cnt[2001][2001], up_cnt[2001][2001], down_cnt[2001][2001];

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    rep(i, n) {
        string S;
        cin >> S;
        rep(j, m) {
            field[i][j] = S[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int cnt1 = 0;
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == '.') {
                left_cnt[i][j] = cnt1;
                ++cnt1;
            } else {
                cnt1 = 0;
            }
        }

        int cnt2 = 0;
        for (int j = m - 1; j >= 0; --j) {
            if (field[i][j] == '.') {
                right_cnt[i][j] = cnt2;
                ++cnt2;
            } else {
                cnt2 = 0;
            }
        }
    }

    cout << "left" << endl;
    for (int i = 0; i < n; ++i) {
      cout << endl;
      for (int j = 0; j < m; ++j) {
        cout << left_cnt[i][j] << " ";
      }
    }

    cout << endl;
    cout << "right" << endl;
    for (int i = 0; i < n; ++i) {
      cout << endl;
      for (int j = 0; j < m; ++j) {
        cout << right_cnt[i][j] << " ";
      }
    }

    for (int j = 0; j < m; ++j) {
        int cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            if (field[i][j] == '.') {
                up_cnt[i][j] = cnt1;
                ++cnt1;
            } else {
                cnt1 = 0;
            }
        }

        int cnt2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (field[i][j] == '.') {
                down_cnt[i][j] = cnt2;
                ++cnt2;
            } else {
                cnt2 = 0;
            }
        }
    }
    cout << "up" << endl;
    for (int i = 0; i < n; ++i) {
      cout << endl;
      for (int j = 0; j < m; ++j) {
        cout << up_cnt[i][j] << " ";
      }
    }
    cout << "down" << endl;
    for (int i = 0; i < n; ++i) {
      cout << endl;
      for (int j = 0; j < m; ++j) {
        cout << down_cnt[i][j] << " ";
      }
    }

    llong res = 0;
    rep(i, n) {
        rep(j, m) {
            if (field[i][j] == '.') {
                res += (left_cnt[i][j] + right_cnt[i][j]) * (up_cnt[i][j] + down_cnt[i][j]);
            }
        }
    }

    cout << res << endl;

    return 0;
}