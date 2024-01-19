/*
Assignment 4
Problem Statement : 
Sparse Matrix: Write a menu driven C++ program with class for Sparse 
Matrix. Write  functions to perform Sparse Matrix operations as listed 
below 
1. Read sparse matrix 
2. Display sparse matrix 
3. Add two sparse matrices 
4. Find transpose using Simple transpose algorithm 
5. Find transpose using Fast transpose algorithm 
Compare complexity of simple and fast transpose using counter. 
*/

#include<iostream>
using namespace std;

class Sparse
{
    public : 
       int mat[10][3];
       int m;

       void addition(Sparse &mat2);
       void fast();
       void simple();

       void accept()
       {
         cout<<"Enter Number of Rows : ";
         cin>>m;
         cout<<"Enter Elements of your Matrix : ";
         for(int i = 0; i < m; i++)
         {
            for(int j = 0; j < 3; j++)
            {
                cin>>mat[i][j];
            }
         }
       }

       void display()
       {
          for(int i = 0; i < m; i++)
          {
             for(int j = 0; j < 3; j++)
             {
                cout<<mat[i][j]<<" ";
             }
                cout<<endl;
          }
       }
};

void Sparse :: addition(Sparse &mat2)
{
    int i = 0 , j = 0 , k = 0;
    int result[10][3] = {0};

    while(i < m && j < mat2.m)
    {
        if (mat[i][0] < mat2.mat[j][0] || (mat[i][0] == mat2.mat[j][0] && mat[i][1] < mat2.mat[j][1])) 
        {
            result[k][0] = mat[i][0];
            result[k][1] = mat[i][1];
            result[k][2] = mat[i][2];
            i++;
        }
        else if(mat[i][0] > mat2.mat[j][0] || (mat[i][0] == mat2.mat[j][0] && mat[i][1] > mat2.mat[j][1]))
        {
            result[k][0] = mat2.mat[j][0];
            result[k][1] = mat2.mat[j][1];
            result[k][2] = mat2.mat[j][2];
            j++;
        }
        else
        {
            result[k][0] = mat[i][0];
            result[k][1] = mat[i][1];
            result[k][2] = mat[i][2] + mat2.mat[j][2];
            i++;
            j++;
        }
            k++;
    }
    while(i < m)
    {
        result[k][0] = mat[i][0];
        result[k][1] = mat[i][0];
        result[k][2] = mat[i][2];
        i++;
        k++;
    }
    while(j < mat2.m)
    {
        result[k][0] = mat2.mat[j][0];
        result[k][1] = mat2.mat[j][1];
        result[k][2] = mat2.mat[j][2];
        j++;
        k++;
    }

        cout<<"Addition Result : "<<endl;
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout<<result[i][j]<<" ";
            }
                cout<<endl;
        }
}

void Sparse :: fast()
{
    int transpose[10][3];
    int row[10] = {0};
    int pos[10] = {0};

    for(int i = 0; i < m; i++)      // Calculate the number of terms in each row

    {
        row[mat[i][1]]++;
    }

    for(int i = 1; i < 10; i++)     // Calculate the starting position for each row

    {
        pos[i] = pos[i - 1] + row[i - 1];
    }

    for(int i = 0; i < m; i++)
    {
        int col = mat[i][1];
        int position = pos[col];

        if(position < 10)
        {
            transpose[position][0] = mat[i][1];
            transpose[position][1] = mat[i][0];
            transpose[position][2] = mat[i][2];
            pos[col]++;
        }
        else
        {
            cout<<"Matrix is Very Large , Can't Perform Fast Transpose. "<<endl;
            return;
        }
    }
    for(int i = 0; i < m; i++)
    {
        mat[i][0] = transpose[i][0];
        mat[i][1] = transpose[i][1];
        mat[i][2] = transpose[i][2];
    }
       cout<<"Fast Transpose : "<<endl;
       display(); 
}

void Sparse :: simple()
{
    int transpose[10][3];

    for(int i = 0; i < m; i++)
    {
        transpose[i][0] = mat[i][1];
        transpose[i][1] = mat[i][0];
        transpose[i][2] = mat[i][2];
    }
    for(int i = 0; i < m; i++)
    {
        mat[i][0] = transpose[i][0];
        mat[i][1] = transpose[i][1];
        mat[i][2] = transpose[i][2];
    }
        cout<<"Simple Transpose : "<<endl;
        display();
}

int main()
{
    Sparse s1 , s2;
    int choice;
    char ch;

  do{
        cout<<"------------------------MENU--------------------------"<<endl;
        cout<<"1. Read and Display. "<<endl;
        cout<<"2. Addition of Sparse Matrix. "<<endl;
        cout<<"3. Fast Transpose. "<<endl;
        cout<<"4. Simple Transpose. "<<endl;
        cout<<"5. Exit Program. "<<endl;

        while(true)
        {
            cout<<"Enter Your Choice : ";
            cin>>choice;

            switch(choice)
            {
               case 1 : s1.accept();
                        s1.display();
                        s2.accept();
                        s2.display();
               break;

               case 2 : 
                        s1.addition(s2);
               break;

               case 3 : s1.accept();
                        s1.fast();
               break;

               case 4 : s1.accept();
                        s1.simple();
               break;

               case 5 : 
                        return 0;

               default : 
                         cout<<"Invalid Choice. "<<endl;        
            }
        }
            cout<<"Do you Want to Continue? (y / n) : ";
            cin>>ch;
  }while(ch == 'Y' || ch == 'y');

      cout<<"Thank You...!!! "<<endl;

      return 0;
}






