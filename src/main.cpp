#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a(9, vector<int>(9));
bool check(int r, int c, int n) {
  for (int i = 0; i < 9; i++) {
    if (a[r][i] == n) {
      return false;
    }else if (a[i][c] == n) {
      return false;
    }else if(a[r-r%3+i/3][c-c%3+i%3]==n){
      return false;
    }
  }
  return true;
}
bool dfs() {
  int rr,cc;
  bool flag = true;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (a[i][j] == 0) {
        rr = i; cc = j;
        flag = false;
        break;
      }
    }
    if (!flag) {
      break;
    }
  }
  if (flag) {
    return true;
  }
  for (int n = 1; n <= 9; n++) {
    if (check(rr,cc,n)) {
      a[rr][cc] = n;
      if (dfs()) {
        return true;
      }
      a[rr][cc] = 0;
    }
  }
  return false;
}
int main(){
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin>>a[i][j];
    }
  }
  if(dfs()) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout<<a[i][j]<<" ";
      }
      cout<<"\n";
    }
  }
}
