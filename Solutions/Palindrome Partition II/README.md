*该题主要解法是DP*
当求解DP(0, i) 时，对于0 <= j < i, 求解dp(0,j)和dp(j+1,i)的最小值。
整体是由小往大的一个递推，整体的复杂度为O(n^2)
不过需要注意的是，因为我们首先得知道字符串整体的回文情况也就是字符串s[i,j]是否是回文。
该过程可以分开在另一个DP中，也可以将其与解DP合并在一起，但是结合实际情况，分开写两个DP会导致TLE，写在同一个DP中会Accept。