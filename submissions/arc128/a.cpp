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
  vector<ll> A(N);
  vector<int> res(N,0);
  rep(i,N) {
    cin >> A[i];
  }
  int i=0;
  while (i<N) {
    while (i<N-1 && A[i]<=A[i+1]) {
      i++;
    }
    int j=i;
    while (j<N-1 && A[j]>A[j+1]) {
      j++;
    }
    if (i==j)
      break;
    res[i] = 1;
    res[j] = 1;
    i = j+1;
  }
  cout << res[0];
  rep(i,N-1) {
    cout << ' ' << res[i+1];
  }
  cout << endl;
  return 0;
}
