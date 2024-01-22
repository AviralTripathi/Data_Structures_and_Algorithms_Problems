#include<bits/stdc++.h>
using namespace std;

// function for the computation of the maximum sum subarray

int maxSumSubarray(int arr[],int n)
{
    // firstly we will be declaring two variables 

    // the first variable will be storing the maximum sum till that index and so thats why
    // intially it is initially to zero.

    int max_ending_here=0;

    // the variable max_so_far will be storing the maximum of all the max found uptill
    // now so that's why it is intialized to INT_MIN(2E-31)

    int max_so_far=INT_MIN;

    // now next target is to simply iterate through the whole array

    for(int i=0;i<n;i++)
    {
        max_ending_here+=arr[i];
        if(max_ending_here>max_so_far)
        // simply update the variable max so far
        max_so_far=max_ending_here;

        // now again checking if the max_ending_here is < 0
        // then simply update to zero

        if(max_ending_here<0)
        max_ending_here=0;
    }
    // max_so_far will be holding the maximum value formed from the partciular subarray

    return max_so_far;
}

int main()
{
    int t;
    cin>>t;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // passing this array to compute the maximum sum subarray using kadane's algo
    int result=maxSumSubarray(arr,n);
    cout<<"Maximum sum subarray is with the sum: "<<result;
}
