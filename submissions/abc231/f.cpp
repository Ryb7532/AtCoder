#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

template<typename T>
struct BIT {
  int n;
  vector<T> dat;
  BIT(int n) : n(n), dat(n+1,0){}
  void add(int i,T x) {
    for (++i; i<=n; i+=(i&-i)) dat[i] += x;
  }
  T sum(int i) {
    T res = 0;
    for (++i; i>0; i-=(i&-i))
      res += dat[i];
    return res;
  }
  T range_sum(int l,int r) { //[l,r]
    return sum(r)-sum(l-1);
  }
};


int main() {
  int N;
  cin >> N;
  vector<pair<pair<int,int>,int>> PA(N), PB(N);
  vector<int> orderB(N);
  BIT<ll> bit(N);
  ll res = 0;
  rep(i,N) {
    int A;
    cin >> A;
    PA[i].first.first = A;
    PB[i].first.second = A;
  }
  rep(i,N) {
    int B;
    cin >> B;
    PA[i].first.second = -B;
    PB[i].first.first = -B;
    PA[i].second = PB[i].second = i;
  }
  sort(all(PA));
  sort(all(PB));
  ll cnt = 0;
  rep(i,N) {
    if (i>0 && PB[i-1].first == PB[i].first) {
      cnt++;
      res += cnt;
    } else {
      cnt = 0;
    }
    int id = PB[i].second;
    orderB[id] = i;
  }
  rep(i,N) {
    int id = PA[i].second;
    int n = orderB[id];
    bit.add(n, 1);
    res += bit.sum(n);
  }
  print(res);
  return 0;
}
