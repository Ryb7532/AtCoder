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
    Mo(int n, int q) : width((int)sqrt(n)), order(q), v(n) {
      rep(i,q) order[i] = i;
    }

    // add a query on [l,r)
    void add(int l, int r) {
      left.push_back(l);
      right.push_back(r);
    }

    // calcurate queries
    int run(const ADD &add, const DEL &del, const REM &rem) {
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
