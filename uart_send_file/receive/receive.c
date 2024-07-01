#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

void receive_file(const char *serial_port, const char *output_file_path) {
    int fd = open(serial_port, O_RDONLY | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    if (tcgetattr(fd, &tty) != 0) {
        perror("tcgetattr");
        close(fd);
        exit(EXIT_FAILURE);
    }

    cfsetospeed(&tty, B115200);
    cfsetispeed(&tty, B115200);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
    tty.c_iflag &= ~IGNBRK;
    tty.c_lflag = 0;
    tty.c_oflag = 0;
    tty.c_cc[VMIN]  = 1;
    tty.c_cc[VTIME] = 5;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~(PARENB | PARODD);
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("tcsetattr");
        close(fd);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(output_file_path, "wb");
    if (!file) {
        perror("fopen");
        close(fd);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    ssize_t n;
    printf("start...\n");

    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
	    printf("%s\n", buffer); 
        if (fwrite(buffer, 1, n, file) != n) {
            perror("fwrite");
            fclose(file);
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    close(fd);
    printf("File received successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <serial_port> <output_file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    receive_file(argv[1], argv[2]);
    return 0;
}

