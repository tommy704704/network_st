/****************************************************************************
** Meta object code from reading C++ file 'FileTransportInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FileTransportInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileTransportInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_file_transport_st__FileTransportInterface_t {
    QByteArrayData data[7];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_file_transport_st__FileTransportInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_file_transport_st__FileTransportInterface_t qt_meta_stringdata_file_transport_st__FileTransportInterface = {
    {
QT_MOC_LITERAL(0, 0, 41), // "file_transport_st::FileTransp..."
QT_MOC_LITERAL(1, 42, 21), // "Signal_GetUploadReply"
QT_MOC_LITERAL(2, 64, 0), // ""
QT_MOC_LITERAL(3, 65, 9), // "bytesRead"
QT_MOC_LITERAL(4, 75, 10), // "totalBytes"
QT_MOC_LITERAL(5, 86, 23), // "Signal_GetDownloadReply"
QT_MOC_LITERAL(6, 110, 21) // "Slot_OnUploadProgress"

    },
    "file_transport_st::FileTransportInterface\0"
    "Signal_GetUploadReply\0\0bytesRead\0"
    "totalBytes\0Signal_GetDownloadReply\0"
    "Slot_OnUploadProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_file_transport_st__FileTransportInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,

       0        // eod
};

void file_transport_st::FileTransportInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileTransportInterface *_t = static_cast<FileTransportInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_GetUploadReply((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->Signal_GetDownloadReply((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->Slot_OnUploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FileTransportInterface::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileTransportInterface::Signal_GetUploadReply)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FileTransportInterface::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileTransportInterface::Signal_GetDownloadReply)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject file_transport_st::FileTransportInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_file_transport_st__FileTransportInterface.data,
      qt_meta_data_file_transport_st__FileTransportInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *file_transport_st::FileTransportInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *file_transport_st::FileTransportInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_file_transport_st__FileTransportInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int file_transport_st::FileTransportInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void file_transport_st::FileTransportInterface::Signal_GetUploadReply(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void file_transport_st::FileTransportInterface::Signal_GetDownloadReply(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
