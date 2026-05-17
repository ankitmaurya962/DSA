class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        vector<int>vis(n, 0);
        q.push(start);

        while(!q.empty()){
            int i = q.front();
            vis[i] = 1;
            q.pop();

            if(arr[i] == 0) return true;

            if(arr[i] + i < n && !vis[arr[i] + i]) q.push(arr[i] + i);
            if(i-arr[i] >= 0 && !vis[i - arr[i]]) q.push(i - arr[i]);
        }
        return false;
    }
};