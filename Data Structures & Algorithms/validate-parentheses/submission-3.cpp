class Solution {
public:
    bool isValid(string s) {
        // stack<char> st;
        // for(int i=0; i<s.size(); i++){
        //     if(s[i] == '(' || s[i] == '{' || s[i] == '['){
        //         st.push(s[i]);
        //     }
        //     else{
        //         if (st.empty()) return false;
        //         else if(s[i] == ')' && st.top() == '('){
        //             st.pop();
        //         }
        //         else if(s[i] == '}' && st.top() == '{'){
        //             st.pop();
        //         }
        //         else if(s[i] == ']' && st.top() == '['){
        //             st.pop();
        //         }
        //         else{
        //             return false;
        //         }
        //     }
        // }
        // if(st.empty()){
        //     return true;
        // }
        // return false;



        stack<int> st;
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char c:s){
            if(m.find(c) != m.end()){
                if(st.empty() || st.top() != m[c]){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};
