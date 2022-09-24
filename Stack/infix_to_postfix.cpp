#include <bits/stdc++.h>
using namespace std;

string convert_infix_to_postfix(string infix)
{
    unordered_map<char, int> rank;
    rank['+'] = rank['-'] = 1;
    rank['*'] = rank['/'] = 2;
    rank['^'] = 3;
    rank['('] = 0;
    rank[')'] = 4;

    string postfix = "";
    stack<char> st;

    for (char ch : infix)
    {
        if (rank.find(ch) == rank.end())
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (st.size() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (st.size() && rank[st.top()] >= rank[ch])
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    string postfix = convert_infix_to_postfix(infix);
    cout << "Infix: " << infix;
    cout << "\nPostfix: " << postfix;

    return 0;
}

/*
Convert the given infix expression to postfix expression.

NOTE: We can use this postfix expression to solve an arithematic expression

To convert infix expression to prefix expression:
1. Reverse the input string
2. Convert the reversed string to postfix
3. Reverse the obtained string

*/