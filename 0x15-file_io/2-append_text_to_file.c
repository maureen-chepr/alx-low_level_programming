#include "main.h"

/**
 * append_text_to_file - append a text to the end of file
 * @filename: filename
 * @text_content: text content of the file
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, lgth, w;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (lgth = 0; text_content[lgth] != '\0'; lgth++)
		;
		w = write(fd, text_content, lgth);
		if (w == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
