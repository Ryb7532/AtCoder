#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
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
    Mo(int n, int q) : width(max<int>(1, n/sqrt(q))), order(q), v(n) {
      rep(i,q) order[i] = i;
    }

    // add a query on [l,r)
    void add(int l, int r) {
      left.emplace_back(l);
      right.emplace_back(r);
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
      for (auto idx: order) {
        while (nl > left[idx]) add(--nl);
        while (nr < right[idx]) add(nr++);
        while (nl < left[idx]) del(nl++);
        while (nr > right[idx]) del(--nr);
        rem(idx);
      }
    }
};


vector<int> A;
ll p = 0;
vector<int> cnt(1e5+1,0);
vector<ll> res;

void add(int i) {
  int a = A[i];
  if (cnt[a]%2)
    p++;
  cnt[a]++;
}

void del(int i) {
  int a = A[i];
  cnt[a]--;
  if (cnt[a]%2)
    p--;
}

void rem(int i) {
  res[i] = p;
}


int main() {
  int N,Q;
  cin >> N;
  A.resize(N);
  rep(i,N) {
    cin >> A[i];
  }
  cin >> Q;
  res.resize(Q);
  Mo mo(N,Q);
  rep(_,Q) {
    int l,r;
    cin >> l >> r;
    mo.add(--l,r);
  }
  mo.run(add, del, rem);
  rep(i,Q) {
    print(res[i]);
  }
  return 0;
}
