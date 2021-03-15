# gnl_refined
## Requirements:
- Use read, malloc, free to write a function called get_next_line.
- The function will read a file (whose link is the argument when executing) to the end of each line.
- The read value is stored in the parameter `line`. It should not contain `'\n'`.
- The function return value 1: a line has been read, 0: reading is finished, -1: error.
- Prototype: `int get_next_line(char **line)`
- There should be no memory leak.
## Requirements for bonus part:
- The program is able to read more than one file at a time.
## How it works?
- Run **test.sh** file by `./test.sh`.
- Otherwise: compile with: `gcc -g -Wall -Wextra -Werror -fsanitize=address main_test.c get_next_line.c get_next_line_utils.c`
- Or with: `gcc -g -Wall -Wextra -Werror -fsanitize=address main_test.c get_next_line_bonus.c get_next_line_utils_bonus.c`
## Files
- *.png*: screenshot of the mindmap
- *.emmx*: mindmap of the project. Opened by Edraw Mindmaster.
- *.c*, *.h*: program files.

