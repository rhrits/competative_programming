class Solution {
public:
    int maxArea(vector<int>& height) {
    int sol = INT_MIN;

    int low = 0;
    int high = height.size() - 1;

    while (low < high)
    {
        int area = min(height[low], height[high]) * (high - low);
        sol = max(area, sol);

        if (height[low] < height[high])
        {
            low++;
        }
        else
        {
            high--;
        }
    }

    return sol;
    }
};