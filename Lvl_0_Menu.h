#pragma once
#include "MenuTemplate.h"
#include "Lvl_0_Options.h"
#include "Settings.h"

class Menu_MainMenu:public MenuTemplate
{
    public:
        Menu_MainMenu(std::shared_ptr<User> i_user):
                        MenuTemplate("Main Menu","Welcome in Play Me",i_user,true)
                        {
                            //this->user=i_user;
                            this->prepare_menu();
                        }
        ~Menu_MainMenu(){};
    private:
        void prepare_menu()
            {              
                this->setAsMainMenu();
                //create option to that menu - already as unique ptr
                std::unique_ptr<OptionTemplate> ptr_1 {new  Option_1_About {"What is Play Me", 1,user_b}}; //text, number on the list
                std::unique_ptr<OptionTemplate> ptr_2 {new  Option_2_LogIn {"Log in", 2,user_b,Settings_1::user_log_pass_list_path}};
                std::unique_ptr<OptionTemplate> ptr_3 {new  Option_3_NewUser {"Im new user", 3,user_b}};
                
                //add unique ptr as a option to menu
                this->option_list[1]=std::move(ptr_1);
                this->option_list[2]=std::move(ptr_2);
                this->option_list[3]=std::move(ptr_3);

                //add back option
                if(!this->isItMainMenu())
                {
                    this->option_list[9]=this->prepare_back_option("Previous menu");
                }
                //add quit_app option
                this->option_list[0]=this->prepare_exit_option();                    
            }
    
};
   
