class Solution {
public:
    string interpret(string command) {
        string ret;

        for (int i = 0; i < command.length(); ) {
            if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ret += "o";
                    i += 2;
                } else if ((command[i + 1] == 'a')
                    && (command[i + 2] == 'l')
                    && (command[i + 3] == ')')) {
                    ret += "al";
                    i += 4;
                } else {
                    ret += command[i];
                    i++;
                }
            } else {
                ret += command[i];
                i++;
            }
        }

        return ret;
    }
};
