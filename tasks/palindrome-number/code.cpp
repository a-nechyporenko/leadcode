class Solution {
public:
    bool isPalindrome(int num) {
        if(num < 0)
            return false;

        if(num == 0)
            return true;

        int temp = num;
        std::string numStr = std::to_string(num);
        std::string reverseNum;
        reverseNum.reserve(numStr.size());

        while (temp != 0) {
            int digit = temp % 10;
            reverseNum.append(std::to_string(digit));
            temp = temp / 10;
        }

        return (numStr == reverseNum);
    }
};