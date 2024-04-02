// program 5
// Conver infix to postfix and postfix to infix

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char operators[128], operands[128];
int top1 = -1, top2 = -1;

int precedence(char c)
{
		if (c == '*' || c == '/') return 3;
		if (c == '+' || c == '-') return 1;
		return -1;
}

char *InfixToPostfix(char *exp)
{
		int len = strlen(exp);
		char *res = (char *)malloc(len + 1);
		int ri = 0;

		for (int i = 0; i < len; i++) {
				char c = exp[i];
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
						res[ri++] = c;

				} else if (c == '(') {
						operators[++top1] = c;
				} else if (c == ')') {
						while (top1 != -1 && operators[top1] != '(') {
								res[ri++] = operators[top1--];
						}
						top1--;
				} else {
						while (top1 != -1 && (precedence(c) <= precedence(operators[top1]))) {
								res[ri++] = operators[top1--];
						}
						operators[++top1] = c;
				}
		}
		while (top1 != -1) { res[ri++] = operators[top1--]; }
		res[ri] = '\0';
		return res;
}

char *PostFixToInfix(char *exp)
{
		int len = strlen(exp);
		char *res = (char *)malloc(len + 1);
		char tmp[128][128] = { 0 };
		int ti = -1;

		for (int i = 0; i < len; i++) {
				char c = exp[i];
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
						ti++;
						tmp[ti][0] = c;
						tmp[ti][1] = '\0';
				} else {
						char op2[128];
						strcpy(op2, tmp[ti--]);
						char op1[128];
						strcpy(op1, tmp[ti--]);
						sprintf(tmp[++ti], "(%s%c%s)", op1, c, op2);
				}
		}
		strcpy(res, tmp[0]);
		return res;
}

char *InfixToPrefix(char *exp)
{
		int len = strlen(exp);
		char *res = (char *)malloc(len + 1);
		int ri = 0;
		for (int i = 0; i < len / 2; i++) {
				char tmp = exp[i];
				exp[i] = exp[len - i - 1];
				exp[len - i - 1] = tmp;
		}
		for (int i = 0; i < len; i++) {
				if (exp[i] == '(')
						exp[i] = ')';
				else if (exp[i] == ')')
						exp[i] = '(';
		}

		char *postfix = InfixToPostfix(exp);
		for (int i = 0; i < len / 2; i++) {
				char tmp = postfix[i];
				postfix[i] = postfix[len - i - 1];
				postfix[len - i - 1] = tmp;
		}
		for (int i = 0; i < len; i++) {
				if (postfix[i] == '(')
						postfix[i] = ')';
				else if (postfix[i] == ')')
						postfix[i] = '(';
		}
		strcpy(res, postfix);
		free(postfix);
		return res;
}

char *PrefixToInfix(char *exp)
{
		int len = strlen(exp);
		char *res = (char *)malloc(len + 1);
		char tmp[128][128] = { 0 };
		int ti = -1;

		for (int i = len - 1; i >= 0; i--) {
				char c = exp[i];
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
						ti++;
						tmp[ti][0] = c;
						tmp[ti][1] = '\0';
				} else {
						char op1[128];
						strcpy(op1, tmp[ti--]);
						char op2[128];
						strcpy(op2, tmp[ti--]);
						sprintf(tmp[++ti], "(%s%c%s)", op1, c, op2);
				}
		}

		strcpy(res, tmp[0]);
		return res;
}

int main()
{
		char buffer[101];

		printf("Enter Infix expression: ");
		scanf("\n%[^\n]100s", buffer);

		char *res = InfixToPostfix(buffer);
		printf("Postfix: %s\n", res);
		free(res);

		res = InfixToPrefix(buffer);
		printf("Prefix: %s\n", res);
		free(res);

		printf("Enter Postfix Expression: ");
		scanf("\n%[^\n]100s", buffer);

		res = PostFixToInfix(buffer);
		printf("Infix: %s\n", res);
		free(res);

		printf("Enter Prefix Expression: ");
		scanf("\n%[^\n]100s", buffer);

		res = PrefixToInfix(buffer);
		printf("Infix: %s\n", res);
		free(res);
		return 0;
}