#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long a[n], cnt[200000] = {};
  for (int i=0; i<n; i++) {
    cin >> a[i];
    cnt[a[i]-1]++;
  }
  long sum = 0;
  for (int i=0; i<n; i++)
    sum += cnt[i]*(cnt[i]-1)/2;
  for (int i=0; i<n; i++) {
    long ans;
    int tmp = a[i]-1;
    ans = sum - cnt[tmp] + 1;
    cout << ans << '\n';
  }
  return 0;
}
