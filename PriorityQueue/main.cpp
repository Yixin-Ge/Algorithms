#include <iostream>
#include <queue>

using namespace std;



int main() {
    priority_queue<int> p;
    p.push(1);
    p.push(2);
    p.push(4);
    p.push(32);
    cout << "p.size(): " << p.size() << endl;
    cout << "p.top(): " << p.top() << endl;

    cout << "after poping 1 element" << endl;
    p.pop();
    cout << "p.top(): " << p.top() << endl;

    cout << "then pop all elements" << endl;
    for(int i = 0; i < 3; ++i) {
        p.pop();
    }
    cout << "p.empty(): " << p.empty() << endl;

    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    priority_queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    p.swap(q);

    q.emplace(0);

    cout << "Here is the p queue:" << endl;
    while(!p.empty()) {
        cout << p.top() << endl;
        p.pop();
    }

    cout << "Here is the q queue:" << endl;
    while(!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }

    return 0;
}
