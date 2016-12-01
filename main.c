#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{





    GtkWidget *pWindow;
    GtkWidget *pVBox;
    GtkWidget *pFrame;
    GtkWidget *pVBoxFrame;
    GtkWidget *pSeparator;
    GtkWidget *pEntry;
    GtkWidget *pLabel;
    gchar *sUtf8;
     GtkWidget *image1 = NULL;
      GtkWidget *hbox = NULL,*email=NULL,*password=NULL,*vbox = NULL;
      GtkWidget *imagebox = NULL;
     GtkWidget *connecter = NULL ;

      GtkWidget *inscrire = NULL ;
         GtkWidget *ButtonBox = NULL ;

       GtkWidget *usernamebox = NULL ;
       GtkWidget *passwordbox = NULL ;
       GtkWidget *table = NULL;
        GtkWidget *entry_pwd = NULL;
         GtkWidget *entry_login= NULL;
         GtkWidget *GirdTable= NULL;



    gtk_init(&argc, &argv);



/* ***********NOTRE FÉNTRE********************** */
    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /* On ajoute un espace de 5 sur les bords de la fenetre */
    gtk_container_set_border_width(GTK_CONTAINER(pWindow), 5);
    gtk_window_set_title(GTK_WINDOW(pWindow), "E-library");
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 320, 200);
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);


/* préparer nos labels inputs Email , login ******  */
     email = gtk_label_new("Votre login : ");
      entry_login =  gtk_entry_new();
     //gtk_entry_set_placeholder_text (entry_login,"");

   //Mot de passe
    password = gtk_label_new("Mot de Passe : ");
    entry_pwd =  gtk_entry_new ();
    gtk_entry_set_visibility (entry_pwd,FALSE);
    gtk_entry_set_invisible_char(entry_pwd,'*');


//**************************************
vbox = gtk_vbox_new (FALSE, 6);
hbox = gtk_hbox_new (TRUE, 6);




 //********* systéme de grille pour login et mot de passe ****************//

    gtk_box_pack_start (GTK_BOX (usernamebox), email, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (usernamebox), entry_login, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (passwordbox), password, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (passwordbox), entry_pwd, TRUE, TRUE, 0);


/* _________________TABLE GRID______________________ */
table=gtk_table_new(3,2,TRUE);
gtk_table_attach(GTK_TABLE(table), usernamebox, 0, 2, 1, 30,  GTK_FILL ,GTK_SHRINK, 0, 0);
gtk_table_attach(GTK_TABLE(table), passwordbox, 0, 2, 2, 60,  GTK_FILL ,GTK_SHRINK, 0, 0);
gtk_box_pack_end (GTK_BOX (vbox), hbox, TRUE, FALSE, 0);
gtk_widget_grab_focus(entry_login);




//image d'introduction*************//
 image1 = gtk_image_new_from_file("images/login_image.png");

//**************Faire appel au systéme de grille vbox ****************//
 /*imagebox = gtk_vbox_new (FALSE, 6);
gtk_box_pack_start (GTK_BOX (imagebox),  image1, TRUE, TRUE, 1);*/





//********************ajouter le button se connecter ***********************//
 ButtonBox = gtk_hbox_new(TRUE, 0);
connecter = gtk_button_new_with_label ("Connecter");
inscrire = gtk_button_new_with_label ("Vous n'avez pas déja un compte ?");
//g_signal_connect (connecter , "clicked",G_CALLBACK (clicked_btn_authentification),  pWindow);
/*gtk_box_pack_start(GTK_BOX(ButtonBox), connecter, TRUE, FALSE, 0);
gtk_container_add(GTK_CONTAINER(pWindow), ButtonBox);*/



/* Creation et insertion de la table 3 lignes 2 colonnes */
    GirdTable=gtk_table_new(5,2,TRUE);


//Ajouter l'image
gtk_table_attach(GTK_TABLE(GirdTable),  image1,
        0, 2, 0, 1,
        GTK_EXPAND | GTK_FILL, GTK_EXPAND,
        0, 0);






    //*****************************//
     gtk_table_attach_defaults(GTK_TABLE(GirdTable),  email,
        0, 1, 1, 2);
    gtk_table_attach(GTK_TABLE(GirdTable),entry_login,
        1, 2, 1, 2,
        GTK_EXPAND, GTK_EXPAND | GTK_FILL,
        0, 0);

         //*****************************//


     gtk_table_attach_defaults(GTK_TABLE(GirdTable), password,
        0, 1, 2, 3);
    gtk_table_attach(GTK_TABLE(GirdTable),entry_pwd,
        1, 3, 1, 3,
        GTK_EXPAND, GTK_EXPAND | GTK_FILL,
        0, 0);






//Ajouter le buttn se connecter
gtk_table_attach(GTK_TABLE(GirdTable),  connecter,
        0, 2, 2, 3,
        GTK_EXPAND | GTK_FILL, GTK_EXPAND,
        0, 0);















//*********************l'ajout du gtkBox dans la féntre princiale ****************//
 /* Ajout de la GtkVBox dans la fenetre */
    //gtk_container_add(GTK_CONTAINER(pWindow), imagebox);
     gtk_container_add(GTK_CONTAINER(pWindow), GTK_WIDGET(GirdTable));





    gtk_widget_show_all(pWindow);

    gtk_main();

    return EXIT_SUCCESS;
}
