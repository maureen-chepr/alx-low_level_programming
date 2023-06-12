#include "main.h"
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - function that reads a text file and
 * prints it to the POSIX standard output
 * @filename: pointer to file
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print,
 * otherwise 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_descriptor, bytes_read, bytes_written, total_bytes_written;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}
	
	bytes_read = read(file_descriptor, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}
	
	total_bytes_written = 0;
	while (bytes_read > 0)
	{
		bytes_written = write(STDOUT_FILENO, buffer + total_bytes_written, bytes_read);
		if (bytes_written == -1)
		{
			free(buffer);
			close(file_descriptor);
			return (0);
		}
		total_bytes_written += bytes_written;
		bytes_read -= bytes_written;
	}
	free(buffer);
	close(file_descriptor);
	return (total_bytes_written);
}
