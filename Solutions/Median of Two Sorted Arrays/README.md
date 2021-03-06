由于题目的复杂度要求是O(log(M + N))，因此不能直接使用暴力破解。
本题使用的方法是找第(M + N)/2 小的数
*怎么找？*
因为要找的是第K大的数，因此我们分别取两个数组A,B的第K/2个数，如果A[k/2] < B[k/2]，那么可以肯定第K大数不在A的0-k/2之中，因此可以缩小A查找范围和K。
同理A[k/2] > B[k/2]。如果相等则该数就是所求的数了。
因为题目所求的是中位数，M+N有可能为奇数也有可能为偶数，因此简单方法就是同时求第(M+N)/2大和(M+N+1)/2大的数，然后求平均。