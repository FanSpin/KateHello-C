#include <gtk/gtk.h>
#include <time.h>

static void activate(GtkApplication *app, gpointer user_data);
//here is the change
static gboolean on_tick(gpointer user_data) {
    GtkWidget *label = user_data;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char buf[16];
    strftime(buf, sizeof buf, "%H:%M:%S", t);
    gtk_label_set_text(GTK_LABEL(label), buf);
    return G_SOURCE_CONTINUE;  /* keep firing every second */
}
//end of the change
int main(void) {
    GtkApplication *app = gtk_application_new("org.example.clock",
                                              G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), 0, NULL);
    g_object_unref(app);
    return status;
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *win = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(win), "Clock");
    gtk_window_set_default_size(GTK_WINDOW(win), 200, 80);

    GtkWidget *label = gtk_label_new("00:00:00");
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_window_set_child(GTK_WINDOW(win), label);

    g_timeout_add_seconds(1, on_tick, label);
    gtk_window_present(GTK_WINDOW(win));
}
