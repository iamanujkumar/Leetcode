class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        string result = "";
        if((long long)numerator * (long long)denominator < 0) {
            result += "-";
        }
        long long nume = labs(numerator);
        long long deno = labs(denominator);
        long long div = nume/deno;
        result+=to_string(div);
        long long remainder = nume%deno;
        if(remainder == 0) return result;
        result+='.';
        unordered_map<int,int>mp;
        while(remainder!=0){
            if(mp.count(remainder)){
                result.insert(mp[remainder],"(");
                result+=")";
                break;
            }
            mp[remainder] = result.length();
            remainder*=10;
            int digit = remainder/deno;
            result+=to_string(digit);
            remainder = remainder%deno;
        }
        return result;
    }
};