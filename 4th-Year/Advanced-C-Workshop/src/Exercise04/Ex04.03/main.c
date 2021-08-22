#include <stdio.h>
#include "parameters.h"

int main(int argc, char **argv)
{
    size_t flag_count = 0;
    size_t case_counters[3] = { 0 };
    printf("Parameters: %d\n", argc - 1);
    for (size_t i = 1; i < argc; ++i)
    {
        printf("\t%s\n", argv[i]);
        flag_count += FlagCount(argv[i]);
        ++case_counters[CaseOf(argv[i])];
    }

    printf("Number of flags: %lu\n", flag_count);
    printf("Number of lower-case parameters: %lu\n", case_counters[LOWER_CASE]);
    printf("Number of upper-case parameters: %lu\n", case_counters[UPPER_CASE]);
    printf("Number of no-case parameters: %lu\n", case_counters[NO_CASE]);

    return 0;
}