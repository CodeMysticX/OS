# LRU Page Replacement Algorithm

This program implements the Least Recently Used (LRU) page replacement algorithm in C.

## Function Description

### lruPageReplacement

This function takes an array of page requests, the number of page requests, and the number of frames as input. It simulates the LRU page replacement algorithm and prints the frames after each page request, along with the total number of page faults.

#### Parameters:

- `pages[]`: An array containing page requests.
- `n`: The number of page requests.
- `frames`: The number of frames in the memory.

#### Algorithm:

1. Initialize an array `frame[]` to hold the frames and an array `recentUse[]` to keep track of the recent use of each frame.
2. Iterate through the page requests.
3. Check if the page is already in one of the frames. If found, update the recent use of the frame.
4. If the page is not found in the frames, find the frame with the minimum recent use and replace it with the current page.
5. Print the frames after each page request.
6. Print the total number of page faults.

## Main Function Description

### main

This function takes user input for the number of frames and page requests, and the page requests themselves. Then, it calls the `lruPageReplacement` function to perform the LRU page replacement algorithm.

## Usage

Compile the program and run it. Enter the number of frames, the number of page requests, and the page requests themselves when prompted.

## Code

```c
#include <stdio.h>

// Function to perform Least Recently Used (LRU) page replacement algorithm
void lruPageReplacement(int pages[], int n, int frames) {
    // Array to hold the frames and an array to keep track of the recent use of each frame
    int frame[frames];
    int recentUse[frames];
    int pageFaults = 0;

    // Initialize frame and recentUse arrays
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;        // Initialize frames with -1 indicating an empty frame
        recentUse[i] = 0;     // Initialize recentUse with 0
    }

    // Iterate through the page requests
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pageFound = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                pageFound = 1;
                recentUse[j] = i + 1;  // Update recent use of the frame
                break;
            }
        }

        // If page is not found in frames
        if (!pageFound) {
            // Find the frame with the minimum recent use
            int minRecentUseIndex = 0;
            for (int j = 1; j < frames; j++) {
                if (recentUse[j] < recentUse[minRecentUseIndex]) {
                    minRecentUseIndex = j;
                }
            }

            // Replace the frame with minimum recent use with the current page
            frame[minRecentUseIndex] = page;
            recentUse[minRecentUseIndex] = i + 1;  // Update recent use
            pageFaults++;  // Increment page faults
        }

        // Print the frames after each page request
        printf("Frames: ");
        for (int j = 0; j < frames; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    // Print total page faults
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int frames, n;
    
    // Input number of frames and page requests
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of page requests: ");
    scanf("%d", &n);

    // Input page requests
    int pages[n];
    printf("Enter the page requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Perform LRU page replacement algorithm
    lruPageReplacement(pages, n, frames);

    return 0;
}
