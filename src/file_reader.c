#include "file_reader.h"

void read_processes_from_file(const char *filename, ProcessQueue *queue) {
    FILE *file = fopen(filename, "r");
    char line[256];
    queue->count = 0;

    // Read the process IDs and count them
    fgets(line, sizeof(line), file);
    char *token = strtok(line, " \t");
    while (token != NULL) {
        queue->count++;
        token = strtok(NULL, " \t");
    }
    queue->count--;  // Subtract one for the "Processo" header

    // Allocate memory for processes
    queue->processes = (Process *)malloc(queue->count * sizeof(Process));

    // Rewind and skip the header lines again
    rewind(file);
    // Read process IDs using a loop
    fgets(line, sizeof(line), file);  // Read the line containing PIDs
    token = strtok(line, " \t");
    for (int i = 0; i < queue->count; i++) {
        token = strtok(NULL, " \t");
        token[strcspn(token, "\n")] = '\0';
        queue->processes[i].pid = strdup(token);  // Use strdup to duplicate the string
    }

    // Read burst times
    fgets(line, sizeof(line), file);
    token = strtok(line, " \t");
    for (int i = 0; i < queue->count; i++) {
        token = strtok(NULL, " \t");
        queue->processes[i].burst_time = atoi(token);
    }

    // Read arrival times
    fgets(line, sizeof(line), file);
    token = strtok(line, " \t");
    for (int i = 0; i < queue->count; i++) {
        token = strtok(NULL, " \t");
        queue->processes[i].arrival_time = atoi(token);
    }

    // Read priorities
    fgets(line, sizeof(line), file);
    token = strtok(line, " \t");
    for (int i = 0; i < queue->count; i++) {
        token = strtok(NULL, " \t");
        queue->processes[i].priority = atoi(token);
    }

    // Initialize other fields
    for (int i = 0; i < queue->count; i++) {
        queue->processes[i].remaining_time = queue->processes[i].burst_time;
        queue->processes[i].waiting_time = 0;
        queue->processes[i].turnaround_time = 0;
        queue->processes[i].response_time = 0;
        queue->processes[i].start_time = -1;
        queue->processes[i].completion_time = 0;
        queue->processes[i].is_completed = queue->processes[i].remaining_time == 0;
    }
    
// debug for read of processes from file
//   for (int i = 0; i < queue->count; i++) {
//       printf("Process ID: %s\nArrival Time: %d\nBurst Time: %d\nPriority: %d\n",
//              queue->processes[i].pid,
//              queue->processes[i].arrival_time,
//              queue->processes[i].burst_time,
//              queue->processes[i].priority);
//   }

    fclose(file);
}