//
//  song.cpp
//  UtPod
//
//  Created by Guy on 10/25/18.
//  Copyright © 2018 Guy Co. All rights reserved.
//

#include "song.h"

using namespace std;

Song::Song(string arti,string titl,int siz){
    
    title=titl;
    artist=arti;
    size=siz;
    
}

Song::Song(){
    
    title="";
    artist="";
    size=NULL;
    
}

bool Song::operator >(Song const &rhs)
{
    if(artist < rhs.artist)
        return false;
    else if(title < rhs.title)
        return false;
    else if(size < rhs.size)
        return false;
    else
        return true;
}

bool Song::operator <(Song const &rhs)
{
    if(artist > rhs.artist)
        return false;
    else if(title > rhs.title)
        return false;
    else if(size > rhs.size)
        return false;
    else
        return true;
}

bool Song::operator ==(Song const &rhs)
{
    if((artist == rhs.artist)&&(title == rhs.title)&&(size == rhs.size))
        return true;
    else
        return false;
}

bool Song::operator =(Song const &rhs){
    
    artist=rhs.getArtist();
    title=rhs.getTitle();
    size=rhs.getSize();
    
    return true;
    
}

void Song::printSong(string prefix){
    
    cout << prefix << title << ", by: " << artist << ", size: " << size << "MB" << endl;
    
}

Song::~Song(){
    
//cout << "destructor called on: " << this->title << ", by: " << this->artist << ". " << this->size << "MB freed." << endl;
    
}


