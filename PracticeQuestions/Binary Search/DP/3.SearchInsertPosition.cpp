#include<iostream>
#include<vector>

using namespace std;
//upper bound: smallest index such that arr[index]> x
//problem link: https://www.naukri.com/code360/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
class Solution {
    public:
    int searchInsert(vector<int>& arr, int x){
	int l=0;
	int r=arr.size()-1;
	int ans=arr.size();

	while(l<=r){
		int mid=(l+r)/2;
		if(arr[mid]>=x){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
		
	}
	return ans;

}
};


int main(){
    vector<int> arr={1,2,3,4,5,5,6,7,8,9,10};
    int x=5;
    Solution sol;
    cout<<"answer is "<<sol.searchInsert(arr,x);
    
    return 0;
}