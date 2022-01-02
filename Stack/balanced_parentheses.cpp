//Updated by Anshuman Singh

#include <iostream> //main header file
#include <stack>
using namespace std;

void balance_parentheses();

int main()
{
    balance_parentheses();
    return 0;
}

void balance_parentheses()
{
    stack<char> a;
    string s;
    cout << "Enter string containing parentheses:"<<endl;;
    cin >> s;
    int flag = 0; //flag is an arbitrary variable

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') 
        {
            a.push(s[i]);
            flag = 1;
        }
        if (!a.empty()) {
            if (s[i] == '}') {
                if (a.top() == '{')
                // top of the stack
                {
                    a.pop();
                    //pop function to delete terms from the top of array
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']') {
                if (a.top() == '[') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')') {
                if (a.top() == '(') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }

    if ((a.empty()) && (flag == 1))
        cout << "String is balanced" << endl;
    else
        cout << "String is not balanced" << endl;
}
