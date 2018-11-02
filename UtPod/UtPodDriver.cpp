//
//  main.cpp
//  UtPod
//
//  Created by Guy on 10/25/18.
//  Copyright © 2018 Guy Co. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}


/* DEMO_Driver.cpp
 Demo Driver for the UtPod.
 
 Roger Priebe
 EE 312 10/16/18
 
 Imported by Guy on 10/25/18.
 Copyright © 2018 Guy Co. All rights reserved.
 
 This is a basic driver for the UtPod.
 
 You will want to do more complete testing.
 
 */

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "song.h"
#include "UtPod.h"

using namespace std;

ostream& operator << (ostream& out, const Song &g);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand(time(NULL));
    
    UtPod t;
    int result;
    
    Song s1("Beyonce", "Formation", 20);
    result=t.addSong(s1);
    cout << "Add song result: " << result << endl;
    
    Song s2("Beyonce", "Formation", 10);
    result=t.addSong(s2);
    cout << "Add song result: " << result << endl;
    
    Song s3("R Kelly", "Ignition (Remix)", 15);
    result=t.addSong(s3);
    cout << "Add song result: " << result << endl;

    Song s4("R Kelly", "Ignition", 9);
    result=t.addSong(s4);
    cout << "Add song result: " << result << endl;

    Song s5("Tyga", "Dip", 30);
    result=t.addSong(s5);
    cout << "Add song result: " << result << endl;
    
    Song s6("Doja Cat", "Mooo!", 40);
    result=t.addSong(s6);
    cout << "Add song result: " << result << endl;
    result=t.addSong(s6);
    cout << "Add song result: " << result << endl;

    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    
    cout << endl << "Songs" << endl;
    t.showSongList();
    
    
    cout << "Shuffling 1 /////////////////////" << endl;
    t.shuffle();
    cout << "Songs" << endl;
    t.showSongList();
    cout << "Shuffling 2 /////////////////////" << endl;
    t.shuffle();
    cout << "Songs" << endl;
    t.showSongList();
    cout << "Shuffling 3 /////////////////////" << endl;
    t.shuffle();
    cout << "Songs" << endl;
    t.showSongList();
    cout << "Shuffling 4 /////////////////////" << endl;
    t.shuffle();
    
    
    cout << "Songs" << endl;
    t.showSongList();
    cout << "Sorting /////////////////////" << endl;
    t.sortSongList();
    cout << "Songs" << endl;
    t.showSongList();
    
    
    result=t.removeSong(s2);
    cout << "Remove song result: " << result << endl;
    result=t.removeSong(s3);
    cout << "Remove song result: " << result << endl;
    
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    
    Song s7("Britney Spears", "Toxic", 150);
    result=t.addSong(s7);
    cout << "Add song result: " << result << endl;
    
    Song s8("Sheck Wes", "Mo Bamba", 150);
    result=t.addSong(s8);
    cout << "Add song result: " << result << endl;
    
    Song s9("Drake", "In My Feelings", 400);
    result=t.addSong(s9);
    cout << "Add song result: " << result << endl;

    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    
    cout << "Songs" << endl;
    t.showSongList();
    cout << "Shuffling 5 /////////////////////" << endl;
    t.shuffle();
    cout << "Songs" << endl;
    t.showSongList();
    cout << "Sorting /////////////////////" << endl;
    t.sortSongList();
    cout << "Songs" << endl;
    t.showSongList();
    
    
    result=t.removeSong(s1);
    cout << "Remove song result: " << result << endl;
    result=t.removeSong(s5);
    cout << "Remove song result: " << result << endl;
    result=t.removeSong(s4);
    cout << "Remove song result: " << result << endl;
    result=t.removeSong(s4);
    cout << "Remove song result: " << result << endl;
    
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    
    cout << "Songs" << endl;
    t.showSongList();
    
    result=t.addSong(s5);
    cout << "Add song result: " << result << endl;
    
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    
    cout << "Songs" << endl;
    t.showSongList();
    
    result=t.removeSong(s5);
    cout << "Remove song result: " << result << endl;
    result=t.removeSong(s7);
    cout << "Remove song result: " << result << endl;
    result=t.removeSong(s6);
    cout << "Remove song result: " << result << endl;
    result=t.removeSong(s6);
    cout << "Remove song result: " << result << endl;
    
    cout << "Songs" << endl;
    t.showSongList();
    
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    
    result=t.removeSong(s8);
    cout << "Remove song result: " << result << endl;
    
    cout << "Songs" << endl;
    t.showSongList();
    
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
//std::cout << "Hello, World!\n";
    return 0;
}

ostream& operator << (ostream& out, const Song &g)
{
    out << g.getTitle() << ", by: " << g.getArtist() << ", size: " << g.getSize() << "MB" << endl;
    return out;
}
