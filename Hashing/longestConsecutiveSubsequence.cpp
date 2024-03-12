Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. 

Examples:  

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: The subsequence 36, 35, 33, 34, 32 is the longest subsequence of consecutive elements.

//steps to be taken care off while having the lcs using hashing

-> Create an empty hash.
-> Insert all array elements to hash.
-> Do the following for every element arr[i]
-> Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 in the hash, if not found, then this is the first element of a subsequence.
> If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
-> If the count is more than the previous longest subsequence found, then update this.


// Code Implementation

int findLongestConseqSubseq(int arr[], int N)
    {
        // initially declaring a set to produce all the elements inside the set (here to be referred as
        // hashset)
      unordered_set<int> s;
    int ans=0;
    // input all the elements in the hash array
    for(int i=0;i<N;i++)
    {
        s.insert(arr[i]);

    }
    for(int i=0;i<N;i++)
    {
        if(s.find(arr[i]-1)!=s.end())
        continue;
        else 
        {
            int j=arr[i];
            while(s.find(j)!=s.end())
            {
                j++;
            }
            ans=max(ans,j-arr[i]);
        }
    }
    return ans;
    }

Time Complexity: O(N), Only one traversal is needed and the time complexity is O(n) under the assumption that hash insert and search takes O(1) time.
Space Complexity:  Auxiliary space: O(N), To store every element in the hashmap O(n) space is needed
