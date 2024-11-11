Q.2) Write a C program to find file properties such as inode number, number of hard links, file permissions, file size, file access and modification time, and so on of a given file using the stat() system call

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat fileStat;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", filename);
    printf("Inode: %ld\n", fileStat.st_ino);
    printf("Number of hard links: %ld\n", fileStat.st_nlink);
    printf("File size: %ld bytes\n", fileStat.st_size);
    printf("File permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last access time: %s", ctime(&fileStat.st_atime));
    printf("Last modification time: %s", ctime(&fileStat.st_mtime));
    printf("Last change time: %s", ctime(&fileStat.st_ctime));

    return 0;
}


Output:
Enter the filename: example.txt
File: example.txt
Inode: 123456
Number of hard links: 1
File size: 1234 bytes
File permissions: 644
Last access time: Fri Nov 11 12:34:56 2024
Last modification time: Fri Nov 11 12:34:56 2024
Last change time: Fri Nov 11 12:34:56 2024