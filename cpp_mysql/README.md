You need to have local MySQL database "pierwsza" with table named "dane"




To compile in Linux use:
g++ -o tak $(mysql_config --cflags) pierwsze_polaczenie.cpp $(mysql_config --libs)

