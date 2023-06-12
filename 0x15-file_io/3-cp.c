#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int file_from_fd, file_to_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from_fd = open(argv[1], O_RDONLY);
	if (file_from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file_to_fd == -1)
	{
		close(file_from_fd);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((bytes_read = read(file_from_fd, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(file_to_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(file_from_fd), close(file_to_fd);
			dprintf(STDERR_FILENO, "Error: Failed to write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		close(file_from_fd), close(file_to_fd);
		dprintf(STDERR_FILENO, "Error: Failed to read from %s\n", argv[1]);
		exit(98);
	}
	if (close(file_from_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from_fd);
		exit(100);
	}
	if (close(file_to_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to_fd);
		exit(100);
	}
	return (0);
}

