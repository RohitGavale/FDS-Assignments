/*
Assignment 8 
Problem Statement : 
Expression conversion: Write a menu driven C++ program for expression 
conversion and evaluation  
1. infix to prefix  
2. prefix to postfix  
3. prefix to infix  
4. postfix to infix  
5. postfix to prefix 
*/

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isOperator(char ch)
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
bool isOperand(char ch)
{
    return(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int getPrecedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    return 0;        
}

string InfixToPostfix(const string& infix)
{
   stack<char> s;
   string postfix = " ";

   for(char ch : infix)
   {
      if(isOperand(ch))
       {
         postfix += ch;
       }
      else if(ch == '(')
          s.push(ch);
      else if(ch == ')')
       {
             while(!s.empty() && s.top() != '(')
             {
                postfix += s.top();
                s.pop();
             } 
                s.pop();
       }    
      else if(isOperator(ch))
       {
           while(!s.empty() && getPrecedence(s.top()) >= getPrecedence(ch))
           {
             postfix += s.top();
             s.pop();
           }
             s.push(ch);
       }    
   } 
   while(!s.empty())
   {
     postfix += s.top();
     s.pop();
   } 
      return postfix;
}

string InfixToPrefix(const string& infix)
{
    string reversedInfix = " ";
    for(int i = infix.size() - 1; i >= 0; --i)
    {
        if(infix[i] == '(')
        {
            reversedInfix += ')';
        }
        else if(infix[i] == ')')
        {
            reversedInfix += '(';
        }
        else
        {
            reversedInfix += infix[i];
        }
    }

    string postfix = InfixToPostfix(reversedInfix);
    string prefix = " ";

    for(int i = postfix.size() - 1; i >= 0; --i)
    {
        prefix += postfix[i];
    }
        return prefix;
}

string PrefixToInfix(const string& prefix)
{
    stack<string> s;

    for(int i = prefix.size() - 1; i >= 0; --i)
    {
        if(isOperand(prefix[i]))
        {
            s.push(string(1 , prefix[i]));     // convert character to string 
        }
        else if(isOperator(prefix[i]))
        {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            s.push("(" + operand1 + prefix[i] + operand2 + ")");
        }
    }
        return s.top();
}

string PostfixToInfix(const string& postfix)
{
    stack<string> s;

    for(char ch : postfix)
    {
        if(isOperand(ch))
        {
            s.push(string(1 , ch));     // convert char to string 
        }
        else if(isOperator(ch))
        {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            s.push("(" + operand1 + ch + operand2 + ")");
        }
    }
        return s.top();
}

string PostfixToPrefix(const string& postfix)
{
    stack<string> s;

    for(char ch : postfix)
    {
        if(isOperand(ch))
        {
            s.push(string(1 , ch));   // convert char to string 
        }
        else if(isOperator(ch))
        {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            s.push(ch + operand1 + operand2);
        }
    }   
        return s.top();      
} 
/*
string prefixToPostfix(string prefix) 
{
        string postfix;
        for (int i = prefix.size() - 1; i >= 0; i--) 
        {
            char ch = prefix[i];
            if (isalnum(ch)) 
            {
                operand.push(string(1, ch));
            } 
            else if (isOperator(ch)) 
            {
                string operand1 = operand.top();
                operand.pop();
                string operand2 = operand.top();
                operand.pop();
                string result = operand1 + operand2 + ch;
                operand.push(result);
            }
        }
        postfix = operand.top();
        return postfix;
}*/

int main()
{
    int choice;
    char ch;
    string expression;

    do{
         cout<<"-----------------------MENU-----------------------"<<endl;
         cout<<"1. Infix to Prefix. "<<endl;
         //cout<<"2. Prefix to Postfix. "<<endl;
         cout<<"3. Prefix to Infix. "<<endl;
         cout<<"4. Postfix to Infix. "<<endl;
         cout<<"5. Postfix to Prefix. "<<endl;
         cout<<"6. Exit. "<<endl;
         cout<<"Enter Your Choice : ";
         cin>>choice;

         switch(choice)
         {
             case 1 : cout<<"Enter Infix Expression : ";
                      cin>>expression;
                      cout<<"Prefix Expression : "<<InfixToPrefix(expression)<<endl;
             break;

             //case 2 : cout<<"Enter Prefix Expression : ";
               //       cin>>expression;
                 //     cout<<"Postfix Expression : "<<prefixToPostfix(expression)<<endl;
             break;

             case 3 : cout<<"Enter Prefix Expression : ";
                      cin>>expression;
                      cout<<"Infix Expression : "<<PrefixToInfix(expression)<<endl;
             break;

             case 4 : cout<<"Enter Postfix Expression : ";
                      cin>>expression;
                      cout<<"Infix Expression : "<<PostfixToInfix(expression)<<endl;
             break;

             case 5 : cout<<"Enter Postfix Expression : ";
                      cin>>expression;
                      cout<<"Prefix Expression : "<<PostfixToPrefix(expression)<<endl;
             break;

             case 6 : cout<<"Existing Program. "<<endl;
             break;

             default : cout<<"Invalid Choice. "<<endl;
         }
             cout<<"Do you Want to Continue? (y / n) : ";
             cin>>ch;
    }while(ch == 'Y' || ch == 'y');

      cout<<"Thank You...!!! "<<endl;

      return 0;
}




