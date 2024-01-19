/*
Assignment 7 
Problem Statement : 
Appointment Management: Write a menu driven C++ program for storing 
appointment schedules for the day.  
Appointments are booked randomly using linked lists. Set start and end 
time for visit slots. Write functions for 
1.  Display free slots  
2.  Book appointment  
3.  Cancel appointment ( check validity, time bounds, availability etc)  
4.  Sort list based on time  
5.  Sort list based on time using pointer manipulation  
*/

#include<iostream>
using namespace std;

class Appointment 
{
    public : 
        string name;
        string startTime;
        string endTime;
        Appointment* next;

        Appointment(string name , string startTime , string endTime)
        {
            this -> name = name;
            this -> startTime = startTime;
            this -> endTime = endTime;
            this -> next = NULL;
        }
};

Appointment* head = NULL;

void Book(int n)
{
    Appointment* node1 , *ptr;
    string name , startTime , endTime;
    int i;
    head = new Appointment(" " , " " , " ");
    
    if(head == NULL)
    {
        cout<<"Unable to Allocate Memory. "<<endl;
        return;
    }
    ptr = head;
    for(int i = 0; i <= n; i++)
    {
        node1 = new Appointment(" " , " " , " ");
            
            if(node1 == NULL)
            {
                cout<<"Unable to Allocate Memory. "<<endl;
                return;
            }
                cout<<"Enter the Name : ";
                cin>>name;
                cout<<"Enter the Start Time : ";
                cin>>startTime;
                cout<<"Enter the End Time : ";
                cin>>endTime;
                node1 -> name = name;
                node1 -> startTime = startTime;
                node1 -> endTime = endTime;
                node1 -> next = NULL;
                ptr -> next = node1;
                ptr = ptr -> next;
    }
}

void Free(Appointment* head)
{
    Appointment* ptr = head -> next;
    string stime = "08:00";
    string etime = "18:00";
    cout<<"Free Slots : "<<endl;

    while(ptr != NULL)
    {
        if(ptr -> startTime > stime)
        {
            cout<<"Free Slots : "<<stime<<" to "<<ptr -> startTime<<endl;
        }
            stime = ptr -> endTime;
            ptr = ptr -> next;
    }
    if(stime < etime)
    {
        cout<<"Free Slots : "<<stime<<" to "<<etime<<endl;
    }
}

void Cancel(Appointment* &head , string startTime , string endTime)
{
    cout<<"Enter the Start Time of Appointment to Cancel : ";
    cin>>startTime;

    if(head == NULL)
    {
        cout<<"No Appointment Found at That Time. "<<endl;
        return;
    }
    if(head -> startTime == startTime)
    {
        Appointment* ptr = head;
        head = head -> next;
        delete ptr;
        cout<<"Appointment Canceled Successfully. "<<endl;
        return;
    }
    
    Appointment* ptr2 = head;
    while(ptr2 -> next != NULL)
    {
        if(ptr2 -> next -> startTime == startTime)
        {
            Appointment* ptr = ptr2 -> next;
            ptr2 -> next = ptr2 -> next -> next;
            delete ptr;
            cout<<"Appointment Canceled Successfully. "<<endl;
            return;
        }
            ptr2 = ptr2 -> next;
    }
        cout<<"No Appointment Found at That Time. "<<endl;
}

void sorting(Appointment* &head)
{
    Appointment* ptr = head -> next;
    Appointment* index = NULL;
    string temp;

    if(head == NULL)
    {
        return;
    }
    else 
    {
        while(ptr != NULL)
        {
            index = ptr -> next;
            while(index != NULL)
            {
                if(ptr -> startTime > index -> startTime)
                {
                    temp = ptr -> startTime;
                    ptr -> startTime = index -> startTime;
                    index -> startTime = temp;
                }
                    index = index -> next;
            }
               ptr = ptr -> next;
        }
    }
}

void Display()
{
    Appointment* ptr = head -> next;
    while(ptr != NULL)
    {
        cout<<ptr -> name<<" "<<ptr -> startTime<<" to "<<ptr -> endTime<<endl;
        ptr = ptr -> next;
    }
        cout<<"-----------------------------------------------------"<<endl;
}

int main()
{
    int n;
    cout<<"Enter Number of Appointments for Today : ";
    cin>>n;
    Book(n);
    Display();

    sorting(head);
    Display();
    Free(head);
    cout<<"----------------------------------------------------------"<<endl;
    string startTime , endTime;
    Cancel(head , startTime , endTime);
    Free(head);
    cout<<"----------------------------------------------------------"<<endl;

    return 0;
}




