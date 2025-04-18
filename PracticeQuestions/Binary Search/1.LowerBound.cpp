#include<iostream>
#include<vector>

using namespace std;
//lower bound: smallest index such that arr[index]>= x
//problem link: https://www.naukri.com/code360/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
class Solution {
    public:
    int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int l=0;
	int r=n-1;
	int ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(arr[mid]>=x){
			r=mid-1;
			ans=mid;
			
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
    cout<<"answer is "<<sol.lowerBound(arr,arr.size(),x);
    
    return 0;
}