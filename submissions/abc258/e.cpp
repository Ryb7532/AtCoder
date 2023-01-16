#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  int N,Q;
  ll X;
  cin >> N >> Q >> X;
  vector<ll> W(N);
  ll sum = 0;
  rep(i,N) {
    cin >> W[i];
    sum += W[i];
  }
  X--;
  int div = X/sum;
  X %= sum;
  X++;
  vector<int> fromto(N);
  int j = 0;
  sum = 0;
  rep(i,N) {
    while (sum < X) {
      sum += W[j];
      j++;
      j %= N;
    }
    fromto[i] = j;
    sum -= W[i];
  }
  ll loop_elem, before_loop;
  int n = 0, d = 0;
  vector<int> dist(N, -1);
  vector<ll> cnt(N);
  while (true) {
    if (dist[n] != -1) {
      before_loop = dist[n];
      loop_elem = d - before_loop;
      break;
    }
    dist[n] = d;
    cnt[d] = (N + fromto[n] - n - 1) % N + 1 + N * div;
    n = fromto[n];
    d++;
  }
  rep(_,Q) {
    ll K;
    cin >> K;
    K--;
    if (K < before_loop) {
      print(cnt[K]);
    } else {
      K -= before_loop;
      K %= loop_elem;
      K += before_loop;
      print(cnt[K]);
    }
  }
  return 0;
}
