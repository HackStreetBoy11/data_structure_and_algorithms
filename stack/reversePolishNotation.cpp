class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // make a stack 
        // take a and b perform operation and send back to stack
        // return top of stack value
        if(tokens.size()==0)return 0;
        stack<int> st;
        for(string &c:tokens)
        {   
            if(c=="+"|| c=="-"|| c=="/"||c=="*")
            {
                if(c=="+")
                {
                    int top_first= st.top();st.pop();
                    int top_second = st.top();st.pop();
                    st.push(top_first + top_second);
                }
                else if(c=="-")
                {
                    int top_first= st.top();st.pop();
                    int top_second = st.top();st.pop();
                    st.push(top_second-top_first);
                    
                }
                else if(c=="*")
                {
                    int top_first= st.top();st.pop();
                    int top_second = st.top();st.pop();
                    st.push(top_first*top_second);
                    
                }
                else
                {
                    int top_first= st.top();st.pop();
                    int top_second = st.top();st.pop();
                    st.push(top_second/top_first);
                }
            }
            else
            {
                int dig=stoi(c);
                st.push(dig);
            }
           
        }
        return st.top();
    }
};
