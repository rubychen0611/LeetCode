
// @Title: 计数质数 (Count Primes)
// @Author: rubychen0611
// @Date: 2018-07-06 10:59:36
// @Runtime: 28 ms
// @Memory: N/A

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
	bool *mark = new bool[n];
	for (int i = 1; i < n; i++)
		mark[i] = true;
	int b = sqrt(n) + 1;
	for (int i = 2; i <= b; i++)
	{
		for (int j = i*i; j < n; j += i)
			mark[j] = false;
	}
	for (int i = 2; i < n; i++)
		if (mark[i] == true)
			count++;
        return count;
    }
};
