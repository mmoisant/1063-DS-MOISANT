//Marcus Moisant
//Cpms1063
//Dr. Griffin
//22 March 2017
// This program converts infix expression to postfix
// by stack and queue implementation then calculates value
// of equation.

#include"Queue.h"
#include"Stack.h"

string getEquation();

void postfix(Queue & Q, Stack & S, string equation);

void main()
{
	string equation;
	equation = "(6+2)*5-8/4";
	//equation = getEquation();

	Queue Q(equation.length() + 2);
	Stack S(equation.length() + 2);

	postfix(Q, S, equation);

	//Q.printQueue();

	system("pause");
}

string getEquation()
{
	string equation;
	cout << "Input Equation: ";
	cin >> equation;
	cout << "\n";

	return equation;
}

void postfix(Queue & Q, Stack & S, string equation)
{
	Stack temp(equation.length() + 2);
	Stack calc(equation.length() + 2);
	int priority = 0;
	int peekPri = 0;
	char peek = '0';
	int i;
	int Num1 = 0;
	int Num2 = 0;

	equation += ')';
	S.push('(');

	for (i = 0; i < equation.length(); i++)
	{
		priority = 0;
		if (equation[i] == '+' || equation[i] == '-')
		{
			priority = 1;
		}
		else if (equation[i] == '*' || equation[i] == '/' || equation[i] == '%')
		{
			priority = 2;
		}
		else if (equation[i] == '^')
		{
			priority = 3;
		}

		if (equation[i] >= 48 && equation[i] <= 57)
		{
			Q.push(equation[i]);
			Q.printQueue();
		}
		else if (equation[i] == ')')
		{
			peek = S.peek();

			while (peek != 0)
			{
				Q.push(S.pop());
				Q.printQueue();
				peek = S.peek();
			}
			S.pop();
		}
		else if (equation[i] == '(')
		{
			S.push(equation[i]);
		}
		if (priority > 0)
		{
			peek = S.peek();
			if (peek == '+' || peek == '-')
			{
				peekPri = 1;
			}
			else if (peek == '*' || peek == '/' || peek == '%')
			{
				peekPri = 2;
			}
			else if (peek == '^')
			{
				peekPri = 3;
			}
			while (peekPri >= priority)
			{
				Q.push(S.pop());
				Q.printQueue();
				peek = S.peek();
				peekPri = 0;
				if (peek == '+' || peek == '-')
				{
					peekPri = 1;
				}
				else if (peek == '*' || peek == '/' || peek == '%')
				{
					peekPri = 2;
				}
				else if (peek == '^')
				{
					peekPri = 3;
				}
			}
			S.push(equation[i]);
		}
	}

	while (!S.isEmpty())
	{
		char temp = S.pop();
		if (temp != '(')
		{
			Q.push(temp);
			Q.printQueue();
		}
	}


	while (!Q.isEmpty())
	{
		char temp;
		temp = Q.pop();
		if (48 <= temp && 57 >= temp)
		{
			Num1 = temp - '0';
			cout << "Conversion: " << Num1 << endl;
			calc.push(Num1);
		}
		else if (temp == '+')
		{
			Num1 = calc.pop();
			Num2 = calc.pop();
			Num2 += Num1;
			cout << "Addition: " << Num2 << endl;
			calc.push(Num2);
		}
		else if (temp == '-')
		{
			Num1 = calc.pop();
			Num2 = calc.pop();
			cout << "Subtraction: " << Num2 << endl;
			Num2 -= Num1;
			calc.push(Num2);
		}
		else if (temp == '*')
		{
			Num1 = calc.pop();
			Num2 = calc.pop();
			Num2 *= Num1;
			cout << "Multiplication: " << Num2 << endl;
			calc.push(Num2);
		}
		else if (temp == '/')
		{
			Num1 = calc.pop();
			Num2 = calc.pop();
			if (Num1 != 0)
			{
				Num2 /= Num1;
				cout << "Division: " << Num2 << endl;
				calc.push(Num2);
			}
		}
		else if (temp == '^')
		{
			Num1 = calc.pop();
			Num2 = calc.pop();
			Num2 = pow(Num2, Num1);
			calc.push(Num2);
		}
		else if (temp == '%')
		{
			int mod1, mod2;

			Num1 = calc.pop();
			Num2 = calc.pop();
			mod1 = Num1;
			mod2 = Num2;
			if (mod1 == Num1&&mod2 == Num2)
			{
				mod2 %= mod1;
				calc.push(mod2);
			}
		}
	}
	int answer = 0;
	answer = calc.pop();
	for (int k = 0; k < equation.length(); k++)
	{
		cout << equation[k];
	}
	cout << " = " << answer << endl;
}
