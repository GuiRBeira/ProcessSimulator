#include "functions.h"
#include "tree_view.h"
#include "file_reader.h"

ProcessQueue queue;
GtkWidget *quantum_entry = NULL;

void on_btn_load_file_clicked(GtkButton *button, void *user_data) {
    Widgets_t *widgets = (Widgets_t *)user_data;
    GtkWidget *dialog;
    GtkFileFilter *filter;
    dialog = gtk_file_chooser_dialog_new("Escolher Arquivo",
                                         GTK_WINDOW(widgets->window),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         "_Open", GTK_RESPONSE_ACCEPT,
                                         NULL);
    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Project Files");
    gtk_file_filter_add_pattern(filter, "*.sop");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Text Files");
    gtk_file_filter_add_pattern(filter, "*.txt");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "All Files");
    gtk_file_filter_add_pattern(filter, "*");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        //printf("Lendo processos\n");
        read_processes_from_file(filename, &queue);
        //printf("Criando treeview\n");
        clear_and_initialize_tree_view(GTK_TREE_VIEW(widgets->process_by_arq), queue);
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

void on_btn_sjf_clicked(GtkButton *button, void *user_data) {
    Widgets_t *widgets = (Widgets_t *)user_data;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widgets->text_output));
    print_to_textview(GTK_TEXT_VIEW(widgets->text_output), "Política: Shortest Job First Preemptiva\n");
    ProcessQueue q = copy_ProcessQueue(&queue);
    if (q.count == 0) {
        print_to_textview(GTK_TEXT_VIEW(widgets->text_output), "A fila de processos está vazia.\n");
    } else {
        // Inicializa o buffer
        gtk_text_buffer_set_text(buffer, "", -1);
        // Simula o escalonamento SJF Preemptivo e preenche o buffer com os resultados
        sjf_preemptive(&q, buffer);
        populate_tree_view(GTK_TREE_VIEW(widgets->process_by_arq), &q);
        //debug_mostra_processos(q);
        //printf("Liberando memória de q\n");
        free_ProcessQueue(&q);
    }
}

void on_btn_rr_clicked(GtkButton *button, void *user_data) {
    Widgets_t *widgets = (Widgets_t *)user_data;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widgets->text_output));
    print_to_textview(GTK_TEXT_VIEW(widgets->text_output), "Política: Round-Robin\n");

    // Criar e exibir a caixa de diálogo para o usuário definir o quantum
    GtkWidget *dialog = create_quantum_dialog(GTK_WIDGET(widgets->window));
    gint result = gtk_dialog_run(GTK_DIALOG(dialog));

    // Processar a entrada do usuário se ele pressionou "OK"
    if (result == GTK_RESPONSE_OK) {
        const gchar *quantum_str = gtk_entry_get_text(GTK_ENTRY(quantum_entry));
        int quantum = atoi(quantum_str);

        // Se a conversão for bem-sucedida, continuar com o escalonamento Round Robin
        if (quantum > 0) {
            ProcessQueue q = copy_ProcessQueue(&queue);
            if (q.count == 0) {
                print_to_textview(GTK_TEXT_VIEW(widgets->text_output), "A fila de processos está vazia.\n");
            } else {
                gtk_text_buffer_set_text(buffer, "", -1);
                round_ronin(&q, quantum, buffer);
                populate_tree_view(GTK_TREE_VIEW(widgets->process_by_arq), &q);
                free_ProcessQueue(&q);
            }
        } else {
            // Exibir mensagem de erro se o quantum não for um número válido
            print_to_textview(GTK_TEXT_VIEW(widgets->text_output), "Valor de quantum inválido. Por favor, insira um número positivo.\n");
        }
    }

    gtk_widget_destroy(dialog); // Fechar a caixa de diálogo
}

void on_btn_priority_clicked(GtkButton *button, void *user_data) {
    Widgets_t *widgets = (Widgets_t *)user_data;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widgets->text_output));
    print_to_textview(GTK_TEXT_VIEW(widgets->text_output), "Política: Prioridade Estática\n");
    ProcessQueue q = copy_ProcessQueue(&queue);
    if (q.count == 0) {
        print_to_textview(GTK_TEXT_VIEW(widgets->text_output), "A fila de processos está vazia.\n");
    } else {
        // Inicializa o buffer
        gtk_text_buffer_set_text(buffer, "", -1);
        // Simula o escalonamento de Prioridade Estática e preenche o buffer com os resultados
        priority_preemptive(&q, buffer);
        populate_tree_view(GTK_TREE_VIEW(widgets->process_by_arq), &q);
        //debug_mostra_processos(q);
        //printf("Liberando memória de q\n");
        free_ProcessQueue(&q);
    }
}

void on_window_destroy(void) {
    gtk_main_quit();
}

GtkWidget *create_quantum_dialog(GtkWidget *parent) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Definir Quantum",
                                                    GTK_WINDOW(parent),
                                                    GTK_DIALOG_MODAL,
                                                    "OK",
                                                    GTK_RESPONSE_OK,
                                                    "Cancelar",
                                                    GTK_RESPONSE_CANCEL,
                                                    NULL);

    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Adicione um GtkEntry à caixa de conteúdo para permitir que o usuário insira o valor do quantum
    quantum_entry = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), quantum_entry);
    gtk_widget_show_all(dialog);

    return dialog;
}
