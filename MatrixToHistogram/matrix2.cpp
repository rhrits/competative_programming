#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int histogram(vector<int> &heights) {
  stack<int> stk;
  int max_area = 0;

  for (size_t i = 0; i < heights.size() || !stk.empty(); ) {
    if (stk.empty() || (i < heights.size() && heights[i] >= heights[stk.top()])) {
      stk.push(i);
      i++;
    } else {
      int top_index = stk.top();
      stk.pop();
      int current_height = heights[top_index];
      int current_width = stk.empty() ? i : i - stk.top() - 1;
      max_area = max(max_area, current_height * current_width);
    }
  }

  return max_area;
}

int main() {
  vector<vector<int>> matrix = {
    {2, 2, 0, 4, 0, 0},
    {1, 1, 0, 3, 3, 1},
    {0, 0, 0, 2, 2, 0},
    {1, 0, 2, 1, 1, 0},
    {0, 1, 1, 0, 0, 0},
  };

  int overall_max_area = 0;

  for (size_t col = 0; col < matrix[0].size(); ++col) {
    vector<int> heights;
    for (size_t row = 0; row < matrix.size(); ++row) {
      heights.push_back(matrix[row][col]);
    }
    int result = histogram(heights);
    overall_max_area = max(overall_max_area, result);
  }

  cout << overall_max_area << endl;

  return 0;
}
