#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int lra(vector<int>& heights) {
    stack<int> stk;
    int maxArea = 0;

    for (int i = 0; i < heights.size() || !stk.empty(); ) {
        if (stk.empty() || (i < heights.size() && heights[i] >= heights[stk.top()])) {
            stk.push(i);
            i++;
        } else {
            int topIndex = stk.top();
            stk.pop();
            int currentHeight = heights[topIndex];
            int currentWidth = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, currentHeight * currentWidth);
        }
    }

    return maxArea;
}

int mra(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> histogram(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                histogram[j] = (i == 0) ? 1 : histogram[j] + 1;
            } else {
                histogram[j] = 0;
            }
        }

        maxArea = max(maxArea, lra(histogram));
    }

    return maxArea;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0, 0}
    };

    int result = mra(matrix);

    cout << result ;

    return 0;
}
