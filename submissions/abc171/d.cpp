#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N;
  int cnt[100001];
  ll sum = 0, a, b, c;
  fill(cnt, cnt+100001, 0);
  for (int i=0; i<N; i++) {
    cin >> a;
    cnt[a]++;
    sum += a;
  }
  cin >> Q;
  ll ans[Q];
  for (int i=0; i<Q; i++) {
    cin >> b >> c;
    sum += (c-b) * cnt[b];
    cnt[c] += cnt[b];
    cnt[b] = 0;
    ans[i] = sum;
  }
  for (int i=0; i<Q; i++)
    cout << ans[i] << endl;
  return 0;
}
