# cpp_20_music_player cpp 

It is bigger procject of Music PLayer at ubuntu.

It base on  menu-tempalte.

It contain a lot of elements:
+FileManager.h class - responsible for text file processing
+Track class - base class for track data object
+Playlist class - class for gathering Track-s
+Playlist_i class - interface class for manipulate class objects
+BaseUser class - base class for user data
+User class - interface class for manipulate user 
+Auth class - responsible for auth and logging
+GeneralFunctions.h - contain usefull functions and gather libs used in project
+Setting.h - contain namespaces with settings all kind of const data which is use in app
+App.h - responsible for lauunch console templates
+MenuTempalte.h - class used as a base for other menus
+OptionTemplate.h - class used as a base for other option, options are base for menus

TODO(main things):
+split h int h+cpp
+clean  app.h
+add test.h - and google mock framework to test
+move that test namespace from main into test.h
