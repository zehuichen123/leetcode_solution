class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int>count;
        map<string, int>::iterator iter;
        vector<vector<string>>ans;
        int num = 0;
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            string sort_str = str;
            sort(sort_str.begin(), sort_str.end());
            iter = count.find(sort_str);
            if(iter != count.end()){
                ans[iter->second].push_back(str);
            }
            else{
                vector<string>tmp = {str};
                ans.push_back(tmp);
                count.insert(pair<string, int>(sort_str, num));
                num += 1;
            }
        }
        return ans;
    }
};