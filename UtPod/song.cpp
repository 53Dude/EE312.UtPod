//
//  song.cpp
//  UtPod
//
//  Created by Guy on 10/25/18.
//  Copyright © 2018 Guy Co. All rights reserved.
//

#include "song.h"

using namespace std;

//song constructor with inputs

Song::Song(string arti,string titl,int siz){
    
    title=titl;
    artist=arti;
    size=siz;
    
}

//song constructor with no inputs

Song::Song(){
    
    title="";
    artist="";
    size=NULL;
    
}

//override > operator

bool Song::operator >(Song const &rhs)
{
    if(artist.compare(rhs.artist)>0)
        return true;
    else if(artist.compare(rhs.artist)<0)
        return false;
    else if(title.compare(rhs.title)>0)
        return true;
    else if(title.compare(rhs.title)<0)
        return false;
    else if(size > rhs.size)
        return true;
    else if(size < rhs.size)
        return false;
    else
        return false;
}

//override < operator

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

//override == operator

bool Song::operator ==(Song const &rhs)
{
    if((artist == rhs.artist)&&(title == rhs.title)&&(size == rhs.size))
        return true;
    else
        return false;
}

//override = operator

bool Song::operator =(Song const &rhs){
    
    artist=rhs.getArtist();
    title=rhs.getTitle();
    size=rhs.getSize();
    
    return true;
    
}

//prints song to terminal

void Song::printSong(string prefix){
    
    cout << prefix << title << ", \tby: " << artist << ", \tsize: " << size << "MB" << endl;
    
}

//not needed but here anyway

Song::~Song(){
    
//cout << "destructor called on: " << this->title << ", by: " << this->artist << ". " << this->size << "MB freed." << endl;
    
}


