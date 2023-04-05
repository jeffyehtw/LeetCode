class Solution {
public:
    double average(vector<int>& salary) {
        double sum = salary[0];
        double max = salary[0];
        double min = salary[0];

        for (int i = 1; i < salary.size(); i++) {
            sum += salary[i];
            max = (max < salary[i]) ? salary[i] : max;
            min = (min > salary[i]) ? salary[i] : min;
        }
        sum -= max + min;

        return sum / (salary.size() - 2);
    }
};
