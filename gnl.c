#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#define BUFF_SIZE 32

int                 ft_modified_strlen(char *s)
{
    int             i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char                *ft_generate_string(char *f_input, char *s_input)
{
    char            *output;

    if (!f_input || !s_input)
        return (NULL);
    output = (char *)malloc(sizeof(char) * (ft_modified_strlen(f_input) + ft_modified_strlen(s_input) + 1));
    if (!output)
        return (NULL);
    strcpy(output, f_input);
    strcat(output, s_input);
    free(f_input);
    free(s_input);
    return (output);
}

char                *ft_generate_line(char *stack)
{
    char            *output;

    output = (char *)malloc(sizeof(char) * (ft_modified_strlen(stack) + 1));
    if (!output)
        return (NULL);
    strcpy(output, stack);
    return (output);
}

int                 get_next_line(const int fd, char **line)
{
    static char     *stack;
    char            *pointer;
    char            buff[BUFF_SIZE + 1];

    bzero(buff, '\0');
    if (fd < 0)
        return (0);
    if (read(fd, buff, 4))
    {
        stack = ft_generate_string(stack, buff);
        if ((pointer = strchr(stack, '\n')))
        {
            *pointer = '\0';
            *line = ft_generate_line(stack);
            return (1);
        }
    }
    return (-1);
}

int             main(int argc, char **argv)
{
/* TEST FUNCTION FT_GENERATE_STRING
    char ch1[] = "PRIVET";
    char ch2[] = "POKA";
    char *p1;
    char *p2;
    char *p3;

    p1 = &ch1[0];
    p2 = &ch2[0];
    p3 = ft_generate_string(p1, p2);
    printf("%s\n", p3);
    printf("%lu", strlen(p3));
*/
    /* TEST GET_NEXT_LINE FUNCTION */
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%d", ft_modified_strlen(line));
    return (0);
}
