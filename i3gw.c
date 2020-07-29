#include <gtk/gtk.h>

#define WINDOW_TITLE "GhostWindow"

static void draw_handler(GtkWidget *widget, cairo_t *cr, gpointer userdata);

int main(int argc, char **argv) {
    GtkWidget *window;
    GdkScreen *screen;
    GdkVisual *visual;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    screen = gdk_screen_get_default();
    visual = gdk_screen_get_rgba_visual(screen);

    g_signal_connect(G_OBJECT(window), "draw", G_CALLBACK(draw_handler), NULL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_title(GTK_WINDOW(window), WINDOW_TITLE);
    gtk_widget_set_app_paintable(window, TRUE);

    if (visual != NULL && gdk_screen_is_composited(screen)) {
        gtk_widget_set_visual(window, visual);
    }

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

static void draw_handler(GtkWidget *widget, cairo_t *cr, gpointer userdata) {
    cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 0.0);
    cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint(cr);
}
