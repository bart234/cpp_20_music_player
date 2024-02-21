#pragma once
#include "MenuTemplate.h"
#include "Lvl_1_Options_UserLogin.h"


//add pre-declaration  of that menu at OptionTemplate.h
 
class Menu_user_logged_in:public MenuTemplate
{
    public:
        std::string menu_title = "Second Menu";
        std::string menu_welcome_screen = "Second Menu";
        Menu_user_logged_in(std::shared_ptr<User> i_user):MenuTemplate(menu_title,menu_welcome_screen,i_user)
                        {
                            //loading data from user file and display last used song/playlist
                            std::cout<<"\nWelcome "<<i_user->getUserName()<<std::endl;
                            if(i_user->getUserLastPlayedSong()!= "None")
                                std::cout<<"Last song played: "<<i_user->getUserLastPlayedSong()<<std::endl;
                            if(i_user->getUserLastPlayedPls()!= "None")
                                std::cout<<"Last playlist listened to: "<<i_user->getUserLastPlayedPls()<<std::endl;
                            this->prepare_menu();
                        }
        ~Menu_user_logged_in(){};
    private:
        void prepare_menu()
            {                    
                
                std::unique_ptr<OptionTemplate> ptr_1 {new  Opt_play_last_song {"Opt_1_play_last_song", 1,user_b}};
                std::unique_ptr<OptionTemplate> ptr_2 {new  Opt_play_last_pls {"Opt_2_play_last_pls", 2,user_b}};
                std::unique_ptr<OptionTemplate> ptr_3 {new  Opt_open_user_playlists {"Opt_3_playlists (done)", 3,user_b}};
                std::unique_ptr<OptionTemplate> ptr_4 {new  Opt_create_playlist {"Opt_4_create_playlist(in progress)", 4,user_b}}; //in progress
                std::unique_ptr<OptionTemplate> ptr_5 {new  Opt_edit_playlist {"Opt_5_edit_playlist", 5,user_b}}; 
                std::unique_ptr<OptionTemplate> ptr_6 {new  Opt_log_out {"Opt_6_log_out", 6,user_b}};
                
                //add unique ptr as a option to menu
                this->option_list[1]=std::move(ptr_1);
                this->option_list[2]=std::move(ptr_2);
                this->option_list[3]=std::move(ptr_3);
                this->option_list[4]=std::move(ptr_4);
                this->option_list[5]=std::move(ptr_5);
                this->option_list[6]=std::move(ptr_6);

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