class Solution {
public: 
bool is_feasible(vector<int>&ranks, int cars, long long current_time){
    long long car = 0;
    for(auto rank: ranks){
        car += sqrt(current_time/rank);
    }
    return car>=cars;
}
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right  = 1e14;

        while(left<right){
            long long mid = left + (right-left)/2;
            if(is_feasible(ranks, cars, mid)){
                right = mid;
            } else{
                left =mid+1;
            }
        }
        return right;
    }
};