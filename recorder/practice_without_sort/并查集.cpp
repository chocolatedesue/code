#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<list>
using namespace std;
vector<list<string>> v(1001);
unordered_map<string, int> m;
int cnt = 1, pre = 0;
bool judge(string temp) {
    for (int i = 1; i < cnt; i++) {
        if (v[i].front() == temp)return true;
    }return false;
}
void solve(string temp2) {

    int idx = m[temp2];
   // if (m.find())
    auto i = v[idx].begin();

        for (; i != v[idx].end(); i++) {
            m[*i] = pre;
            if (judge(*i)) {
                solve(*i);
           }
        }
}
int main() {
    string temp;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> temp)
    {
        if (temp[0] == '$')
            break;
        else if (temp[0] == '#') {
            string  temp2 = temp.substr(1, temp.size() - 1);
            if (m.find(temp2) == m.end()) {
                /*list<string>t;
                t.push_front(temp2);*/

                v[cnt].push_front(temp2);
                m[temp2] = cnt;
                pre = cnt;
                cnt++;
            }
            else {
                int idx = m[temp2];
                v[idx].push_back(temp2);
                pre = idx;
            }
        }
        else if (temp[0] == '+') {

            string  temp2 = temp.substr(1, temp.size() - 1);
          //  if (m.find(temp2) == m.end()) {
                v[pre].push_back(temp2);

                m[temp2] = pre;
            /*}
            else {
                v[pre].push_back(temp2);
                solve(temp2);
                }*/


        }
        else if (temp[0] == '?') {
            string  temp2 = temp.substr(1, temp.size() - 1);
            int idx = m[temp2];
            while (m[v[idx].front()] != idx) {
                idx = m[v[idx].front()];
            }
            cout << temp2 << " " << (v[idx].front()) << endl;
        }
    }
    return 0;
}