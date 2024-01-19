/*
Assignment 12 
Problem Statement : 
Searching: Write a C++ program to store roll numbers of students in an 
array who attended online lectures in random order. Write function for 
searching, whether a particular student attended lecture  or not using  
1.  Linear search  
2.  Binary search  
3.  Jump search  
compare the searching methods based on complexities of an algorithm 
Provide choice to user to take input from user or using random numbers 
Use Visual C++ compiler to compile and execute the program. 
*/

#include<iostream>
using namespace std;

class Searching
{
    public : 
       void linear(int a[] , int size)
       {
          int key;
          cout<<"Enter the Roll Number of Students to Find if he Attended the Lectures or Not. "<<endl;
          cin>>key;
          int found = 0;
          for(int i = 0; i < size; i++)
          {
             if(a[i] == key)
             {
                cout<<"Student Has Attended the Online Lectures. "<<endl;
                found = 1;
                break;
             }
          }
          if(found == 0)
          {
             cout<<"Student Has Not Attended the Online Lectures. "<<endl;
          }
       }

       void bubble(int a[] , int size)
       {
          for(int i = 0; i < size; i++)
          {
             int flag = 0;
             for(int j = 0; j < size - 1 - i; j++)
             {
                if(a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    flag = 1;
                }
             }
             if(flag == 0)
             break;
          }
       }

       int binary(int a[] , int size)
       {
          int l = 0;
          int r = size - 1;
          int mid = (l + r)/2;
          int key;
          int found = 0;
          cout<<"Enter the Roll No. of Students to Find if he Attended the Online Lectures or Not. "<<endl;
          cin>>key;

          while(l <= r)
          {
             if(key == a[mid])
             {
                cout<<"Student Has Attended Online Lectures. "<<endl;
                found = 1;
                break;
             }
             else if(key < a[mid])
             {
                r = mid - 1;
             }
             else if(key > a[mid])
             {
                l = mid + 1;
             }
             mid = (l + r) / 2;
          }

          if(found == 0)
          {
             cout<<"Student Has Not Attended the Online Lectures. "<<endl;
          } 
            return -1;

       }
};

int main()
{
    int n;
    char ch;
    cout<<"Enter Total No. of Students : ";
    cin>>n;
    int a[n];
    cout<<"Enter the Roll No. of Students who Attended the Online Lectures : "<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    Searching op;
    int x;
    do{
         cout<<"---------------------MENU-------------------------"<<endl;
         cout<<"1. Searching Using Linear Search. "<<endl;
         cout<<"2. Searching Using Binary Search. "<<endl;
         cout<<"Enter Your Choice : ";
         cin>>x;

         switch(x)
         {
            case 1 : 
                      op.linear(a , n);
            break;

            case 2 : 
                      op.bubble(a , n);
                      op.binary(a , n);
            break;

            default : cout<<"Invalid Choice. "<<endl;          
         }
            cout<<"Do you Want to Continue? (y / n) : ";
            cin>>ch;
    }while(ch == 'Y' || ch == 'y');

        cout<<"Thank You...!!! "<<endl;

    return 0;    
}



