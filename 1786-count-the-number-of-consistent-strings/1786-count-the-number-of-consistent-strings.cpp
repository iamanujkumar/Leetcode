class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(auto ch:allowed){
            st.insert(ch);
        }
        int count=0;
        for(auto ch:words){
            bool flag=true;
            for(int i=0;i<ch.size();i++){
                if(st.find(ch[i])==st.end()){
                    flag=false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};