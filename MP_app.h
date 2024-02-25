    #include "Lvl_0_Menu.h" 
    #include "MP_user_main.h"
    class App
    {
        private:
            std::shared_ptr<User> user =nullptr;            
            /*bool flag_close_me{false};
            bool flag_isuser_selected{false};
            bool flag_already_logged{false};
            Playlist availible_music;
            
            std::shared_ptr<User_simple> current_user{nullptr};
            void menu_select_user();
            void menu_select_general_action();
            void menu_showUserPlaylist();
            void menu_editUserPlaylist();
            void menu_editUserPlaylist_trackMoveMenu(int &selectedTrackId);
            void menu_playMyPlaylist();
            void menu_showAvailibleTracks();
            void menu_add_track_from_storage_to_user_pls();
            */
        public:
            App(){};
            ~App()=default;
            //std::list<User_simple> container_user_list;
            void app_run();
            
    };

    void App::app_run()
    {

         //my main stack
        std::stack<std::shared_ptr<MenuTemplate>> stack_of_menus;

        //we add start main menu
        std::shared_ptr<MenuTemplate> main_menu_lvl0 {new Menu_MainMenu{user}}; 
        stack_of_menus.push(main_menu_lvl0);

        // main_menu by default is going to add to that quene
        int selected_option;
        
        //main_loop
        while (true)
        {   

            stack_of_menus.top()->show_menu();        
            selected_option=stack_of_menus.top()->manageUserInput();            
            stack_of_menus.top()->launch_selected_option(selected_option,stack_of_menus);
            if (selected_option == 0) {break;}                  //Quit
            if (selected_option == 9) {stack_of_menus.pop();}   // Back to previous menu
        }
        //TODO: move previous menu option in to new function and add it in to template
        
        /*old
        //load users from source
        this->container_user_list.emplace_back("Aga",10);
        this->container_user_list.emplace_back("Beata",8);

        while(!flag_close_me)
        {
            //TODO:fix that ifs
            //0 0 not logged, not user selected
            if(!this->flag_isuser_selected && !this->flag_already_logged)
            {
                menu_select_user();
                if(flag_close_me)break;
            }
            
            // 1 1 logged and user selected
            if(this->flag_isuser_selected && this->flag_already_logged)
            {
                cout<<"User is already selected, do you want switch it?Y/N and q for close app"<<endl;
                std::string tempInput;
                cin>>tempInput;
                if(tempInput=="y"||tempInput=="Y")
                {
                    this->flag_isuser_selected=false;
                    this->flag_already_logged=false;
                    this->current_user=nullptr;
                }
                else if (tempInput=="q" || tempInput=="Q")
                {
                    this->flag_close_me=true;
                    this->flag_isuser_selected=false;
                    this->flag_already_logged=false;
                }
                else
                {
                    this->flag_already_logged=false;
                }
            }

            //1 0
            if(this->flag_isuser_selected and !this->flag_already_logged)
            {
                cout<<"Hello "<<this->current_user->getUserName()<< " select ation"<<endl;
                menu_select_general_action();
                this->flag_already_logged=true;
                if(flag_close_me)break;
            }
        }
        */
    } 
/*
    void App::menu_select_general_action()
    {
        bool quit_me{false};
        std::string rawUserInput;
        int userInput;
        while(!quit_me)
        {
            cout<<"--------------------------"<<endl;
            cout<<"   General menu    "<<endl;
            cout<<"1. Show my playlist"<<endl;
            cout<<"2. Edit my playlist"<<endl;
            cout<<"3. Play my playlist"<<endl;
            cout<<"4. Show availible tracks"<<endl;
            cout<<"9. Back to previous menu"<<endl;
            cout<<"0. To close app"<<endl;
            cout<<"Type here:";
            cin>>rawUserInput;
            userInput=rawInputHandler(rawUserInput);
            if(userInput==0 || userInput == 9|| userInput <0) 
                {
                    quit_me =true;
                    if(userInput==0)this->flag_close_me=true;
                }
            if(userInput==1)
            {
                menu_showUserPlaylist();
            }
            else if(userInput ==2)
            {
                menu_editUserPlaylist();
                if(flag_close_me)break;
            }
            else if(userInput ==3)
            {
                menu_playMyPlaylist();
                if(flag_close_me)break;
            }
            else if(userInput ==4)
            {
                menu_showAvailibleTracks();
                if(flag_close_me)break;
            }
        }
    }

    void App::menu_showAvailibleTracks()
    {
        bool quit_me{false};
        std::string rawUserInput;
        int userInput;
        int track_id = 0;
        availible_music.loadAvailibleMusic();

        while(!quit_me)
        {
            availible_music.printComparePlaylist(true,current_user->user_playlist());

            cout<<"--------------------------"<<endl;
            cout<<"   General menu    "<<endl;
            cout<<"1. Add to track/trackt to playlist "<<endl;
            cout<<"9. Back to previous menu"<<endl;
            cout<<"0. To close app"<<endl;
            cout<<"Type here:";
            cin>>rawUserInput;
            userInput=rawInputHandler(rawUserInput);

            if(userInput==0 || userInput == 9|| userInput <0) 
            {
                quit_me =true;
                if(userInput==0)this->flag_close_me=true;
            }
            if(userInput==1)
            {
                menu_add_track_from_storage_to_user_pls();     
                if(userInput==0)this->flag_close_me=true;
            }
        }
    }

    void App::menu_add_track_from_storage_to_user_pls()
    {
        cout<<endl;
        availible_music.printComparePlaylist(true,current_user->user_playlist());

        bool quit_me{false};
        std::string rawUserInput;
        int userInput;
        int track_id = 0;
        std::vector<int> vector_with_ids;
        //while(!quit_me)
        //{
        cout<<"--------------------------"<<endl;
        cout<<"Type tracks id with space between, to add them at the end of you playlist"<<endl;
        cout<<"Not corrected id will be skipped"<<endl;
        cout<<"Provide space or leave empty to back to previous menu"<<endl;
        cout<<"Type here:";
        while(true)
        {   
            vector_with_ids = vector_int_from_cin_getline(true);
            for(int &id: vector_with_ids)
            {
                std::string result_find {availible_music.puttTrackIdReturnTrackName(id)};
                if(result_find != "None")
                {
                    current_user->user_playlist().push_back(result_find);
                }
                else
                {
                    cout<<"Element "<<id<<" skipped"<<endl;
                }
            }
            break;

        }



        //}
    }

    void App::menu_playMyPlaylist()
    {   
        bool quit_me{false};
        std::string rawUserInput;
        int userInput;
        int track_id = 0;
        cout<<endl;
        while(!quit_me)
        {
            cout<< "---------------------------------------"<<endl;
            cout<<current_user->getUserName()<<" 's playlist"<<endl;

            current_user->printUserPlaylist(true,track_id);
            cout<<endl;
            songPlaying(current_user->getTrackIdReturnTrackName(track_id),4);
            cout<<endl;
            cout<<"Option: 1->next, 2->previous, 3-> again, 4->selected id, 9->Previous menu, 0->Quit app "<<endl;
            cout<<"Type here:";
            cin>>rawUserInput;
            userInput=rawInputHandler(rawUserInput);

            if(userInput==0 || userInput == 9|| userInput <0) 
                {
                    quit_me =true;
                    if(userInput==0)this->flag_close_me=true;
                }
            if(userInput==1)
            {
                //1->next,
                if(track_id==(current_user->user_playlist().size()-1))
                {
                    track_id = -1;
                }
                track_id++;
            }
            else if(userInput ==2)
            {
                //2->previous
                if(track_id==0)
                {
                    track_id = current_user->user_playlist().size();
                }
                track_id--;
            }
            else if(userInput ==3)
            {
                //3->again 
                //just nothing
            }
            else if(userInput ==4)
            {
                cout<<"Put id between 0 and "<<current_user->user_playlist().size()-1<<endl;
                std::string rawUserInput_select_id;
                cin>>rawUserInput_select_id;
                int userInput_select_id;        
                userInput_select_id=rawInputHandler(rawUserInput_select_id);
                //-1 - user not exist or you type something else to exit
                //-2 - you type q
                //>=0 - user id
                if(userInput_select_id<0|| userInput_select_id>current_user->user_playlist().size()-1)
                {
                    cout<<"Track doesnt exist, I will play again last one"<<endl;                    
                }
                else
                {
                    track_id=userInput_select_id;
                }


                //3->selected id
            }
        }

        

    }

    void App::menu_editUserPlaylist()
    {
        std::string rawUserInput;
        int userInput=rawInputHandler(rawUserInput);
        cout<<endl;
        cout<<"---------" <<current_user->getUserName()<< "'s playlist ----------"<<endl;
        current_user->printUserPlaylist(true);
        cout<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"First select track id, then chose action from next menu."<<endl;
        cin>>rawUserInput;
        userInput=rawInputHandler(rawUserInput);
        cout<<"----------------------------"<<endl;

        menu_editUserPlaylist_trackMoveMenu(userInput);
    }

    void App::menu_editUserPlaylist_trackMoveMenu(int &selectedTrackId)
    {
        bool quit_me{false};
        std::string rawUserInput;
        int userInput;
        while(!quit_me)
        {
            cout<<endl;
            cout<<"----------------------------"<<endl;
            cout<<"    Current  selected track:  " << selectedTrackId<<" : "<<current_user->getTrackIdReturnTrackName(selectedTrackId)<<endl;
            cout<<endl;
            cout<<"Chose your action:"<<endl;
            if(selectedTrackId != 0)
                cout<<"1. Move to position "<< selectedTrackId-1<<endl;
            if(selectedTrackId != current_user->user_playlist().size()-1)
                cout<<"2. Move to position "<< selectedTrackId+1<<endl;
            cout<<"3. Switch with other track"<<endl;
            cout<<"4. Remove from playlist"<<endl;
            cout<<"9. Back to previous menu"<<endl;
            cout<<"0. To close app"<<endl;
            cout<<"Type  here:";
            cin>>rawUserInput;
            userInput=rawInputHandler(rawUserInput);

            if(userInput==0)
            {   quit_me=true;
                flag_close_me=true;
                cout<<"Application going to close"<<endl;
                break;
            }
            else if (userInput==9)
            {
                quit_me=true;
            }
            else if (userInput==-1)
            {
                cout<<"Option doesnt exist,please try other option"<<endl;  
            }
            else
            {
                cout<<"------- Action made ----------"<<endl;
                switch(userInput)
                {
                    case 1:
                    {
                        //TODO? i dont need to override it because it is to string, and im looking for string
                        if(!swapElementsAtList(current_user->user_playlist(),selectedTrackId,selectedTrackId-1))
                            {
                                cout<<"Move failed"<<endl;
                            }   
                        selectedTrackId-=1;
                        break;
                    }
                    case 2:
                    {                        
                        if(!swapElementsAtList(current_user->user_playlist(),selectedTrackId,selectedTrackId+1))
                            {
                                cout<<"Move failed"<<endl;  
                            }                            
                        selectedTrackId+=1;
                        break;
                    }
                    case 3:
                    {
                        cout<<"3. Switch with other track"<<endl;
                        //get user input and check it
                        std::string raw_other_track_id;
                        cout<<"Put number of second track"<<endl;
                        cin>>raw_other_track_id;
                        int int_other_track_id = rawInputHandler(raw_other_track_id);
                        if(int_other_track_id<0)
                            {   
                                break;
                            }
                            else 
                            {
                                if(int_other_track_id<=current_user->user_playlist().size())
                                {
                                    if(!swapElementsAtList(current_user->user_playlist(),selectedTrackId,int_other_track_id));
                                    {cout<<"Move failed"<<endl;}
                                        
                                    selectedTrackId = int_other_track_id;
                                    break;
                                }
                                else
                                {
                                    cout<<"That track doesnt exist"<<endl;
                                }
                            }                        
                        break;
                    }
                    case 4:
                    {
                        //std::list<std::string>::iterator it = std::find(current_user->user_playlist().begin(),
                        //                                            current_user->user_playlist().end(),
                        //                                            current_user->getTrackIdReturnTrackName(selectedTrackId));
                        current_user->user_playlist().remove(current_user->getTrackIdReturnTrackName(selectedTrackId));
                        cout<<"Track removed"<<endl;
                        cout<<endl;
                        cout<<"---- after change -----"<<endl;
                        current_user->printUserPlaylist(true);
                        quit_me=true;
                        break;
                    }                        
                }
                cout<<endl;
                cout<<"---- after change -----"<<endl;
                current_user->printUserPlaylist(true);
                cout<<endl;
            }


        }
    }

    void App::menu_showUserPlaylist()
    {
        std::string rawUserInput;
        cout<<endl;
        cout<<"---------" <<current_user->getUserName()<< "'s playlist ----------"<<endl;
        current_user->printUserPlaylist();
        cout<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Press enter key to back to previous menu"<<endl;
        cin>>rawUserInput;
        cout<<"----------------------------"<<endl;
    }

    void App::menu_select_user()
    {
        bool quit_me{false};
        std::string rawUserInput;
        int userInput;
        while(!quit_me)
        {
            if(!this->flag_isuser_selected)
            {
                cout<<"To select user typ his id, or type 'q' to exit"<<endl;
                for(auto it = this->container_user_list.begin();it!=this->container_user_list.end();++it)
                {   
                    cout<<"# "<<it->getUserId()<<"  "<<it->getUserName()<<endl;
                }

                cout<<"Type here:";
                cin>>rawUserInput;
                userInput=rawInputHandler(rawUserInput);
                
                if(userInput==-2)
                {   quit_me=true;
                    flag_close_me=true;
                    cout<<"Application going to close"<<endl;
                    break;
                }
                else if (userInput==-1)
                {
                    cout<<"user doesnt exist or you type something else to exit"<<endl;  
                }
                else
                {
                    //find user
                    for(auto &el: this->container_user_list)
                    {
                        //TODO: switch that to iterator ?
                        if(el.getUserId()==userInput)
                        {
                            this->current_user = std::make_shared<User_simple>(el);
                            this->flag_isuser_selected=true;   
                            quit_me=true;                                     
                            break;
                        }
                    }
                    if(!this->flag_isuser_selected)
                        cout<<"User doesnt exist"<<endl;                                        
                }                
            }   
        }
    }
*/