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
  vector<vector<ll>> A(3);
  map<char,int> color = {{'R',0}, {'G',1}, {'B',2}};
  rep(i,2*N) {
    ll a;
    char c;
    cin >> a >> c;
    A[color[c]].push_back(a);
  }
  int even = -1;
  rep(i,3) {
    if (A[i].size()%2 == 0) {
      if (even != -1) {
        print(0);
        return 0;
      }
      even = i;
    }
    sort(all(A[i]));
  }
  vector<ll> min_complain(3);
  rep(i,3) {
    int j=0, k=0;
    ll m = 1e15;
    auto B = A[(i+1)%3], C = A[(i+2)%3];
    int b = B.size(), c = C.size();
    while (j < b && k < c) {
      while (k < c-1 && abs(B[j]-C[k]) >= abs(B[j]-C[k+1])) {
        k++;
      }
      m = min(m, abs(B[j]-C[k]));
      j++;
    }
    min_complain[i] = m;
  }
  ll res = min_complain[even];
  res = min(res, min_complain[(even+1)%3]+min_complain[(even+2)%3]);
  print(res);
  return 0;
}
