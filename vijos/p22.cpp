class Solution {
public:
    vector<string> ans;
    void findSolution(string solution, int count, string tmp){
        if(count != 0){
            solution += '(';
            tmp += '(';
            findSolution(solution, count-1, tmp);
            solution.pop_back();
            tmp.pop_back();
            if(solution.size() > 0){
                solution.pop_back();
                tmp += ")";
                findSolution(solution, count, tmp);
            }
        }
        else{
            for(int i=0; i<solution.size(); i++){
                tmp += ")";
            }
            ans.push_back(tmp);
        }
    }
    vector<string> generateParenthesis(int n) {
        string a = "";
        string tmp = "";
        findSolution(a, n, tmp);
        return ans;
    }
};