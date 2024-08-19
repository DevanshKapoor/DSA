#include<iostream>
#include<vector>

using namespace std;
//lower bound: smallest index such that arr[index]>= x
//problem link: https://www.naukri.com/code360/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
class Solution {
    public:
    bool binarySearch(vector<int>& vec, int key, int l, int r){
        if(l>r){
            return false;
        }
        int mid=(l+r)/2;
        if(key==vec[mid]){
            return true;
        }
        else if(key<vec[mid]){
            
            return binarySearch(vec,key,l,mid-1);
        }
        else{
            return binarySearch(vec,key,mid+1,r);
        }

    }
    
};

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int r=arr.size()-1;
    int key=11;
    Solution sol;
    cout<<"answer is "<<sol.binarySearch(arr,key,0,r);
    
    return 0;
}return 0;
}