#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


// Mo's Algorithm (Query Square Root Decomposition)
// Constraints:
// 1. constant array
// 2. read-ahead queries
// 3. interval can be stretched / shrunk by O(1)
class Mo {
  using ADD = function<void(int)>;
  using DEL = function<void(int)>;
  using REM = function<void(int)>;
  int width;
  vector<int> left, right, order;
  vector<bool> v;

  public:
    Mo(int n, int q) : width((int)sqrt(n)), order(q), v(n) {
      rep(i,q) order[i] = i;
    }

    // add a query on [l,r)
    void add(int l, int r) {
      left.push_back(l);
      right.push_back(r);
    }

    // calcurate queries
    void run(const ADD &add, const DEL &del, const REM &rem) {
      assert(left.size() == order.size());
      sort(all(order), [&](int a, int b) {
        int ablock = left[a]/width, bblock = left[b]/width;
        if (ablock != bblock) return ablock < bblock;
        if (ablock & 1) return right[a] < right[b];
        return right[a] > right[b];
      });
      int nl = 0, nr = 0;
      auto push = [&](int idx) {
        v[idx].flip();
        if (v[idx]) add(idx);
        else del(idx);
      };
      for (auto idx: order) {
        while (nl > left[idx]) push(--nl);
        while (nr < right[idx]) push(nr++);
        while (nl < left[idx]) push(nl++);
        while (nr > right[idx]) push(--nr);
        rem(idx);
      }
    }
};


int main() {
  int N,Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
    A[i]--;
  }
  Mo mo(N,Q);
  rep(i,Q) {
    int l,r;
    cin >> l >> r;
    mo.add(--l, r);
  }
  ll r = 0;
  vector<ll> res(Q);
  vector<ll> cnt(2e5, 0);
  auto add = [&](int idx) {
    ll c = cnt[A[idx]];
    r += c * (c-1) / 2;
    cnt[A[idx]]++;
  };
  auto del = [&](int idx) {
    ll c = --cnt[A[idx]];
    r -= c * (c-1) / 2;
  };
  auto rem = [&](int idx) {
    res[idx] = r;
  };
  mo.run(add, del, rem);
  rep(i,Q) {
    print(res[i]);
  }
  return 0;
}
