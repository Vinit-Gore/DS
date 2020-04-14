Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1

Explanation:
Testcase 1: Since, 3 is present more than N/2 times, so it is the majority element.

https://practice.geeksforgeeks.org/problems/majority-element/0/?track=md-arrays&batchId=144

Used **Moore's Voting** algorithm:
* Loop through each element and maintains a count of majority element, and a majority index, maj_index
* **If the next element is same then increment the count if the next element is not same then decrement the count.**
if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
* Traverse through the array and find the count of majority element found.
* If the count is greater than half the size of the array, print the element
* Else print that there is no majority element

Time Complexity: O(n)
Space complexity: O(1)