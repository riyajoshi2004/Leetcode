class Solution {
public:
    bool checkValidString(string s) {

        int openMin = 0;   // minimum possible unmatched '('
        int openMax = 0;   // maximum possible unmatched '('

        for(char ch : s){

            if(ch == '('){
                openMin++;
                openMax++;
            }

            else if(ch == ')'){
                openMin--;
                openMax--;
            }

            else{ // '*'
                openMin--;   // treat '*' as ')'
                openMax++;   // or treat '*' as '('
            }

            if(openMax < 0)
                return false;

            if(openMin < 0)
                openMin = 0;
        }

        return openMin == 0;
    }
};