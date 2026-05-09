class Solution {
public:
    vector<int> Primes(int n) {
        vector<int> primemap(n+1, 1);
        primemap[0] = primemap[1] = 0;
        for (int i = 2; i * i <=n; i++) {
            if (primemap[i] == 1) {
                for (int j = i * i; j <= n; j += i) {
                    primemap[j] = 0;
                }
            }
        }
        return primemap;
    }
    int minJumps(vector<int>& nums) {
        int maxElem = 0;
        unordered_map<int, vector<int>> mp;
    
        for (int i = 0; i < nums.size(); i++) {
            maxElem = max(nums[i], maxElem);
            mp[nums[i]].push_back(i);
        }

        vector<int> isPrime = Primes(maxElem);
        queue<int> q;
        vector<int> vis(nums.size(), 0);
        unordered_set<int>visPrime;

        q.push(0);
        vis[0] = 1;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop();
                if (i == nums.size() - 1) {
                    return steps;
                }
                if (i - 1 >= 0 && !vis[i - 1]) {
                    q.push(i - 1);
                    vis[i - 1] = 1;
                }
                if (i + 1 < nums.size() && !vis[i + 1]) {
                    q.push(i + 1);
                    vis[i + 1] = 1;
                }
                if (isPrime[nums[i]] == 0 || visPrime.count(nums[i])) {
                    continue;
                }
                // visiting multiples of prime
                for (int multiple = nums[i]; multiple <= maxElem; multiple += nums[i]) {
                    if (mp.find(multiple) != mp.end()) {
                        for (auto it : mp[multiple]) {
                            if (!vis[it]) {
                                q.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                }
                visPrime.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};