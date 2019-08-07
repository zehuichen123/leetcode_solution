class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool hasNext = true;
        int ptr = digits.size()-1;
        do{
            if(ptr >= 0 && hasNext){
                int sum = digits[ptr] + int(hasNext);
                digits[ptr] = sum % 10;
                hasNext = sum / 10;
                ptr -= 1;
            }
            else if(hasNext){
                digits.insert(digits.begin(), 1);
                break;
            }
            else{
                break;
            }
        }while(true);
        return digits;
    }
};