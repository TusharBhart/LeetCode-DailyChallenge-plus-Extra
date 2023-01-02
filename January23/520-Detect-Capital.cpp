// Approach 1
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool a = isupper(word[0]), b = false, c = false;
        for(int i=1; i<word.size(); i++) {
            isupper(word[i]) ? b = true : c = true;
        }
        return word.size() == 1 || a && !b && c || !a && !b && c || a && b && !c; 
    }
};

// Approach 2
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0, pos;
        
        for(int i=0; i<word.size(); i++){
            if(isupper(word[i])) count++, pos = i;
        }
        return !count || count == word.size() || (count == 1 && !pos);
    }
};