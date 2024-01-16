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
  vector<int> heights = {2, 4, 3, 4, 5, 1};
  int result = histogram(heights);

  cout << result ;

  return 0;
}
