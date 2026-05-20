#include <stdio.h>

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3};
    int n = 6;
    int frames_count = 3;

    int frames[3] = {-1, -1, -1}; // Start empty
    int page_faults = 0;
    int oldest_idx = 0; // The next frame to replace

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int hit = 0; // Simple integer for boolean status

        // Check if page already in memory
        for (int j = 0; j < frames_count; j++) {
            if (frames[j] == page) {
                hit = 1; // It's a Hit
                break;
            }
        }

        // Handle Page Fault
        if (!hit) {
            frames[oldest_idx] = page; // Use FIFO: replace the oldest
            oldest_idx = (oldest_idx + 1) % frames_count; // Cycle to next frame
            page_faults++;
            printf("Page %d: Fault | ", page);
        } else {
            printf("Page %d: Hit   | ", page);
        }

        // Simplified print
        for (int j = 0; j < frames_count; j++) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal FIFO Faults: %d\n", page_faults);
    return 0;
}