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
#include <string>

using namespace std;

class Song
{
private:
    
    string title;
    string artist;
    int size;
    
public:
    Song(string titl,string arti,int siz);
    Song();
    
    void dupeSong(Song *a, Song const &b);
    
    void setTitle(string titl) {
        title=titl;
    }
    void setArtist(string arti) {
        artist=arti;
    }
    void setSize(int siz) {
        size=siz;
    }

    
    string getTitle() const {
        return title;
    }
    string getArtist() const {
        return artist;
    }
    int getSize() const {
        return size;
    }
    
    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator =(Song const &rhs);
    
    void printSong(string prefix);
    
    ~Song();
    
};

#endif /* song_hpp */
