#include <string>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int rotate_array(vector<int> query, vector<vector<int>> &matrix)
{
  int x = query[0] - 1;
  int y = query[1] - 1;

  int curr_num = matrix[x][y];
  int minv = curr_num;

  int dir = 0;
  while (dir < 4)
  {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < query[0] - 1 || nx > query[2] - 1 || ny < query[1] - 1 || ny > query[3] - 1)
    {
      dir += 1;
      continue;
    }
    int temp = matrix[nx][ny];
    matrix[nx][ny] = curr_num;
    curr_num = temp;
    x = nx;
    y = ny;
    minv = min(minv, temp);
  }
  return minv;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
  vector<int> answer;
  vector<vector<int>> matrix(rows, vector<int>(columns));
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= columns; j++)
    {
      matrix[i - 1][j - 1] = j + (i - 1) * columns;
    }
  }
  for (auto query : queries)
  {
    int minv = rotate_array(query, matrix);
    answer.push_back(minv);
  }
  return answer;
}