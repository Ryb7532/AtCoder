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
  int K;
  cin >> S >> K;
  int N = S.size();
  rep(i,N) {
    int s = S[i]-'a';
    s = (26-s)%26;
    if (K>=s) {
      S[i] = 'a';
      K-=s;
    } else {
      continue;
    }
  }
  int s = S[N-1]-'a';
  s += K;
  s %= 26;
  S[N-1] = 'a'+s;
  print(S);
  return 0;
}
