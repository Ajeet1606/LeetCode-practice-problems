class Solution {
public:
    bool checkSubarraySum(vector<int>& A, int k) {
	int n = A.size(), sum = 0;
	unordered_map<int, int>u;
	u.insert({ 0, -1 });
	for (int i = 0; i < n; i++) {
		sum += A[i];
		int mod = k == 0 ? sum : sum % k;
		if (u.find(mod) == u.end()) 
           u.insert({ mod, i });
		else if (i - u[mod] > 1) return true;
	}
	return false;
}
};