/****************************************************************************
** Meta object code from reading C++ file 'ftp_upload.h'
**
** Created: Wed Jul 16 16:21:04 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ftp_upload.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftp_upload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ftp_upload[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      21,   11,   11,   11, 0x08,
      46,   44,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ftp_upload[] = {
    "ftp_upload\0\0upload()\0ftpCommandStarted(int)\0"
    ",\0ftpCommandFinished(int,bool)\0"
};

void ftp_upload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ftp_upload *_t = static_cast<ftp_upload *>(_o);
        switch (_id) {
        case 0: _t->upload(); break;
        case 1: _t->ftpCommandStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ftp_upload::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ftp_upload::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ftp_upload,
      qt_meta_data_ftp_upload, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ftp_upload::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ftp_upload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ftp_upload::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ftp_upload))
        return static_cast<void*>(const_cast< ftp_upload*>(this));
    return QWidget::qt_metacast(_clname);
}

int ftp_upload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
