#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void *my_realloc(void *ptr, size_t new_size, void *add) {
    if (new_size == 0 || ptr == NULL) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }

    int i = 0;
	int n = 0;
    char *src = ptr;  // eski pointer
    char *dst = new_ptr;  // yeni pointer
	char *addsrc = add;  // yeni pointer
    while(src[i] != '\0'){
        dst[i] = src[i];
        i++;
    }
	while(addsrc[n] != '\0'){
        dst[i + n] = addsrc[n];
        n++;
    }

    free(ptr);

    return new_ptr;
}

char *get_next_line(int fd) {
    static void* n;
    void *line;
    char buffer[5];
    int bytes_read;

    if (fd == -1) {
        perror("Dosya açılamadı");
        return NULL;
    }

    bytes_read = read(fd, buffer, sizeof(buffer));

    if (bytes_read == -1) {
        perror("Okuma hatası");
        return NULL;
    }

    while (bytes_read >= 0)
    {
        if(buffer[bytes_read] == '\n'){
			break;
        }
        bytes_read--;
    }

	my_realloc(line, (5 - bytes_read), )
    
    return line;
}

int main() {
    int fd = open("example.txt", O_RDONLY);  // Dosyayı okuma modunda aç

    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    char *line1 = get_next_line(fd);  // İlk satırı oku
    if (line1) {
        write(1, line1, 2);  // Satır numarasını yazdır
        free(line1);  // Belleği serbest bırak
    }

    char *line2 = get_next_line(fd);  // İkinci satırı oku
    if (line2) {
        write(1, line2, 2);  // Satır numarasını yazdır
        free(line2);  // Belleği serbest bırak
    }

    write(1, "\n", 1);  // Bir satır sonu daha ekle

    close(fd);  // Dosyayı kapat
    return 0;
}
