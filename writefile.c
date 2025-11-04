// write a file

#include <stdio.h>
#include <stdlib.h>

void write_input_file() {
    FILE *f = fopen("input.txt", "w");
    if (!f) { perror("Write Error"); exit(1); }
    int num,i;
    printf("Enter 10 integers:\n");
    for ( i = 0; i < 10; i++) {
        printf("Int %d: ", i + 1);
        if (scanf("%d", &num) == 1) {
            fprintf(f, "%d\n", num);
        } else {
            printf("Invalid input skipped.\n");
            while(getchar() != '\n'); // Clear buffer
            i--; // Retry
        }
    }
    fclose(f);
}

void process_and_write_output() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    if (!in || !out) { perror("File Error"); if (in) fclose(in); if (out) fclose(out); return; }

    int num, sum = 0, count = 0;
    while (fscanf(in, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    
    float avg = (count > 0) ? (float)sum / count : 0.0;
    
    fprintf(out, "Sum: %d\n", sum);
    fprintf(out, "Average: %.2f\n", avg);
    
    fclose(in);
    fclose(out);
}

void display_file_contents(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) { perror("Display Error"); return; }
    
    char buffer[256];
    printf("\n--- Contents of %s ---\n", filename);
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }
    fclose(f);
}

int main() {
    write_input_file();
    process_and_write_output();
    display_file_contents("input.txt");
    display_file_contents("output.txt");
    return 0;
}