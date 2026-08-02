class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s1;
        map<char, int> t1;
        if (s.length() != t.length())
        {
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            char letter = s[i];
            if (s1.find(letter) == s1.end())
            {
                s1[letter] = 0;
            }
            s1[letter]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            char letter = t[i];
            if (t1.find(letter) == t1.end())
            {
                t1[letter] = 0;
            }
            t1[letter]++;
        }
        return s1 == t1;
    }
};