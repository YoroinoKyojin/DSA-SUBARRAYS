// Optimal Approach(Using Set data structure): 
// We will adopt a similar approach to the brute-force method but with optimizations in the search process. Instead of searching sequences for every array element as in the brute-force approach, we will focus solely on finding sequences only for those numbers that can be the starting numbers of the sequences. This targeted approach narrows down our search and improves efficiency.

// We will do this with the help of the Set data structure.

// How to identify if a number can be the starting number for a sequence:

// First, we will put all the array elements into the set data structure.
// If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set, we will check if x-1 exists inside the set. :
// If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
// If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.
// How to search for consecutive elements for a number, x:

// Instead of using linear search, we will use the set data structure itself to search for the elements x+1, x+2, x+3, and so on.
// Thus, using this method we can narrow down the search and optimize the approach.

// Algorithm:
// We will declare 2 variables, 

// ‘cnt’ → (to store the length of the current sequence), 
// ‘longest’ → (to store the maximum length).
// First, we will put all the array elements into the set data structure.
// For every element, x, that can be a starting number(i.e. x-1 does not exist in the set) we will do the following:
// We will set the length of the current sequence(cnt) to 1.
// Then, again using the set, we will search for the consecutive elements such as x+1, x+2, and so on, and find the maximum possible length of the current sequence. This length will be stored in the variable ‘cnt’.
// After that, we will compare ‘cnt’ and ‘longest’ and update the variable ‘longest’ with the maximum value (i.e. longest = max(longest, cnt)).
// Finally, we will have the answer i.e. ‘longest’.

#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}