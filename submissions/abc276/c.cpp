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
  int N;
  cin >> N;
  vector<int> P(N);
  rep(i,N) {
    cin >> P[i];
  }
  vector<int> res(N);
  vector<int> R;
  int i = N-1;
  while (P[i-1]<P[i]) {
    R.push_back(P[i]);
    i--;
  }
  R.push_back(P[i]);
  sort(rall(R));
  int M = R.size();
  rep(j,M) {
    if (R[j] < P[i-1]) {
      swap(R[j], P[i-1]);
      break;
    }
  }
  sort(rall(R));
  for (int e: R) {
    P[i] = e;
    i++;
  }
  rep(i,N) {
    cout << P[i] << " ";
  }
  cout << endl;
  return 0;
}
