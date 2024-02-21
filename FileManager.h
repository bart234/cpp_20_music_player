#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "MP_track.h"
#include <fstream>
#include <algorithm>
#include <sstream>

class FileManager
{
    private:
    
   
    
    public:
    static void clean(std::vector<std::string*>*);  
    //void clean(std::vector<std::string*>*);     //it cleaning content of obj std::vector<std::string*>* from GetAllContentFromFileRowByRowIntoVector
    void PrintFileContent(std::string file_path); //if print coontent of file from  GetAllContentFromFileRowByRowIntoVector

    //main funciton
    static std::vector<std::string*>* GetAllContentFromFileRowByRowIntoVector(std::string file_path); //data from file into ptrs vector string

    //
    std::string LoadFileContentLoadOnlyOneNrow(std::string file_path,size_t row_to_load); //it load GetAllContentFromFileRowByRowIntoVector and extract n-element from vector    
    std::string FindElementByNColumnAtFileRetRow(std::string file_path,std::string element_from_n_position,int position, char delimiter_in_file);//it split file into vector_string_ptr_ 
    std::vector<std::string> GetNColumnFromFileToVector(std::string file_path,int position, char delimiter_in_file);
    std::map<std::string,int> GetNColumnFromFileToVector(std::string file_path,int position, char delimiter_in_file,bool map_return);
    //utility
    //mv to General Functoinsstd::vector<std::string>* SplitStringByDelimiter(std::string string_to_split, char delmiter); //it split string by delimiter into vector_string_ptr
    
    //old

    //to remove??
    std::vector<std::string>* FileContentInToVectorString(std::string file_path,size_t num_or_values_at_row);


    std::vector<std::string>* SplitFirstRowByDelimiter(std::vector<std::string*>* DataFromTextFile, char delmiter);

    std::map<std::string, std::string>* LoadUserCrudIntoMap(std::string file_path,size_t num_or_values_at_row);
    std::vector<Track*>* LoadDataFileToObjectVector_1(std::string file_path,size_t num_or_values_at_row);
    

    bool IsFileExist(std::string file_path);
    void CreateAppendFile(std::string file_path, std::vector<Track> & obj_to_save);
    int CreateFileSaveOneRowOfString(std::string file_path,std::string save_that_string); //in progress, return0,1
    int AppendAtEndOfFileOneRowOfString(std::string file_path,std::string save_that_string);
    std::string  FindElementByFirstColumnAtFileRetRow(std::string file_path,std::string element_from_n_position,char delimiter_in_file);

    

    //void RemoveFile(std::string file_path);

};


std::vector<std::string> FileManager::GetNColumnFromFileToVector(std::string file_path,int position, char delimiter_in_file)
{
    std::vector<std::string> return_vector;
    std::vector<std::string*>* v_string_ptr = this->GetAllContentFromFileRowByRowIntoVector(file_path);
    for(std::string* s:*v_string_ptr)
    {
        if(s->length()!=0)
            {
                return_vector.push_back(GeneralFuncitons::FindNElementFromSeparatedByDelimString(*s,delimiter_in_file,position));
            }
    }

    this->clean(v_string_ptr);
    delete v_string_ptr;
    v_string_ptr = nullptr;

    return return_vector;
}
std::map<std::string,int> FileManager::GetNColumnFromFileToVector(std::string file_path,int position, char delimiter_in_file,bool map_return)
{
    std::map<std::string,int> return_map;
    std::vector<std::string*>* v_string_ptr = this->GetAllContentFromFileRowByRowIntoVector(file_path);
    for(std::string* s:*v_string_ptr)
    {
        if(s->length()!=0)
            {
                return_map.insert({GeneralFuncitons::FindNElementFromSeparatedByDelimString(*s,delimiter_in_file,position),1});
            }
    }

    this->clean(v_string_ptr);
    delete v_string_ptr;
    v_string_ptr = nullptr;

    return return_map;
}

std::string  FileManager::FindElementByNColumnAtFileRetRow(std::string file_path,std::string element_what_looking_for,int position,char delimiter_in_file)
{
    std::vector<std::string*>* v_string_ptr = this->GetAllContentFromFileRowByRowIntoVector(file_path);
    std::string return_string;
    for(std::string* s:*v_string_ptr)
    {

        if(s->length()!=0)
            {
                if(GeneralFuncitons::FindNElementFromSeparatedByDelimString(*s,delimiter_in_file,position)==element_what_looking_for)
                {
                    return_string=*s;
                }
            }
    }

    this->clean(v_string_ptr);
    delete v_string_ptr;
    v_string_ptr = nullptr;
    return return_string;
};


std::string  FileManager::FindElementByFirstColumnAtFileRetRow(std::string file_path,std::string element_what_looking_for,char delimiter_in_file)
{
    return this->FindElementByNColumnAtFileRetRow(file_path,element_what_looking_for,1,delimiter_in_file);
};


std::vector<std::string>* FileManager::SplitFirstRowByDelimiter(std::vector<std::string*>* dataFromTextFile, char delmiter)
{
    std::vector<std::string>* splited_values {new std::vector<std::string>};
    std::string temp_str;
    for(char a: *((*dataFromTextFile).at(0)))
    {
        
        if(a==delmiter)
        {
            splited_values->push_back(temp_str);
            temp_str.clear();
        }
        if(a!=delmiter){temp_str += a;}            
    }
    splited_values->push_back(temp_str);
    

    //we can clean 
    this->clean(dataFromTextFile);
    delete dataFromTextFile;
    dataFromTextFile=nullptr;
    return  splited_values;   
}

void FileManager::CreateAppendFile(std::string file_path, std::vector<Track> & obj_to_save)
{        
    //new file
    std::ofstream out_file;
    std::string full_file_path {file_path};

    //out_file.open(full_file_path);                  //this on overriding whole file 
    out_file.open(full_file_path,std::ios::app);    //this one appending that
    if(!out_file.is_open())
    {
        std::cout<<"Error during file creation."<<std::endl;
    }else
    {
        std::string my_line;
        for(auto &element: obj_to_save)
        {
            out_file<<element.DbTemplate()<<std::endl;
        }      
        out_file.close();
    }          
}

int FileManager::CreateFileSaveOneRowOfString(std::string file_path,std::string save_that_string)
{        
    //new file
    std::ofstream out_file;
    std::string full_file_path {file_path};
   
    out_file.open(full_file_path,std::ios::app);    //this one appending that
    if(!out_file.is_open())
    {
        std::cout<<"Error during file creation."<<std::endl;
    }else
    {        
        out_file<<save_that_string<<std::endl;
        out_file.close();
    }      
    
   return 0;    
}

int FileManager::AppendAtEndOfFileOneRowOfString(std::string file_path,std::string save_that_string)
{          
   return this->CreateFileSaveOneRowOfString(file_path,save_that_string);
   
}




std::vector<std::string>* FileManager::FileContentInToVectorString(std::string file_path,size_t num_or_values_at_row)
{
    std::vector<std::string>*  vector_for_values_from_row {new std::vector<std::string>};
    auto ptr_to_raw_data = this->GetAllContentFromFileRowByRowIntoVector(file_path);

        std::string my_string_to_split;
        for(auto &a: *ptr_to_raw_data)
        {
            my_string_to_split = *a;
            std::istringstream iss{my_string_to_split};
            std::string temp;          

            for(size_t i=0;i<=num_or_values_at_row;i++)
            {
            iss>>temp;
            vector_for_values_from_row->push_back(temp);
            }

        }
    //we can clean 
    this->clean(ptr_to_raw_data);
    delete ptr_to_raw_data;
    ptr_to_raw_data=nullptr;
    return  vector_for_values_from_row;   
}

std::map<std::string, std::string>* FileManager::LoadUserCrudIntoMap(std::string file_path,size_t num_or_values_at_row=3)
    {
        //size_t num_or_values_at_row=4 - have to be equal with Obj constructor  variables in arr and inside it 
        std::map<std::string, std::string>*  map_with_user_crud {new std::map<std::string, std::string>};
        auto ptr_to_raw_data = this->GetAllContentFromFileRowByRowIntoVector(file_path);

        std::string my_string_to_split;
        for(auto &a: *ptr_to_raw_data)
        {
            my_string_to_split = *a;
            std::istringstream iss{my_string_to_split};
            std::string temp[num_or_values_at_row];          

            for(size_t i=0;i<=num_or_values_at_row;i++)
            {iss>>temp[i];}
            //we not check if there are 2 same logins, it iwll be cover durin saving/changing login
            map_with_user_crud->insert(std::pair<std::string, std::string>(temp[0],temp[1]));
        }

        //we can clean 
        this->clean(ptr_to_raw_data);
        delete ptr_to_raw_data;
        ptr_to_raw_data=nullptr;
        return  map_with_user_crud;        
    }
    
//todo: template from that
std::vector<Track*>* FileManager::LoadDataFileToObjectVector_1(std::string file_path,size_t num_or_values_at_row=4)
    {
        //size_t num_or_values_at_row=4 - have to be equal with Obj constructor  variables in arr and inside it 
        std::vector<Track*>* viki_with_cust_obj{new std::vector<Track*>};
        auto ptr_to_raw_data = this->GetAllContentFromFileRowByRowIntoVector(file_path);

        std::string my_string_to_split;
        for(auto &a: *ptr_to_raw_data)
        {
            my_string_to_split = *a;
            std::istringstream iss{my_string_to_split};
            std::string temp[num_or_values_at_row];                        
            //TODO: <---- copy to temp from iss!!!!
            //make it more flexible do not copy  it, move it 
            for(size_t i=0;i<=num_or_values_at_row;i++){iss>>temp[i];}
            viki_with_cust_obj->push_back(new Track(temp));
        }

        //we can clean 
        this->clean(ptr_to_raw_data);
        delete ptr_to_raw_data;
        ptr_to_raw_data=nullptr;
        return  viki_with_cust_obj;        
    }
    

void FileManager::PrintFileContent(std::string file_path)
{
    auto aaaa = this->GetAllContentFromFileRowByRowIntoVector(file_path);
    for(auto &a: *aaaa)
    {
        std::cout<<*a<<std::endl;
    }
}

std::vector<std::string*>* FileManager::GetAllContentFromFileRowByRowIntoVector(std::string file_path)
{
    std::vector<std::string*>* v{new std::vector<std::string*>};
    //TODO: remove and set to nullptr ->std::vector
    //TODO: remove and set to nullptr ->all vector content
    
    std::string file_path1{file_path};
    std::fstream my_file{file_path1};

    if(!my_file.is_open()){
        std::cout<<"File is closed:" <<file_path<<std::endl;
    }
    else
    {
        std::string line;
        while(!my_file.eof())
        {            
            std::getline(my_file,line);
            v->push_back({new std::string(line)});
        }
    }
    my_file.close();
    return v;
}

//that return  vector will have only one row, with n-row values
std::string FileManager::LoadFileContentLoadOnlyOneNrow(std::string file_path,size_t row_to_load)
{
    std::vector<std::string*>* v = GetAllContentFromFileRowByRowIntoVector(file_path);
    std::string temp_to_return{*((*v).at(row_to_load))};
    this->clean(v);
    delete v;
    v = nullptr;
    return  temp_to_return;
}

bool FileManager::IsFileExist(std::string file_path)
{
    std::ifstream myfile;
    myfile.open(file_path);
    if(myfile){
        myfile.close();
        return true;
    }else{
        return false;
    }
}

void FileManager::clean(std::vector<std::string*>* viki_to_clean)
{
    for(auto &a: *viki_to_clean)
        {
            delete a;
            a =nullptr;
        }     
}
#endif