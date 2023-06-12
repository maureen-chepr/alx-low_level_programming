#include "main.h"

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
	FILE *file_from, *file_to;
	char buffer[1024];
	size_t bytes_read, bytes_written;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}
	
	file_from = fopen(argv[1], "rb");
	if (file_from == NULL)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = fopen(argv[2], "wb");
	if (file_to == NULL)
	{
		fclose(file_from);
		fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((bytes_read = fread(buffer, 1, sizeof(buffer), file_from)) > 0)
	{
		bytes_written = fwrite(buffer, 1, bytes_read, file_to);
		if (bytes_written != bytes_read)
		{
			fclose(file_from);
			fclose(file_to);
			fprintf(stderr, "Error: Failed to write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (ferror(file_from) || ferror(file_to))
	{
		fclose(file_from);
		fclose(file_to);
		fprintf(stderr, "Error: File I/O error occurred\n");
		exit(99);
	}
	fclose(file_from);
	fclose(file_to);
	return (0);
}
