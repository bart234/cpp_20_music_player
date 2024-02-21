#ifndef MP_AUTH_H
#define MP_AUTH_H
#include "GeneralFunctions.h"

class Authorization
{
    private:
        std::string &file_path;
    public:
        Authorization(std::string &file_path):file_path{file_path}{};
        
        bool check_auth(std::string &login, std::string &pwd)
            {
                FileManager fm;
                std::map<std::string, std::string>* temp_viki{nullptr};
                temp_viki = fm.LoadUserCrudIntoMap(Setting::DefaultFolderPaths::main_app_folder+Setting::DefaultFilesNames::user_login_pwd);
                
                //action
                //to manage file content: user user1 10
                auto find_result = temp_viki->find(login);
                if (find_result != temp_viki->end() && find_result->second == pwd){
                    delete temp_viki;
                    temp_viki = nullptr;
                    return true;
                }else{
                    delete temp_viki;
                    temp_viki = nullptr;
                    return false;
                }                
                return true;
            }

};


#endif