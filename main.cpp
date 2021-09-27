#define CROW_MAIN
#include "inc/crow_all.h"

#include<iostream>
#include<string>

using namespace std;

int main()
{
    cout << "ReST Framework Example Using Crow" << endl;

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([](){
        return "Hello world";
    });

    CROW_ROUTE(app, "/signup").methods(crow::HTTPMethod::GET, crow::HTTPMethod::POST)
    ([](const crow::request& req){

        auto recvd_json = crow::json::load(req.body);
        if (!recvd_json)
            return crow::response(400);

        //username
        const string username =  recvd_json["username"].s();
        //password
        const string password = recvd_json["password"].s();

        
        string reponse_json = "Hello " + username + ", your password is :: " + password;
        return crow::response(reponse_json);//"Hello " + ", your password is :: " ;
    });

    app.port(18080).multithreaded().run();
}