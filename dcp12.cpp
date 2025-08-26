#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isvalid(string s){
if(s.empty()==1){ 
    return true;
}
if(s.size()%2!=0){
    return false;
}
stack<char>st;
for(char c:s)
{ 
    if(c=='(' || c=='{' || c=='['){
        st.push(c);}
    else{
        if(st.empty()) return false;
        char top= st.top();
        if((c==')' && top =='(')||
           (c=='}' && top=='{') ||
           (c==']' && top=='[')){
            st.pop();
           }else{
            return false;
           }
    }
}
return st.empty();
}
int main()
    {
        string s;
        cout<<"enter a string of parentheses:";
        cin>>s;
        if(isvalid(s)){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    
    return 0;
}


