class Solution
{
    public:
        int poorPigs(int N, int Die, int Test)
        {
            return ceil(log(N) / log(Test / Die + 1));
            /*if there are N buckets then there should be a min x pigs to test which of the buckets is poisonous in 
                T tests which follows the equation (T+1)^x>=N, where T=Test/Die */
           	//Hence x will the min value of log(N)/log(T+1) which can be calculated by ceil function 
        }
};