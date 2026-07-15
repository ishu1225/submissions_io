class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        vector<int> compare(26);
        for(char a: s){
            compare[a-'a']++;
        }
        for(char a:t){
            compare[a-'a']--;
        }
        for(int x: compare)if(x!=0)return false;
        return true;
    }
};
