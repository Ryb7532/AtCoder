#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  string s;
  char S[H][W], ans[H][W], pro[H][W];
  for (int i=0; i<H; i++) {
    cin >> s;
    for (int j=0; j<W; j++) {
      S[i][j] = s[j];
    }
  }
  /*
  for (int i=1; i<=H; i++)
    for (int j=1; j<=W; j++) {
      if (S[i][j] == '#' && S[i][j-1] == '#' && S[i][j+1] == '#' && S[i-1][j] == '#' && S[i-1][j-1] == '#' && S[i-1][j+1] && S[i+1][j] == '#' && S[i+1][j-1] == '#' && S[i+1][j+1] == '#')
        ans[i-1][j-1] = '#';
      else
        ans[i-1][j-1] = '.';
    }
  */
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      ans[i][j] = '#';
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      if (S[i][j] == '.')
        for (int k=max(0, i-1); k<=min(i+1, H-1); k++)
          for (int l=max(0, j-1); l<=min(j+1, W-1); l++)
            ans[k][l] = '.';
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      pro[i][j] = '.';
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      if (ans[i][j] == '#')
        for (int k=max(0, i-1); k<=min(i+1, H-1); k++)
          for (int l=max(0, j-1); l<=min(j+1, W-1); l++)
            pro[k][l] = '#';
  bool c = true;
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      if (S[i][j] != pro[i][j])
        c = false;
  if (c) {
    cout << "possible" << endl;
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++)
        cout << ans[i][j];
      cout << endl;
    }
  } else {
    cout << "impossible" << endl;
  }
  return 0;
}
