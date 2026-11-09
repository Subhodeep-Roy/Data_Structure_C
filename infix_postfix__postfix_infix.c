// // infix to postfix
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// int prior(char i)
// {
//     if (i == '/')
//         return 4;
//     if (i == '*')
//         return 3;
//     if (i == '+')
//         return 2;
//     if (i == '-')
//         return 1;
//     else
//         return 0;
// }
// void infix_postfix(char exp[])
// {
//     char stack[100], res[100];
//     int top = 0;
//     stack[top] = '(';

//     int k = 0;
//     for (int i = 0; i < strlen(exp); i++)
//     {
//         if (isalnum(exp[i]))
//         {
//             res[k] = exp[i];
//             k++;
//         }
//         else
//         {
//             if (exp[i] == '/' || exp[i] == '*' || exp[i] == '+' || exp[i] == '-')
//             {

//                 while (prior(stack[top]) >= prior(exp[i]))
//                 {

//                     res[k] = stack[top];
//                     top--;
//                     k++;
//                 }
//                 top++;
//                 stack[top] = exp[i];
//             }
//             else if (exp[i] == ')' || exp[i] == '(')
//             {
//                 if (exp[i] == '(')
//                 {
//                     top++;
//                     stack[top] = exp[i];
//                 }
//                 else
//                 {
//                     while (stack[top] != '(')
//                     {
//                         res[k] = stack[top];
//                         top--;
//                         k++;
//                     }
//                     top--;
//                 }
//             }
//         }
//     }
//     res[k] = '\0';
//     puts(res);
// }

// void infix_prefix(char exp[])
// {
//     char stack[100], res[100];
//         int top = 0;
//         stack[top] = ')';
//         int k = 0;
        
//         for (int i = 0; i < strlen(exp); i++)
//         {
//             if (isalnum(exp[i]))
//             {
//                 res[k] = exp[i];
//                 k++;
//             }
//             else
//             {
//                 if (exp[i] == '/' || exp[i] == '*' || exp[i] == '+' || exp[i] == '-')
//                 {
//                     while (prior(stack[top]) > prior(exp[i]))
//                     {
//                         res[k] = stack[top];
//                         top--;
//                         k++;
//                     }
//                     top++;
//                     stack[top]=exp[i];
//                 }
//                 else if (exp[i] == '(' || exp[i] == ')')
//                 {
//                     if (exp[i] == '(')
//                     {
//                         while (stack[top] != ')')
//                         {
//                             res[k] = stack[top];
//                             top--;
//                             k++;
//                         }
//                         top--;
//                     }
//                     else
//                     {
//                         top++;
//                         stack[top] = exp[i];
//                     }
//                 }
//             }
//         }
//         res[k]='\0';
//         for (int i = 0; i < strlen(res)/2; i++)
//         {
//             int temp = res[i];
//             res[i] = res[strlen(res) - (i+1)];
//             res[strlen(res) - (i+1)] = temp;
//         }
//         puts(res);
// }

// void main()
// {

//     char exp[100];
//     printf("Enter the expression:");
//     fgets(exp, sizeof(exp), stdin);
//     exp[strcspn(exp, "\n")] = '\0';
//     char exp1[100], exp2[100];
    
//     printf("\n--Menu--");
//     printf("\n1)Infix to Postfix");
//     printf("\n2)Infix to Prefix");
//     printf("\n3)Exit");
//     int choice = 0;
//     while (choice != 3)
//     {
//         printf("\n Enter your choice:");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//             case 1:
//             {
//             strcpy(exp1, exp);
//             strcat(exp1, ")");
//             infix_postfix(exp1);
//             break;
//         }
        
//         case 2:
//         strcpy(exp2, exp);
//         {
//             for (int i = 0; i < strlen(exp)/2; i++)
//         {
//             int temp = exp[i];
//             exp[i] = exp[strlen(exp) - (i+1)];
//             exp[strlen(exp) - (i+1)] = temp;
//         }
//             strcat(exp2, "(");
//             infix_prefix(exp2);
//             break;
//         }
//         case 3:
//         {
//             printf("Exit");
//             break;
//         }
//         default:{
//             printf("Invalid Input");
//             break;

//         }
//         }
        
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Push an element into stack
void push(char item)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = item;
}

// Pop an element from stack
char pop()
{
    if (top < 0)
    {
        return '\0';
    }

    return stack[top--];
}

// Return top element of stack
char peek()
{
    if (top < 0)
    {
        return '\0';
    }

    return stack[top];
}

// Check whether character is an operator
int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '^');
}

// Return operator precedence
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/' || ch == '%')
        return 2;

    if (ch == '^')
        return 3;

    return 0;
}

// Check whether operator is right associative
int is_right_associative(char ch)
{
    return (ch == '^');
}

// Infix to Postfix conversion
void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;
    char ch;

    top = -1;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        // Ignore spaces
        if (ch == ' ')
        {
            i++;
            continue;
        }

        // If operand, add directly to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // If left parenthesis, push into stack
        else if (ch == '(')
        {
            push(ch);
        }

        // If right parenthesis
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
            {
                pop();   // Remove '('
            }
        }

        // If operator
        else if (is_operator(ch))
        {
            while (top != -1 &&
                   peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) &&
                    !is_right_associative(ch))))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1)
    {
        if (peek() != '(')
        {
            postfix[j++] = pop();
        }
        else
        {
            pop();
        }
    }

    postfix[j] = '\0';
}

// Main function
int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%99[^\n]", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}