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
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  int l2 = 50,l3 = 50;
  vector<int> R(N), c2(N,0), c3(N,0);
  rep(i,N) {
    int a = A[i];
    while (a%2 == 0) {
      c2[i]++;
      a /= 2;
    }
    while (a%3 == 0) {
      c3[i]++;
      a /= 3;
    }
    l2 = min(l2,c2[i]);
    l3 = min(l3,c3[i]);
    R[i] = a;
  }
  bool flag = true;
  rep(i,N-1) {
    if (R[i] != R[i+1])
      flag = false;
  }
  if (!flag) {
    print(-1);
    return 0;
  }
  int res = 0;
  rep(i,N) {
    res += c2[i]-l2;
    res += c3[i]-l3;
  }
  print(res);
  return 0;
}
