#pragma once
#include "OptionTemplate.h"
#include "Lvl_1_Menu_UserLogin.h"
#include "MP_auth.h"



class Option_1_About:public Option_MainMenu_Template
    {   
        public:
            Option_1_About(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                    Option_MainMenu_Template(i_description,i_option_number,i_user)
                    {};
            ~Option_1_About(){};
        public:
            virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                    {
                        //expected action - preapare menu behind option 1
                        std::cin.get();
                        std::cout<<"This is a basic app for  Music Player \n"<<std::endl;
                        std::cout<<"Please press any key to back to previous menu"<<std::endl;
                        
                        //std::shared_ptr<MenuTemplate> main_menu2 {new Menu_at_mm_opt1{}}; //include that menu as file
                        //i_stack_of_menus.push(main_menu2);   

                    }
    };
    
class Option_2_LogIn:public Option_MainMenu_Template
{   
    private:
        std::string i_user_login_pass_path{};

    public:
        Option_2_LogIn(std::string i_description, int i_option_number,std::shared_ptr<User> i_user,std::string user_login_pass_path):
                Option_MainMenu_Template(i_description,i_option_number,i_user),i_user_login_pass_path{user_login_pass_path}
                {};
        ~Option_2_LogIn(){};
    public:
        void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
            {
                std::string cred[2]={"",""};
                std::cout<<"Login:"<<std::endl;
                std::cin>>cred[0];
                std::cout<<"Password:"<<std::endl;
                std::cin>>cred[1];

                std::cout<<"Login: "<<cred[0]<<" Password: "<<cred[1]<<std::endl;

                if(true)
                {
                    Authorization auth(i_user_login_pass_path);
                    if (auth.check_auth(cred[0],cred[1]))
                    {
                        std::cout<<"Access granted"<<std::endl;
                        std::shared_ptr<User> a {new User()};
                        user_b = std::move(a);
                        user_b->LogIn(cred[0]);     
                        
                        std::shared_ptr<MenuTemplate> user_logged_in_menu {new Menu_user_logged_in{user_b}}; //include that menu as file
                        i_stack_of_menus.push(user_logged_in_menu); 
                    }
                    else
                    {
                        std::cout<<"Login or password are incorret"<<std::endl;
                    };                    
                }
                else
                {
                std::cout<<"Login or password are wrong. Please try again."<<std::endl;
                }
            }
};
    
class Option_3_NewUser:public Option_MainMenu_Template
{   
    public:
        Option_3_NewUser(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Option_3_NewUser(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                {std::cout<<"Custom action at option nr 3 menu 0"<<std::endl;}
};
