#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  int N;
  cin >> N;
  vector<pair<int,int>> A(N);
  set<int> left, right;
  rep(i,N) {
    cin >> A[i].first;
    A[i].second = i;
    right.insert(i);
  }
  sort(all(A));
  ll res = 0;
  int j = 0;
  while (j<N) {
    int rj = j;
    int lj = j;
    while (rj<N && A[j].first==A[rj].first) {
      right.erase(A[rj].second);
      rj++;
    }
    while (j<rj) {
      res += left.size()* right.size();
      j++;
    }
    while (lj < rj) {
      left.insert(A[lj].second);
      lj++;
    }
  }
  print(res);
  return 0;
}
