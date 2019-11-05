#include "libmx.h"

char *mx_file_to_str(const char *file)
{
	if (!file)
		return NULL;

	char buf[1];
	int count = 0;

	int srcFile = open(file, O_RDONLY);
	if (srcFile < 0)
		return NULL;

	// Считаем кол-во символов в файле
	for (int c = read(srcFile, buf, 1); c > 0; count++)
		c = read(srcFile, buf, 1);

	close(srcFile);
	// Выделяем новую память с нужным кол-вом байт
	char *d = mx_strnew(count);
	if (!d) return NULL;
	
	srcFile = open(file, O_RDONLY);
	if (srcFile < 0) return NULL;

	read(srcFile, d, count);
	close(srcFile);
	return d;
}

// int main() {
// 	printf("%s", mx_file_to_str("src/file.txt"));
// 	return 0;
// }
