//
//  UtPod.cpp
//  UtPod
//
//  Created by Guy on 10/25/18.
//  Copyright © 2018 Guy Co. All rights reserved.
//

#include "UtPod.h"

using namespace std;

UtPod::UtPod(){
    
    memSize=MAX_MEMORY;
    songs=NULL;
    
}

UtPod::UtPod(int size){
    
    if(size>=MAX_MEMORY||size<=0)
        memSize=MAX_MEMORY;
    else
        memSize=size;
    songs=NULL;
}


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
    int temp=1+rand()%(working.size()*3);
    for(int i=0;i<temp;i++){
        for(int s=0;s<(int)working.size();s++){
            for(int e=(int)working.size()-1;e>0;e--){
                tempSong=working[s];
                working[s]=working[e];
                working[e]=tempSong;
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

void UtPod::showSongList(){
    
    if(songs==NULL){
        return;
    }
    
    SongNode *ptr=songs;
    while(ptr!=NULL){
        
        ptr->s.printSong("");
        
        ptr=ptr->next;
        
    }
    
}

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

int UtPod::getRemainingMemory(){
    
    SongNode *ptr=songs;
    int taken=0;
    
    while(ptr!=NULL){
        
        taken+=ptr->s.getSize();
        ptr=ptr->next;
        
    }
    
    return memSize-taken;
    
}

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
