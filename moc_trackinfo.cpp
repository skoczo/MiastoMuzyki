/****************************************************************************
** Meta object code from reading C++ file 'trackinfo.h'
**
** Created: Thu Feb 10 18:43:31 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "trackinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_trackInfo[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   23,   10,   10, 0x0a,
      62,   54,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_trackInfo[] = {
    "trackInfo\0\0dataReady()\0reply\0"
    "finished(QNetworkReply*)\0station\0"
    "show(QString)\0"
};

const QMetaObject trackInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_trackInfo,
      qt_meta_data_trackInfo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &trackInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *trackInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *trackInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_trackInfo))
        return static_cast<void*>(const_cast< trackInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int trackInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dataReady(); break;
        case 1: finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: show((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void trackInfo::dataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
