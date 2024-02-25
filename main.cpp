#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <array>
#include <numeric>
#include <deque>
#include <cctype>
#include <list>
#include <forward_list>
#include <iterator> //required for user std::advance function
#include <cstring>
#include <memory>
#include <unistd.h>
#include "MP_app.h"
#include "Lvl_0_Menu.h" // moved inf mp_app

using namespace std;

namespace tests
{
    void test_1_split_by_delimiter()
        {
        /*FileManager fm;
        std::string dataFromTextFile = fm.LoadFileContentLoadOnlyOneNrow("test1.txt",3);
        std::vector<std::string>* result =fm.SplitFirstRowByDelimiter(dataFromTextFile,',');
        for(auto e:*result){std::cout<<e<<std::endl;}
        delete result;
        result = nullptr;
        */

                                           /*Setting::DefaultFolderPaths::main_app_folder +
                                                Setting::DefaultFolderPaths::pls_details_folder+
                                                "Bob"+
                                                Setting::Utility::default_additional_slash +
                                                Setting::DefaultFilesNames::user_setting_file,
                                            3);*/
    }
    void test_2_create_playlist_from_string()
    {
        /*
        std::string for_pls{"1,3,4"};
        Playlist_I p;
        //p.CheckIfPlaylistAlreadyExist()
        //menu ->
        //replace it// append it/ choose diff name/show existing pls/cancel

        //load pls_list.lst
        //split it to map<pls_name -2nd, std::pair <int -1th el, std::string 3th and more)
        //load it as map
        //check at map it pls_name exist 
            //if does -> replace it// append it/ choose diff name/show existing pls/cancel
                //replace it -> get second from pair, get int from result, find that line in file and replace it
        
        p.SaveTracksIdIntoPlaylis("Bob","my pls name",for_pls);
        p.PrintPlaylistContent();
        */

    }

    void test_3_file_man()
    {
        FileManager fm;
        //fm.CreateFileSaveOneRowOfString("test1.txt","save me here,a,");
        //fm.AppendAtEndOfFileOneRowOfString("test1.txt","save at end of file");
        std::cout<<fm.FindElementByFirstColumnAtFileRetRow("test1.txt","second_pls",',')<<std::endl;
        
    }    

    void test_4_find_n_element_in_string_between_delimiter()
    {
        

        //int column_num{4};
        char d{','};
        std::string s1{"abba, beta ,1,2,3,orzeszek"};
        std::cout<<GeneralFuncitons::FindNElementFromSeparatedByDelimString(s1,d,8)<<std::endl;
        /*
        std::string s2{"save at end of file,4,3,1,1,2,"};
        std::string s3{"1abba,2aaa, 3ss"};//,,5ffgfhgf"};

        std::vector<int> pos{};
        std::vector<std::pair<int,int>> pos2{};
        int i=1;
        s1 =s2;
        int other_s{0};
        std::vector<int> word_size{};

        
        for(char &el: s1)
        {
            if(el==d )
            {   if(pos.size()==0)
                    {
                        word_size.push_back(i-1);
                        pos.push_back(0);
                    }
                else{
                    word_size.push_back(other_s);
                    
                }
                pos.push_back(i);
                //std::cout<<"where is delim: "<<i<< "value from other_s: "<<other_s<<std::endl;
                
                other_s = 0;
            }
            else{
                ++other_s;
            }
            ++i;
        }
        word_size.push_back(s1.length()-(pos.at(pos.size()-1))+1);

        std::cout<<s1.substr(pos.at(column_num-1),word_size.at(column_num-1))<<std::endl;
        */
    }
    void test_5_fm_GetRowByElementFromNcolumn()
    {
        FileManager fm;
        std::cout<<fm.FindElementByNColumnAtFileRetRow("test1.txt","my_first_pls",1,',')<<std::endl;
        std::cout<<fm.FindElementByNColumnAtFileRetRow("test1.txt","abba",3,',')<<std::endl;
    }
    void test_6_fm_GetVectorWithWholeColumnFromFile()
    {
        FileManager fm;
        for(auto el: fm.GetNColumnFromFileToVector("test1.txt",3,','))
        {std::cout<<el<<std::endl;}
    }

    void test_7_input_validation()
    {
        std::string pls_name{};
        
         while(GeneralFuncitons::validateInputOnlyLetterAndSpaces(pls_name))
        {
            std::cin>>pls_name;
            std::cout<<"loop in"<<std::endl;

        }
        std::cout<<"loop end"<<std::endl;
    }

    void test_8_test_find_map()
    {
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;

        it = mymap.find('x');
        if (it != mymap.end())
            std::cout<<"i found it?"<<std::endl;
        else
            std::cout<<"there is no d"<<std::endl;

        //thats mean sadsa.end() is not  last element at list - 
        //so if we looking for element which is last on list 
        //we will fund that, but it is not .end()
    }
    
    void test_9_test_user_instance()
    {
        //todo: remake whole user class because it generate error  somewhere as a class itself
        // clas wasnt compile because lack of "{}" in constructor and destructor ...
        //User u;
        //std::cout<<u.LogIn("Bob")<<std::endl;
    }
}

int main()
{
    //tests::test_1_split_by_delimiter();
    //tests::test_3_file_man();
    //tests::test_4_find_n_element_in_string_between_delimiter();
    //tests::test_5_fm_GetRowByElementFromNcolumn();
    //tests::test_6_fm_GetVectorWithWholeColumnFromFile();
    //tests::test_7_input_validation();
    //tests::test_8_test_find_map();
    //tests::test_9_test_user_instance();
    //return 0;

    App my_app{};
    my_app.app_run();      

}

