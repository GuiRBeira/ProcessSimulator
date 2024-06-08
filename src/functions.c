#include "functions.h"

void round_ronin(ProcessQueue *queue, int quantum, GtkTextBuffer *buffer) {
    int time = 0; // Tempo atual de execução
    int completed = 0; // Número de processos completados
    char timeline[4096] = ""; // Linha do tempo dos processos
    GtkTextIter iter; // Iterador para o buffer de texto

    // Obter o iterador para o final do buffer de texto
    gtk_text_buffer_get_end_iter(buffer, &iter);

    // Continuar até que todos os processos tenham sido completados
    while (completed < queue->count) {
        // Iterar sobre todos os processos na fila
        for (int i = 0; i < queue->count; i++) {
            // Verificar se o processo ainda não foi completado e se chegou ao tempo de chegada
            if (!queue->processes[i].is_completed && queue->processes[i].arrival_time <= time) {
                // Iniciar o processo se ainda não foi iniciado
                if (queue->processes[i].start_time == -1) {
                    queue->processes[i].start_time = time;
                }

                // Adicionar o segmento de tempo à linha do tempo
                char *segment = g_strdup_printf("|%d|-----", time);
                strcat(timeline, segment);
                strcat(timeline, queue->processes[i].pid);
                strcat(timeline, "-----");
                g_free(segment);

                // Verificar se o tempo restante do processo é maior que o quantum
                if (queue->processes[i].remaining_time > quantum) {
                    // Reduzir o tempo restante do processo pelo quantum
                    time += quantum;
                    queue->processes[i].remaining_time -= quantum;
                } else {
                    // Processo concluído
                    time += queue->processes[i].remaining_time;
                    queue->processes[i].remaining_time = 0;
                    queue->processes[i].turnaround_time = time;
                    wait_response_time(queue, i);
                    queue->processes[i].is_completed = true;
                    completed++;
                }
            }
        }
    }

    // Adicionar o tempo final à linha do tempo
    char *end_time = g_strdup_printf("|%d|", time);
    strcat(timeline, end_time);
    g_free(end_time);

    // Exibir a linha do tempo no GtkTextView
    gtk_text_buffer_set_text(buffer, timeline, -1);
}

void sjf_preemptive(ProcessQueue *queue, GtkTextBuffer *buffer) {
    int time = 0; // Tempo atual de execução
    int completed = 0; // Número de processos completados
    char timeline[2048] = ""; // Linha do tempo dos processos
    char last_pid[3] = ""; // PID do último processo adicionado à linha do tempo
    GtkTextIter iter; // Iterador para o buffer de texto

    // Obter o iterador para o final do buffer de texto
    gtk_text_buffer_get_end_iter(buffer, &iter);

    // Continuar até que todos os processos tenham sido completados
    while (completed < queue->count) {
        int shortest_job_index = -1;
        int shortest_job_time = INT_MAX;

        // Iterar sobre todos os processos na fila
        for (int i = 0; i < queue->count; i++) {
            // Verificar se o processo ainda não foi completado e se chegou ao tempo de chegada
            if (!queue->processes[i].is_completed && queue->processes[i].arrival_time <= time) {
                // Verificar se o tempo de execução deste processo é o menor até agora
                if (queue->processes[i].remaining_time < shortest_job_time) {
                    shortest_job_time = queue->processes[i].remaining_time;
                    shortest_job_index = i;
                }
            }
        }

        if (shortest_job_index != -1) {
            // Iniciar o processo se ainda não foi iniciado
            if (queue->processes[shortest_job_index].start_time == -1) {
                queue->processes[shortest_job_index].start_time = time;
            }

            // Adicionar o segmento de tempo à linha do tempo apenas se o PID mudou
            if (strcmp(last_pid, queue->processes[shortest_job_index].pid) != 0) {
                char *segment = g_strdup_printf("|%d|-----", time);
                strcat(timeline, segment);
                strcat(timeline, queue->processes[shortest_job_index].pid);
                strcat(timeline, "-----");
                g_free(segment);
                strcpy(last_pid, queue->processes[shortest_job_index].pid);
            }

            // Reduzir o tempo restante do processo em 1 unidade e avançar o tempo
            queue->processes[shortest_job_index].remaining_time--;
            time++;

            // Verificar se o processo foi concluído
            if (queue->processes[shortest_job_index].remaining_time == 0) {
                queue->processes[shortest_job_index].turnaround_time = time;
                queue->processes[shortest_job_index].is_completed = true;
                // Calcular o tempo de resposta
                wait_response_time(queue, shortest_job_index);
                completed++;
            }
        } else {
            // Avançar o tempo se não houver nenhum processo pronto
            time++;
        }
    }

    // Adicionar o tempo final à linha do tempo
    char *end_time = g_strdup_printf("|%d|", time);
    strcat(timeline, end_time);
    g_free(end_time);

    // Exibir a linha do tempo no GtkTextView
    gtk_text_buffer_set_text(buffer, timeline, -1);
}

void priority_preemptive(ProcessQueue *queue, GtkTextBuffer *buffer) {
    int time = 0; // Tempo atual de execução
    int completed = 0; // Número de processos completados
    char timeline[2048] = ""; // Linha do tempo dos processos
    char last_pid[3] = ""; // PID do último processo adicionado à linha do tempo
    GtkTextIter iter; // Iterador para o buffer de texto

    // Obter o iterador para o final do buffer de texto
    gtk_text_buffer_get_end_iter(buffer, &iter);

    // Continuar até que todos os processos tenham sido completados
    while (completed < queue->count) {
        int highest_priority_index = -1;
        int highest_priority = INT_MAX;

        // Iterar sobre todos os processos na fila
        for (int i = 0; i < queue->count; i++) {
            // Verificar se o processo ainda não foi completado e se chegou ao tempo de chegada
            if (!queue->processes[i].is_completed && queue->processes[i].arrival_time <= time) {
                // Verificar se a prioridade deste processo é a maior (menor valor)
                if (queue->processes[i].priority < highest_priority) {
                    highest_priority = queue->processes[i].priority;
                    highest_priority_index = i;
                }
            }
        }

        if (highest_priority_index != -1) {
            // Iniciar o processo se ainda não foi iniciado
            if (queue->processes[highest_priority_index].start_time == -1) {
                queue->processes[highest_priority_index].start_time = time;
            }

            // Adicionar o segmento de tempo à linha do tempo apenas se o PID mudou
            if (strcmp(last_pid, queue->processes[highest_priority_index].pid) != 0) {
                char *segment = g_strdup_printf("|%d|-----", time);
                strcat(timeline, segment);
                strcat(timeline, queue->processes[highest_priority_index].pid);
                strcat(timeline, "-----");
                g_free(segment);
                strcpy(last_pid, queue->processes[highest_priority_index].pid);
            }

            // Reduzir o tempo restante do processo em 1 unidade e avançar o tempo
            queue->processes[highest_priority_index].remaining_time--;
            time++;

            // Verificar se o processo foi concluído
            if (queue->processes[highest_priority_index].remaining_time == 0) {
                queue->processes[highest_priority_index].turnaround_time = time;
                queue->processes[highest_priority_index].is_completed = true;
                // Calcular o tempo de resposta
                wait_response_time(queue, highest_priority_index);
                completed++;
            }
        } else {
            // Avançar o tempo se não houver nenhum processo pronto
            time++;
        }
    }

    // Adicionar o tempo final à linha do tempo
    char *end_time = g_strdup_printf("|%d|", time);
    strcat(timeline, end_time);
    g_free(end_time);

    // Exibir a linha do tempo no GtkTextView
    gtk_text_buffer_set_text(buffer, timeline, -1);
}

void print_to_textview(GtkTextView *text_view, const char *message) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
    GtkTextIter end_iter;
    gtk_text_buffer_get_end_iter(buffer, &end_iter);
    gtk_text_buffer_insert(buffer, &end_iter, message, -1);
}

void wait_response_time(ProcessQueue *queue, int i) {
    queue->processes[i].response_time = queue->processes[i].turnaround_time - queue->processes[i].arrival_time;
    queue->processes[i].waiting_time = queue->processes[i].response_time - queue->processes[i].burst_time;
}