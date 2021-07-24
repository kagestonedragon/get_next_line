# get_next_line

`Проект реализовывался в рамках обучения в "Школе 21". Разработка функции на си для построчного чтения из файла.`

That function takes file descriptor, and the string where line from file will be written.

```c
int get_next_line(const int fd, char **line);
```

It returns:
* `1` - line was recorded;
* `0` - end of file;
* `-1` - error;


#### Info from the subject:

<p>You are now starting to understand that it will get tricky to read data from a file descriptor if you don’t know its size beforehand. What size should your buffer be? How many times do you need to read the file descriptor to retrieve the data?</p>

<p>It is perfectly normal and natural that, as a programmer, you would want to read a “line” that ends with a line break from a file descriptor. For example each command that you type in your shell or each line read from a flat file.</p>

<p>Thanks to the project get_next_line, you will finally be able to write a function that will allow you to read a line ending with a newline character from a file descriptor. You’ll be able to add this function to your libft if you feel like it and most importantly, use it in all the future projects that will require it.</p>
