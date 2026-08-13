class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> q;
        int n = students.size();
        for (int student:students)
        {
            q.push(student);
        }
        int res = n;
        for(int sandwich : sandwiches)
        {int cnt=0;
            while(q.front()!=sandwich &&  cnt<n)
            {
                q.push(q.front());
                q.pop();
                cnt++;
            }
            if(q.front()==sandwich)
            {
                q.pop();
                res--;
            }
            else
            {
                break;
            }
            
        }
        return res;
    }
};