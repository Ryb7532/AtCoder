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
  int N = S.size();
  vector<vector<char>> bra;
  bra.push_back(vector<char>());
  set<char> used;
  bool flag = true;
  rep(i,N) {
    if (S[i] == '(') {
      bra.push_back(vector<char>());
    } else if (S[i] == ')') {
      auto rm_string = bra[bra.size()-1];
      for (char c : rm_string) {
        used.erase(c);
      }
      bra.pop_back();
    } else {
      if (used.find(S[i]) != used.end()) {
        flag = false;
        break;
      } else {
        used.insert(S[i]);
        bra[bra.size()-1].push_back(S[i]);
      }
    }
  }
  print((flag ? "Yes" : "No"));
  return 0;
}
