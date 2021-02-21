# CCC-2021

Full Solutions to all of the CCC 2021 Problems.

Solutions to CCC Junior are done in Python 3.

Solutions to CCC Senior are done in C++, with the exception of S1.

Keep in mind that a problem can have multiple solutions, so these solutions are likely not the only correct ones.

<hr>

# Brief Editorials

## Junior

### J1 - Boiling Water

Compute P using the formula given in the statement. Then use if/elif/else statements to determine whether you are below sea level, at sea level, or above sea level.

<hr>

### J2 - Silent Auction

Maintain 2 variables: the maximum bid so far, and the name of the person who put the bid. Update the variables if and only if the new bid is **strictly greater** than the current bid. This will take care of the condition that the if there is a tie, the person whose bid was placed first wins.

<hr>

### J3 - Secret Instructions

Use a while loop to take input continuously, and break if the input is "99999". 

Keep track of a variable "prev" which stores the previous direction that was travelled in. Update this variable every time we make a turn.

Use string slicing to process parts of the 5 digits.

<hr>

### J4 - Arranging Books

We can split the entire bookshelf into sections: we want all the "L"s to be in the first section, all the "M"s to be in the second section, and all the "S"s to be in the third section.

Notice that the length of each section is precisely the total number of letters that belong in that section.

Now we have 2 cases.

Case 1: letter X is in the Y section, and letter Y is in the X section.

This can be resolved in 1 swap: swap X and Y.

Example: LSLSSL -> LLLSSS

Case 2: letter X is in the Y section, letter Y is in the Z section, letter Z is in the X section.

This can be resolved in 2 swaps: swap X and Y first. Now we have Case 1 where a letter X is in the Z section and a letter Z is in the X section. Use another swap to resolve this.

Example: LLSLM -> LLLSM -> LLLMS

We can determine the number of X letters in the Y section using \<Y section\>.count(X).

Then calculate the number of Y letters in the X section similarly.

Exactly min(\<X letters in Y section\>, \<Y letters in X section\>) pairs can be categorized as Case 1. We can resolve each of the pairs in 1 swap.

The rest of the unpaired ones must belong to a cycle. Accumulate this to a variable (lets call it temp).

Repeat this process for each pair of letters. ("L" and "M", "M" and "S", "S" and "L")

We know that all cycles contain 3 misplaced letters, and take 2 swaps to resolve. Therefore at the end, we add temp // 3 * 2 to our answer.

<hr>

### J5 - Modern Art
Lets maintain 2 lists: 1 for counting the amount of times each row has been painted, and the other for columns.

More specifically, row[i] stores the amount of times that the ith row has been painted, col[i] stores the amount of times that the ith column has been painted.

With each update, simply add 1 to row[i] or col[i], depending on which one is being updated.

Notice that if a square has been updated an odd number of times, it will be gold. If it is updated an even amount of times, it will be black.

Therefore, we can iterate over each of the M\*N squares, and determine the amount of times it has been updated by adding row[currentrow] + col[currentcolumn]. Add to our answer if this result is odd.

<hr>

## Senior

### S1 - Crazy Fencing

The area of a trapezoid is (base1 + base2) * height / 2. In this case, it is (height on the left + height on the right) * width / 2.

Iterate over N and accumulate (height[i] + height[i+1]) * width[i] / 2.

Be careful of decimal precision if you're using C++.

Time complexity: O(N)

<hr>

### S2 - Modern Art

See J5.

Time complexity: O(MN + K)

There exists a faster solution using Principle of Inclusion/Exclusion that runs in O(M + N + K)

<hr>

### S3 - Lunch Concert

First, we can brute force the value for all positions from left to right. We notice that the values are first decreasing, then reaches a minimum (for potentially more than 1 position), then increases. We can use ternary search to find the minimum value similar to the idea described here: https://cp-algorithms.com/num_methods/ternary_search.html

Essentially, we pick 2 positions that divide the range into thirds. We then compare the values at these position to see which third the answer can't be in, and reduce the range by 1/3.

Time Complexity: O(Nlog(P))

<hr>

### S4 - Daily Commute

The key observation is that we want to get on the train from the beginning, and when we get off, we are going to walk to N instead of going to another station and waiting there.

If we get off the train just to go to another station and wait there, we might as well have stayed on the train - it does not save us time.

In this context, lets equate distance and time since the train travels between stations in 1 minute and we can walk between stations in 1 minute.

First, using the walkways, compute the minimum distance to walk from each station to N (it may be impossible) using BFS. Lets call this answer dist[i] for a station i.

If the stations were stationary, then the answer is min(distance that the train travels from beginning to the station + distance we need to walk from the station to N) for all stations.

We can keep all these values in a multiset (we dont want to remove all occurences of an answer, only one of them when we delete).

When we swap stations at positions X and Y, we have to remove (an occurence of) the original values and add the new values into our multiset.

Original values: X + dist[station[X]] - 1, Y + dist[station[Y]] - 1

New values: X + dist[station[Y]] - 1, Y + dist[station[X]] - 1

Don't forget to actually swap the stations since the swaps are persistent.

Time Complexity: O(N + W + (N + D)log(N))

<hr>

### S5 - Math Homework

If we want a contiguous subarray to have a GCD of Z, we at least have to make sure every element in the subarray is a multiple of Z. 

However, since we have multiple requirements that may overlap, The GCD of our subarray in the end might actually be greater than after the original update. 

For example, if we need a subarray to have GCD 2, then have GCD 4, it is obvious that it is impossible for both to be satisfied in the end.

Therefore, we will construct the array, then validate it in the end.

For each requirement, assign every element in the subarray as LCM(element,Z). Store this requirement so we can query it later.

After the updates, query for the GCD of each range again to make sure the requirements are all satisfied in the end.

To do the updates and queries in log(N) time, we can use a Segment Tree with Lazy Propogation.

Time complexity: O(Mlog(N))

<hr>
