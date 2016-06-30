#include <iostream>
#include <mysql/mysql.h>
using namespace std;
int main() {

  MYSQL mysql;
  mysql_init(&mysql);
  if (mysql_real_connect(&mysql, "127.0.0.1", "root", "password", "pierwsza", 0,
                         NULL, 0))
    cout << "Nawiazano polaczenie - Connected! :)" << endl;
  else
    cout << "Niestety nie nawiazano polaczenia - I can't connect :(" << endl;

  MYSQL_RES *idZapytania;
  MYSQL_ROW wiersz;

  mysql_select_db(&mysql, "pierwsza");
  mysql_query(&mysql, "SELECT * FROM dane");
  idZapytania = mysql_store_result(&mysql);

  while ((wiersz = mysql_fetch_row(idZapytania)) != NULL) {
    for (int i = 0; i < mysql_num_fields(idZapytania); i++)
      cout << wiersz[i] << " ";

    cout << endl;
  }

  mysql_close(&mysql);
}
