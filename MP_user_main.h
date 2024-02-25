#ifndef USER_MAIN_H
#define USER_MAIN_H
#include "MP_user_base.h"

class User
{      
    public:
    User(){};
    ~User(){};

    User_base user{};
    
    std::list<std::string> user_playlists_list;
    std::vector<std::pair<int,std::string>> saved_pls;
    Playlist_I playlists_interface{};   
    bool is_logged = false;

    
    
    private:
    bool LoadUserSettings();
    bool LoadUserPlaylistsList();

    public:
    bool LogIn(std::string username);
    std::vector<std::string> GetUserPlaylistsNameList();        //done

    bool CreateUser(std::string username, std::string pwd);    
    bool ChangeUserPassword(std::string old_pwd, std::string new_pwd);   
    

    public:
    
    std::pair<int,std::string> CreateNewPlaylist();             //done

    std::string getUserName(){return user.name;};
    std::string getUserLastPlayedSong(){return user.user_last_played_objects.find(Setting::SettingFromFile::played_song)->second;};
    std::string getUserLastPlayedPls(){return user.user_last_played_objects.find(Setting::SettingFromFile::played_playlist)->second;};
    int GetSettingVolume();             //todo
    int GetSettingOrderOnPlsList();            //todo
    std::string GetSettingOrderAtPlsBy();            //todo
    std::string GerSettingBehaviorAfterLastSong();            //todo
};

std::vector<std::string> User::GetUserPlaylistsNameList()
    {
        return playlists_interface.GetUserPlaylistsNameList(Setting::DefaultFolderPaths::main_app_folder+
                                                                Setting::DefaultFolderPaths::pls_details_folder+
                                                                this->getUserName()+ Setting::Utility::default_additional_slash+
                                                                Setting::DefaultFilesNames::user_pls_lists);
    }

std::pair<int,std::string> User::CreateNewPlaylist()
    {
        return playlists_interface.CreateNewPlaylist(Setting::DefaultFolderPaths::main_app_folder+
                                                        Setting::DefaultFolderPaths::pls_details_folder+
                                                        this->getUserName()+ Setting::Utility::default_additional_slash+
                                                        Setting::DefaultFilesNames::user_pls_lists);        

        //result.first=1;
        //result.second="You didnt senect any track to add to that playlist";
        //return result;

    };

bool User::LogIn(std::string username)
{    
    user.name = username;
    if(this->LoadUserSettings() == false)
    {
        std::cout<<"User setting loading failed"<<std::endl;

    }
    if(this->LoadUserPlaylistsList() == false)
    {
        std::cout<<"User playlist loading failed"<<std::endl;
    }
    return true;


}

bool User::LoadUserSettings()
{
    //function prepared for loading data saved in usser cfg file
    //first row , delimited by space, going for map app_user_setting and
    //all that settings are availible by getters
    //second row, delimited by coma, going to map user_last_played_object and
    //all that names are availible by getters
    //TODO: split it by two functions
    //TODO: combine LoadDataFromFile(by row) and SplitStringByDelimiter together in File manager

    FileManager fm;
    //settings -1th row: loading data from file into vector
    std::vector<std::string>* map_with_users_setting{new std::vector<std::string>};
    map_with_users_setting = fm.FileContentInToVectorString(Setting::DefaultFolderPaths::main_app_folder +
                                                    Setting::DefaultFolderPaths::pls_details_folder+
                                                    this->getUserName()+
                                                    Setting::Utility::default_additional_slash +
                                                    Setting::DefaultFilesNames::user_setting_file,
                                                    Setting::SettingFromFile::VariableNumberAtSettings);

    //merge type of value (setting file) with value (user file)
    size_t i =0;
    for(auto &setting_value: Setting::SettingFromFile::header_user_settings)
    {
        user.app_user_setting_map.insert(
            std::pair<std::string,std::string>(setting_value,map_with_users_setting->at(i)));
        ++i;
    }

    delete map_with_users_setting;
    map_with_users_setting = nullptr;  


    // settings 2nd row - because of spaces, diff delimiter
    std::string dataFromTextFile = fm.LoadFileContentLoadOnlyOneNrow(
                                                Setting::DefaultFolderPaths::main_app_folder +
                                                    Setting::DefaultFolderPaths::pls_details_folder+
                                                    this->getUserName()+
                                                    Setting::Utility::default_additional_slash +
                                                    Setting::DefaultFilesNames::user_setting_file,
                                                2);
    /*std::vector<std::string>* vector_with_last_played_user_obj =fm.SplitStringByDelimiter(dataFromTextFile,',');
    for(auto e:*vector_with_last_played_user_obj){std::cout<<e<<std::endl;}

    //merge type of value (setting file) with value (user file)
    size_t a =0;
    for(auto &setting_value: Setting::SettingFromFile::headers_user_last_played)
    {   
        try
        {
            //user.user_last_played_objects.insert({"abba","beta"});
            user.user_last_played_objects[setting_value]= (*vector_with_last_played_user_obj).at(a);
            ++a;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }

    
    delete vector_with_last_played_user_obj;
    vector_with_last_played_user_obj = nullptr;
*/

    for(auto &a: user.app_user_setting_map)
    {
        std::cout<<"Settings loaded: " <<a.first<< "---->  "<<a.second<<std::endl;
    }

        for(auto &a: user.user_last_played_objects)
    {
        std::cout<<"Settings loaded: " <<a.first<< "---->  "<<a.second<<std::endl;
    }

                                             
    return true;
}

bool User::LoadUserPlaylistsList()
{
    return true;
}

#endif