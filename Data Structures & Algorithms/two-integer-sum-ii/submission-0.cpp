class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1,m,n;

        while(i<j){
            if(numbers[i]+numbers[j]==target){
                m=i;
                n=j;
                break;
            }
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            if(numbers[i]+numbers[j]<target){
                i++;
            }
        }

        return {m+1,n+1};
    }
};
