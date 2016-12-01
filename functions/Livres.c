#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

//*****une fonction pour afficher les livres***********//
void afficher_livres()
{


}


//*****une fonction pour Modife un livre les livres***********//
void Modifier_livres()
{


}

//*****une fonction pour Modife un livre les livres***********//
void Ajouter_livres()
{


}

//*****une fonction pour Modife un livre les livres***********//
void Supprimer_livres()
{


}



//*****une fonction pour Modife un livre les livres***********//
void Rechercher_livre_ISBN()
{


}



//*****une fonction pour Modife un livre les livres***********//
void Rechercher_livre_Titre()
{


}



void Rechercher_livre_Auteur()
{


}

void Rechercher_livre_Regex()
{


}










int verifierLoginPwd(char * login , char * pwd){
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "hosni", "root",
          "GRH", 0, NULL, 0) == NULL)
    {
      finish_with_error(con);
    }

    char querry[100];
    sprintf(querry,"%s%s%s%s%s","SELECT * FROM Utilisateur WHERE login='",login,"' and passw='",pwd,"';");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }
    MYSQL_ROW row=mysql_fetch_row(result);
    int res=(row==NULL)?-1:0;

    if(res==0){
        if(strcmp(row[3],"admin")==0){
            res=1;
        }else if(strcmp(row[3],"employe")==0){
            res=2;
        }else if(strcmp(row[3],"responsable")==0){
            res=3;
        }
    }

    mysql_free_result(result);
    mysql_close(con);

    return res;

}
