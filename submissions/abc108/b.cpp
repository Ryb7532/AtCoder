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
  int L;
  cin >> L;
  vector<bool> B;
  while (L>0) {
    B.push_back(L%2);
    L /= 2;
  }
  int N = B.size();
  int M = 2*(N-1);
  int sum = 0;
  vector<int> pow(N);
  pow[0]=1;
  rep(i,N-1) {
    pow[i+1] = pow[i]*2;
  }
  reverse(all(B));
  reverse(all(pow));
  rep(i,N-1) {
    if (B[i+1])
      M++;
  }
  print(N << ' ' << M);
  rep(i,N-1) {
    print(i+1 << ' ' << i+2 << ' ' << 0);
    print(i+1 << ' ' << i+2 << ' ' << pow[i+1]);
  }
  sum += pow[0];
  rep(i,N-1) {
    if (B[i+1]) {
      print(1 << ' ' << i+2 << ' ' << sum);
      sum += pow[i+1];
    }
  }
  return 0;
}
