#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 32

char            *ft_string_realloc(char *input, int size)
{
    char        *output;

    if (!input)
        output = (char *)malloc(sizeof(char) * (size + 1));
    else
    {
        output = (char *)malloc(sizeof(char) * (size + 1));
        bzero(output, (size + 1));
        strcpy(output, input);
        free(input);
    }
    return (output);
}

int             get_next_line(const int fd, char **line)
{
    static char *stack[10240];
    char        *pointer;
    char        buffer[BUFF_SIZE + 1];
    int         amount;

    bzero(buffer, BUFF_SIZE + 1);
    if (fd < 0)
        return (0);
    while (amount = read(fd, buffer, BUFF_SIZE + 1))
    {
        stack[fd] = ft_string_realloc(stack[fd], strlen(stack[fd]) + amount);
        strcat(stack[fd], buffer);
        if (pointer = strchr(stack[fd], '\n'))
        {
            *pointer = '\0';
            ft_string_realloc(*line, strlen(stack[fd]));
            return (1);
        }
    }
    return (0);
}

int             main(int argc, char **argv)
{
    int         fd;
    char        *line;

    fd = open(argv[1], O_RDONLY);
    get_next_line(fd, &line);
    printf("%s", line);
    return (argc);
}
