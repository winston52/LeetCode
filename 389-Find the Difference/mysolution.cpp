class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i=0;i<s.length();i++)
            t.erase(t.find(s[i]),1);        
        return t[0];
    }
};