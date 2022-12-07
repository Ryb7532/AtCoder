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

vec<string> P = {"H","2B","3B","HR"};

int main() {
  string S;
  map<string,int> cnt;
  rep(i,4) {
    cin >> S;
    cnt[S]++;
  }
  rep(i,4) {
    if (cnt[P[i]]!=1) {
      print(No);
      return 0;
    }
  }
  print(Yes);
  return 0;
}
