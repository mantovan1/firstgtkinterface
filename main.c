#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

GObject *nota1Entry, *nota2Entry, *nota3Entry, *nota4Entry;
GObject *labelresultado;

static void calcularMedia (GtkButton *btn, gpointer data) {

	float notas[4];
  
	notas[0] = atof(gtk_entry_get_text(GTK_ENTRY(nota1Entry)));
	notas[1] = atof(gtk_entry_get_text(GTK_ENTRY(nota2Entry)));
 	notas[2] = atof(gtk_entry_get_text(GTK_ENTRY(nota3Entry)));
	notas[3] = atof(gtk_entry_get_text(GTK_ENTRY(nota4Entry)));

  	char result_text[10];

  	float r = (notas[0] + notas[1] + notas[2] + notas[3]) / 4;

  	gcvt (r, 10, result_text);

  	gtk_label_set_label ( GTK_LABEL ( labelresultado ), result_text );

  	//g_print ("%.2f", r);
  	//
}

int main (int   argc, char *argv[]) {
	GtkBuilder *builder;
  	GObject *window;
  	GObject *label;
  	GError *error = NULL;

  	//GObject *nota1Entry, *nota2Entry, *nota3Entry, *nota4Entry;
  	GObject *button;

  	gtk_init (&argc, &argv);

  	/* Construct a GtkBuilder instance and load our UI description */
  	builder = gtk_builder_new ();
  	if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0) {
        	g_printerr ("Error loading file: %s\n", error->message);
      		g_clear_error (&error);
      		return 1;
    	}

  	/* Connect signal handlers to the constructed widgets. */
  	window = gtk_builder_get_object (builder, "window");
  	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  	nota1Entry = gtk_builder_get_object (builder, "input_nota1");
  	nota2Entry = gtk_builder_get_object (builder, "input_nota2");
  	nota3Entry = gtk_builder_get_object (builder, "input_nota3");
  	nota4Entry = gtk_builder_get_object (builder, "input_nota4");

  	label = gtk_builder_get_object (builder, "label1");
  	label = gtk_builder_get_object (builder, "label2");
  	label = gtk_builder_get_object (builder, "label3");
  	label = gtk_builder_get_object (builder, "label4");

  	labelresultado = gtk_builder_get_object (builder, "labelresultado");

  	button = gtk_builder_get_object (builder, "calcular");
  	g_signal_connect (button, "clicked", G_CALLBACK(calcularMedia), NULL);

  	gtk_main ();

  	return 0;
}

