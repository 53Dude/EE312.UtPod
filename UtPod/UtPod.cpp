//
//  UtPod.cpp
//  UtPod
//
//  Created by Guy on 10/25/18.
//  Copyright © 2018 Guy Co. All rights reserved.
//

#include "UtPod.h"

using namespace std;

//pre-conditions: none
//purpose: Constructor for the default UTPod with no input
//result: UTPod with no songs and 512 MB memory

UtPod::UtPod(){
    
    memSize=MAX_MEMORY;
    songs=NULL;
    
}

//pre-conditions: none
//purpose: Constructor for the default UTPod with input
//result: UTPod with no songs and size MB memory

UtPod::UtPod(int size){
    
    if(size>=MAX_MEMORY||size<=0)
        memSize=MAX_MEMORY;
    else
        memSize=size;
    songs=NULL;
}

//pre-conditions: Song must have title, artist, and needs to fit in the UTPod's storage
//purpose: Adds a song to UTPod if it fits
//result: song is added to target UTPod

int UtPod::addSong(Song const &s){
    
    if(s.getSize()<=0||s.getArtist()==""||s.getTitle()==""){
        return NOT_FOUND;
    }
    
    if(s.getSize()>this->getRemainingMemory()){
        return NO_MEMORY;
    }
    
    UtPod::SongNode * temp = new SongNode;
    
    (temp->s).setSize(s.getSize());
    (temp->s).setTitle(s.getTitle());
    (temp->s).setArtist(s.getArtist());
    
    temp->next=songs;
    this->songs=temp;
    
    return SUCCESS;
    
}

//pre-conditions: target utpod must have songs
//purpose: remove song s from the utpod
//result: song s is no longer in utpod

int UtPod::removeSong(Song const &s){
    
    Song temps=s;
    SongNode *ptr=songs;
    SongNode *trail=songs;
    
    if(ptr->s==temps){
        songs=ptr->next;
        delete(ptr);
        return SUCCESS;
    }
    ptr=ptr->next;
    
    while(ptr!=NULL){
        if(ptr->s==temps){
            trail->next=ptr->next;
            delete(ptr);
            return SUCCESS;
        }
        ptr=ptr->next;
        trail=trail->next;
    }
    
    return NOT_FOUND;
    
}

//pre-conditions: none
//purpose: to shuffle songs in the utpod
//result: shuffled utpod

void UtPod::shuffle(){
    
//cout << "shuffle" << endl;
    
    if(songs==NULL)
        return;
    
    SongNode *tempSN=songs;
    vector<Song> working;
    Song tempSong;
    
    while(tempSN!=NULL){
        working.push_back(tempSN->s);
        tempSN=tempSN->next;
    }
    
    if(working.size()==1)
        return;
    
    //flips list a random amount of times, moving elements depending on random value
    int temp=rand()%9;
    for(int i=0;i<working.size()*temp;i++){
        
        int iOne=rand()%working.size();
        int iTwo=rand()%working.size();
        while(iOne==0||iTwo==0){
            iOne=rand()%working.size();
            iTwo=rand()%working.size();
        }
        
        tempSong=working[iOne];
        working[iOne]=working[iTwo];
        working[iTwo]=tempSong;
    }
    tempSN=songs;
    int i=0;
    while(tempSN!=NULL){
        tempSN->s=working[i];
        tempSN=tempSN->next;
        i++;
    }
    
}

//pre-conditions: none
//purpose: prints list of songs to screen
//result: songs printed to terminal

void UtPod::showSongList(){
    
    if(songs==NULL){
        return;
    }
    
    SongNode *ptr=songs;
    while(ptr!=NULL){
        
        ptr->s.printSong("");
        ptr=ptr->next;
        
    }
    cout << endl;
    
}

//pre-conditions: none
//purpose: sorts songs in list to be ordered by artist, then title, then size
//result: sorted list

void UtPod::sortSongList(){
    
//cout << "sort" << endl;
    
    if(songs==NULL)
        return;
    
    SongNode *tempSN=songs;
    vector<Song> working;
    Song tempSong;
    
    while(tempSN!=NULL){
        working.push_back(tempSN->s);
        tempSN=tempSN->next;
    }
    if(working.size()==1)
        return;
    
    bool done=false;
    Song mail;
    while(!done){
        done=true;
        for(int i=0;i<working.size()-1;i++){
            if(working[i]>working[i+1]){
                done=false;
                mail=working[i];
                working[i]=working[i+1];
                working[i+1]=mail;
            }
        }
    }
    
    tempSN=songs;
    int i=0;
    while(tempSN!=NULL){
        tempSN->s=working[i];
        tempSN=tempSN->next;
        i++;
    }
    
}

//returns remaining memory of specific utpod

int UtPod::getRemainingMemory(){
    
    SongNode *ptr=songs;
    int taken=0;
    
    while(ptr!=NULL){
        
        taken+=ptr->s.getSize();
        ptr=ptr->next;
        
    }
    
    return memSize-taken;
    
}

//deconstructor for utpod

UtPod::~UtPod(){
    
    SongNode *p = songs;
//    while (p != NULL)
//    {
//        p->s.printSong("Deconstructing: ");
//        p = p->next;
//    }
    
    while (songs != NULL) {
        p = songs;
        songs = songs->next;
        delete p;
    }
    
}
