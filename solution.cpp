#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
        stack<char> stk;
        int l = s.length();
        for(int i=0; i<l; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else if (stk.empty() || s[i] == ')') {
                char x = stk.top();
                if ( x != '('){
                    stk.pop();
                    return false;
                }
            }
            else if (stk.empty() || s[i] == '}') {
                char x = stk.top();
                if ( x != '{'){
                    stk.pop();
                    return false;
                }
            }
            else if (stk.empty() || s[i] == ']') {
                char x = stk.top();
                if ( x != '[') {
                    stk.pop();
                    return false;
                }
            }
        }
        return true;
    }

int main() {
    // your code goes here
    string s = "{[]}";

    if(isValid(s)) {
        cout<<"True";
    }
    else {
        cout<<"false";
    }
   
    return 0;
}
