class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> mp2;
        unordered_set<string> mp(supplies.begin(), supplies.end());
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            inDegree[recipe] = ingredients[i].size();
            for (string& ing : ingredients[i]) {
                mp2[ing].push_back(recipe);
            }
        }
        queue<string> q;
        for (const string& supply : supplies) {
            q.push(supply);
        }
        vector<string> result;
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            for (const string& recipe : mp2[curr]) {
                inDegree[recipe]--;
                if (inDegree[recipe] == 0) {
                    result.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return result;
    }
};