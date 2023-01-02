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
  vector<pair<int,int>> I(N);
  rep(i,N) {
    cin >> I[i].first >> I[i].second;
  }
  sort(all(I));
  int i = 0;
  while (i < N) {
    int L = I[i].first;
    int R = I[i].second;
    while (i < N && I[i].first <= R) {
      R = max(R, I[i].second);
      i++;
    }
    print(L << " " << R);
  }
  return 0;
}
