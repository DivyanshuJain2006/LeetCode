/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans = 0;
    unordered_set<int>visited;
    void bfs(vector<Employee*> employees, Employee* e1){
        queue<Employee*>qu;
        ans += e1->importance;
        qu.push(e1);
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            for(auto neighbor : curr->subordinates){
                if(!visited.count(neighbor)){
                    for(auto curr : employees){
                        if(curr->id==neighbor){
                            qu.push(curr);
                            ans += curr->importance;
                            break;
                        }
                    }
                    visited.insert(neighbor);
                }
            }
        }
    
    }
    int getImportance(vector<Employee*> employees, int id) {
        Employee* e1;
        for(auto curr : employees){
            if(curr->id == id){
                e1 = curr;
                break;
            }
        }
        bfs(employees,e1);
        return ans;
    }
};