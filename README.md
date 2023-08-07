# Get Next Line

## About
The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

![get_next_line_mandatory part](https://github.com/BurcuBulakBozkurt/get_next_line_42/assets/122625978/22ea3c69-77ef-42c2-8c20-4622b849a30e)
                       
* Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
* Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
* Make sure that your function works as expected both when reading a file and when
reading from the standard input.
* Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
* Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
* Add all the helper functions you need in the get_next_line_utils.c file.

- For detailed information, please check [the subject of this project](https://github.com/BurcuBulakBozkurt/ft_printf_42/blob/main/Prinft_subject.pdf).
