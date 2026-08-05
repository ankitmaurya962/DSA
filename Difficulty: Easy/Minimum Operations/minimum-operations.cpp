class Solution {
	public:
	int minOperation(int n) {
		int count = 1;
		
		while (n > 1) {
			if (n % 2 == 0)
				n /= 2;
			else
				n--;
			
			count++;
		}
		
		return count;
		
	}
};
