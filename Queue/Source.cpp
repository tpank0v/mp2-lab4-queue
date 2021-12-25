#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(10);
    q.Push(20);
    cout << q <<endl;
    q.Pop();
    cout << q << endl;
    q.Push(30);
    cout << q << endl;
    q.Pop();
    cout << q << endl;
    q.Push(40);
    cout << q << endl;
    q.Pop();
    cout << q << endl;
    q.Push(50);
    q.Pop();
    cout << q << endl;
    q.Pop();
    cout << q << endl;
    q.Pop();
    cout << q << endl;

    return 0;
}