#include "widgets.h"

int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    Widgets_t *widgets = g_slice_new(Widgets_t);
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/window.glade", NULL);

    widgets->window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    widgets->btn_load_file = GTK_WIDGET(gtk_builder_get_object(builder, "btn_load_file"));
    widgets->btn_sjf = GTK_WIDGET(gtk_builder_get_object(builder, "btn_sjf"));
    widgets->btn_rr = GTK_WIDGET(gtk_builder_get_object(builder, "btn_rr"));
    widgets->btn_priority = GTK_WIDGET(gtk_builder_get_object(builder, "btn_priority"));
    widgets->process_by_arq = GTK_WIDGET(gtk_builder_get_object(builder, "process_by_arq"));
    widgets->text_output = GTK_WIDGET(gtk_builder_get_object(builder, "text_output"));
    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);
    gtk_widget_show(widgets->window);
    gtk_main();
    g_slice_free(Widgets_t, widgets);
    return EXIT_SUCCESS;

}