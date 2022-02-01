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
  string S;
  cin >> S;
  int N=S.size();
  bool flag = true;
  int i=0,j=N-1;
  while (j>i && S[j]=='a') {
    if (i<N && S[i]=='a') {
      i++;
    }
    j--;
  }
  while (j>i) {
    if (S[i]!=S[j]) {
      flag = false;
      break;
    }
    i++;
    j--;
  }
  print((flag ? Yes : No));
  return 0;
}
