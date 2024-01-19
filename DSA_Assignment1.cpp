/*
Assignment 1 
Problem Statement : 
Set operations: Write a menu driven C++ program to store sets for 
students' names participating in different events in Equinox such as Coding 
contest, Project competition, Paper Presentation, MasterMind etc. 
1. Find out participants who have participated in Coding and Project 
both 
2. Find out participants who have participated in Coding or Project 
competition or  both or Mastermind 
3. Find out participants who have participated in Coding but not in  
Master mind  
 Find out participants who have participated in all events
*/

#include<iostream>
using namespace std;

class Student 
{
    public : 
       string name; 
       int  event1 , event2 , event3 , event4;

    void input()
     {
        cout<<"Enter Your Name : ";
        cin>>name;
        cout<<"Please Answer Below Question Related to Equinox , '1' for Yes and '0' for No. "<<endl;
        cout<<"Have you Participated in Coding Contest? : ";
        cin>>event1;
        cout<<"Have you Participated in Project Competition? : ";
        cin>>event2;
        cout<<"Have you Participated in Paper Presentation? : ";
        cin>>event3;
        cout<<"Have you Participated in MasterMind? : ";
        cin>>event4;
     }    
};

int main()
{
        char ch; 
        int n;
        cout<<"Enter Number of Student : ";
        cin>>n;
        Student s[n];

        for(int i = 0; i < n; i++)
         {
            cout<<"For Student "<<i+1<<endl;
            s[i].input();
         }    

    do{  
        int k;
        cout<<"Enter 1 to Know the Student who Participated in Coding Contest and Project Competition. "<<endl;
        cout<<"Enter 2 to Know the Student who Participated in Coding Contest or Project Competition or Both or MasterMind. "<<endl;  
        cout<<"Enter 3 to Know the Student who Participated in Coding Contest But not in MasterMind. "<<endl;
        cout<<"Enter 4 to Know the Student who Participatee in All Events. "<<endl;
        cout<<"Enter 5 to Know the Student who Does not Participated in Any Event. "<<endl;
        cin>>k;

        switch(k)
        {
            case 1 :  for(int i = 0; i < n; i++)
                        {
                            if(s[i].event1 == 1 && s[i].event2 == 1)
                              {
                                 cout<<s[i].name<<endl;
                              }
                        }
            break;

            case 2 : for(int i = 0; i < n; i++)
                       {
                            if((s[i].event1 == 1 || s[i].event2 == 1) || (s[i].event1 == 1 && s[i].event2 == 1) || (s[i].event4 == 1))
                              {
                                 cout<<s[i].name<<endl;
                              }
                       }
            break;

            case 3 : for(int i = 0; i < n; i++)
                        {
                            if(s[i].event1 == 1 && s[i].event4 == 0) 
                              {
                                 cout<<s[i].name<<endl;
                              }
                        }

            case 4 : for(int i = 0; i < n; i++)
                        {
                            if(s[i].event1 == 1 && s[i].event2 == 1 && s[i].event3 == 1 && s[i].event4 == 1)
                              {
                                 cout<<s[i].name<<endl;
                              }
                        }                                         
            break;

            case 5 : for(int i = 0; i < n; i++)
                        {
                            if(s[i].event1 == 0 && s[i].event2 == 0 && s[i].event3 == 0 && s[i].event4 == 0)
                               {
                                  cout<<s[i].name<<endl;
                               }
                        }
            break;            

            default : cout<<"Please Enter Correct Choice. "<<endl;         
        }
            cout<<"Do you Want to Continue? (y / n) : ";
            cin>>ch;
    } while(ch == 'y' || ch == 'Y');

      cout<<"Thank You...!!!";

    return 0;
}





