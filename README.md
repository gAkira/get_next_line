## This is a project from Ecole 42

#### Function name:
get\_next\_line

#### Description:
It's a function which returns a line read from a file descriptor, without the new line

#### Prototype:
```c
int get_next_line(int fd, char **line);
```

#### Parameters:
```
fd: file descriptor for reading
line: the value of what has been read
```

#### Return value:
```
1: A line has been read
0: End Of File (EOF) has been read
-1:	An error happened
```

#### Obs.:
The function must use the BUFFER\_SIZE defined during compilation to read from a file or from stdin