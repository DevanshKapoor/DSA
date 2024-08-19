#include<bits/stdc++.h>
using namespace std;

//problem link: https://www.naukri.com/code360/problems/rose-garden_2248080?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

int numBouque(vector<int> arr, int k, int day){
	int n=arr.size();
	int count=0;
	int numBouque=0;
	for(int i=0;i<n;i++){
		if(arr[i]<=day){
			count++;
		}
		else{
			numBouque+=count/k;
			count=0;
		}
		
	}
	numBouque+=count/k;

	return numBouque;
	

}

int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int min=INT_MAX;
	int max=INT_MIN;
	for(int num:arr){
		if(num<min){
			min=num;
		}
		if(num>max){
			max=num;
		}
	}

	int ans=-1;
	while(min<=max){
		int mid=(min+max)/2;
		if(numBouque(arr,k,mid)>=m){
			ans=mid;
			max=mid-1;
		}
		else{
			min=mid+1;
		}
	}

	return ans;
	
}