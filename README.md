# CCC-2021

Full Solutions to all of the CCC 2021 Problems.

Solutions to CCC Junior are done in Python 3.

Solutions to CCC Senior are done in C++, with the exception of S1.

Keep in mind that a problem can have multiple solutions, so these solutions are likely not the only correct ones.


# Brief Editorials

## Junior

### J1 - Boiling Water
Compute P using the formula given in the question. Then use if/elif/else statements to determine whether you are below sea level, at sea level, or above sea level.

### J2 - Silent Auction
Maintain 2 variables: the maximum bid so far, and the name of the person who put the bid. Update the variables if and only if the new bid is **strictly greater** than the current bid. This will take care of the condition that the if there is a tie, the person whose bid was placed first wins.

### J3 - Secret Instructions
Use a while loop to take input continuously, and break if the input is "99999". 
Keep track of a variable "prev" which stores the previous direction that was travelled in. Update this variable every time we make a turn.
Use string slicing to process parts of the 5 digits.

### J4 - Arranging Books
We can split the entire bookshelf into sections: we want all the "L"s to be in the first section, all the "M"s to be in the second section, and all the "S"s to be in the third section.
Notice that the length of each section is precisely the total number of letters that belong in that section.

Now we have 2 cases.

Case 1: letter X is in the Y section, and letter Y is in the X section.
This can be resolved in 1 swap: swap X and Y.
Example: LSLSSL -> LLLSSS

Case 2: letter X is in the Y section, letter Y is in the Z section, letter Z is in the X section.
This can be resolved in 2 swaps: swap X and Y first. Now we have Case 1 where a letter X is in the Z section and a letter Z is in the X section. Use another swap to resolve this.

We can determine the number of X letters in the Y section using <Y section>.count(X).
Then calculate the number of Y letters in the X section similarly.
Exactly min(<X letters in Y section>, <Y letters in X section>) can be categorized as Case 1. We can resolve each of the pairs in 1 swap.

The rest of the unpaired ones must belong to a cycle. Accumulate this to a variable (lets call it temp).

Repeat this process for each pair of letters. ("L" and "M", "M" and "S", "S" and "L")

We know that all cycles contain 3 misplaced letters, and take 2 swaps to resolve. Therefore at the end, we add temp // 3 * 2 to our answer.

### J5 - Modern Art
Lets maintain 2 lists: 1 for counting the amount of times each row has been painted, and the other for columns.
More specifically, row[i] stores the amount of times that the ith row has been painted, col[i] stores the amount of times that the ith column has been painted.
With each update, simply add 1 to row[i] or col[i], depending on which one is being updated.

Notice that if a square has been updated an odd number of times, it will be gold. If it is updated an even amount of times, it will be black.

Therefore, we can iterate over each of the M\*N squares, and determine the amount of times it has been updated by adding row[currentrow] + col[currentcolumn]. Add to our answer if this result is odd.

