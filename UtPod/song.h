//
//  song.hpp
//  UtPod
//
//  Created by Guy on 10/25/18.
//  Copyright © 2018 Guy Co. All rights reserved.
//

#ifndef song_h
#define song_h

#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class Song
{
private:
    
    string title;
    string artist;
    int size;
    
public:
    Song(string titl,string arti,int siz);
    
    void setTitle(string titl) {
        title=titl;
    }
    void setArtist(string arti) {
        artist=arti;
    }
    void setSize(int siz) {
        size=siz;
    }
    
    
    int getTitle() {
        return title;
    }
    int getArtist() {
        return artist;
    }
    int getSize() {
        return size;
    }
    
    ~Song();
    
};

#endif /* song_hpp */
