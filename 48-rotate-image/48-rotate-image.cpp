class Solution
{
    public:
        void rotate(vector<vector < int>> &matrix)
        {
            int startRow = 0, endRow = matrix.size() - 1;
            int startCol = 0, endCol = endRow;

            while (startRow < endRow and startCol < endCol)
            {
                vector<int> v(endCol - startCol);
               	//traverse startRow
                for (int i = startCol, idx = 0; i < endCol; ++i)
                {
                    v[idx++] = matrix[startRow][i];
                }


               	//traverse endCol
                for (int i = startRow, idx = 0; i < endRow; ++i)
                {
                    swap(matrix[i][endCol], v[idx++]);
                }

               	//traverse endRow
                for (int i = endCol, idx = 0; i > startCol; --i)
                {
                    swap(matrix[endRow][i], v[idx++]);
                }


               	//traverse startCol
                for (int i = endRow, idx = 0; i > startRow; --i)
                {
                    swap(matrix[i][startCol], v[idx++]);
                }


               	//traverse startRow
                for (int i = startCol, idx = 0; i < endCol; ++i)
                {
                    swap(matrix[startRow][i], v[idx++]);
                }


                startRow++;
                endCol--;
                endRow--;
                startCol++;
               
            }
        }
};