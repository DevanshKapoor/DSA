#include<iostream>
#include<vector>

using namespace std;
//recursive binary search

class Solution {
    public:
    bool binarySearch(vector<int>& vec, int key, int l, int r){
        int temp=(l+r)/2;
        if(l>r && key!=vec[temp]){
            return false;
        }
        if(key==vec[temp]){
            return true;
        }
        else if(key<vec[temp]){
            
            return binarySearch(vec,key,l,temp-1);
        }
        else{
            return binarySearch(vec,key,temp+1,r);
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