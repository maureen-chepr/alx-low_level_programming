#include "main.h"
#include <unistd.h>
#include <fcntl.h>
/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename:  the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);
	
	bytes_written = write(file_descriptor, text_content, content_length);
	close(file_descriptor);
	if (bytes_written == -1)
		return (-1);
	
	return (1);
}
