使用两个指针建立一个窗口，对下一个元素进行测试，测试是否在该窗口中，不在就将其加入，在的话需要将左窗口指针移到该元素首次出现的位置的下一位。
由于在Python中，find方法是O(N)的，因此结果会出现TLE，建议使用in。