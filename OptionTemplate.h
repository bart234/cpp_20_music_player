#ifndef OPTIONTEMPLATE_H
#define OPTIONTEMPLATE_H
#include "GeneralFunctions.h"
#include "MP_playlist_i.h"
#include "MP_user_main.h"


    //pre-declaration
    class MenuTemplate;
    class Menu_MainMenu;
    class Menu_at_mm_opt1;
    
    
    class OptionTemplate
    {                    
        
        private:
            std::string option_description;
            int option_numer;  
        public:
            //std::queue<std::shared_ptr<MenuTemplate>> &main_queue;
            std::shared_ptr<User> user_b =nullptr; 
            
        public:
            virtual void print_me(){std::cout<<"#"<<option_numer<<".  "<<option_description<<std::endl;};
            virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)=0;
            public:
            OptionTemplate(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                            option_description{i_description},option_numer{i_option_number},user_b{i_user}
                            {};
            ~OptionTemplate(){};
            virtual void setNewDescription(std::string new_description){this->option_description=new_description;};
    };

    class Option_MainMenu_Template: public OptionTemplate
    {
        public:
            Option_MainMenu_Template(std::string i_description, int i_option_number,std::shared_ptr<User> i_user):
                            OptionTemplate(i_description,i_option_number,i_user)
                            {};
            ~Option_MainMenu_Template(){};
    };
    
    class Option_ToPreviousMenu:public OptionTemplate
    {   
        std::string previus_menu_name;
        public:
            Option_ToPreviousMenu(std::string i_previous_menu_name,std::shared_ptr<User> i_user):
                    OptionTemplate("",9,i_user),previus_menu_name{i_previous_menu_name}
                    {
                        std::string temp {"Back to " + std::string{i_previous_menu_name} + " menu."};
                        this->setNewDescription(temp);
                    };
            ~Option_ToPreviousMenu(){};
        public:
            virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                    {
                        std::cout<<"Back to previous menu."<<std::endl;
                    }
    };

    class Option_ExitApp:public OptionTemplate
    {   
        std::string previus_menu_name;
        public:
            Option_ExitApp(std::shared_ptr<User> i_user):
                        OptionTemplate("Quit",0,i_user){};
            ~Option_ExitApp(){};
        public:
            virtual void doMyAction(std::stack<std::shared_ptr<MenuTemplate>> &i_stack_of_menus)override
                    {
                        std::cout<<"It should close all."<<std::endl;
                    }
    };
    

#endif