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
#include <ctime>
#include <thread>

using namespace std;


GtkBuilder *builder; 
GtkWidget *window;
GtkWidget *button0,*button1,*button2,*button3,*button4,*button5,*button6,*button7,*button8,*button9,*buttonBack,*buttonGo;
GtkWidget *labelTime,*labelDate,*labelOption;
GdkPixbuf *pixbuf,*icono, *pixred, *pixblue, *pixgreen;
GtkListStore *liststore;
GtkFileFilter *filter;
//g++ main.cpp -o salida `pkg-config --cflags --libs gtk+-3.0 `  -export-dynamic -lX11
//MSYS2:  g++ main.cpp -o salida `pkg-config --cflags --libs gtk+-3.0 ` -lm -lpthread -lgdi32

void on_window_main_destroy()
{
    gtk_main_quit();
}

void ingresar_numero(GtkWidget *widget, gpointer data)
{   
    char* actual = (char*)gtk_label_get_text ((GtkLabel *)labelOption);
    if(strlen(actual)<4){
        char* val = (char*)gtk_button_get_label ((GtkButton *)widget);
        strcat(actual, val);
        gtk_label_set_text((GtkLabel *)labelOption,actual);
    }
    /*else{
        actual[0]=actual[1];
        actual[1]=actual[2];
        actual[2]=actual[3];
        actual[3]='\0';
        char* val = (char*)gtk_button_get_label ((GtkButton *)widget);
        strcat(actual, val);
        gtk_label_set_text((GtkLabel *)labelOption,actual);
    }*/
}

void borrar_numero(GtkWidget *widget, gpointer data)
{   
    char* actual = (char*)gtk_label_get_text ((GtkLabel *)labelOption);
    if(strlen(actual)>0){
        char* val = (char*)gtk_button_get_label ((GtkButton *)widget);
        actual[strlen(actual)-1]='\0';
        gtk_label_set_text((GtkLabel *)labelOption,actual);
    }
}

void update()
{   
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::stringstream sfecha, shora;
    sfecha << std::to_string(ltm->tm_mday) << "/" << std::to_string(1 + ltm->tm_mon) << "/" << std::to_string(1900 +  ltm->tm_year);
    shora <<  std::to_string(ltm->tm_hour) << " : " << std::to_string(ltm->tm_min) << " : " << std::to_string(ltm->tm_sec);
    std::string fecha = sfecha.str();
    std::string hora = shora.str();
    gtk_label_set_text((GtkLabel *)labelDate,fecha.c_str());
    gtk_label_set_text((GtkLabel *)labelTime,hora.c_str());
}

int main(int argc, char* argv[])
{
    /*gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ASISTENCIA");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    */

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "main.glade", NULL);
    
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    labelOption = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    labelTime = GTK_WIDGET(gtk_builder_get_object(builder, "labelTime"));
    gtk_label_set_max_width_chars((GtkLabel *)labelTime,1);
    gtk_label_set_justify((GtkLabel *)labelTime,  GTK_JUSTIFY_FILL);

    labelDate = GTK_WIDGET(gtk_builder_get_object(builder, "labelDate"));
    gtk_widget_modify_font (labelTime,  pango_font_description_from_string ("Monospace Bold 42"));
    

    gtk_widget_modify_font (labelOption,  pango_font_description_from_string ("Verdana Bold 42"));
    button0 = GTK_WIDGET(gtk_builder_get_object(builder, "button0"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
    button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
    button4 = GTK_WIDGET(gtk_builder_get_object(builder, "button4"));
    button5 = GTK_WIDGET(gtk_builder_get_object(builder, "button5"));
    button6 = GTK_WIDGET(gtk_builder_get_object(builder, "button6"));
    button7 = GTK_WIDGET(gtk_builder_get_object(builder, "button7"));
    button8 = GTK_WIDGET(gtk_builder_get_object(builder, "button8"));
    button9 = GTK_WIDGET(gtk_builder_get_object(builder, "button9"));

    buttonBack = GTK_WIDGET(gtk_builder_get_object(builder, "buttonBack"));
    GtkImage *iconBack, *iconGo;
    iconBack = (GtkImage *)gtk_image_new_from_file("image/cancel.png"); 
    gtk_button_set_image (GTK_BUTTON(buttonBack),(GtkWidget *)iconBack); 
    buttonGo = GTK_WIDGET(gtk_builder_get_object(builder, "buttonGo"));
    iconGo = (GtkImage *)gtk_image_new_from_file("image/check.png"); 
    gtk_button_set_image (GTK_BUTTON(buttonGo),(GtkWidget *)iconGo); 

    g_signal_connect(G_OBJECT(button0), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button5), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button6), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button7), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button8), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(button9), "clicked", G_CALLBACK(ingresar_numero), window);
    g_signal_connect(G_OBJECT(buttonBack), "clicked", G_CALLBACK(borrar_numero), window);
    //gtk_builder_connect_signals(builder, window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(on_window_main_destroy), NULL);

    g_object_unref(builder);

    //gtk_window_set_default_size(GTK_WINDOW(window), 700, 550);
    //char *file = ;
    //icono = gdk_pixbuf_new_from_file_at_scale("./src/icono.png", 80, 80, TRUE, NULL);

    //gtk_image_set_from_file(GTK_IMAGE(image),file);
    //gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
    //gtk_window_set_icon(GTK_WINDOW(window), icono);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 480);
    //GdkRGBA color = {.10, .10, .10, 1.0};
    
    //gtk_widget_override_background_color(GTK_WIDGET(window), GTK_STATE_FLAG_NORMAL, &color );
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
    g_timeout_add(200,(GSourceFunc)update, NULL);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}