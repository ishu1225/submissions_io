class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            vector<int> temp(26);
            for(char a:strs[i]){
                temp[a-'a']++;
            }
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto &it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};
