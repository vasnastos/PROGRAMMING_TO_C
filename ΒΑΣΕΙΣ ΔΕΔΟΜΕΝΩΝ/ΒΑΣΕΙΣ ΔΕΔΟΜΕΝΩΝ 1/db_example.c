#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

void show_records()
{
    sqlite3 *db=NULL;//Δείκτης που θα χειρίζεται βάση
    sqlite3_stmt *q=NULL;//Χειριστής ερωτημάτων βάσης
    char *sql;//Δείκτης που θα αποθηκεύει το query που θα τρέχει στην βάση.
    int res=sqlite3_open("clothes.db",&db);//Άνοιγμα βάσης δεδομένων με όνομα clothes.db
    //Επιστρέφει έναν ακέραιο αυτή η συνάρτηση
    if(res!=SQLITE_OK)//Αν η συνάρτηση δεν επίστρεψει την τιμή 0 που αντιστοιχεί στην σταθερά SQLITE_OK
    {
        printf("%s\n",sqlite3_errmsg(db));//καλείται η συνάρτηση που επιστρέφει το μήνυμα λάθους του query.
        free(sql);
        sqlite3_close(db);//κλείνω την βάση μου
        return;//σταματάω την εκτέλεση της void συνάρτησης.
    }
    sql=(char *)malloc(200 * sizeof(char));
    strcpy(sql,"select * from Shop;");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);//Προετιμασία ερωτήματος sql προς την βάση
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));//καλείται η συνάρτηση που επιστρέφει το μήνυμα λάθους του query.
        free(sql);//Αποδέσμευση της μνήμης που δέσμευσε ο δείκτες σε χαρακτήρες sql.
        sqlite3_close(db);//Κλείσιμο βάσης.
        return;
    }
    while(sqlite3_step(q)==SQLITE_ROW)//sqlite3_step(q)-->κάνει fetch την επόμενη εγγραφή που επιστρέφει το query.
    {
        int id=sqlite3_column_int(q,0);
        char colr[200];
        strcpy(colr,(char *)sqlite3_column_text(q,1));//convert το δεύτερο value σε string.
        char size[200];
        strcpy(size,(char *)sqlite3_column_text(q,2));
        double pr=sqlite3_column_double(q,3);
        char desc[200];
        strcpy(desc,(char *)sqlite3_column_text(q,4));
        printf("%d--%s--%s--%.2lf--%s\n",id,colr,size,pr,desc);
    }
    free(sql);
    sqlite3_close(db);
}

int main()
{
    show_records();
}