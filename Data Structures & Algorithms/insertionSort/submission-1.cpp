// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int k=0;
        vector<vector<Pair>> ans;

        while(k<pairs.size()){
            if(k>0){
                int i=k;
                while(pairs[i].key < pairs[i-1].key){
                    Pair t = pairs[i];
                    pairs[i] = pairs[i-1];
                    pairs[i-1]=t;
                    i--;
                }
                
            }
            
            ans.push_back(pairs);
            k++;
        }

        return ans;
    }
};
