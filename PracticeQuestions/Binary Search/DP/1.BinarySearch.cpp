#include<iostream>
#include<vector>

using namespace std;
//recursive binary search
//TC : O(log n)
class Solution {
    public:
    int binarySearchRecursive(vector<int>& vec, int key, int l, int r){
        if(l>r){
            return -1; //returns -1 if no index with key element
        }
        int mid=(l+r)/2;
        if(key==vec[mid]){
            return mid; //returns the index
        }
        else if(key<vec[mid]){
            
            return binarySearch(vec,key,l,mid-1);
        }
        else{
            return binarySearch(vec,key,mid+1,r);
        }

    }

    int binarySearchIterative(vector<int>& vec, int key){
        int l=0;
        int r=vec.size()-1;
        int mid=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(key==vec[mid]){
                return mid;
            }
            else if(key<vec[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return -1;
    }
    
};

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int r=arr.size()-1;
    int key=11;
    Solution sol;
    cout<<"answer is "<<sol.binarySearchRecursive(arr,key,0,r);
    
    return 0;
}