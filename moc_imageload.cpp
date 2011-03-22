/****************************************************************************
** Meta object code from reading C++ file 'imageload.h'
**
** Created: Tue Mar 22 17:03:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imageload.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_imageLoad[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   27,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_imageLoad[] = {
    "imageLoad\0\0image(QPixmap*)\0reply\0"
    "finished(QNetworkReply*)\0"
};

const QMetaObject imageLoad::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_imageLoad,
      qt_meta_data_imageLoad, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &imageLoad::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *imageLoad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *imageLoad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_imageLoad))
        return static_cast<void*>(const_cast< imageLoad*>(this));
    return QObject::qt_metacast(_clname);
}

int imageLoad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: image((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 1: finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void imageLoad::image(QPixmap * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
