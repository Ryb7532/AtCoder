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
  vec<int> B(N);
  vec<int> Aright(N, -1), Bleft(N, -1);
  vec<int> cnt(N,0);
  int offset=0;
  rep(i,N) {
    int a;
    cin >> a;
    cnt[--a]++;
    Aright[a] = max(Aright[a],i);
  }
  rep(i,N) {
    int b;
    cin >> b;
    B[i] = b;
    cnt[--b]++;
    if (Bleft[b]==-1)
      Bleft[b] = i;
  }
  rep(i,N) {
    if (cnt[i]>N) {
      print(No);
      return 0;
    }
  }
  print(Yes);
  rep(i,N) {
    if (Aright[i]==-1 || Bleft[i]==-1)
      continue;
    if (Aright[i] >= Bleft[i]+offset)
      offset = Aright[i]-Bleft[i]+1;
  }
  stringstream ss;
  rep(i,N) {
    ss << B[(i+N-offset)%N] << " ";
  }
  string res = ss.str();
  res.pop_back();
  print(res);
  return 0;
}
