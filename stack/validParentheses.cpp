class Solution {
public:
    bool isValid(string s) {
        // i will take the ( 
        // if ) mean i am reading but stack is empty so return false
        stack<char> st;
        for(char &c: s)
        {
            if(c=='('|| c=='{'|| c=='[')
            {
                st.push(c);
            }
            else{
                char top = st.top();
                if(st.empty())return false;
                else if(top=='(' && c==')')st.pop();
                else if(top=='[' && c==']')st.pop();
                else if(top=='{' && c=='}')st.pop();
                else return false;
            }
        }
        return st.empty()?true:false;
    }
};
