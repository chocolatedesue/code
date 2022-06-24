#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        //if (s.size() == 1)return s;
        string temp = s;
        s = get_string(s);
        int len = s.size();
        if (len == 5)return temp;
        vector<int>p(len + 10, 0);
        int center = 0, r = 0;
        for (int i = 1; i <= len - 1; ++i) {
            int i_mirror = 2 * center - i;
            if (r > i) {
                p[i] = min(r - i, p[i_mirror]);//  若可以以p[i_mirror]展开 r-i<=p[i_mirror] 当且仅当 i_mirror 在while中没有扩展
               // p[i] = p[i_mirror];          //  若不可以展开  则 p[i_mirror]为0
            }
            else {
                p[i] = 0;
            }

            while ((i - 1 - p[i]) >= 0 && i+1+p[i]<len && s[i + 1 + p[i]] == s[i - 1 - p[i]])++p[i];//总拓展长度不会超过n
            if (i + p[i] > r) {
                center = i;
                r = i + p[i];
            }
        }
        int maxlen = 0;
        int centeridx = 0;
        for (int i = 1; i <= len - 1; ++i) {
            if (p[i] > maxlen) {
                maxlen = p[i];
                centeridx = i;
            }
        }
        int start = (centeridx - maxlen) / 2;  //maxlen一定是偶数  center为奇数 相当于自带floor
        return temp.substr(start, maxlen);
    }
    string get_string(const string& s) {
        string res = "^#";
        for (int i = 0; i < s.size(); ++i) {
            res.push_back(s[i]);
            res.push_back('#');
        }
        return res + "$";
    }
};

//
//  Version by me;

// int main() {
//     Solution my = Solution();
//     string temp = my.longestPalindrome("babadada");
//         cout << temp << endl;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// string tar;
// string get_mystring(string temp){
// 	string res="#";
// 	for (int i=0;i<temp.size();++i){
// 		res.push_back(temp[i]);
// 		res.push_back('#');
// 	}
// 	return res;
// }

// int p[30005];

// int main(){
// 	getline(cin,tar);
//     if (tar.length()==1){
//         cout << 1 << endl;
//         return 0;
//     }
// 	string temp = get_mystring(tar);
// //	cout<<temp<<endl;
// 	int len=temp.size();
// 	// if (len==3){
// 	// 	cout<<1<<endl;
// 	// 	return 0;
// 	// }
// 	int max_len=1,start=0;
// 	int cur = 0,r=0;
// 	for (int i=0;i<len;++i)
// 	{
// 		int i_mirror=2*cur-i;
// 		if (r>i){
// 			p[i]=min(p[i_mirror],r-i);
// 		}
// 		else {
// 			p[i]=0;
// 		}
// 		int left=i-1-p[i],right=i+1+p[i];//日  你的马拉错东西了...一定要记得p[i]  不只是从左右两边为一距离位置开始
// 		while (left>=0 && right<len && temp[left]==temp[right]){
// 			++p[i],
// 			--left,++right;
// 		}
// //		if (p[i]>max_len)
// 		max_len=max(max_len,p[i]);
// 		if (i>r+cur){
// 			cur=i;
// 			r=cur+p[i];
// 		}
// 	}
// 	cout<<max_len<<endl;
// 	return 0;
// }

