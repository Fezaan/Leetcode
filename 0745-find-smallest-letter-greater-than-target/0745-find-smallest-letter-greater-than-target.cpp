class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ch=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(ch==letters.size())  return letters[0];
        return letters[ch];
    }
};