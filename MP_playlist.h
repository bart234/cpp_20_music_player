
#include "FileManager.h"
#include "MP_track.h"

class Playlist
    {
        private:
        int pls_id;
        std::vector<Track*> pls_content{};

        private:
        void clean(std::vector<std::string*>* viki_to_clean);
        void clean_ptr_tracks(std::vector<Track*> viki_to_clean);

        public:
        std::vector<Track*> GetPlaylist(){return pls_content;}
        void addTrack(Track*t)
        {
            pls_content.push_back(t);
        }
        
        ~Playlist()
        {
            this->clean_ptr_tracks(pls_content);
        }
        /*void printPlaylist(bool show_id);
        void printComparePlaylist(bool show_id,std::list<std::string> &userPls);
        std::string puttTrackIdReturnTrackName(int track_id);
        std::list<std::string> getPlayList(){return basic_playlist;}; */       
    };

void Playlist::clean(std::vector<std::string*>* viki_to_clean)
{
    for(auto &a: *viki_to_clean)
        {
            delete a;
            a =nullptr;
        }     
}
void Playlist::clean_ptr_tracks(std::vector<Track*> viki_to_clean)
{
    for(auto &a: viki_to_clean)
        {
            delete a;
            a =nullptr;
        }     
}



/*

    std::string Playlist::puttTrackIdReturnTrackName(int track_id)
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


    void Playlist::printComparePlaylist(bool show_id,std::list<std::string> &userPls)
    {
        int temp_id{0};
        for(auto &el:this->basic_playlist)
        {                            
            std::list<std::string>::iterator it = std::find(userPls.begin(), userPls.end(),el);
            if(it!= userPls.end())
            {
                std::cout<<temp_id<< ". onpls  " <<el<<std::endl;                           
                temp_id++;
            }else
            {
                std::cout<<temp_id<< ".        " <<el<<std::endl;                           
                temp_id++;
            }
        }
    }

    void Playlist::printPlaylist(bool show_id=false)
    {
        if(show_id==false )
        {
            for(auto &el:this->basic_playlist)
                std::cout<<el<<std::endl;
        }
        else
        {   int temp_id{0};
            for(auto &el:this->basic_playlist)
                {                            
                    std::cout<<temp_id<< ".      " <<el<<std::endl;                           
                    temp_id++;
                }
        }
    };
*/
    