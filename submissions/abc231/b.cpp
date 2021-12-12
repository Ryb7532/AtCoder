#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  sort(all(S));
  S.push_back("");
  string name = "";
  int vote = 0, max_vote = 0, id = -1;
  rep(i,N+1) {
    if (S[i] != name) {
      if (max_vote < vote) {
        id = i-1;
        max_vote = vote;
      }
      vote = 0;
      name = S[i];
    }
    vote++;
  }
  print(S[id]);
  return 0;
}
