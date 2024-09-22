#include<iostream>
using namespace std;

class stack {
public:
	 char* stackArray;
	int top = -1;
	char* postfix;
	int postTop = -1;
	stack(int s)
	{
		stackArray = new char[s];
		postfix = new char[s];
	}

	void eval(string str)
	{
		///(p+q)*(m-n) => pq+mn-*
		///note: EVERY OPERATOR YOU POP FROM STACK SHOULD BE PUSHED TO POSTFIX, "(" IS NEVER PUSHED TO POSTFIX, ")" IS NEVER PUSHED EITHER TO POSTFIX OR STACK
		///EVERY NEW OPERATOR SHOULD BE PUSHED EXCEPT ")"

		int size = str.length();
		for (int i = 0; i < size; i++)
		{
			char a = str[i]; ///read element from string

			if (a == ')')
			{
				///keep popping until "(" inclusive)
				while (stackArray[top] != '(')
				{
					postfix[++postTop] = stackArray[top--]; ///pop from stack and push to postfix
				}
				top--; ///to pop extra remaining "("
			}

			else if (a == '*' || a == '+' || a == '-' || a == '/' || a == '(')
			{
				///we pop from stack and push it to postfix on three conditions
				///	1. jb dono(top of stack and new operator ) ki precedence same ho e.g: +,- or -,+ or *,/ or /,*
				/// 2. jb dono operators same hon e.g: +,+ etc
				/// 3.aglay ki precedence kum ho 
				if ( stackArray[top] == '+' && a == '-' || stackArray[top] == '-' && a == '+' || stackArray[top] == '*' && a == '/' || stackArray[top] == '/' && a == '*' 
					|| stackArray[top] == '/' && a == '/' || stackArray[top] == '*' && a == '*' || stackArray[top] == '-' && a == '-' || stackArray[top] == '+' && a == '+' 
					|| stackArray[top] == '*' && a == '-' || stackArray[top] == '*' && a == '+' || stackArray[top] == '/' && a == '-' || stackArray[top] == '/' && a == '+')
				{
					postfix[++postTop] = stackArray[top--];///pichlay wala pop ho Kr postfix me agya
				}
				

				///agr new wali ki precedence zyada ho to sirf push krna ha 
				else if (stackArray[top] == '-' && a == '/' || stackArray[top] == '+' && a == '/' || stackArray[top] == '-' && a == '*' || stackArray[top] == '+' && a == '*')
				{
					stackArray[top++] = a;
				}
				
				stackArray[++top] = a; ///new operator ko hamesha push krna ha except when ")"
			}

			else ///koi operand ho to push it to postfix
				postfix[++postTop] = a;
		}

		///add remaining stack to postfix and pop stack
		while (top != -1)
		{
			postfix[++postTop] = stackArray[top--];
		}


		cout << "Postfix: ";
		for (int i = 0; i <= postTop; i++)
			cout << postfix[i];

		cout << endl<<"stack: ";
		for (int i = 0; i <= top; i++)
			cout << stackArray[i];
	}


};





int main()
{


	///uncomment test case u want to use

	//string str = "(p+q)*(m-n)";
	string str = "(a+b)*(c-d)/e";
	//string str = "a*(b+c)/d";


	stack * s = new stack(str.length());

	s->eval(str);

	return 0;
}