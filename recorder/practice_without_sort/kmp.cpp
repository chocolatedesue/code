#include<bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e6+10)
int Next[MAXN];
int Next2[MAXN];
string text, pat;
int len1, len2;

// oop 模式设计代码算法... 深刻学习

//坑点  如何处理非首位的  前后公共前后缀为1时的判断  要有区分
void get_Next() {
	int i = 1, idx = 0, len = 0;//next为公共最长前后缀， i为前缀  idx为后缀  1个字母没有前后缀
	while (i < len2) {
		if (pat[i] == pat[idx]) {
			Next[i++] = ++idx;
		}
		else {
			while (idx > 0 && pat[i] != pat[idx]) {
				idx = Next[idx - 1];
			}
			if (idx == 0) {
				if (pat[i] == pat[idx])
				{
					Next[i++] = ++idx;
				}
				else Next[i++] = 0;
			}
		}
	}
}

void kmp() {
	Next2[0] = -1;
	for (int i = 1; i <= len2; ++i) {
		Next2[i] = Next[i - 1];
	}
	int idx = 0, i = 0;
	while (i < len1) {
		if (text[i] == pat[idx]) {
			++i, ++idx;
		}
		if (idx == len2) {
			cout << i - idx + 1 << endl;
			idx = Next2[idx];
		}
		else {
			while (idx != -1 && pat[idx] != text[i]) {
				idx = Next2[idx];
			}
			if (idx == -1)++i, ++idx;//-1哨兵用来处理第一位和最后一位匹配不上的情况

		}
	}
}



int main() {
	cin >> text >> pat;
	len1 = text.size(), len2 = pat.size();
	get_Next();
	kmp();


	for (int i = 0; i < len2; ++i) {
		cout << Next[i] << " ";
	}


	return 0;
}