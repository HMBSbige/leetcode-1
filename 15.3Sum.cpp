class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;

        std::sort(num.begin(), num.end());

        int target, front, back, back_ = num.size() - 1;

        for (int i = 0; i < num.size(); i++) {

            target = -num[i];
            front = i + 1;
            back = back_;

            if (target < 0)
            {
                break;
            }

            while (front < back) {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;

        }

        return res;
    }
};