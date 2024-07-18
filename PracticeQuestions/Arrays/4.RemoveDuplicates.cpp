//remove duplicates from sorted array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int brute(vector<int>&arr){
        //by using sets
        set<int> st;
        for(int i:arr){
            st.insert(i);
        }
        int k=0;
        for(int i: st){
            arr[k]=i;
            k++;
        }
        cout<<"brute force solution:"<<endl;
        for(int i=0;i<arr.size();i++){
            cout<<arr[i];
            cout<<"\t";
        }
        cout<<"\n";
        return k;
    }
    int numUniqueElements(vector<int>&nums){
        //using 2 pointer approach
        int pt1=0;
        for(int pt2=0;pt2<nums.size();pt2++){
            if(nums[pt1]!=nums[pt2]){
                nums[pt1+1]=nums[pt2];
                pt1++;
            }
        }
          cout<<"\n\noptimal 2 pointer solution:"<<endl;
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
            cout<<"\t";
        }
        cout<<"\n";
        return pt1+1;
        }
};

int main(){
    Solution sol;
    vector<int>A={1,1,1,3,3,3,4,5,6,7,7};
    cout<<sol.brute(A);
    //since paas by reference, A gets altered
    vector<int>B={1,1,1,3,3,3,4,5,6,7,7};
    cout<<sol.numUniqueElements(B);

    return 0;
}

