#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i<n; i++)
#define reps(i,s,n) for (int i=s, i<n; i++)
#define rep1(i,n) for (int i=1; i<=n; i++)
#define print(a) cout << a << endl;

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  for (int i=a; ; i += a) {
    if (i < n)
      continue;
    if (i%b == 0) {
      print(i);
      break;
    }
  }
  return 0;
}
