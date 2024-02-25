#ifndef USER_BASE_H
#define USER_BASE_H
#include "GeneralFunctions.h"


class User_base
{
    public:
        std::string name;
        int user_id{};
        std::map<std::string,std::string>app_user_setting_map;
        std::map<std::string,std::string> user_last_played_objects;

    public:
    
    User_base()
    {        
        user_last_played_objects.insert({"played_song","None"});
        user_last_played_objects.insert({"played_playlist","None"});
    };    
    ~User_base(){};

    User_base& operator=(User_base&& other_user)
    {
        this->name=other_user.name;
        this->user_id=other_user.user_id;
        return *this;
    }

     //operators - currently useless, list just keep string, not a opj with diff elements
    //bool operator ==(const std)



/*
    std::list<std::string> & user_playlist(){return this->basic_playlist;};
    void printUserPlaylist(bool show_id=false,int replace_id_by_arrow_at_track_number =-1)
    {
        if(show_id==false && replace_id_by_arrow_at_track_number == -1)
        {
            for(auto &el:this->basic_playlist)
                std::cout<<el<<std::endl;
        }
        else
        {   int temp_id{0};
            for(auto &el:this->basic_playlist)
            {
                if(replace_id_by_arrow_at_track_number == -1)
                {
                    std::cout<<temp_id<< ".      " <<el<<std::endl;
                }
                else
                {   
                    if(temp_id==replace_id_by_arrow_at_track_number)
                    {
                        std::cout<<"------>"<< " " <<el<<std::endl;
                        
                    }
                    else
                    {
                        std::cout<<temp_id<< ".      " <<el<<std::endl;
                    }                                
                }
                temp_id++;
            }
        }
    };


    std::string getTrackIdReturnTrackName(int track_id)
    {
        int temp_id{0};
        for(auto &el:this->basic_playlist)
            {
                if(track_id==temp_id)
                    return el;
                temp_id++;
            }
        return "None";
    }    
*/


};

#endif