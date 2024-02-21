
    namespace TestCases
    {
         void test8_f_vector_int_from_cin_getline()
        {            
            
            cout<<"Give me some numbers"<<endl;
            std::vector<int> a = vector_int_from_cin_getline();
            for(auto el:a)
            {cout<<el<<endl;}     
            
            cout<<"Give me some numbers ill remove duplicates"<<endl;
            std::vector<int> b = vector_int_from_cin_getline(true);
            for(auto el2:b)
            {cout<<el2<<endl;}    
            
        }

        
        void test7_f_waitForUserInput()
        {
            cout<<""<<endl;
            //waitForUserInput();
        }

        void test6_f_songPlaying()
        {
            songPlaying("abba",4);
        }
        
        void test4_f_putTrackIdReturnTrackName()
        {
            User_simple u("Ania",33);
            u.printUserPlaylist(true);
            cout<<putTrackIdReturnTrackName(2,u.user_playlist())<<endl;
        }
        void test2_f_swap()
        {
            User_simple u("Ania",22);
            u.printUserPlaylist();
            //auto list = u.user_playlist();
            cout<<"we switch it"<<endl;
            std::list<std::string>::iterator it = u.user_playlist().begin();
            //std::advance(it,1);
            std::list<std::string>::iterator it2 = u.user_playlist().begin();
            std::advance(it2,2);
            //it - begin 
            //it2 - 3th - swan lake
            std::swap(*it,*it2);
            cout<<endl;
            u.printUserPlaylist();
        }
        void test3_f_swapElementsAtList()
        {
            User_simple u("Ania",33);
            u.printUserPlaylist();
            cout<<swapElementsAtList(u.user_playlist(),"Kodak Kodak-Beta-21","Davy-Jones-34")<<endl;
            u.printUserPlaylist();
        }
        void test5_f_swapElementsAtList_by_track_id()
        {
            cout<<"---- test test5_f_swapElementsAtList_by_track_id -----"<<endl;
            std::vector<int> to_switch = {3,0};
            User_simple u("Ania",33);
            u.printUserPlaylist(true);
            std::string el1_before{putTrackIdReturnTrackName(to_switch[0],u.user_playlist())};
            std::string el2_before{putTrackIdReturnTrackName(to_switch[1],u.user_playlist())};
            std::string el1_after;
            std::string el2_after;
            //cout<<swapElementsAtList(u.user_playlist(),0,2)<<endl;
            cout<<swapElementsAtList(u.user_playlist(),to_switch[0],to_switch[1])<<endl;
            u.printUserPlaylist(true);
            cout<<"---------"<<endl;
            el1_after={putTrackIdReturnTrackName(to_switch[0],u.user_playlist())};
            el2_after={putTrackIdReturnTrackName(to_switch[1],u.user_playlist())};
            cout<<"moved: " <<to_switch[0]<<" "<<el1_before<<" --> "<<to_switch[1]<< " " <<el1_after<<endl;
            cout<<"moved: " <<to_switch[1]<<" "<<el2_before<<" --> "<<to_switch[0]<< " " <<el2_after<<endl;

        }
    }
