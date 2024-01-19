/*
Assignment 9
Problem Statement : 
String operations: A palindrome is a string of characters that's identical 
when read in forward and backward direction. Typically, punctuation, 
capitalization, and spaces are ignored. For example, “1.Poor Dan is in a 
droop!!” is a palindrome, as can be seen by examining the characters 
“poordanisinadroop” and observing that they are identical when read 
forward and backward directions. One way to check for a palindrome is to 
reverse the characters in the string and  compare them with the original-in a 
palindrome, the sequence will be identical.  
Write C++ program with functions using Standard Template Library (STL) 
stack- 
1.  To print original string followed by reversed string using stack 
2.  To check whether given string is palindrome or not 
*/

#include<iostream>
#include<stack>
using namespace std;

class Stack 
{
   public : 
      stack<string>myStack;
      stack<string>temp1;
      stack<string>newStack;
      stack<string>temp2;

      void input()
      {
         string str;
         cout<<"Enter the String : ";
         getline(cin , str);

         string element;
         for(int i = 0; i < str.length(); i++)
         {
            if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                element = (tolower(str[i]));
                myStack.push(element);
            }
         }
      }

      void display()
      {
         int n;
         string str1;
         string str2;
         cout<<"Original Stack : "<<endl;
         while(!myStack.empty())
         {
            cout<<myStack.top()<<"\t";
            str1 = myStack.top();
            newStack.push(str1);
            temp1.push(str1);
            myStack.pop();
         }
            cout<<endl;

         cout<<"Reversed Stack : "<<endl;
         while(!newStack.empty())
         {
            cout<<newStack.top()<<"\t";
            str2 = newStack.top();
            temp2.push(str2);
            newStack.pop();
         }   
            cout<<endl;

         if(temp1.top() == temp2.top())
         {
            cout<<"Given String is Palindrome. "<<endl;
            temp1.pop();
            temp2.pop();
         } 
         else
         {
            cout<<"Given String is Not Palindrome. "<<endl;
         }   
      }
};

int main()
{
    stack<int>myStack;
    Stack obj;
    obj.input();
    obj.display();

    return 0;
}

