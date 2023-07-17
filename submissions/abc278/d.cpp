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
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,Q;
  cin >> N;
  vector<pair<ll,int>> A(N);
  rep(i,N) {
    cin >> A[i].first;
    A[i].second = 0;
  }
  cin >> Q;
  int rtime = 0;
  ll rvalue = 0;
  rep(i,Q) {
    int t;
    cin >> t;
    if (t == 1) {
      rtime = i+1;
      cin >> rvalue;
    } else if (t == 2) {
      int id;
      ll x;
      cin >> id >> x;
      id--;
      if (A[id].second < rtime) {
        A[id] = {rvalue, rtime};
      }
      A[id].first += x;
    } else {
      int id;
      cin >> id;
      id--;
      if (A[id].second < rtime) {
        A[id] = {rvalue, rtime};
      }
      print(A[id].first);
    }
  }
  return 0;
}
