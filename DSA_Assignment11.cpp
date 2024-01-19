/*
Assignment 11
Problem Statement :
Sorting: Write a C++ menu driven program to store the percentage of 
marks obtained by the students in an array. Write function for sorting array 
of floating point numbers in ascending order using  
1. Selection Sort  
2. Bubble sort  
3. Insertion sort  
4. Shell Sort  
5. Quick sort  
6. Radix sort  
7. Display top five scores   
Implement 4 methods of sorting. Provide choice to user to take input from 
user or using random numbers. 
Use Standard Template Library (STL) sort function for above data. 
*/

#include<iostream>
using namespace std;

class Sorting 
{
    public : 
       int n;

       void display(float arr[10] , int n)
       {
          cout<<"The Marks Obtained by the Students are : ";
          for(int i = 0; i < n; i++)
          {
             cout<<arr[i]<<"\t";
          }
             cout<<endl;
       }

       void bubble(float arr[10] , int n)
       {
          cout<<"The Marks After Bubble Sort : ";
          for(int i = 0; i < n - 1; i++)
          {
             for(int j = 0; j < n - i - 1; j++)
             {
                if(arr[j] > arr[j + 1])
                {
                    swap(arr[j] , arr[j + 1]);
                }
             }
          }
          for(int i = 0; i < n; i++)
          {
             cout<<arr[i]<<"\t";
          }
       }

       void insertion(float arr[10] , int n)
       {  
          cout<<"The Marks After Insertion Sort : ";
          for(int i = 0; i < n; i++)
          {
             float temp = arr[i];
             int j = i - 1;
             while(j >= 0)
             {
                if(arr[j] > temp)
                {
                    arr[j + 1] = arr[j];
                }
                else 
                {
                    break;
                }
                   j--;
             }
                arr[j + 1] = temp;
          }
          for(int i = 0; i < n; i++)
          {
             cout<<arr[i]<<"\t";
          }
       }

       void selection(float arr[10] , int n)
       {
          cout<<"The Marks After Selection Sort : ";
          for(int i = 0; i < n - 1; i++)
          {
             int minIndex = i;
             for(int j = i + 1; j < n; j++)
             {
                if(arr[minIndex] > arr[j])
                {
                    minIndex = j;
                }
             }
               swap(arr[minIndex] , arr[i]);
          }
          for(int i = 0; i < n; i++)
          {
             cout<<arr[i]<<"\t";
          }
       }

       void shell(float arr[] , int n)
       {
          for(int gap = n/2; gap > 0; gap /= 2)
          {
             for(int j = gap; j < n; j++)
             {
                int temp = arr[j];
                int i = 0;
                for(i = j; i >= gap && arr[i - gap] > temp; i -= gap)
                {
                    arr[i] = arr[i - gap];
                }
                arr[i] = temp;
             }
          }
          cout<<"The Marks After Shell Sort : ";
          for(int i = 0; i < n; i++)
          {
             cout<<arr[i]<<"\t";
          }
             cout<<endl; 
       }

       int partition(float arr[] , int start , int end)
       {
          float pivot = arr[end];
          int i = start - 1;
          for(int j = start; j <= end - 1; j++)
          {
             if(arr[j] < pivot)
             {
                i++;
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
             }
          }
            i++;
            float temp = arr[i];
            arr[i] = arr[end];
            arr[end] = temp;
            return i;
       }

       void quick(float arr[] , int start , int end)
       {
          if(end <= start)
          {
             return;
          }
          int pivot = partition(arr , start , end);
          quick(arr , start , pivot - 1);
          quick(arr , pivot + 1 , end);
       }

       void displayTop(float arr[10] , int n)
       {
          cout<<"The Top Five Scores in the Class : ";
          for(int i = n - 1; i >= n - 5; i--)
          {
             cout<<arr[i]<<"\t";
          }
             cout<<endl;
       }
};

int main()
{
    float arr[10];
    int n;
    cout<<"Enter the Number of Students : ";
    cin>>n;
    cout<<"Enter the Marks Obtained by the Students : "<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    Sorting obj;
    int option;
    char ch;
    do{
         cout<<"-----------------------MENU----------------------------"<<endl;
         cout<<"1. Display the Unsorted List of Marks. "<<endl;
         cout<<"2. Sort List Using Bubble Sort. "<<endl;
         cout<<"3. Sort List Using Insertion Sort. "<<endl;
         cout<<"4. Sort List Using Selection Sort. "<<endl;
         cout<<"5. Sort List Using Shell Sort. "<<endl;
         cout<<"6. Sort List Using Quick Sort. "<<endl;
         cout<<"7. Display the Top Five Scores. "<<endl;
         cout<<"Enter Your Choice : ";
         cin>>option;
         cout<<endl;

         switch(option)
         {
            case 1 : obj.display(arr , n);
                     cout<<"***********************************************************************************"<<endl;
            break;

            case 2 : obj.bubble(arr , n);
                     cout<<endl; 
                     cout<<"***********************************************************************************"<<endl;
            break;

            case 3 : obj.insertion(arr , n);
                     cout<<endl;
                     cout<<"***********************************************************************************"<<endl;
            break;

            case 4 : obj.selection(arr , n);
                     cout<<endl;
                     cout<<"***********************************************************************************"<<endl;
            break;

            case 5 : obj.shell(arr , n);
                     cout<<"***********************************************************************************"<<endl;
            break;

            case 6 : obj.quick(arr , 0 , n - 1);
                     cout<<"The Marks After Quick Sort : ";
                     for(int i = 0; i < n; i++)
                     {
                        cout<<arr[i]<<"\t";
                     }  
                     cout<<endl;
                     cout<<"***********************************************************************************"<<endl;
            break;

            case 7 : obj.displayTop(arr , n);
                     cout<<"***********************************************************************************"<<endl;
            break;         

            default : cout<<"Invalid Choice. "<<endl;
           
         }
            cout<<"Do you Want to Continue? (y / n) : ";
            cin>>ch;
    }while(ch == 'Y' || ch == 'y');

      cout<<"Thank You...!!! "<<endl;

    return 0;     
}


