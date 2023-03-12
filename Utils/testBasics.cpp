#include "Stack.h"
using namespace igmdk;

void DDDVector()
{
    Vector<int> Vector0to4;
    for (int i = 0; i < 5; ++i)
        Vector0to4.append(i);
    cout << "breakpoint" << endl;
}

void DDDStack()
{
    Stack<int> Stack0to4;
    for (int i = 0; i < 5; ++i)
        Stack0to4.push(i);
    cout << "breakpoint" << endl;
}

int main()
{
    DDDVector();
    DDDStack();
}