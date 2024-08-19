#include<iostream>
#include<vector>

using namespace std;
//ceiling and floor value for x in given array
//problem link: https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401


//solution 1(thoda aalsi wala) --> i think ye better hai waise, doosra wala just broken into functions hai

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	pair<int,int> answer={-1,-1};
	int lowIndex=0;
	int highIndex=n-1;
	int ans=n;

	while(lowIndex<=highIndex){
		int midIndex=(lowIndex+highIndex)/2;

		if(a[midIndex]>=x){
			highIndex=midIndex-1;
			ans=midIndex;
		}

		else{
			lowIndex=midIndex+1;
		}
	}

	if(a[ans]==x){
		return{x,x};
	}
	if(ans==0){
		return{-1,a[ans]};
	}

	if(ans==n){
		return {a[ans-1],-1};
	}

	return{a[ans-1],a[ans]};



}



// solution 2 (striver wala)

int floor(vector<int> &a, int n, int x){
	int lowIndex=0;
	int highIndex=n-1;
	int ans=n;

	while(lowIndex<=highIndex){
		int midIndex=(lowIndex+highIndex)/2;

		if(a[midIndex]<=x){
			lowIndex=midIndex+1;
			ans=midIndex;
		}

		else{
			highIndex=midIndex-1;
		}
	}
	if(ans==n){
		return -1;
	}

	return a[ans];
}

int ceil(vector<int> &a, int n, int x){
	int lowIndex=0;
	int highIndex=n-1;
	int ans=-1;

	while(lowIndex<=highIndex){
		int midIndex=(lowIndex+highIndex)/2;

		if(a[midIndex]>=x){
			highIndex=midIndex-1;
			ans=midIndex;
		}

		else{
			lowIndex=midIndex+1;
		}
	}
	if(ans==-1){
		return -1;
	}

	return a[ans];


}


pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.

	return{floor(a,n,x),ceil(a,n,x)};

}








int main(){
    return 0;
}