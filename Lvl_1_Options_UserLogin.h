#pragma once
#include "OptionTemplate.h"
//#include "Lvl_2_Menu_Create_new_pls.h"

class Opt_play_last_song:public Option_MainMenu_Template
{   
    public:
        Opt_play_last_song(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_play_last_song(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                {std::cout<<"Opt_1_play_last_song"<<std::endl;}
};

class Opt_play_last_pls:public Option_MainMenu_Template
{   
    public:
        Opt_play_last_pls(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_play_last_pls(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                {std::cout<<"Opt_2_play_last_pls"<<std::endl;}
};

class Opt_open_user_playlists:public Option_MainMenu_Template
{   
    public:
        Opt_open_user_playlists(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_open_user_playlists(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                {
                    std::cout<<"\n Bob's playlists:"<<std::endl;
                    auto viki_string = user_b->GetUserPlaylistsNameList();
                    for(auto el:viki_string)
                    {std::cout<<el<<std::endl;}
                }
};

class Opt_create_playlist:public Option_MainMenu_Template
{   
    public:
        Opt_create_playlist(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_create_playlist(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                {
                    std::cout<<"Opt_create_playlist"<<std::endl;
                    std::pair<int,std::string> result_of_creation {user_b->CreateNewPlaylist()};
                    
                    if(result_of_creation.first)
                    {
                        std::cout<<"\nPlaylist created\n";
                        std::cout<<result_of_creation.second<<std::endl;
                    }
                    else
                    {
                        std::cout<<"\nPlaylist creation failed\n";
                        std::cout<<result_of_creation.second<<std::endl;
                    }                   


                    //std::shared_ptr<MenuTemplate> user_create_new_pls {new Menu_Create_new_pls{user_b}}; //include that menu as file
                   //i_stack_of_menus.push(user_create_new_pls); 
                }
};
class Opt_edit_playlist:public Option_MainMenu_Template
{   
    public:
        Opt_edit_playlist(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_edit_playlist(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                {std::cout<<"Opt_5_edit_playlist"<<std::endl;}
};
class Opt_log_out:public Option_MainMenu_Template
{   
    public:
        Opt_log_out(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_log_out(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_main_queue)override
                {std::cout<<"Opt_6_log_out"<<std::endl;}
};
