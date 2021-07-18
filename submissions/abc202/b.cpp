#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S;
  cin >> S;
  int n = S.size();
  n--;
  while (n>=0) {
    if (S[n]=='9')
      cout << '6';
    else if (S[n]=='6')
      cout << '9';
    else
      cout << S[n];
    n--;
  }
  cout << endl;
  return 0;
}
