#include <stdio.h>
#include <string.h>
#include "ReadLine.h"
#include "ForEachWord.h"
#include "stack.h"

#define WHITESPACE " \n\r\t"

void PushStringToStack(char *string, va_list stack_container)
{
    Stack *stack = va_arg(stack_container, Stack *);
    char *string_copy = strdup(string);
    Push(stack, string_copy);
}

int main()
{
    char *sentence = NULL;
    size_t size;
    ReadLine("Enter a sentence:\n> ", &sentence, &size);

    Stack *stack = CreateStack();
    ForEachWord(sentence, WHITESPACE, PushStringToStack, stack);

    while (!IsEmpty(stack))
    {
        char *word;
        Pop(stack, (void **) &word);
        printf("%s ", word);
        free(word);
    }

    printf("\n");
    return 0;
}