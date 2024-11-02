#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> ans;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            ans.push_back(word);
        }
        for (int i = 0; i < ans.size(); i++) {
            int nextIndex = (i + 1) % ans.size();
            if (ans[i].back() != ans[nextIndex].front()) {
                return false;
            }
        }
        return true;
    }
};
