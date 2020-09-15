class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        unordered_set<string>beginSet={beginWord};
        unordered_set<string>endSet={endWord};
        if(wordDict.find(endWord) == wordDict.end()){
            return 0;
        }
        int ans = 1;
        while(!beginSet.empty()){
            for(auto str: beginSet){
                wordDict.erase(str);
            }
            unordered_set<string>searchSet;
            for(auto str:beginSet){
                for(int i=0; i<str.size(); i++){
                    for(char j='a'; j<='z'; j++){
                        string tmp_str = str;
                        tmp_str[i] = j;
                        if(endSet.find(tmp_str) != endSet.end()){
                            return ans + 1;
                        }
                        if(wordDict.find(tmp_str) == wordDict.end()){
                            continue;
                        }
                        searchSet.insert(tmp_str);
                    }
                }
            }
            if(searchSet.size() > endSet.size()){
                beginSet = endSet;
                endSet = searchSet;
            }
            else{
                beginSet = searchSet;
            }
            ans += 1;
        }
        return 0;
    }
};