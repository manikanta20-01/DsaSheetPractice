class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        // Build graph: for each prime value, group all indices that are divisible by it
        unordered_map<int, vector<int>> primeGroups;
        
        for (int i = 0; i < n; i++) {
            // Find all prime factors of nums[i] and add this index to their groups
            int num = nums[i];
            for (int p = 2; p * p <= num; p++) {
                if (num % p == 0) {
                    primeGroups[p].push_back(i);
                    while (num % p == 0) {
                        num /= p;
                    }
                }
            }
            if (num > 1) {
                primeGroups[num].push_back(i);
            }
        }
        
        // BFS
        queue<int> q;
        vector<bool> visited(n, false);
        unordered_set<int> usedPrimes;
        
        q.push(0);
        visited[0] = true;
        int jumps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            jumps++;
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                // Adjacent moves
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    if (curr - 1 == n - 1) return jumps;
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                
                if (curr + 1 < n && !visited[curr + 1]) {
                    if (curr + 1 == n - 1) return jumps;
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                
                // Prime teleportation: check if current position has a prime number
                if (isPrime(nums[curr])) {
                    int prime = nums[curr];
                    if (usedPrimes.find(prime) == usedPrimes.end()) {
                        usedPrimes.insert(prime);
                        
                        // Visit all positions that are divisible by this prime
                        if (primeGroups.count(prime)) {
                            for (int next : primeGroups[prime]) {
                                if (next != curr && !visited[next]) {
                                    if (next == n - 1) return jumps;
                                    visited[next] = true;
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};