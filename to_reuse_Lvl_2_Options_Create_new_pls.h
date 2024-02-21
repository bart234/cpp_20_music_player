#pragma once
#include "OptionTemplate.h"


class Opt_1_set_new_playlist:public Option_MainMenu_Template
{   
    public:
        Opt_1_set_new_playlist(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_1_set_new_playlist(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_main_queue)override
                {std::cout<<"Opt_1_set_new_playlist"<<std::endl;}
};

class Opt_2_edit_existing_playlis:public Option_MainMenu_Template
{   
    public:
        Opt_2_edit_existing_playlis(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_2_edit_existing_playlis(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_main_queue)override
                {std::cout<<"Opt_2_edit_existing_playlis"<<std::endl;}
};

class Opt_3_show_availible_tracks:public Option_MainMenu_Template
{   
    public:
        Opt_3_show_availible_tracks(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                Option_MainMenu_Template(i_description,i_option_number,i_user)
                {};
        ~Opt_3_show_availible_tracks(){};
    public:
        virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_main_queue)override
                {
                    std::cout<<"Opt_3_show_availible_tracks"<<std::endl;
                    Playlist_I pls_all_tracks;
                    pls_all_tracks.PrintAvailibleTracks();
                }
};
