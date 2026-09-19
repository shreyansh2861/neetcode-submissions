class Solution {
public:
    bool isValid(string s) {
        stack<char> para;

        for(int i=0;i<s.size();i++){
            if(para.empty()){
                para.push(s[i]);
                continue;
            }
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                para.push(s[i]);
            }
            else if(s[i]==')'){
                if(para.top()=='('){
                    para.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(para.top()=='{'){
                    para.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(para.top()=='['){
                    para.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(!para.empty()){
            return false;
        }
        return true;
    }
};
