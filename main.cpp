#define CROW_MAIN
#include "crow_all.h"

#include<iostream>

using namespace std;

int main()
{
    cout << "ReST Framework Example Using Crow" << endl;

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    app.port(18080).run();
}