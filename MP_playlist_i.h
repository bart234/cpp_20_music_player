#include "MP_playlist.h"

// show pls with all music - for all
class Playlist_I 
{    
    private:
    Playlist *pls_local{new Playlist};
    Playlist *pls_local_tracks_to_pick{nullptr};

    bool IsPlaylistNameAlreadyExist(std::string path_to_pls_list_file,std::string new_playlist_name);
    Playlist* LoadDataFromFileIntoPlaylistObject(std::vector<std::string*>* ptr_to_raw_data,
                                                size_t num_or_values_at_row,
                                                char default_delimiter_at_track_lib_file);
        
    public:
    Playlist_I(){};
    ~Playlist_I(){delete pls_local;pls_local=nullptr;}
    std::vector<std::string> GetUserPlaylistsNameList(std::string user_name); //todo Opt_3_open_user_playlists
    std::map<std::string,int> GetUserPlaylistsNameList(std::string file_path,bool map_return);
    std::pair<int,std::string> CreateNewPlaylist(std::string path_to_pls_list_file);
    
    
    void PrintPlaylistContent(Playlist *pls); 
    void Load_pls_with_track_to_pick_for_everyone();
    void Load_pls_by_user_by_name(std::string pls_name, std::string user_name);
    
    
    void SaveTracksIdIntoPlaylis(std::string user_name,std::string playlist_name, std::string tracks_id);   //todo
    //void SavePlaylistInfoFile(std::string playlist_name);   //todo
    

};




std::pair<int,std::string> Playlist_I::CreateNewPlaylist(std::string path_to_pls_list_file)
{
        std::pair<int,std::string> result;
        //Playlist_I new_pl;
        std::string pls_name;
        std::cout<<"Please tape new playlist name:";
        std::cin>>pls_name;

        //trimming only letter and spaces
        while(GeneralFuncitons::validateInputOnlyLetterAndSpaces(pls_name))
        {
            std::cin>>pls_name;
        }

        //check at start if that already exist
        if(this->IsPlaylistNameAlreadyExist(path_to_pls_list_file,pls_name))
        {
            //nothing to clean
            std::cout<<"Test:- that pls already exist"<<std::endl;
            return {0,"Error: this->IsPlaylistNameAlreadyExist"};
        }

        //




        //new_pl.CreatePlaylist(pls_name);              -done
        //set pls name                                  -done
        //check if pls exist - return up if it is       -done
        //load file with track, to playlist, and print it nice form for user - done
        //ask user to  write id of songs which should be added, by ","
        //manage user input, split id-s, check if all are valid
        //return up if not, print , which one are not valid, which are valid
        //create pls_ obj, save it with details,
        //save track id in pls obj and in file - in progress
}




    
void Playlist_I::SaveTracksIdIntoPlaylis(std::string user_name,std::string playlist_name, std::string tracks_list_del_by_coma)
{
    FileManager fm;
    if(fm.IsFileExist(Setting::DefaultFolderPaths::main_app_folder+
                        Setting::DefaultFolderPaths::pls_details_folder+ 
                        user_name + Setting::Utility::default_additional_slash+
                        Setting::DefaultFilesNames::user_pls_lists))
    {
        //file exist
    }
    else
    {
        //file doesnt exist - we dont need to check if pls exist - just create it
        //todo - change it to bool and check if everyting is ok
        /*int result = fm.CreateFileSaveOneRowOfString(Setting::DefaultFolderPaths::main_app_folder+
                                            Setting::DefaultFolderPaths::pls_details_folder+ 
                                            user_name + Setting::Utility::default_additional_slash+
                                            Setting::DefaultFilesNames::user_pls_lists,
                                        playlist_name,
                                        tracks_list_del_by_coma);*/
    }

};



Playlist* Playlist_I::LoadDataFromFileIntoPlaylistObject(
                            std::vector<std::string*>* ptr_to_raw_data,
                            size_t num_or_values_at_row=Setting::SettingPlaylistFile::number_of_columns_in_track_lib_file,
                            char default_delimiter_at_track_lib_file=Setting::SettingPlaylistFile::delimiter_used_in_all_file)
    {   
        std::string my_string_to_split;
        Playlist *pls_result {new Playlist()}; 

        for(auto &a: *ptr_to_raw_data)
        {
            my_string_to_split = *a;                    
            Track* t {new Track(GeneralFuncitons::SplitStringByDelimiter(*a,','))};
            pls_result->addTrack(t);
        }

        //can we clean ptr_to_raw_data and its content ?
        //yep- it is  copy into track 

        FileManager::clean(ptr_to_raw_data);
        delete ptr_to_raw_data;
        ptr_to_raw_data=nullptr;      
    }



void Playlist_I::Load_pls_by_user_by_name(std::string pls_name,std::string user_name)
{   
    //it load selected playlist by user and by user_id
    
    FileManager fm;
    if (pls_name == Setting::SettingPlaylistFile::deafult_)  
    {
        //load default pls - mean all availible tracks
            
        
        std::vector<std::string*>* p_viki = fm.GetAllContentFromFileRowByRowIntoVector(
                                Setting::DefaultFolderPaths::main_app_folder + 
                                Setting::DefaultFilesNames::availible_tracks);
        this->pls_local_tracks_to_pick = this->LoadDataFromFileIntoPlaylistObject(p_viki);

    }
    else
    {
        std::string temp {pls_name};
        if(user_name=="")
            throw "Username cannot be empty";
        //load custom pls - TODO TO FINISH
        /*
        temp += Setting::SettingPlaylistFile::dash_dash_+ user_name;
        std::vector<std::string*>* p_viki = fm.GetAllContentFromFileRowByRowIntoVector(Setting::DefaultFolderPaths::main_app_folder+
                                                                                            Setting::DefaultFolderPaths::pls_details_folder +
                                                                                            user_name+Setting::Utility::default_additional_slash+
                                                                                            pls_name);
        pls_local = this->CreatePlaylistFromLoadedData(p_viki);
        */
    }

    //find_pls_at_file -> file content:"default--00000;file_name_with_that_pls"
}


void Playlist_I::Load_pls_with_track_to_pick_for_everyone()
{   
    Load_pls_by_user_by_name(Setting::SettingPlaylistFile::deafult_,"");
}

void Playlist_I::PrintPlaylistContent(Playlist *pls)
{
    for(auto t:pls->GetPlaylist())
    {
        t->print_me();
    }
}

std::map<std::string,int> Playlist_I::GetUserPlaylistsNameList(std::string file_path,bool map_return)
{
    FileManager fm;
    auto a = fm.GetNColumnFromFileToVector(file_path,
                                            Setting::SettingPlaylistFile::column_number_with_pls_name,
                                            Setting::SettingPlaylistFile::delimiter_used_in_all_file,
                                            map_return);
    return a;
}

std::vector<std::string> Playlist_I::GetUserPlaylistsNameList(std::string file_path)
{
    FileManager fm;
    auto a = fm.GetNColumnFromFileToVector(file_path,
                                            Setting::SettingPlaylistFile::column_number_with_pls_name,
                                            Setting::SettingPlaylistFile::delimiter_used_in_all_file);
    return a;
}

bool Playlist_I::IsPlaylistNameAlreadyExist(std::string path_to_pls_list_file,std::string new_playlist_name)
{
    std::map<std::string,int>  existing_playlists_names;
    existing_playlists_names = GetUserPlaylistsNameList(path_to_pls_list_file,true);
    auto result = existing_playlists_names.find(new_playlist_name);
    
    if(result != existing_playlists_names.end())
        return true;
    else
        return false;
    
}
















// prepare "new playlist option"
// prepare "change my plst"