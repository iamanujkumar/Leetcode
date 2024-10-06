class Solution {
public:
    bool areSentencesSimilar(string sen1, string sen2) {
        vector<string> vex1 = split(sen1);
        vector<string> vex2 = split(sen2);        
        int i = 0, j = 0;
        int n1 = vex1.size(), n2 = vex2.size();
        while (i < n1 && i < n2 && vex1[i] == vex2[i]) {
            i++;
        }
        while (j < n1 - i && j < n2 - i && vex1[n1 - 1 - j] == vex2[n2 - 1 - j]) {
            j++;
        }
        return i + j == n1 || i + j == n2;
    }
    vector<string> split(const string &sentence) {
        vector<string> vex;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            vex.push_back(word);
        }
        return vex;
    }
};
