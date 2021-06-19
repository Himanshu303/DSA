//IN A GIVEN EXPRESSION CHECKING WHETHER ALL PARANTHESIS ARE BALANCED
#include<bits/stdc++.h>
using namespace std;
bool type(char x,char y)
{
    if(x=='(' && y==')') return true;
    if(x=='[' && y==']') return true;
    if(x=='{' && y=='}') return true;

    return false;
}
stack<char> st;
int main()
{
    string s;
    cout<<"ENTER EXPRESSION\n";
    cin>>s;
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<"\n";
    bool balanced=true;
    for(int i=0;i<s.size();i++)
    {   
        if(s[i]=='(' || s[i]=='[' ||s[i]=='{')
            st.push(s[i]);
        else if(s[i]==')' || s[i]==']' ||s[i]=='}')
        {
            if(st.empty()) 
            {
                balanced=false;
                break;
            }
            char temp=st.top();
            st.pop();
            if(!type(temp,s[i]))
            {
                balanced=false;
                break;
            }
        }
    }
    if(balanced && st.empty()) cout<<"EXPRESSION IS BALANCED\n";
    else cout<<"EXPRESSION IS NOT BALANCED\n";
}
