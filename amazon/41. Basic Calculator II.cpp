//227. Basic Calculator II
//https://leetcode.com/problems/basic-calculator-ii/
class Solution {
public:
    int calculate(string s) {
        stack<pair<int,bool> > stk;
        bool flag = true;
        int res=0;
        int tmp_num=0;
        int tmp_mul=0;
        int tmp_div=0;
        for(int i=0 ; i<s.size() ;){
            if(isspace(s[i])){
                i++;
                continue;
            }
            if(isdigit(s[i])){
                tmp_num = tmp_num*10 + (s[i++]-'0');
                continue;
            }
            if(s[i]=='+' || s[i]=='-'){
                stk.push({tmp_num,flag});
                if(s[i]=='+')
                    flag = true;
                else if(s[i]=='-')
                    flag = false;
                tmp_num=0;
                i++;
            }
            else if(s[i]== '*' || s[i] =='/'){
                if(s[i] == '*'){
                    i++;
                    while(isspace(s[i]))i++;
                    while(i<s.size()&&isdigit(s[i])){
                        tmp_mul = tmp_mul*10 + (s[i++]-'0');
                    }
                    tmp_num *= tmp_mul;
                    tmp_mul=0;
                }
                else if(s[i]=='/'){
                    i++;
                    while(isspace(s[i]))i++;
                    while(i<s.size()&&isdigit(s[i]))
                        tmp_div = tmp_div*10 + (s[i++]-'0');
                    tmp_num /=tmp_div;
                    tmp_div=0;
                }
            }              
        }
        if(flag)
            res = tmp_num;
        else
            res = -1*tmp_num;
        while(!stk.empty()){
            int num = stk.top().first;
            bool flag = stk.top().second;
            stk.pop();
            if(flag)
                res += num;
            else if(!flag)
                res -= num;
        }
        return res;
    }
};