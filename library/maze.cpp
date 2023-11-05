#include <bits/stdc++.h>
using namespace std;


int H, W;
vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
// vector<int> dx = {-1,-1,-1,0,1,1,1,0}, dy = {1,0,-1,-1,-1,0,1,1};

pair<int,int> newPos(int x, int y, int id, int step=1) {return {x+step*dx[id], y+step*dy[id]};}

bool isRange(int h, int w) {return h>=0 && h<H && w>=0 && w<W;}
