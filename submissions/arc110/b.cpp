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
  int N;
  string T;
  cin >> N >> T;
  string S;
  int cnt = 0;
  if (N==1 && T=="1") {
    cout << 2;
    rep(_,10) {
      cout << 0;
    }
    cout << endl;
    return 0;
  }
  while (3*cnt<N) {
    S += "110";
    cnt++;
  }
  if (S.find(T)==S.npos) {
    S += "110";
    cnt++;
  }
  if (S.find(T)==S.npos) {
    print(0);
    return 0;
  }
  cnt--;
  print((ll)1e10-cnt);
  return 0;
}
