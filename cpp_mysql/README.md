You need to have local MySQL database "pierwsza" (password: "password") with table named "dane"




To compile on Linux system use:
g++ -o tak $(mysql_config --cflags) pierwsze_polaczenie.cpp $(mysql_config --libs)

You can also simply run my already compiled version by:
  ./tak
