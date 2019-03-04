// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999
// https://leetcode.com/problems/integer-to-roman/


class Solution {
public:
    void convert(string& res, int value, char* ten, char* five, char* one) {
        if (value == 9) {
            res.insert(0, ten);
            res.insert(0, one);
        } else if (value == 4) {
            res.insert(0, five);
            res.insert(0, one);
        } else {
            int flag = 0;
            int data = value;
            if (data >= 5) {
                flag = 1;
                data -= 5;
            }
            for(int i = 0; i < data; i++) {
                res.insert(0, one);
            }
            if (flag) {
                res.insert(0, five);
            }
        }
    }
    string intToRoman(int num) {
        string res;
        int ones = num % 10;
        convert(res, ones, "X", "V", "I");
        int tens = (num / 10) % 10;
        convert(res, tens, "C", "L", "X");
        int hundreds = (num / 100) % 10;
        convert(res, hundreds, "M", "D", "C");
        int thousands = (num / 1000) % 10;
        convert(res, thousands, "z", "z", "M");
        return res;
    }
};
