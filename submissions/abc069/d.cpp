#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  int a[n];
  for (int i=0; i<n; i++)
    cin >> a[i];
  int ans[h*w], idx = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<a[i]; j++) {
      ans[idx] = i+1;
      idx++;
    }
  }
  for (int i=0; i<h; i++) {
    if (i%2) {
      for (int j=w-1; j>=0; j--)
        cout << ans[i*w+j] << ' ';
    } else {
      for (int j=0; j<w; j++)
        cout << ans[i*w+j] << ' ';
    }
    cout << endl;
  }
  return 0;
}