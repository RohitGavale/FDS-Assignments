/*
Assignment 3
Problem Statement : 
String Operations: Write a menu driven C++ program with a class for 
String. Write  functions  
1. To determine the frequency of occurrence of a particular character 
in the string. 
2. Extract a new string from original string by accepting starting 
position and length  
3. To accept any character and return the string with by removing all 
occurrences of a character accepted 
4. To make an in-place replacement of a substring w of a string by the 
string x. Note that w may not be of same size that of x 
5. To check whether given string is palindrome or not
*/

#include<iostream>
#include<string.h>
using namespace std;

static char str1[50] , str2[50];

void getString1()
{
    cout<<"Enter String 1 : ";
    cin>>str1;
}
void getString2()
{
    cout<<"Enter String 2 : ";
    cin>>str2;
}

void frequency(char c)   // calculate the frequency of character 
{
    int count = 0;
    int i = 0;
    while(str1[i] != '\0') 
    {
        if(str1[i] == c)
        {
            count++;
        }
       i++;
    }
       cout<<"Frequency of "<<c<<" is "<<count<<endl;
}

void subString(int pos , int len)     // Extracting a substring by pos and len
{
    for(int i = pos - 1; i < len; i++)
    {
        cout<<str1[i]<<endl;
    }
}

void remove(int c)       // Removing a specific character 
{
    int i = 0;
    while(str1[i] != '\0')
    {
        if(str1[i] == c)
        {
            i++;
            continue;
        }
          cout<<str1[i]<<endl;
          i++;
    }
}

/*
void replace()
{
    int len = strlen(str2);
    getString2();

    for(int i = 0; str1[i] != '\0'; i++)
    {

    }
}
*/

void palindrome()
{
    int flag;
    int left = 0;
    int right = strlen(str1) - 1;
    while(str1[left] != '\0')
    {
        if(str1[left] == str1[right])
        {
            left++;
            right--;
            flag = 1;
        }
        else 
        {
            flag = 2;
            break;
        }
    }
    if(flag == 1)
    {
        cout<<"String is Palindrome. "<<endl;
    }
    if(flag == 2)
    {
        cout<<"String is Not Palindrome. "<<endl;
    }
}

int main()
{
    char ch , c;
    int op , pos , len;

    do{
         cout<<"-------------------MENU----------------------"<<endl;
         cout<<"1. Determine the Frequency of Particular Character. "<<endl;
         cout<<"2. Extract new String by Position and Length. "<<endl;
         cout<<"3. Remove the Occurrences. "<<endl;
         cout<<"4. Replace Substring. "<<endl;
         cout<<"5. Check String is Palindrome or Not. "<<endl;
         cin>>op;
         getString1();

         switch(op)
         {
            case 1 : cout<<"Enter a Character : ";
                     cin>>c;
                     frequency(c);
            break;

            case 2 : cout<<"Enter the Position : ";
                     cin>>pos;
                     cout<<"Enter the Length : ";
                     cin>>len;
                     subString(pos , len);
            break;

            case 3 : cout<<"Enter Character to be Removed : ";
                     cin>>c;
                     remove(c);
            break;

            case 4 :  

            break;

            case 5 : palindrome();

            break;

            default : cout<<"Invalid Choice. "<<endl;

         }
            cout<<"Do you Want to Continue? (y / n) : ";
            cin>>ch;
    }while(ch == 'Y' || ch == 'y');

    cout<<"Thank You...!!! "<<endl;

    return 0;
}



