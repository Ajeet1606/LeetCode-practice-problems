class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& qs) {
    long long res = 0, cols_cnt = n, rows_cnt = n;
    vector<bool> cols(n), rows(n);
    for (int i = qs.size() - 1; i >= 0; --i) {
        int type = qs[i][0], id = qs[i][1], v = qs[i][2];
        if (type == 0) { // row
            if (!rows[id]) {
                rows[id] = true;
                --rows_cnt;
                res += v * cols_cnt;
            }
        }
        else { // col
            if (!cols[id]) {
                cols[id] = true;
                --cols_cnt;    
                res += v * rows_cnt;
            }
        }
    }
    return res;
}
};