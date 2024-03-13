Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return true If you can find a way to do that or false otherwise.

 

Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.


Intuition
Solve using unordered_map hashig technique

Approach
If length of given array is odd, return false.
An odd length array cannot be divided into pairs.
Traverse input array and count occurrences of
all remainders (use (arr[i] % k)+k)%k for handling the case of negative integers as well).
freq[((arr[i] % k) + k) % k]++
Traverse input array again.
a) Find the remainder of the current element.
b) If remainder divides k into two halves, then
there must be even occurrences of it as it
forms pair with itself only.
c) If the remainder is 0, then there must be
even occurrences.
d) Else, number of occurrences of current
the remainder must be equal to a number of
occurrences of "k - current remainder".


  bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
    // checking for the length of the given vector being odd or not
    if(n&1) return false;
    // unordered map is needed to count no. of occurrences of a particular remainder
    unordered_map<int,int> freq;
    // now traversing the i/p vector
    for(int i=0;i<n;i++) {
        // did this to handle the negative cases as well
        freq[((arr[i]%k)+k)%k]++;
    }
    //  now again traversing the vector
    for(int i=0;i<n;i++) {
        // Find the remainder of the current element.
        int rem=((arr[i]%k)+k)%k;

        if(2*rem==k) {
            /*
            Find the remainder of the current element.
            If remainder divides k into two halves, then
            there must be even occurrences of it as it
            forms pair with itself only.
            */
            if(freq[rem]%2!=0) return false;
        } else if(rem==0) {
            /*
            If the remainder is 0, then there must be
            even occurrences.
            */
            if(freq[rem]&1) return false;
        } else {
            /*
            Else, number of occurrences of current
            the remainder must be equal to a number of
            occurrences of "k - current remainder".
            */
            if(freq[rem]!=freq[k-rem]) return false;
        }
    }
    // return true if nothing has been returned up till now
    return true;

Time Complexity: O(N)
Space Complexity: O(N)
