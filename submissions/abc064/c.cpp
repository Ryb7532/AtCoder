#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a, cnt_rate[9] = {};
  for (int i=0; i<N; i++) {
    cin >> a;
    cnt_rate[min(a/400, 8)]++;
  }
  int cnt_color = 0;
  for (int i=0; i<8; i++) {
    if (cnt_rate[i]>0)
      cnt_color++;
  }
  cout << max(1, cnt_color) << ' ' << cnt_color+cnt_rate[8] << endl;
  return 0;
}
