#ifndef DATAUPDATER_H
#define DATAUPDATER_H
#include <QObject>
#include <phonon/MediaObject>
#include <phonon/phonon>

/*
 this class emit signal newSong
 when song chagne
 */
class dataUpdater : public QObject
{
    Q_OBJECT
private:
    Phonon::MediaObject *media;
    //last artist
    QString lastArt;
    //last title
    QString lastTitle;
public:
    /* destructor get media objet
       this object have information about actual track
       */
    dataUpdater(Phonon::MediaObject *m);
public slots:

    /*this function checks
      if new song is played
      */
    void update();
signals:
    /*
     this signal is emitted
     when song changed
     */
    void newSong();
};

#endif // DATAUPDATER_H
