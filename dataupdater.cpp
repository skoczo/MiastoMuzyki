#include "dataupdater.h"

/*
 constructor gets media object
*/
dataUpdater::dataUpdater(Phonon::MediaObject *m)
{
    media=m;
}

/*
 check if new song is played
*/
void dataUpdater::update()
{
    //if aktualizacja is true signal newSong is emitted
    bool aktualizacja=false;

    //this is variable for hold track data
    QStringList tmp;
    //get artist to tmp
    tmp=media->metaData(Phonon::ArtistMetaData);

    //check is tmp have any data
    if(tmp.size()>0&&lastArt!=tmp[0])
    {
        lastArt=tmp[0];
        aktualizacja=true;
    }

    //get title to tmp
    tmp=media->metaData(Phonon::TitleMetaData);

    //check is tmp have any data
    if(tmp.size()>0&&lastTitle!=tmp[0])
    {
        lastTitle=tmp[0];
        aktualizacja=true;
    }

    //if aktualizacja true it means the new song is played
    if(aktualizacja)
    {
        qDebug("song change");
        emit newSong();
    }
}
