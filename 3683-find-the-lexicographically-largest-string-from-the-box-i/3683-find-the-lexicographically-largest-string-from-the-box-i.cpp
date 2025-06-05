class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends==1)   return word;

        int i = 0;
        int j = 1;
        int gap = 0;

        //Find largest suffix
        while(j+gap < n){
            if(word[i+gap]==word[j+gap])    gap++;
            else if(word[i+gap]<word[j+gap]){
                int save = i;
                i = j;
                j = max(j+1,save+gap+1);
                gap = 0;
            }else{
                j = j+gap+1;
                gap = 0;
            }
        }
        return word.substr(i,n-numFriends+1);
    }
};