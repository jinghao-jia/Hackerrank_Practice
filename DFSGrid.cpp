#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int biggest_region_rec(vector<vector<int>> & grid, int i, int j, int n, int m);

int get_biggest_region(vector<vector<int>> & grid, int n, int m) {
  int result = 0;
  for(int grid_i = 0;grid_i < n;grid_i++){
    for(int grid_j = 0;grid_j < m;grid_j++){
      if(grid[grid_i][grid_j]) {
        int temp = biggest_region_rec(grid, grid_i, grid_j, n, m);
        if(result < temp)
          result = temp;
      }
    }
  }
  return result;
}

inline bool in_bound(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int biggest_region_rec(vector<vector<int>> & grid, int i, int j, int n, int m) {
  int result = 1;
  grid[i][j] = 0;

  if(in_bound(i - 1, j - 1, n, m) && grid[i - 1][j - 1])
    result += biggest_region_rec(grid, i - 1, j - 1, n, m);

  if(in_bound(i - 1, j, n, m) && grid[i - 1][j])
    result += biggest_region_rec(grid, i - 1, j, n, m);

  if(in_bound(i - 1, j + 1, n, m) && grid[i - 1][j + 1])
    result += biggest_region_rec(grid, i - 1, j + 1, n, m);


  if(in_bound(i, j - 1, n, m) && grid[i][j - 1])
    result += biggest_region_rec(grid, i, j - 1, n, m);

  if(in_bound(i, j + 1, n, m) && grid[i][j + 1])
    result += biggest_region_rec(grid, i, j + 1, n, m);


  if(in_bound(i + 1, j - 1, n, m) && grid[i + 1][j - 1])
    result += biggest_region_rec(grid, i + 1, j - 1, n, m);

  if(in_bound(i + 1, j, n, m) && grid[i + 1][j])
    result += biggest_region_rec(grid, i + 1, j, n, m);

  if(in_bound(i + 1, j + 1, n, m) && grid[i + 1][j + 1])
    result += biggest_region_rec(grid, i + 1, j + 1, n, m);

  return result;
}

int main(){
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<int>> grid(n,vector<int>(m));
  for(int grid_i = 0;grid_i < n;grid_i++){
    for(int grid_j = 0;grid_j < m;grid_j++){
      cin >> grid[grid_i][grid_j];
    }
  }
  cout << get_biggest_region(grid, n, m) << endl;
  return 0;
}
