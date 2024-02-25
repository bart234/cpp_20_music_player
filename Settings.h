#ifndef SETTINGS_
#define SETTINGS_
#include <iostream>
#include <stack>
#include <memory>
#include <map>
#include <list>
#include <stdlib.h>
#include <string>
#include <vector>
#include "GeneralFunctions.h"

namespace Settings_1
{
    std::string user_log_pass_list_path = "my_path_to_user_string";
}

namespace Playlists_sttg
{
    //use in pls_i
    //std::string playlist_folder = "pls/"; to remove
    //std::string availible_tracks = "track_list.lib";
    //std::string playlists_main_path = "pls_details/"; to remove
    std::string playlists_main_user_pls_list_file = "pls.lib";   
}

namespace Setting
{

    namespace SettingFromFile
    {
        size_t VariableNumberAtSettings =4;
        std::string setting_volume = "volume";
        std::string setting_order_on_pls_list = "order_on_pls_list";
        std::string setting_order_at_pls_by = "order_at_pls_by";
        std::string setting_behavior_after_last_song = "behavior_after_last_song";
        std::string played_song = "played_song";
        std::string played_playlist = "played_playlist";
        std::string something_to_crash = "crash me";
        //order at cfg file 
        std::vector<std::string>header_user_settings {
            setting_volume,
            setting_order_on_pls_list,
            setting_order_at_pls_by,
            setting_behavior_after_last_song
            };
        std::vector<std::string> headers_user_last_played{
            played_song,
            played_playlist,
            something_to_crash
        };  
    }

    namespace SettingPlaylistFile
    {
        int column_number_with_pls_name =1;
        size_t number_of_columns_in_track_lib_file =4;
        char delimiter_used_in_all_file =',';
        std::string deafult_ ="deafult";
        std::string dash_dash_ ="--";
        std::string playlist_name_chars_acceptable ="ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz_0123456789";       
        std::string playlist_name_chars_acceptable_descr =" big and small letters, spaces, numbers, and floor '_'";       

    }


    namespace DefaultFolderPaths
    {
        std::string main_app_folder = "pls/";
        std::string pls_details_folder = "pls_details/";
    }
    namespace DefaultFilesNames
    {
        std::string user_login_pwd = "user.app";        //doone
        std::string user_setting_file = "setting.cfg";  //todo
        std::string user_pls_lists = "pls_list.lst";    //todo
        std::string user_detailed_plsts = "pls_details.lst";    //todo
        std::string availible_tracks = "track_list.lib";        //done
    }

    namespace Utility
    {
        std::string default_additional_slash = "/";
    }
}

#endif