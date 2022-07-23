#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(vector<int> &next, const string &s) {
    int j = 0;
    next[0] = j;

    for(int i = 1; i < s.size(); ++i) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }

        if (s[i] == s[j]) j++;
        next[i] = j;
    }
}

void printNext(vector<int> &next) {
    for(const int &a: next) {
        cout << a;
    }
    cout << endl;
}

int strStr(string s, string needle) {
    if (needle.size() == 0) return 0;

    vector<int> next(needle.size());
    getNext(next, needle);

    // j是指向needle字符串的某个位置
    int j = 0;
    for(int i = 0; i < s.size(); ++i) {
        while(j > 0 && s[i] != needle[j]) {
            // 如果目标串和模式串不匹配，j返回到next[j-1]，找到下一个匹配的位置
            j = next[j - 1];
        }
        // 如果目标串和模式串的字符匹配，则j加1
        if(s[i] == needle[j]) j++;

        // 如果j指向模式串最后，则匹配完成
        if(j == needle.size()) {
            return (i - needle.size() + 1);
        }
    }

    return -1;
}

int main() {
    vector<string> strList;
    strList.push_back("aabaaf");
    strList.push_back("aabaab");
    strList.push_back("aab");

//    for(const string& str: strList) {
//        vector<int> next(str.size());
//        getNext(next, str);
//        cout << "str: \n" << str << endl;
//        printNext(next);
//    }
    int result;
    result = strStr("hello", "ll");

    cout << result << endl;

    return 0;
}
