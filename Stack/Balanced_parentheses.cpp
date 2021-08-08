//IN A GIVEN EXPRESSION CHECKING WHETHER ALL PARANTHESES ARE BALANCED
#include<bits/stdc++.h>
using namespace std;
bool can(char x,char y)
    {
        if(x=='(' && y==')') return true;
        
        if(x=='{' && y=='}') return true;
        
        if(x=='[' && y==']') return true;
        
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
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            
            else
            {
                    if(st.empty()) 
                    {
                        balanced=false;
                        break;
                     }
                    char temp=st.top();
                
                    st.pop();
                
                    if(!can(temp,s[i]))
                    {
                       balanced=false;
                        break;
                    }
            }
        }
        
    if(balanced && st.empty()) cout<<"EXPRESSION IS BALANCED\n";
    else cout<<"EXPRESSION IS NOT BALANCED\n";
}
