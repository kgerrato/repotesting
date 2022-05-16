#include <iostream>
#include <iostream>
#include <stack>

using namespace std;

int MaxLen(string A)
{
    int n = A.length();
 
    stack<int> stackA; //stack created with -1 pushed as initial index
    stackA.push(-1);

    int result = 0; //result initialization

    for (int i = 0; i < n; i++) //characters string is traversed here
    {
        if (A[i] == '(') //when ( then push index
            stackA.push(i);

        else //otherwise if )
        {
            stackA.pop(); //pop opening bracket's index

            if (!stackA.empty()) //check if length of valid substring is more than max
                result = max(result, i - stackA.top());

            else stackA.push(i); //if empty then push base as next valid string
        }
    }

    return result;
}

// Driver program 
int main()
{//testing it a few different ways
    string A = "((()()()()"; //()()() = 8
    cout << MaxLen(A) << endl;

    A = "()()"; //()() = 4
    cout << MaxLen(A) << endl;

    A = "()))"; //() = 2
    cout << MaxLen(A) << endl;

    return 0;
}
