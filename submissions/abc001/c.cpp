#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

string d[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

int main() {
  int Deg, Dis;
  cin >> Deg >> Dis;
  Deg *= 10;
  Dis *= 10;
  Deg += 1125;
  Deg %= 36000;
  Deg /= 2250;
  string Dir = d[Deg];
  int W;
  if (Dis<25*6) {
    W = 0;
  } else if (Dis<155*6) {
    W = 1;
  } else if (Dis<335*6) {
    W = 2;
  } else if (Dis<545*6) {
    W = 3;
  } else if (Dis<795*6) {
    W = 4;
  } else if (Dis<1075*6) {
    W = 5;
  } else if (Dis<1385*6) {
    W = 6;
  } else if (Dis<1715*6) {
    W = 7;
  } else if (Dis<2075*6) {
    W = 8;
  } else if (Dis<2445*6) {
    W = 9;
  } else if (Dis<2845*6) {
    W = 10;
  } else if (Dis<3265*6) {
    W = 11;
  } else {
    W = 12;
  }
  if (W == 0)
    Dir = 'C';
  cout << Dir << " " << W << endl;
  return 0;
}
