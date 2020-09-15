// ZigZag Conversion

// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

// 请你实现这个将字符串进行指定行数变换的函数：

// string convert(string s, int numRows);
// 示例 1:

// 输入: s = "LEETCODEISHIRING", numRows = 3
// 输出: "LCIRETOESIIGEDHN"

class Solution {
public:
    string convert(string s, int numRows) {
        int circle_size = numRows * 2 - 2;
        if(circle_size == 0){
            return s;
        }
        string ans = "";
        for(int i=0; i<numRows; i++){
            if(i == 0 || i == numRows-1){
                int ptr = i;
                while(ptr < s.length()){
                    ans += s[ptr];
                    ptr += circle_size;
                }
            }
            else{
                int ptr = i, ptr2 = circle_size - i;
                while(ptr < s.length()){
                    ans += s[ptr];
                    ptr += circle_size;
                    if(ptr2 < s.length()){
                        ans += s[ptr2];
                        ptr2 += circle_size;
                    }
                }
                if(ptr2 < s.length()){
                    ans += s[ptr2];
                    ptr2 += circle_size;
                }
            }
        }
        return ans;
    }
};