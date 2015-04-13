class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        if (size == 1) {
            return num[0];
        }
        int left = 0;
        int right = size - 1;

        while(left < right) {
            int center = (left + right) / 2;
            cout<<num[left]<<" "<<num[center]<<" "<<num[right]<<endl;
            if (num[left] > num[center]) {
                right = center;
            }
            else {
                if (num[left] > num[right]) {
                    left = center + 1;
                }
                else {
                    return num[left];
                }
            }
        }
        return num[left];
    }
};