#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  char a[H][W+5];
  for (int i=0; i<H; i++)
    cin >> a[i];
  for (int i=0; i<W+2; i++)
    cout << '#';
  cout << endl;
  for (int i=0; i<H; i++) {
    cout << '#';
    for (int j=0; j<W; j++)
      cout << a[i][j];
    cout << "#\n";
  }
  for (int i=0; i<W+2; i++)
    cout << '#';
  cout << endl;
  return 0;
}
