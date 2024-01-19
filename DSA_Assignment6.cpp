/*
Assignment 6
Problem Statement : 
Linked list operations: Create a linked list of names and birthdays of 
students. Write a menu driven C++ program to perform following 
operations 
1. Insert name and birthday of new student 
2. Delete a student entry 
3. Display a happy birthday message for whom today (based on 
system date) is birthday 
4. Display list of students with their birthdays. 
*/

#include<iostream>
#include<ctime>
#include<iomanip>
#include <sstream>

using namespace std;

static string name , dob , d;
class Node
{
    public : 
        string name;
        string dob;
        Node *next;

        Node(string name , string dob)
        {
            this -> name = name;
            this -> dob = dob;
        }
};

class Student 
{
    public : 
       Node *head = NULL;
       Node *tail = NULL;
       void create(string name , string dob);
       void display();
       void remove(string name);
       void wish();
};

void Student :: create(string name , string dob)
{
    Node *temp = new Node(name , dob);
    if(head == NULL)
    {
        head = temp;
    }
    else 
    {
        tail -> next = temp;
    }
        tail = temp;
}

void Student :: display()
{
    int count = 1;
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<count<<" "<<"Name : "<<temp -> name<<endl<<" "<<"Birth Date : "<<temp -> dob<<endl;
        temp = temp -> next;
        count++;
    }
}

void Student :: remove(string name)
{
   Node *temp = head;
   if(temp == NULL)
    {
        cout<<"Linked List is Empty. "<<endl;
    }
    if(head -> name == name)
    {
        Node *d = head;
        head = head -> next;
        delete d;
        return;
    }
    while(temp -> next -> name != name && temp -> next != NULL)
    {
        temp = temp -> next;
    }
    if(temp -> next != NULL)
    {
        Node *d = temp -> next;
        temp -> next = temp -> next -> next;
        delete d;
    }
}

void Student :: wish()
{
    int flag = 0;
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp -> dob.substr(0 , 4) == d.substr(0 , 4))
        {
            cout<<"Happy BirthDay "<<temp -> name<<endl;
            flag = 1;
        }
            temp = temp -> next;
    }
    if(flag == 0)
    {
        cout<<"There is No Birthday Today. "<<endl;
    }
}

void insert()
{
    cout<<"Enter the Name : ";
    cin>>name;
    cout<<"Enter Birth Date : ";
    cin>>dob;
}

int main()
{
    time_t ct = time(0);
    tm* timeInfo = localtime(&ct);
    stringstream bdate;
    bdate<<put_time(timeInfo, "%d/%m");
    string date = bdate.str();
    cout<<date;
    d = date;

    char ch;
    int op;
    Student s;

    do{
         cout<<"-----------------------MENU--------------------------"<<endl;
         cout<<"1. Insert Name and Birthday. "<<endl;
         cout<<"2. Display All Information. "<<endl;
         cout<<"3. Delete Student Entry. "<<endl;
         cout<<"4. Wish Happy BirthDay. "<<endl;
         cout<<"Enter Your Choice : ";
         cin>>op;
         switch(op)
         {
            case 1 : insert();
                     s.create(name , dob);
            break;

            case 2 : s.display();
            break;

            case 3 : cout<<"Enter the name to be Deleted : ";
                     cin>>name;
                     s.remove(name);
                     cout<<"Name Deleted Successfully. "<<endl;
            break;

            case 4 : s.wish();
            break;

            default : cout<<"Invalid Choice. "<<endl;         
         }
            cout<<"Do you Want to Continue? (y / n) : ";
            cin>>ch;
    }while(ch == 'Y' || ch == 'y');
      cout<<"Thank You...!!! "<<endl;

    return 0;
}




