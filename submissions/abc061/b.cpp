#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int cnt[50] = {}, a, b;
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
  }
  for (int i=0; i<N; i++)
    cout << cnt[i] << endl;
  return 0;
}
