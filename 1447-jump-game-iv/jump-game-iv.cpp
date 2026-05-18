class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);

        int steps = 0;

        while (!q.empty()) {

            int s = q.size();
            while (s--) {
                int i = q.front();
                vis[i] = 1;
                q.pop();

                if (i == n - 1)
                    return steps;

                int l = i - 1;
                int r = i + 1;

                if (r < n && !vis[r])
                    q.push(r);
                if (l >= 0 && !vis[l])
                    q.push(l);

                if (mp.find(arr[i]) != mp.end()) {
                    for (auto it : mp[arr[i]]) {
                        q.push(it);
                    }
                    mp.erase(arr[i]);
                }
            }

            steps++;
        }

        return steps;
    }
};