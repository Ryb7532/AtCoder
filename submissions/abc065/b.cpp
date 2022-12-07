#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[N], cnt = 0, button = 0;
  bool used[N], can = false;
  for (int i=0; i<N; i++) {
    cin >> a[i];
    a[i]--;
    used[i] = false;
  }
  while (!used[button]) {
    cnt++;
    used[button] = true;
    button = a[button];
    if (button == 1) {
      can = true;
      break;
    }
  }
  if (can)
    cout << cnt << endl;
  else
    cout << -1 << endl;
  return 0;
}
