class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int idx, i;
        bool ans = false;
        for (i = 0; i <= row; ++i)
        {
            if (matrix[i][col]>target)
            {
                idx = i;
                break;
            }
            else if (matrix[i][col]==target)
            {
                ans = true;
                break;
            }
        }
        if (!ans && i<= row)
        {
            for (int i = 0; i <= col; ++i)
            {
                if (matrix[idx][i]==target)
                {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
};