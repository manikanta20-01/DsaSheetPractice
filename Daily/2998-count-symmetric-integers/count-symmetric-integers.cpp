class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        while(low<=high){
            string s;
            int x=low;
            while(x>0){
                int tem=x%10;
                x/=10;
                s+=tem+'0';
            }
            if(s.size()>0&&s.size()%2==0){
                int sum1=0,sum2=0;
                for(int i=0;i<s.size()/2;i++){
                    sum1+=s[i]-'0';
                }
                for(int i=s.size()/2;i<s.size();i++){
                    sum2+=s[i]-'0';
                }
                if(sum1==sum2){
                    ans++;
                }
            }
            low++;
        }
        return ans;
    }
};