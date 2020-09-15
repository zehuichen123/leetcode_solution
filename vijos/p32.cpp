class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>_stack = {};
        _stack.push(-1);
        int max_count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                _stack.push(i);
            }
            else{
                _stack.pop();
                if(_stack.empty()){
                    _stack.push(i);
                }
                else{
                    max_count = max(i - _stack.top(), max_count);
                }
            }
        }
        return max_count;
    }
};