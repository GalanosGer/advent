#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
    FILE* file;
    long long total = 0;
    
    file = fopen("input3.txt", "r");
    if (!file) return 1;
    
    char line[4096];
    int line_count = 0;
    
    while (fscanf(file, "%s", line) == 1) {
        int len = strlen(line);
        
        // We need at least 12 digits in the line
        if (len < 12) {
            printf("Line %d has only %d digits, skipping...\n", ++line_count, len);
            continue;
        }
        
        long long max_joltage = 0;
        
        // 12 nested loops - VERY inefficient!
        for (int i1 = 0; i1 <= len - 12; i1++) {
            for (int i2 = i1 + 1; i2 <= len - 11; i2++) {
                for (int i3 = i2 + 1; i3 <= len - 10; i3++) {
                    for (int i4 = i3 + 1; i4 <= len - 9; i4++) {
                        for (int i5 = i4 + 1; i5 <= len - 8; i5++) {
                            for (int i6 = i5 + 1; i6 <= len - 7; i6++) {
                                for (int i7 = i6 + 1; i7 <= len - 6; i7++) {
                                    for (int i8 = i7 + 1; i8 <= len - 5; i8++) {
                                        for (int i9 = i8 + 1; i9 <= len - 4; i9++) {
                                            for (int i10 = i9 + 1; i10 <= len - 3; i10++) {
                                                for (int i11 = i10 + 1; i11 <= len - 2; i11++) {
                                                    for (int i12 = i11 + 1; i12 < len; i12++) {
                                                        // Form 12-digit number
                                                        long long joltage = 0;
                                                        joltage = joltage * 10 + (line[i1] - '0');
                                                        joltage = joltage * 10 + (line[i2] - '0');
                                                        joltage = joltage * 10 + (line[i3] - '0');
                                                        joltage = joltage * 10 + (line[i4] - '0');
                                                        joltage = joltage * 10 + (line[i5] - '0');
                                                        joltage = joltage * 10 + (line[i6] - '0');
                                                        joltage = joltage * 10 + (line[i7] - '0');
                                                        joltage = joltage * 10 + (line[i8] - '0');
                                                        joltage = joltage * 10 + (line[i9] - '0');
                                                        joltage = joltage * 10 + (line[i10] - '0');
                                                        joltage = joltage * 10 + (line[i11] - '0');
                                                        joltage = joltage * 10 + (line[i12] - '0');
                                                        
                                                        if (joltage > max_joltage) {
                                                            max_joltage = joltage;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        total += max_joltage;
        line_count++;
        
        // Optional: Print progress (this will be VERY slow)
        if (line_count % 10 == 0) {
            printf("Processed %d lines, current total: %lld\n", line_count, total);
        }
    }
    
    fclose(file);
    printf("\n=== FINAL TOTAL: %lld ===\n", total);
    return 0;
}