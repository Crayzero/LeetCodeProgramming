class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        if (size == 0) {
            return 0;
        }
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
            else if(num[left] < num[center]) {
                if (num[left] >= num[right]) {
                    left = center + 1;
                }
                else {
                    return num[left];
                }
            }
            else {
                if (num[left] > num[right]) {
                    left = center + 1;
                }
                else if (num[left] < num[right]){
                    return num[left];
                }
                else {
                    vector<int> num_left, num_right;
                    for(int i = left; i< center; i++) {
                        num_left.push_back(num[i]);
                    }
                    for(int j = center; j< right; j++) {
                        num_right.push_back(num[j]);
                    }
                    if (left == center) {
                        return min(num[left], findMin(num_right));
                    }
                    return min(findMin(num_left), findMin(num_right));
                }
            }
        }
        return num[left];
    }
};