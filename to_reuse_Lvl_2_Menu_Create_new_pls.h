#pragma once
#include "MenuTemplate.h"
#include "Lvl_2_Options_Create_new_pls.h"


//add pre-declaration  of that menu at OptionTemplate.h
 
class Menu_Create_new_pls:public MenuTemplate
{
    public:
        std::string menu_title = "Second Menu";
        std::string menu_welcome_screen = "Second Menu";
        Menu_Create_new_pls(std::shared_ptr<User> i_user):MenuTemplate(menu_title,menu_welcome_screen,i_user)
                        {
                            std::cout<<"\nPlaylist creator "<<std::endl;
                            this->prepare_menu();
                        }
        ~Menu_Create_new_pls(){};
    private:
        void prepare_menu()
            {                    
                
                std::unique_ptr<OptionTemplate> ptr_1 {new  Opt_1_set_new_playlist {"Opt_1_set_new_playlist", 1,user_b}};
                std::unique_ptr<OptionTemplate> ptr_2 {new  Opt_2_edit_existing_playlis {"Opt_2_edit_existing_playlis", 2,user_b}};
                std::unique_ptr<OptionTemplate> ptr_3 {new  Opt_3_show_availible_tracks {"Opt_3_show_availible_tracks", 3,user_b}};
                
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
// data moved because double import 