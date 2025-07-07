class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int max_area = 0;

        while (start < end) {
            int h = min(height[start], height[end]);
            int width = end - start;
                max_area = max(max_area, h * width);

                // Move the pointer pointing to the shorter line
            if (height[start] < height[end])
                start++;
            else
                end--;
        }

        return max_area;
    }
};
