class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
    vector<string> result;
    string cunt = "";
    for (const string& f : folder) {
        if (cunt.empty() || f.find(cunt + "/") != 0) {
            result.push_back(f);
            cunt = f;
        }
    }
    return result;
    }
};