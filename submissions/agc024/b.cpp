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
  vector<int> P(N);
  rep(i,N) {
    int A;
    cin >> A;
    A--;
    P[A] = i;
  }
  int M = 0;
  int i=0;
  while (i<N) {
    int s = i;
    while (i<N-1 && P[i] < P[i+1]) {
      i++;
    }
    i++;
    M = max(M, i-s);
  }
  print(N-M);
  return 0;
}
