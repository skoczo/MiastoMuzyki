/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Mar 13 16:39:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      50,   44,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     101,   11,   11,   11, 0x08,
     112,  110,   11,   11, 0x08,
     128,  110,   11,   11, 0x08,
     148,  110,   11,   11, 0x08,
     174,  172,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionUstawienia_triggered()\0"
    "index\0on_listWidget_doubleClicked(QModelIndex)\0"
    "newSong()\0update()\0p\0image(QPixmap*)\0"
    "imageNext(QPixmap*)\0setProxy(QNetworkProxy)\0"
    "i\0test(int)\0setVolume(int)\0play_pause()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionUstawienia_triggered(); break;
        case 1: on_listWidget_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: newSong(); break;
        case 3: update(); break;
        case 4: image((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 5: imageNext((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 6: setProxy((*reinterpret_cast< QNetworkProxy(*)>(_a[1]))); break;
        case 7: test((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: play_pause(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
