/*
    TODO: Minimum Swaps to Sort
    ? https://practice.geeksforgeeks.org/problems/minimum-swaps/1
*/

class Solution
{
public:
    int minOperations(vector<int> &arr)
    {
        vector<pair<int, int>> pr;
        int n = arr.size(), cnt = 0;
        for (int i = 0; i < n; i++)
            pr.push_back({arr[i], i});
        sort(pr.begin(), pr.end());
        for (int i = 0; i < n; i++)
        {
            if (pr[i].second == i)
                continue;
            else
            {
                while (pr[i].second != i)
                {
                    int idx = pr[i].second;
                    swap(pr[i], pr[idx]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> arr;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                arr.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            cnt += minOperations(arr);
        }
        return cnt;
    }
};