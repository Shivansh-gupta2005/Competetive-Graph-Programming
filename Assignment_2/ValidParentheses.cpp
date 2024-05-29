class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        std::stack<char> stack;

        for (char ch : s) {
            if (bracketMap.find(ch) != bracketMap.end()) {
                // It's a closing bracket
                if (stack.empty() || stack.top() != bracketMap[ch]) {
                    return false;
                }
                stack.pop();
            } else {
                // It's an opening bracket
                stack.push(ch);
            }
        }

        return stack.empty();
    
    }
};