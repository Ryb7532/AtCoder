#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,s,e) assert(s <= e); for (int i=s; i<(int)(e); i++)
#define repn(i,n) rep(i,0,n)
#define rrep(i,s,e) assert(s >= e); for (int i=s-1; i>=e; i--)
#define rrepn(i,n) rrep(i,n,0)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  ll N;
  cin >> N;
  vector<int> X(N), Y(N);
  repn(i,N) {
    cin >> X[i] >> Y[i];
  }
  ll obtuse = 0, right = 0, acute = N*(N-1)*(N-2)/6;
  repn(i,N) {
    vector<int> X_(N), Y_(N);
    vector<int> order;
    repn(j,N) {
      X_[j] = X[j] - X[i];
      Y_[j] = Y[j] - Y[i];
      if (i != j)
        order.push_back(j);
    }
    auto dot = [&](int a, int b) {
      return X_[a]*X_[b] + Y_[a]*Y_[b];
    };
    auto cross = [&](int a, int b) {
      return X_[a]*Y_[b] - Y_[a]*X_[b];
    };
    sort(all(order), [&](int a, int b) {
      return atan2(Y_[a], X_[a]) < atan2(Y_[b], X_[b]);
    });
    int id = 0, l = 0, r = 0;
    while (id < N-1) {
      while (cross(order[id],order[(r+1)%(N-1)]) > 0)
        r++;
      while (l < r && dot(order[id],order[(l+1)%(N-1)]) >= 0)
        l++;
      obtuse += r-l;
      if (dot(order[id],order[l%(N-1)]) == 0)
        right++;
      id++;
      if (r < id)
        r = id;
      if (l < id)
        l = id;
    }
  }
  acute -= right + obtuse;
  print(acute << " " << right << " " << obtuse);
  return 0;
}
