#include<bits/stdc++.h>
using namespace std;

//problem link: https://www.naukri.com/code360/problems/minimum-rate-to-eat-bananas_7449064?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=PROBLEM

int findMax(vector<int> &v){
    int maxi=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,v[i]);
    }

    return maxi;
}
//had to use long long becuse of input range, it kept failing for a particular test case
long long int totalHours(vector<int> &v, int hourly){
    long long int totalH=0;
    int n=v.size();
    for(int i=0;i<n;i++){
        totalH +=ceil((double)v[i]/(double)hourly);//dividing integer by integer will always yield integer, so we type casted both numbers to double to get cprrect answer
    }

    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h){
    int low=1, high=findMax(v);
    while(low<=high){
        int mid=(low+high)/2;
        long long int totalH=totalHours(v,mid);
        if(totalH<=h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

        
    }
    return low;
}
