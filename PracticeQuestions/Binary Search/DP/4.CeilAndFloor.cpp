#include<iostream>
#include<vector>

using namespace std;
//upper bound: smallest index such that arr[index]> x
//problem link: https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
class Solution {
    public:
    

};


int main(){
    vector<int> arr={1,2,3,4,5,5,6,7,8,9,10};
    int x=5;
    Solution sol;
    cout<<"answer is "<<sol.searchInsert(arr,x);
    
    return 0;
}