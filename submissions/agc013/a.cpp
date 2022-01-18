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
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  int res = 0;
  int i=0;
  while (i<N) {
    res++;
    while (i<N-1 && A[i]==A[i+1]) {
      i++;
    }
    if (i==N-1)
      break;
    if (A[i] < A[i+1]) {
      while (i<N-1 && A[i]<=A[i+1]) {
        i++;
      }
    } else {
      while (i<N-1 && A[i]>=A[i+1]) {
        i++;
      }
    }
    i++;
  }
  print(res);
  return 0;
}
