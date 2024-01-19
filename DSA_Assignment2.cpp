/*
Assignment 2 
Problem Statement : 
Random walk: A (drunken) cockroach is placed on a given square in the 
middle of a tile floor in a rectangular room of size n x m tiles. The bug 
wanders (possibly in search of an aspirin) randomly from tile to tile 
throughout the room. Assuming that it may move from his present tile to any 
of the eight tiles surrounding it (unless it is against a wall) with equal 
probability, how long will it take him to touch every tile on the floor at least 
once? 
Write a C++ program to graphically show a random walk of a (drunken) 
cockroach and find the no of moves made. 
*/

#include<iostream>
#include<random>
#include<time.h>
using namespace std;

static int arr[100][100];

bool check(int m , int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
           if(arr[i][j] != 1)
           {
              return true;
           }
        } 
    }
       return false;
} 

int main()
{
    int count = 0;
    srand(time(0));
    int m , n;         // m is row and n is col
    cout<<"Enter Rows and Columns : "<<endl;
    cin>>m>>n;

    for(int i = 0; i < m; i++)       // Make every element of the array 0
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    
    // center of the array 
    int center_x = m/2;
    int center_y = n/2;
    arr[center_x][center_y] = 1;

    while(check(m , n)) 
    {
        int x = center_x;
        int y = center_y;
        int min = 1 , max = 8;

        if(y == (n - 1))
        {
            min = 1;
            max = 5;
        }
        if(y == 0)
        {
            min = 4;
            max = 8;
        }

        int range = max - min + 1;
        int num = rand() % range + min;

        switch(num)
        {
            case 1 : 
                     x--;
                     y--;
            break;

            case 2 : 
                     x;
                     y--;
            break;

            case 3 : 
                     x++;
                     y--;
            break;

            case 4 : 
                     x--;
                     y;
            break;

            case 5 : 
                     x++;
                     y; 
            break;

            case 6 : 
                     x--;
                     y++;
            break;

            case 7 : 
                    x;
                    y++;
            break;

            case 8 : 
                     x++;
                     y++;
            break;                                                                       
        }
           if(x < 0 || y < 0 || (m-1) < x || (n-1) < y)
           {
              continue;
           }

           arr[x][y] = 1;
           center_x = x;
           center_y = y;
           cout<<x<<" "<<y<<endl;
           count++;
    } 

          cout<<"Total Number of Moves Made are "<<count<<endl;

    return 0;
}


