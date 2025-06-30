//check if given array is sorted
#include<iostream>
using namespace std;

class Solution{
    public:
    bool isSorted(int arr[],int size){
        for(int i=0;i<size;i++){
            if(arr[i-1]>arr[i]){
               return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    bool sorted1;
    bool sorted2;
    int arr[]={1,2,2,3,5,6,7,8};
    int arr1[]={2,4,45,2,2,41,2};
    sorted1=sol.isSorted(arr,8);
    sorted2=sol.isSorted(arr1,7);
    cout<<sorted1<<"\n";
    cout<<sorted2;
    
}
