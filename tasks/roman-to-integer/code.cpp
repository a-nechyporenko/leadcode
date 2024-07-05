


class Solution {
public:
    int romanToInt(string s) {
        if(s.empty())
            return 0;

        std::transform(s.begin(), s.end(), s.begin(), 
                [](unsigned char c){ return std::toupper(c); }
                );
        
        int result = 0;

        for(int i = s.size() - 1; i >= 0; --i)
        {
            switch(s[i])
            {
                case 'I':
                result += 1;
                break;
                case 'V':
                if(i - 1 >= 0 && s[i-1] == 'I')
                { 
                    result += 4;
                    --i;
                }
                else
                {
                    result += 5;
                }
                break;
                case 'X':
                if(i - 1 >= 0 && s[i-1] == 'I')
                { 
                    result += 9;
                    --i;
                }
                else
                {
                    result += 10;
                }
                break;
                case 'L':
                if(i - 1 >= 0 && s[i-1] == 'X')
                { 
                    result += 40;
                    --i;
                }
                else
                {
                    result += 50;
                }
                break;
                case 'C':
                if(i - 1 >= 0 && s[i-1] == 'X')
                { 
                    result += 90;
                    --i;
                }
                else
                {
                    result += 100;
                }
                break;
                case 'D':
                if(i - 1 >= 0 && s[i-1] == 'C')
                { 
                    result += 400;
                    --i;
                }
                else
                {
                    result += 500;
                }
                break;
                case 'M':
                if(i - 1 >= 0 && s[i-1] == 'C')
                { 
                    result += 900;
                    --i;
                }
                else
                {
                    result += 1000;
                }
                break;
                default:
                std::cout << "Error, char:" << s[i] << "was n`t hadle";
                break;
            }
        }

        return result;
    }
};