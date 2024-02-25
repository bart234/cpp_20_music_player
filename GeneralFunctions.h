#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H
#include "Settings.h"


namespace GeneralFuncitons
{
    bool is_number(const std::string &rawElement)
    {
        try{
            std::stoi(rawElement);
            }
        catch(std::exception &e)
            {
                return false;
            }
        return true;
    }

    int validateIsInputOnlyLetterAndSpaces(std::string inputFromConsole,std::string accptable_chars_in_str = "")
    {
        if (accptable_chars_in_str =="")
        {
            std::cout<<"Setting:SettingPlaylistFile:accptable_chars_in_str required"<<std::endl;
            return 0;
        }
        else
        {
            for(char &a: inputFromConsole)
            {
                int temp_check=0;
                for(char &b: accptable_chars_in_str)
                {
                    if(a ==b)
                    {
                    temp_check++;
                    break;
                    }    
                }
                if (temp_check==0)
                {
                    return 0;
                }

            }

            return 1;
        }
    }

    int rawInputHandler(std::string inputFromConsole)
    {
        //-1 - user not exist or you type something else to exit
        //-2 - you type q
        //>=0 - user id
        if(is_number(inputFromConsole))
        {   
            return std::stoi(inputFromConsole);
        }
        else
        {
            //it is not number
            if(inputFromConsole =="q" || inputFromConsole=="Q"|| inputFromConsole=="exit")
            {
                return -2;
            }
            else
            {
                return -1;
            }
        }
        
    }
    std::string FindNElementFromSeparatedByDelimString(std::string &string_to_search,char delimiter, size_t column_num_to_return)
    {
   
        try
        {
            if(string_to_search.length()==0)
                return "empty string";
            std::vector<int> pos{};
            std::vector<int> word_size{};
            int i=1;
            int other_s{0};
            for(char &el: string_to_search)
            {
                if(el==delimiter )
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
            word_size.push_back(string_to_search.length()-(pos.at(pos.size()-1))+1);

            return string_to_search.substr(pos.at(column_num_to_return-1),word_size.at(column_num_to_return-1));
        }
        catch(const std::exception& e)
        {
            std::cerr <<"Function: FindNElementFromSeparatedByDelimString: \ninputs:\n"
                        <<"string: " <<string_to_search<<",\n"
                        <<"delimiter: ->"<<delimiter<<"<-\n"
                        <<"column_num: "<<column_num_to_return<<",\n"
                        << e.what() << '\n';
        }

        return "FindNElementFromSeparatedByDelimString::error";
    }

    std::vector<std::string>* SplitStringByDelimiter(std::string string_to_split, char delmiter)
    {
        std::vector<std::string>* splited_values {new std::vector<std::string>};
        std::string temp_str;
        for(char a: string_to_split)
        {
            
            if(a==delmiter)
            {
                splited_values->push_back(temp_str);
                temp_str.clear();
            }
            if(a!=delmiter){temp_str += a;}            
        }
        splited_values->push_back(temp_str);
        return  splited_values;
    };

}

#endif
