class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // {server becomes free at, server ID}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        set<int> available;
        for (int server = 0; server < k; ++server) {
            available.insert(server);
        }

        vector<int> handled(k, 0);

        for (int i = 0; i < arrival.size(); ++i) {
            // Free every server whose request has completed.
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) continue; // Drop the request.

            int preferred = i % k;
            auto it = available.lower_bound(preferred);

            // Wrap around if no available server has ID >= preferred.
            if (it == available.end()) it = available.begin();

            int server = *it;
            available.erase(it);

            ++handled[server];
            busy.push({static_cast<long long>(arrival[i]) + load[i], server});
        }

        int mostHandled = *max_element(handled.begin(), handled.end());
        vector<int> result;

        for (int server = 0; server < k; ++server) {
            if (handled[server] == mostHandled) {
                result.push_back(server);
            }
        }

        return result;
    }
};