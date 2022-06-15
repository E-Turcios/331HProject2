#include<iostream>
#include<stack>
#include "Stack.h"

using namespace std;
int input(char c)
{
  switch (c)
{
  case '(':
  return 1;
  case '+':
  case '-':
  return 2;
  case '*':
  case '/':
  return 3;
  case '^':
  return 4;
}
return -1;
}
int evaluate(char op, int num1 , int num2)
{
  if(op == '+')
{
  return num1 + num2;
}
  else if(op == '-')
  {
    return num1 - num2 ;
  }
  else if(op == '*')
  {
    return num1 * num2;
  }
  else if(op == '/')
  {
    if(num2 > 0)
    {
      return num1/num2;
    }
    return 0;
  }
  else if(op == '^')
  {
    return num1 ^ num2;
  }
  return -1;
}
int main(){

std::string string;
cin.getline(string);
int l = sizeof(string)/sizeof(char);
int k = 0;
stack<char> Operator;
stack<int> Operand;
cout <<"The expression: " << string <<" is equal to: "<<endl;
int i = 0;
while(string[i] != '\0')
{
  if(string[i] == '(')
  {
    Operator.push('(');
  }
  else if(string[i] == ')')
  {
    while(Operator.top() != '(')
    {
      int num2 = Operand.top();
      Operand.pop();
      int num1 = Operand.top();
      Operand.pop();
      int a =  evaluate(Operator.top(),num1,num2);
      Operand.push(a);
      Operator.pop();
    }
    Operator.pop();
  }
  else if(string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '^' || string[i] == '/')
  {
    int b = input(string[i]);
    while(!Operator.empty() && input(Operator.top()) >= b)
    {
      int num2 = Operand.top();
      Operand.pop();
      int num1 = Operand.top();
      Operand.pop();
      int a =  evaluate(Operator.top(),num1,num2);
      Operand.push(a);
      Operator.pop();
    }
    Operator.push(string[i]);
  }
  else
  {
    Operand.push(int(string[i])- 48);
  }
  i++;
}
while(!Operator.empty())
{
  int r = Operand.top();
  Operand.pop();
  int l = Operand.top();
  Operand.pop();
  int a =  evaluate(Operator.top(),l,r);
  Operand.push(a);
  Operator.pop();
}
cout <<"--> "<< Operand.top();
return 0;
}
