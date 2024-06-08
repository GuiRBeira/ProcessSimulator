#ifndef WIDGETS_H
#define WIDGETS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *btn_load_file;
    GtkWidget *btn_sjf;
    GtkWidget *btn_rr;
    GtkWidget *btn_priority;
    GtkWidget *process_by_arq;
    GtkWidget *text_output;
} Widgets_t;

typedef struct {
    bool is_completed;      // Indicador de processo concluído
    char *pid;              // PID do processo
    int burst_time;         // Tempo de execução do processo
    int arrival_time;       // Tempo de chegada do processo
    int priority;           // Prioridade do processo
    int remaining_time;     // Tempo restante de execução do processo
    int turnaround_time;    // Tempo total decorrido desde a chegada até a conclusão do processo
    int start_time;         // Tempo em que o processo começou a ser executado
    int completion_time;    // Tempo em que o processo foi concluído
    float waiting_time;     // Tempo de espera do processo
    float response_time;    // Tempo de resposta do processo (tempo até o primeiro início de execução)
} Process;

typedef struct {
    int count;                  // Número de processos
    float avg_response_time;   // Média do tempo de resposta dos processos
    float avg_waiting_time;    // Média do tempo de espera dos processos
    Process *processes;     // Array dinâmico de processos
} ProcessQueue;

void on_window_destroy(void);
void avg_processes(ProcessQueue *queue);
GtkWidget *create_quantum_dialog(GtkWidget *parent);
void on_btn_rr_clicked(GtkButton *button, gpointer user_data);
void on_btn_sjf_clicked(GtkButton *button, gpointer user_data);
void on_btn_priority_clicked(GtkButton *button, gpointer user_data);
void on_btn_load_file_clicked(GtkButton *button, gpointer user_data);

#endif // WIDGETS_H