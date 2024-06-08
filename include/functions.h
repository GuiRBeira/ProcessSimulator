#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "widgets.h"

void wait_response_time(ProcessQueue *queue, int i);
void sjf_preemptive(ProcessQueue *queue, GtkTextBuffer *buffer);
void print_to_textview(GtkTextView *text_view, const char *message);
void priority_preemptive(ProcessQueue *queue, GtkTextBuffer *buffer);
void round_ronin(ProcessQueue *queue, int quantum, GtkTextBuffer *buffer);

#endif //FUNCTIONS_H