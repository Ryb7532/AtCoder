#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N,M,H,K;
  string S;
  cin >> N >> M >> H >> K >> S;
  set<pair<int,int>> item;
  rep(_,M) {
    int x,y;
    cin >> x >> y;
    item.insert({x,y});
  }
  int x = 0, y = 0;
  bool flag = true;
  map<char, pair<int,int>> move = {{'R',{1,0}}, {'L',{-1,0}}, {'U',{0,1}}, {'D',{0,-1}}};
  rep(i,N) {
    H--;
    if (H < 0) {
      flag = false;
      break;
    }
    x += move[S[i]].first;
    y += move[S[i]].second;
    if (item.find({x,y}) != item.end()) {
      if (H < K) {
        H = K;
        item.erase({x,y});
      }
    }
  }
  printyesno(flag);
  return 0;
}
