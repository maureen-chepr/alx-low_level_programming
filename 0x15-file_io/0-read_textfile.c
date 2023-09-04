#include "main.h"
/**
* read_textfile - function that reads a text file and prints
* it to the POSIX standard output
* @filename: name of file to be read
* @letters: number of letters to read
* Return: number of letters it could read and print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int x = 0;
	ssize_t bytes;
	char buf[READ_BUF_SIZE * 8];
	
	if (!filename || !letters)
		return (0);
	
	x = open(filename, O_RDONLY);
	if (x == -1)
		return (0);
	bytes = read(x, &buf[0], letters);
	bytes = write(STDOUT_FILENO, &buf[0], bytes);
	close(x);
	return (bytes);

}
