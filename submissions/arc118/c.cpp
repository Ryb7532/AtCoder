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
  cout << 10 << " " << 15;
  N -= 2;
  for (int i=6; i<=10000; i+=6) {
    cout << " " << i;
    N--;
    if (N == 0) {
      return 0;
    }
  }
  for (int i=20; i<=10000; i+=10) {
    if (i%3 == 0) continue;
    cout << " " << i;
    N--;
    if (N == 0) {
      return 0;
    }
  }
  for (int i=45; i<=10000; i+=30) {
    cout << " " << i;
    N--;
    if (N == 0) {
      return 0;
    }
  }
  return 0;
}
