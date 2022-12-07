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
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<int> used(N,-1);
  ll res;
  ll cnt = 0;
  ll time = 0;
  while (time < K && used[cnt%N] == -1) {
    used[cnt%N] = time;
    cnt += A[cnt%N];
    time++;
  }
  K -= time;
  if (K==0) {
    print(cnt);
    return 0;
  }
  res = cnt;
  cnt %= N;
  used[cnt] = time;
  ll loop_cnt = A[cnt];
  int loop = 1;
  ll n = cnt;
  n += A[n];
  n %= N;
  while (used[n] != time) {
    loop_cnt += A[n];
    n += A[n];
    n %= N;
    loop++;
  }
  res += K/loop * loop_cnt;
  K %= loop;
  while (K>0) {
    res += A[res%N];
    K--;
  }
  print(res);
  return 0;
}
