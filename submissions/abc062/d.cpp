#include <bits/stdc++.h>
using namespace std;
#define INF -(1LL << 50)

int main() {
  int N;
  cin >> N;
  long a[3*N];
  for (int i=0; i<3*N; i++)
    cin >> a[i];
  priority_queue<int, vector<int>, greater<int>> f;
  priority_queue<int, vector<int>> l;
  long fsum[N+1], lsum[N+1], sum = 0, ans = INF;
  for (int i=0; i<N; i++) {
    f.push(a[i]);
    sum += a[i];
  }
  fsum[0] = sum;
  for (int i=0; i<N; i++) {
    f.push(a[N+i]);
    sum += a[N+i];
    sum -= f.top();
    f.pop();
    fsum[i+1] = sum;
  }
  sum = 0;
  for (int i=1; i<=N; i++) {
    l.push(a[3*N-i]);
    sum += a[3*N-i];
  }
  lsum[N] = sum;
  for (int i=1; i<=N; i++) {
    l.push(a[2*N-i]);
    sum += a[2*N-i];
    sum -= l.top();
    l.pop();
    lsum[N-i] = sum;
  }
  for (int i=0; i<=N; i++)
    ans = max(ans, fsum[i]-lsum[i]);
  cout << ans << endl;
  return 0;
}