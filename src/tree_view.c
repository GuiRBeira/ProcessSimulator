#include "tree_view.h"

void clear_and_initialize_tree_view(GtkTreeView *tree_view, ProcessQueue queue) {
    clear_tree_view_columns(tree_view);
    initialize_tree_view(tree_view);
    populate_tree_view(tree_view, &queue);
}

void clear_tree_view_columns(GtkTreeView *tree_view) {
    GList *columns, *iter;
    // Obtém a lista de colunas existentes na GtkTreeView
    columns = gtk_tree_view_get_columns(tree_view);
    // Percorre a lista de colunas e remove cada uma delas
    for (iter = columns; iter != NULL; iter = iter->next) {
        gtk_tree_view_remove_column(tree_view, GTK_TREE_VIEW_COLUMN(iter->data));
    }
    // Libera a lista de colunas
    g_list_free(columns);
}

void initialize_tree_view(GtkTreeView *tree_view) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;

    if (tree_view != NULL) {
        // Coluna do Processo
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Processo", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna do Tempo de Burst
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Tempo", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna do Tempo de Chegada
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Chegada", renderer, "text", 2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna da Prioridade
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prioridade", renderer, "text", 3, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna do Tempo Restante
        //renderer = gtk_cell_renderer_text_new();
        //column = gtk_tree_view_column_new_with_attributes("Tempo Restante", renderer, "text", 4, NULL);
        //gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna do Tempo de Resposta
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Tempo Resposta", renderer, "text", 4, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna do Tempo de Início
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Início", renderer, "text", 5, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna do Tempo de Turnaround
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Tempo Execução", renderer, "text", 6, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
        // Coluna do Tempo de Espera
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Espera", renderer, "text", 7, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
    }
}

void populate_tree_view(GtkTreeView *tree_view, ProcessQueue *queue) {
    GtkListStore *store;
    GtkTreeIter iter;
    ProcessQueue q = copy_ProcessQueue(queue);
    store = gtk_list_store_new(8, G_TYPE_STRING,  // pid
                                  G_TYPE_INT,     // burst_time
                                  G_TYPE_INT,     // arrival_time
                                  G_TYPE_INT,     // priority
                                  //G_TYPE_INT,     // remaining_time
                                  G_TYPE_STRING,  // response_time
                                  G_TYPE_INT,     // start_time
                                  G_TYPE_INT,     // turnaround_time
                                  G_TYPE_STRING); // waiting_time

    char response_time_str[16];
    char waiting_time_str[16];

    for (int i = 0; i < q.count; i++) {
        snprintf(response_time_str, sizeof(response_time_str), "%.2f", q.processes[i].response_time);
        snprintf(waiting_time_str, sizeof(waiting_time_str), "%.2f", q.processes[i].waiting_time);

        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
                           0, q.processes[i].pid,
                           1, q.processes[i].burst_time,
                           2, q.processes[i].arrival_time,
                           3, q.processes[i].priority,
                           //4, q.processes[i].remaining_time,
                           4, response_time_str,
                           5, q.processes[i].start_time,
                           6, q.processes[i].turnaround_time,
                           7, waiting_time_str,
                           -1);
    }

    gtk_tree_view_set_model(tree_view, GTK_TREE_MODEL(store));
    avg_processes(&q);

    snprintf(response_time_str, sizeof(response_time_str), "%.2f", q.avg_response_time);
    snprintf(waiting_time_str, sizeof(waiting_time_str), "%.2f", q.avg_waiting_time);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,
                        0, "Total",
                        1, 0,
                        2, 0,
                        3, 0,
                        //4, 0,
                        4, response_time_str,
                        5, 0,
                        6, 0,
                        7, waiting_time_str,
                        -1);

    g_object_unref(store);
    // debug_mostra_processos(q);
}

void avg_processes(ProcessQueue *queue){
    ProcessQueue *q = queue;
    for(int i = 0; i < q->count; i++){
        q->avg_waiting_time += q->processes[i].waiting_time;
        q->avg_response_time += q->processes[i].response_time;
    }
    q->avg_response_time /= q->count;
    q->avg_waiting_time /= q->count;
}

ProcessQueue copy_ProcessQueue(ProcessQueue *original) {
    ProcessQueue copy;
    //printf("Copia criada\n");
    copy.count = original->count;
    copy.avg_response_time = original->avg_response_time;
    copy.avg_waiting_time = original->avg_waiting_time;
    copy.processes = (Process *)malloc(copy.count * sizeof(Process));
    for (int i = 0; i < copy.count; i++) {
        copy.processes[i] = original->processes[i];
    }
    //printf("Copia retornada\n");
    return copy;
}

void free_ProcessQueue(ProcessQueue *queue) {
    free(queue->processes);
    queue->processes = NULL;
    queue->count = 0;
}

void debug_mostra_processos(ProcessQueue q) {
    for (int i = 0; i < q.count; i++) {
        printf("Process ID: %s\nArrival Time: %d\nBurst Time: %d\nPriority: %d\nRemaining Time: %d\nResponse Time: %.2f\nStart Time: %d\nTurnaround Time: %d\nWaiting Time: %.2f\n\n",
               q.processes[i].pid,
               q.processes[i].arrival_time,
               q.processes[i].burst_time,
               q.processes[i].priority,
               q.processes[i].remaining_time,
               q.processes[i].response_time,
               q.processes[i].start_time,
               q.processes[i].turnaround_time,
               q.processes[i].waiting_time);
    }
}
