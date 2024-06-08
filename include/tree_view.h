#ifndef TREE_VIEW_H
#define TREE_VIEW_H

#include "widgets.h"

void free_ProcessQueue(ProcessQueue *queue);
void debug_mostra_processos(ProcessQueue q);
void initialize_tree_view(GtkTreeView *tree_view);
void clear_tree_view_columns(GtkTreeView *tree_view);
ProcessQueue copy_ProcessQueue(ProcessQueue *original);
void populate_tree_view(GtkTreeView *tree_view, ProcessQueue *queue);
void clear_and_initialize_tree_view(GtkTreeView *tree_view, ProcessQueue queue);
#endif // TREE_VIEW_H