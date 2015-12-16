#include <QCoreApplication>
#include <qstring.h>
#include <iostream>
#include <string.h>

int hash(std::string h){

   int val;
   int letra;
   for(int i=0;i<h.size();i++){
       letra=h[i];
        val=val+letra;
   }
    val= val/h[0];

    std::cout<<val<<std::endl;
    return val;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string l;
    std::cin>>l;
    hash(l);

    return a.exec();
}

