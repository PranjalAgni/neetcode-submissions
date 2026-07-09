class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        list<int> studentsList(students.begin(), students.end());
        list<int> sandwichesList(sandwiches.begin(), sandwiches.end());

        int N = students.size();
        int pos = 0;
        while (sandwichesList.size() > 0 && pos < N * N) {
            if (studentsList.front() != sandwichesList.front()) {
                int x = studentsList.front();
                studentsList.pop_front();
                studentsList.push_back(x);
            } else {
                studentsList.pop_front();
                sandwichesList.pop_front();
            }

            pos += 1;
        }


        return sandwichesList.size();
    }
};