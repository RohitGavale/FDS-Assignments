/*
Assignment 5 
Problem Statement : 
Polynomial operations: Write a menu driven C++ program with class for 
single variable polynomial and write functions to perform following 
polynomial operations using arrays  
1. Read polynomial 
2. Display polynomial 
3. Add two polynomials  
You can try above polynomial operation using Linked list.
*/

#include<iostream>
using namespace std;

struct Expression 
{
   int coef;
   int expo;
}; Expression e;

class Polynomial 
{
   public : 
      Expression e[50];
      int total_terms , i , j , k;

      Polynomial()
      {
        total_terms = 0;
      }

      void read();
      void display();
      Polynomial add(Polynomial);
};

Polynomial Polynomial :: add(Polynomial B)
{
    int i = 0 , j = 0 , k = 0;
    Polynomial C;

    while(i < total_terms && j < B.total_terms)
    {
        if(e[i].expo == B.e[j].expo)
        {
            C.e[k].coef = e[i].coef + B.e[j].coef;
            C.e[k].expo = e[i].expo;
            i++;
            j++;
            k++;
        }
        else if(e[i].expo > B.e[j].expo)
        {
            C.e[k].coef = e[i].coef;
            C.e[k].expo = e[i].expo;
            i++;
            k++; 
        }
        else
        {
            C.e[k].coef = B.e[j].coef;
            C.e[k].expo = B.e[j].expo;
            k++;
            j++;
        }
    }
    while(i < total_terms)
    {
        C.e[k].expo = e[i].expo;
        C.e[k].coef = e[i].coef;
        k++;
        i++;
    }
    while(j < B.total_terms)
    {
        C.e[k].expo = B.e[j].expo;
        C.e[k].coef = B.e[j].coef;
        k++;
        j++;
    }
        C.total_terms = k;
        return C;
}

void Polynomial :: display()
{
    for(int i = 0; i < total_terms; i++)
    {
        cout<<e[i].coef<<"x^"<<e[i].expo<<"+";
    }
}

void Polynomial :: read()
{
    cout<<"Enter the Total Number of Variables : ";
    cin>>total_terms;
    for(int i = 0; i < total_terms; i++)
    {
        cout<<"Enter the Coefficient : ";
        cin>>e[i].coef;
        cout<<"Enter the Exponent : ";
        cin>>e[i].expo;
    }
}

int main()
{
   char ch;
   Polynomial p , q , r;
   int op;

   do{
        cout<<"-------------------MENU-----------------------"<<endl;
        cout<<"1. Read Polynomial. "<<endl;
        cout<<"2. Display Polynomial. "<<endl;
        cout<<"3. Add Polynomial. "<<endl;
        cout<<"Enter Your Choice : ";
        cin>>op;

        switch(op)
        {
            case 1 : p.read();
                     q.read();
            break;

            case 2 : cout<<"Polynomial 1 : ";
                     p.display();
                     cout<<endl;
                     cout<<"Polynomial 2 : ";
                     q.display();
                     cout<<endl;
            break;

            case 3 : cout<<"Addition of Polynomials : ";
                     r = p.add(q);
                     r.display();
                     cout<<endl;
            break;

            default : cout<<"Invalid Choice. "<<endl;
            break;                           
        } 
            cout<<"Do you want to Continue? (y / n) : ";
            cin>>ch;
   } while(ch == 'Y' || ch == 'y');
     
     cout<<"Thank You...!!! "<<endl;

     return 0;
}



