class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        deque<char>dq;
        set<string>seen;
        set<string>repeated;
        int i=0,j=0;
        while(j<s.size()){
            dq.push_back(s[j]);
            if(dq.size()<10){
                j++;
            }
            else if(dq.size()==10){
                string seq(dq.begin(),dq.end());
                if(seen.count(seq)){
                    repeated.insert(seq);
                }
                else{
                    seen.insert(seq);
                }
                dq.pop_front(); 
                i++;
                j++;
            }
        }
        return vector<string>(repeated.begin(),repeated.end());
    }
};