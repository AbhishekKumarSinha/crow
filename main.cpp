#define CROW_MAIN
#include "inc/crow_all.h"
#include "inc/system.h"

#include<iostream>
#include<string>

using namespace std;

int main()
{
    cout << "ReST Framework Example Using Crow" << endl;

    crow::SimpleApp app;

    System::get_instance(); //lazy-initialization

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

        if(System::get_instance()->check_username_availability(username))
        {
            return crow::response(400);   
        }


        System::get_instance()->signup(username, password);
        
        string reponse_json = "Hello " + username + ", your password is :: " + password;
        return crow::response(reponse_json);//"Hello " + ", your password is :: " ;
    });


    CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST)
    ([](const crow::request& req){

        auto recvd_json = crow::json::load(req.body);
        if (!recvd_json)
            return crow::response(400);

        //username
        const string username =  recvd_json["username"].s();
        //password
        const string password = recvd_json["password"].s();

        if(System::get_instance()->check_login_credentials(username,password))
        {
            System::get_instance()->set_login_status(username,true);

            return crow::response(200);
        }
        else
            return crow::response(400); 

    });



    app.port(18080).multithreaded().run();
}