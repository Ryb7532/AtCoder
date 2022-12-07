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

map<char, int> strtg2int = {{'G',0}, {'C',1}, {'P',2}};

int main() {
  int N,M;
  cin >> N >> M;
  vec<string> A(2*N);
  rep(i,2*N) {
    cin >> A[i];
  }
  set<pair<int, int>> rank;
  rep(i,2*N) {
    rank.insert({0,i});
  }
  rep(j,M) {
    set<pair<int,int>> newrank;
    auto it = rank.begin();
    rep(i,N) {
      auto p1 = *(it++);
      auto p2 = *(it++);
      int win = strtg2int[A[p1.second][j]];
      win -= strtg2int[A[p2.second][j]];
      win = (win+3)%3;
      if (win==1)
        p2.first--;
      else if (win==2)
        p1.first--;
      newrank.insert(p1);
      newrank.insert(p2);
    }
    rank = newrank;
  }
  auto it = rank.begin();
  rep(i,2*N) {
    print(it->second +1);
    it++;
  }
  return 0;
}
