#include <iostream>
using namespace std;

#define Max(a, b) ((a>b)?a:b)

int main() {
  int n;
  cin >> n;
  int a[n], cnt[100000] = {};
  for (int i=0; i<n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 0;
  for (int i=1; i<100000-1; i++)
    ans = Max(ans, cnt[i-1]+cnt[i]+cnt[i+1]);
  cout << ans << '\n';
  return 0;
}