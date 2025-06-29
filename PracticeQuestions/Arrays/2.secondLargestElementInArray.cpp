#include<iostream>
#include<algorithm>

using namespace std;
//find second largest element in the array
class Solution {
    public:
    int secondLargestElement_bruteForce(int arr[],int size){
        sort(arr,arr+size);
        int largest=arr[size-1];
        int sLargest;
        for(int i=size-2;i>=0;i--){
            if(arr[i]!=largest){
                sLargest=arr[i];
                return sLargest;
            }
        }
        return -1;
    }

    int betterApproach(int arr[],int size){
        //find largest first
        int largest=arr[0];
        for(int i=0;i<size;i++){
            if(arr[i]>largest){
                largest=arr[i];
            }
        }
        int slargest=INT_MIN;
        for(int i=0;i<size;i++){
            if(arr[i]>slargest && largest!=arr[i]){
                slargest=arr[i];
            }
        }

        return slargest;
    }

    int optimalSol(int arr[],int size){
        int largest=arr[0];
        int slargest=INT_MIN;
        for(int i=0;i<size;i++){
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
            }
            else if (arr[i]>slargest){
                slargest=arr[i];
            }
        }

        return slargest;
    }
};

int main(){
    int arr[]={23,4,5,6,99,7,88,2,8,98,99,77,5,5,43};
    Solution sol;
    int result1=sol.secondLargestElement_bruteForce(arr,14);
    int result2=sol.betterApproach(arr,14);
    int result3=sol.optimalSol(arr,14);
    cout<<result1<<"\n";
    cout<<result2<<"\n";
    cout<<result3;
    return 0;
}