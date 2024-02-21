#ifndef TRACK_H
#define TRACK_H
#include "GeneralFunctions.h"

class Track
    {
        private:
        std::string a;
        std::string b;
        std::string c;
        std::string d;

        public:
        Track(std::string in_a,std::string in_b,std::string in_c,std::string in_d):
                    a{in_a},b{in_b},c{in_c},d{in_d}{};
        Track(std::string args[4]):a{args[0]},b{args[1]},c{args[2]},d{args[3]}{};
        Track(std::vector<std::string>*v):a{v->at(0)},b{v->at(1)},c{v->at(2)},d{v->at(3)}{}

        void print_me(){std::cout<<"This is my test obj: " <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<std::endl;};
        std::string DbTemplate(){return a +" "+b +" "+c +" "+d;}
    };

/*   
namespace TrackFunctions
{
    
    void songPlaying(std::string songSong, int duration)
    {
        //#include <unistd.h>
        for ( int a = duration;a>0;--a)
        {
            cout<<a<<" " << songSong<<endl;
            sleep(1);
        }
    }

    
    std::string putTrackIdReturnTrackName(int track_id,std::list<std::string> &l)
    {
        //todo: redudance same function in user class
        int temp_id{0};
        for(auto &el:l)
            {
                if(track_id==temp_id)
                    return el;
                temp_id++;
            }
        return "none";
    }

    bool swapElementsAtList(std::list<std::string> & string_list,
                                std::string el_to_switch_1,
                                std::string el_to_switch_2)
        {
            try
            {
                std::list<std::string>::iterator it = std::find(string_list.begin(),string_list.end(),el_to_switch_1);
                std::list<std::string>::iterator it2 = std::find(string_list.begin(),string_list.end(),el_to_switch_2);
                if(it==string_list.end() || it2==string_list.end())
                    return false;
                std::swap(*it,*it2);
                return true;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return false;
            }
            
        }
    
    bool swapElementsAtList(std::list<std::string> & string_list,
                            unsigned int pos_of_el1,
                            unsigned int pos_of_el2)
    {
        try
        {
            int temp_offset;
            //idiot case                
            //
            //||
            unsigned int size_list =static_cast<unsigned int>(string_list.size());
            size_list -=1;
            if(pos_of_el1<0  ||pos_of_el2<0 || pos_of_el1==pos_of_el2||pos_of_el2> size_list||pos_of_el1> size_list)
                return false;
            
            if(pos_of_el1>pos_of_el2)
            {
                std::swap(pos_of_el1,pos_of_el2);
            }            
            std::list<std::string>::iterator it = std::find(string_list.begin(),string_list.end(),putTrackIdReturnTrackName(pos_of_el1,string_list)); 
            temp_offset = pos_of_el2-pos_of_el1;
            std::list<std::string>::iterator it2 =it;
            std::advance(it2,temp_offset);
            std::swap(*it,*it2);
            return true; 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }        
    }

    std::vector<int> vector_int_from_cin_getline(bool remove_duplicates=false)
    {
        std::vector<int> ab;
        std::set<int> without_duplicates;
        std::string rawUserInput;
        std::getline(std::cin >> std::ws, rawUserInput);
                    
        std::istringstream iss{rawUserInput};
        std::string s;
        while(std::getline(iss,s,' '))
        {
            try
                {
                    if(remove_duplicates)
                    {without_duplicates.insert(std::stoi(s));}
                    else
                    {ab.push_back(std::stoi(s));};
                    
                }
            catch(const std::exception& e)
                {
                    cout << s<<" will be skipped"<<endl;
                }
        }
        if(remove_duplicates)
        {
            for(auto el:without_duplicates)
            {ab.push_back(el);}
        }

        return ab;
    }
*/

#endif