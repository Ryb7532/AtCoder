#include <bits/stdc++.h>
using namespace std;
#define vec vector


int H, W;
vector<int> dh = {-1,0,1,0}, dw = {0,-1,0,1};

bool isRange(int h, int w) {
  return h>=0 && h<H && w>=0 && w<W;
}
