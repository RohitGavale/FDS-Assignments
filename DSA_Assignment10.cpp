/*
Assignment 10
Problem Statement : 
Simulation of pizza parlor: Pizza parlor accepting maximum M orders. 
Orders are served on a first come first served basis. Order once placed 
cannot be canceled.  
Write C++  program to simulate the system using simple queue or circular 
queue
*/

#include<iostream>
using namespace std;

const int Max_Orders = 5;

class Pizza 
{
    private : 
       int front , rear;
       int orders[Max_Orders];

    public : 
       Pizza()
       {
          front = -1;
          rear = -1;
       }   

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }      
    bool isFull()
    {
        return (rear + 1) % Max_Orders == front;
    }

    void PlaceOrder(int orderId)
    {
       if(isFull())
       {
          cout<<"Sorry , the Pizza Parlor is Full. Cannot Accept more Orders. "<<endl;
       }
       else
       {
            if(isEmpty())
            {
                 front = rear = 0;
            }
            else
            {
                 rear = (rear + 1) % Max_Orders;
            }     
                 orders[rear] = orderId;
                 cout<<"Order "<<orderId<<" Placed Successfully. "<<endl;
        }
    }
    
    void ServeOrder()
    {
        if(isEmpty())
        {
            cout<<"No Orders to Serve. The Pizza Parlor is Empty. "<<endl;
        }
        else 
        {
            int serveOrderId = orders[front];
            cout<<"Order "<<serveOrderId<<" Served. "<<endl;

            if(front == rear)
            {
                front = rear = -1;
            }
            else 
            {
                front = (front + 1) % Max_Orders;
            }
        }
    }

    void DisplayOrder()
    {
        if(isEmpty())
        {
            cout<<"No Orders in the Queue. "<<endl;
        }
        else 
        {
            cout<<"Current Oders in the Queue : "<<endl;
            int i = front;
            do{
                cout<<"Order "<<orders[i]<<endl;
                i = (i + 1) % Max_Orders;
            }while(i != (rear + 1) % Max_Orders);
        }
    }
};

int main()
{
    Pizza p;
    int choice , orderId;
    char ch;

    do {
         cout<<"----------------------MENU-----------------------"<<endl;
         cout<<"Placed Order. "<<endl;
         cout<<"Serve Order. "<<endl;
         cout<<"Display Current Orders. "<<endl;
         cout<<"Enter Your Choice : ";
         cin>>choice;

         switch(choice)
         {
            case 1 : cout<<"Enter the Order ID : ";
                     cin>>orderId;
                     p.PlaceOrder(orderId);
            break;

            case 2 : 
                     p.ServeOrder();
            break;

            case 3 : 
                     p.DisplayOrder();
            break;

            default : cout<<"Invalid Choice. "<<endl;                            

         }
            cout<<"Do you Want to Continue? (y / n) : ";
            cin>>ch;
    }while(ch == 'Y' || ch == 'y');

            cout<<"Thank You. Visit Again. "<<endl;

    return 0;          
}


