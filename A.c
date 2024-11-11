Q.1) Display all the files from the current directory whose size is greater than n bytes, where n is accepted from the user

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    char dir_path[] = ".";  // Current directory
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    long n;

    printf("Enter the size in bytes: ");
    scanf("%ld", &n);

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    printf("Files greater than %ld bytes:\n", n);
    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &file_stat) == 0) {
            if (file_stat.st_size > n) {
                printf("%s\n", entry->d_name);
            }
        }
    }

    closedir(dir);
    return 0;
}

Output (assuming files file1.txt, file2.txt, and file3.txt exist with varying sizes):

Enter the size in bytes: 100
Files greater than 100 bytes:
file2.txt
file3.txt