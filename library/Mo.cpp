#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()


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
    Mo(int n, int q) : width(max<int>(1, n/max(1.0, sqrt(q*2.0/3.0)))), order(q), v(n) {
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
