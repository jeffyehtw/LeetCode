/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // var
        queue<int> q;
        int result = 0;
        map<int, int> m;
        
        // init
        q.push(id);
        for (int i = 0; i < employees.size(); i++)
            m[employees[i]->id] = i;
        
        while (!q.empty()) {
            // var
            queue<int> tmp;
            
            while (!q.empty()) {
                // var
                Employee* e = employees[m[q.front()]];
                
                result += e->importance;
                
                for (auto employee : e->subordinates)
                    tmp.push(employee);
                
                q.pop();
            }
            q = tmp;
        }
        return result;
    }
};