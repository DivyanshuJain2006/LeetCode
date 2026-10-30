class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if (source == target) return 0;

        unordered_map<int, vector<int>> mp;

    
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                mp[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visitedStops;
        vector<bool> visitedRoutes(routes.size(), false);

        q.push(source);
        visitedStops.insert(source);

        int buses = 0;

        while (!q.empty()) {
            int sz = q.size();
            buses++;

            while (sz--) {
                int stop = q.front();
                q.pop();

                for (int route : mp[stop]) {

                    if (visitedRoutes[route]) continue;

                    visitedRoutes[route] = true;

                    for (int nextStop : routes[route]) {

                        if (nextStop == target)
                            return buses;

                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};