#include <iostream>
#include <stdlib.h>
#ifdef linux
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <X11/Xlib.h>
#endif
#include "gtk/gtk.h"
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <unistd.h>
#include <cairo.h>

using namespace std;


GtkWidget *window, *darea, *histograma, *winred, *winblue, *wingreen;
GtkWidget *contenedor, *image, *imared, *imablue, *imagreen;
GtkWidget *vbox, *valign, *hbox, *halign, *box;
GdkPixbuf *pixbuf,*icono, *pixred, *pixblue, *pixgreen;
GtkListStore *liststore;
GtkFileFilter *filter;
//g++ main.cpp -o salida `pkg-config --cflags --libs gtk+-3.0 `  -export-dynamic -lX11
//MSYS2:  g++ main.cpp -o salida `pkg-config --cflags --libs gtk+-3.0 ` -lm -lpthread -lgdi32

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ASISTENCIA");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    //gtk_window_set_default_size(GTK_WINDOW(window), 700, 550);
    //char *file = ;
    //icono = gdk_pixbuf_new_from_file_at_scale("./src/icono.png", 80, 80, TRUE, NULL);

    //gtk_image_set_from_file(GTK_IMAGE(image),file);
    //gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
    //gtk_window_set_icon(GTK_WINDOW(window), icono);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 480);
    //gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
    //gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    /*
    vbox = gtk_vbox_new(FALSE, 5);

    hbox = gtk_hbox_new(TRUE, 3);

    contenedor = gtk_grid_new();


    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request (darea, 350, 450);
    //gtk_box_pack_end(GTK_BOX(vbox), darea, FALSE, FALSE, 0);

    //gtk_box_pack_end(GTK_BOX(vbox), expression_label, FALSE, FALSE, 0);
    gtk_grid_attach (GTK_GRID(contenedor), image, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID(contenedor), darea, 1, 0, 1, 1);
    gtk_grid_set_row_homogeneous(GTK_GRID(contenedor),true);
    gtk_grid_set_column_homogeneous(GTK_GRID(contenedor),true);
    gtk_box_pack_start(GTK_BOX(vbox), contenedor, FALSE, FALSE, 0);

    GdkRGBA color = {.75, .75, .75, 1.0};
    
    gtk_widget_override_background_color(GTK_WIDGET(vbox), GTK_STATE_FLAG_NORMAL, &color );
    gtk_container_add(GTK_CONTAINER(window), vbox);
    */
    //int load_handler_id = g_signal_connect(G_OBJECT(load_button), "clicked", G_CALLBACK(load_file), NULL);

    //g_signal_connect(G_OBJECT(run_button), "clicked", G_CALLBACK(get_expression), NULL);
    /*
    enum {
        TARGET_STRING,
        TARGET_URL
    };

    static GtkTargetEntry targetentries[] =
            {
                    {"STRING",        0, TARGET_STRING},
                    {"text/plain",    0, TARGET_STRING},
                    {"text/uri-list", 0, TARGET_URL},
            };
    */
    //gtk_drag_dest_set(window, GTK_DEST_DEFAULT_ALL, targetentries, 3, GDK_ACTION_COPY);
    //g_signal_connect(window, "drag_data_received", G_CALLBACK(on_drop), liststore);
    //g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}