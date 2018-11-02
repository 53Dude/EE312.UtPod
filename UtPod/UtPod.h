//
//  UtPod.hpp
//  UtPod
//
//  Created by Guy on 10/25/18.
//  Copyright © 2018 Guy Co. All rights reserved.
//

#ifndef UtPod_h
#define UtPod_h

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "song.h"

using namespace std;

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;
    
    struct SongNode
    {
        Song s;
        SongNode *next;
    };
    
    SongNode *songs;  //the head pointer
    
    int memSize;
    
public:
    UtPod();
    UtPod(int size);

    
    int addSong(Song const &s);
    int removeSong(Song const &s);
    void shuffle();
    void showSongList();
    void sortSongList();
    
    int getTotalMemory() {
        return memSize;
    }
    
    int getRemainingMemory();
    
    ~UtPod();
    
};

#endif /* UtPod_hpp */
