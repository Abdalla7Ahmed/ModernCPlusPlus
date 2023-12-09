// 2- create a function to search to the number in the array which number is taken from user

#include<iostream>
#include <algorithm>

void search(int *arr,int size,int number)
{
    int index{},flag{};
    for(int i=0;i<size;i++)
    {
        if(number == arr[i])
        {
            index = i;
            flag = 1;
            break;
        }
    }

   if(flag)
   {
    std::cout<<"the number is found in index "<<index<<std::endl;
    return ;
   } 
   std::cout<<"the number is not found "<<std::endl;
   


}
int main(void)
{
    int size ,number;
    std::cout<<"Enter the number of elements"<<std::endl;
    std::cin>>size;
    int arr[10]{0};
    for(int i=0;i<size;i++)
    {
        std::cout<<"Enter element "<< i+1 <<std::endl;
        std::cin>>arr[i];
    }
    std::cout<<"Enter the number to search"<<std::endl;
    std::cin>>number;
    search(arr,size,number);


    // ============================================================
    

    int arr[] = {10, 20, 7, 15, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
        // Use std::find to search for the target value in the array
    int* result = std::find(arr, arr + size, target);

    // Check if the value was found
    if (result != arr + size) {
        // Calculate the index of the found element
        int index = std::distance(arr, result);
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }


    return 0;
}